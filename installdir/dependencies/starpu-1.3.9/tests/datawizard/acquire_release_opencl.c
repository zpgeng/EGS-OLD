/* StarPU --- Runtime system for heterogeneous multicore architectures.
 *
 * Copyright (C) 2012-2021  Université de Bordeaux, CNRS (LaBRI UMR 5800), Inria
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

/*
 * Queue an OpenCL kernel that just increments a variable
 */

extern struct starpu_opencl_program opencl_program;
void increment_opencl(void *buffers[], void *args)
{
	(void) args;
	int id, devid;
        cl_int err;
	cl_kernel kernel;
	cl_command_queue queue;

	cl_mem val = (cl_mem)STARPU_VARIABLE_GET_PTR(buffers[0]);

	id = starpu_worker_get_id_check();
	devid = starpu_worker_get_devid(id);

	err = starpu_opencl_load_kernel(&kernel, &queue, &opencl_program, "_increment_opencl_codelet", devid);
	if (err != CL_SUCCESS)
		STARPU_OPENCL_REPORT_ERROR(err);

	err = clSetKernelArg(kernel, 0, sizeof(val), &val);
	if (err != CL_SUCCESS)
		STARPU_OPENCL_REPORT_ERROR(err);

	{
		size_t global=1;
		size_t local=1;

		err = clEnqueueNDRangeKernel(queue, kernel, 1, NULL, &global, &local, 0, NULL, NULL);
		if (err != CL_SUCCESS)
			STARPU_OPENCL_REPORT_ERROR(err);
	}
	starpu_opencl_release_kernel(kernel);
}
