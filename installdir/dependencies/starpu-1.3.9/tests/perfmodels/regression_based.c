/* StarPU --- Runtime system for heterogeneous multicore architectures.
 *
 * Copyright (C) 2011-2021  Université de Bordeaux, CNRS (LaBRI UMR 5800), Inria
 * Copyright (C) 2011       Télécom-SudParis
 *
 * StarPU is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or (at
 * your option) any later version.
 *
 * StarPU is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU Lesser General Public License in COPYING.LGPL for more details.
 */

#include <starpu.h>
#include <starpu_scheduler.h>
#include "../helper.h"

/*
 * Benchmark memset with a linear regression
 */

#define START 1024
#ifdef STARPU_QUICK_CHECK
#define END 1048576
#else
#define END 16777216
#endif

#ifdef STARPU_USE_CUDA
static void memset_cuda(void *descr[], void *arg)
{
	(void)arg;
	STARPU_SKIP_IF_VALGRIND;

	int *ptr = (int *)STARPU_VECTOR_GET_PTR(descr[0]);
	unsigned n = STARPU_VECTOR_GET_NX(descr[0]);

	cudaMemsetAsync(ptr, 42, n * sizeof(*ptr), starpu_cuda_get_local_stream());
}
#endif

#ifdef STARPU_USE_OPENCL
extern void memset_opencl(void *buffers[], void *args);
#endif

void memset0_cpu(void *descr[], void *arg)
{
	(void)arg;
	STARPU_SKIP_IF_VALGRIND;

	int *ptr = (int *)STARPU_VECTOR_GET_PTR(descr[0]);
	unsigned n = STARPU_VECTOR_GET_NX(descr[0]);
	unsigned i;

	for (i = 0; i < n; i++)
		ptr[i] = 42;
}

void memset_cpu(void *descr[], void *arg)
{
	(void)arg;
	STARPU_SKIP_IF_VALGRIND;

	int *ptr = (int *)STARPU_VECTOR_GET_PTR(descr[0]);
	unsigned n = STARPU_VECTOR_GET_NX(descr[0]);

	starpu_usleep(10);
	memset(ptr, 42, n * sizeof(*ptr));
}

static struct starpu_perfmodel model =
{
	.type = STARPU_REGRESSION_BASED,
	.symbol = "memset_regression_based"
};

static struct starpu_perfmodel nl_model =
{
	.type = STARPU_NL_REGRESSION_BASED,
	.symbol = "non_linear_memset_regression_based"
};

static struct starpu_codelet memset_cl =
{
#ifdef STARPU_USE_CUDA
	.cuda_funcs = {memset_cuda},
	.cuda_flags = {STARPU_CUDA_ASYNC},
#endif
#ifdef STARPU_USE_OPENCL
	.opencl_funcs = {memset_opencl},
	.opencl_flags = {STARPU_OPENCL_ASYNC},
#endif
	.cpu_funcs = {memset0_cpu, memset_cpu},
	.cpu_funcs_name = {"memset0_cpu", "memset_cpu"},
	.model = &model,
	.nbuffers = 1,
	.modes = {STARPU_W}
};

static struct starpu_codelet nl_memset_cl =
{
#ifdef STARPU_USE_CUDA
	.cuda_funcs = {memset_cuda},
	.cuda_flags = {STARPU_CUDA_ASYNC},
#endif
#ifdef STARPU_USE_OPENCL
	.opencl_funcs = {memset_opencl},
	.opencl_flags = {STARPU_OPENCL_ASYNC},
#endif
	.cpu_funcs = {memset0_cpu, memset_cpu},
	.cpu_funcs_name = {"memset0_cpu", "memset_cpu"},
	.model = &nl_model,
	.nbuffers = 1,
	.modes = {STARPU_W}
};

static void test_memset(int nelems, struct starpu_codelet *codelet)
{
	int nloops = 100;
	int loop;
	starpu_data_handle_t handle;

        starpu_vector_data_register(&handle, -1, (uintptr_t)NULL, nelems, sizeof(int));
	for (loop = 0; loop < nloops; loop++)
	{
		struct starpu_task *task = starpu_task_create();

		task->cl = codelet;
		task->handles[0] = handle;

		int ret = starpu_task_submit(task);
		if (ret == -ENODEV)
			exit(STARPU_TEST_SKIPPED);
		STARPU_CHECK_RETURN_VALUE(ret, "starpu_task_submit");
	}

        starpu_data_unregister(handle);
}

static void show_task_perfs(int size, struct starpu_task *task)
{
	unsigned workerid;
	for (workerid = 0; workerid < starpu_worker_get_count(); workerid++)
	{
		char name[32];
		starpu_worker_get_name(workerid, name, sizeof(name));

		unsigned nimpl;
		for (nimpl = 0; nimpl < STARPU_MAXIMPLEMENTATIONS; nimpl++)
		{
			FPRINTF(stdout, "Expected time for %d on %s (impl %u):\t%f\n",
				size, name, nimpl, starpu_task_expected_length(task, starpu_worker_get_perf_archtype(workerid, task->sched_ctx), nimpl));
		}
	}
}

#ifdef STARPU_USE_OPENCL
struct starpu_opencl_program opencl_program;
#endif

int main(int argc, char **argv)
{
	struct starpu_conf conf;
	starpu_data_handle_t handle;
	int ret;

	starpu_conf_init(&conf);

	conf.sched_policy_name = "dmda";
	conf.calibrate = 2;

	ret = starpu_initialize(&conf, &argc, &argv);
	if (ret == -ENODEV) return STARPU_TEST_SKIPPED;
	STARPU_CHECK_RETURN_VALUE(ret, "starpu_init");

#ifdef STARPU_USE_OPENCL
	ret = starpu_opencl_load_opencl_from_file("tests/perfmodels/opencl_memset_kernel.cl",
						  &opencl_program, NULL);
	STARPU_CHECK_RETURN_VALUE(ret, "starpu_opencl_load_opencl_from_file");
#endif

	int size;
	for (size = START; size < END; size *= 2)
	{
		/* Use a linear regression */
		test_memset(size, &memset_cl);

		/* Use a non-linear regression */
		test_memset(size, &nl_memset_cl);
	}

	ret = starpu_task_wait_for_all();
	STARPU_CHECK_RETURN_VALUE(ret, "starpu_task_wait_for_all");

	/* Now create a dummy task just to estimate its duration according to the regression */

	size = 12345;

	starpu_vector_data_register(&handle, -1, (uintptr_t)NULL, size, sizeof(int));

	struct starpu_task *task = starpu_task_create();
	task->cl = &memset_cl;
	task->handles[0] = handle;
	task->destroy = 0;

	show_task_perfs(size, task);

	task->cl = &nl_memset_cl;

	show_task_perfs(size, task);

	starpu_task_destroy(task);

	starpu_data_unregister(handle);

#ifdef STARPU_USE_OPENCL
        ret = starpu_opencl_unload_opencl(&opencl_program);
        STARPU_CHECK_RETURN_VALUE(ret, "starpu_opencl_unload_opencl");
#endif
	starpu_shutdown();

	return EXIT_SUCCESS;
}
