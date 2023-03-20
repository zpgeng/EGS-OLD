/* StarPU --- Runtime system for heterogeneous multicore architectures.
 *
 * Copyright (C) 2009-2021  Université de Bordeaux, CNRS (LaBRI UMR 5800), Inria
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

/* LU Kernels with partial pivoting */

#include "xlu.h"
#include "xlu_kernels.h"

/*
 *	Construct the DAG
 */

static struct starpu_task *create_task(starpu_tag_t id)
{
	struct starpu_task *task = starpu_task_create();
		task->cl_arg = NULL;

	task->use_tag = 1;
	task->tag_id = id;

	return task;
}

static int create_task_pivot(starpu_data_handle_t *dataAp, unsigned nblocks,
			     struct piv_s *piv_description,
			     unsigned k, unsigned i,
			     starpu_data_handle_t (* get_block)(starpu_data_handle_t *, unsigned, unsigned, unsigned), unsigned no_prio)
{
	int ret;

	struct starpu_task *task = create_task(PIVOT(k, i));

	task->cl = &cl_pivot;
	task->color = 0xc0c000;

	/* which sub-data is manipulated ? */
	task->handles[0] = get_block(dataAp, nblocks, k, i);

	task->cl_arg = &piv_description[k];

	/* this is an important task */
	if (!no_prio && (i == k+1))
		task->priority = STARPU_MAX_PRIO;

	/* enforce dependencies ... */
	if (k == 0)
	{
		starpu_tag_declare_deps(PIVOT(k, i), 1, TAG11(k));
	}
	else
	{
		if (i > k)
		{
			starpu_tag_declare_deps(PIVOT(k, i), 2, TAG11(k), TAG22(k-1, i, k));
		}
		else
		{
			starpu_tag_t *tags = malloc((nblocks - k)*sizeof(starpu_tag_t));

			tags[0] = TAG11(k);
			unsigned ind, ind2;
			for (ind = k + 1, ind2 = 0; ind < nblocks; ind++, ind2++)
			{
				tags[1 + ind2] = TAG22(k-1, ind, k);
			}

			/* perhaps we could do better ... :/  */
			starpu_tag_declare_deps_array(PIVOT(k, i), (nblocks-k), tags);
			free(tags);
		}
	}

	ret = starpu_task_submit(task);
	if (ret != -ENODEV) STARPU_CHECK_RETURN_VALUE(ret, "starpu_task_submit");
	return ret;
}

static struct starpu_task *create_task_11_pivot(starpu_data_handle_t *dataAp, unsigned nblocks,
						unsigned k, struct piv_s *piv_description,
						starpu_data_handle_t (* get_block)(starpu_data_handle_t *, unsigned, unsigned, unsigned), unsigned no_prio)
{
	struct starpu_task *task = create_task(TAG11(k));

	task->cl = &cl11_pivot;
	task->color = 0xffff00;

	task->cl_arg = &piv_description[k];

	/* which sub-data is manipulated ? */
	task->handles[0] = get_block(dataAp, nblocks, k, k);

	/* this is an important task */
	if (!no_prio)
		task->priority = STARPU_MAX_PRIO;

	/* enforce dependencies ... */
	if (k > 0)
	{
		starpu_tag_declare_deps(TAG11(k), 1, TAG22(k-1, k, k));
	}

	return task;
}

static int create_task_12(starpu_data_handle_t *dataAp, unsigned nblocks, unsigned k, unsigned j,
			  starpu_data_handle_t (* get_block)(starpu_data_handle_t *, unsigned, unsigned, unsigned), unsigned no_prio)
{
	int ret;

/*	printf("task 12 k,i = %d,%d TAG = %llx\n", k,i, TAG12(k,i)); */

	struct starpu_task *task = create_task(TAG12(k, j));

	task->cl = &cl12;
	task->color = 0x8080ff;

	task->cl_arg = (void *)(uintptr_t)(task->tag_id);

	/* which sub-data is manipulated ? */
	task->handles[0] = get_block(dataAp, nblocks, k, k);
	task->handles[1] = get_block(dataAp, nblocks, j, k);

	if (!no_prio && (j == k+1))
	{
		task->priority = STARPU_MAX_PRIO;
	}

	/* enforce dependencies ... */
#if 0
	starpu_tag_declare_deps(TAG12(k, i), 1, PIVOT(k, i));
#endif
	if (k > 0)
	{
		starpu_tag_declare_deps(TAG12(k, j), 2, TAG11(k), TAG22(k-1, k, j));
	}
	else
	{
		starpu_tag_declare_deps(TAG12(k, j), 1, TAG11(k));
	}

	ret = starpu_task_submit(task);
	if (ret != -ENODEV) STARPU_CHECK_RETURN_VALUE(ret, "starpu_task_submit");
	return ret;
}

static int create_task_21(starpu_data_handle_t *dataAp, unsigned nblocks, unsigned k, unsigned i,
			  starpu_data_handle_t (* get_block)(starpu_data_handle_t *, unsigned, unsigned, unsigned), unsigned no_prio)
{
	int ret;

	struct starpu_task *task = create_task(TAG21(k, i));

	task->cl = &cl21;
	task->color = 0x8080c0;

	/* which sub-data is manipulated ? */
	task->handles[0] = get_block(dataAp, nblocks, k, k);
	task->handles[1] = get_block(dataAp, nblocks, k, i);

	if (!no_prio && (i == k+1))
	{
		task->priority = STARPU_MAX_PRIO;
	}

	task->cl_arg = (void *)(uintptr_t)(task->tag_id);

	/* enforce dependencies ... */
	starpu_tag_declare_deps(TAG21(k, i), 1, PIVOT(k, i));

	ret = starpu_task_submit(task);
	if (ret != -ENODEV) STARPU_CHECK_RETURN_VALUE(ret, "starpu_task_submit");
	return ret;
}

static int create_task_22(starpu_data_handle_t *dataAp, unsigned nblocks, unsigned k, unsigned i, unsigned j,
			  starpu_data_handle_t (* get_block)(starpu_data_handle_t *, unsigned, unsigned, unsigned), unsigned no_prio)
{
	int ret;

/*	printf("task 22 k,i,j = %d,%d,%d TAG = %llx\n", k,i,j, TAG22(k,i,j)); */

	struct starpu_task *task = create_task(TAG22(k, i, j));

	task->cl = &cl22;
	task->color = 0x00ff00;

	task->cl_arg = (void *)(uintptr_t)(task->tag_id);

	/* which sub-data is manipulated ? */
	task->handles[0] = get_block(dataAp, nblocks, k, i); /* produced by TAG21(k, i) */
	task->handles[1] = get_block(dataAp, nblocks, j, k); /* produced by TAG12(k, j) */
	task->handles[2] = get_block(dataAp, nblocks, j, i);  /* produced by TAG22(k-1, i, j) */

	if (!no_prio &&  (i == k + 1) && (j == k +1) )
	{
		task->priority = STARPU_MAX_PRIO;
	}

	/* enforce dependencies ... */
	if (k > 0)
	{
		starpu_tag_declare_deps(TAG22(k, i, j), 3, TAG22(k-1, i, j), TAG12(k, j), TAG21(k, i));
	}
	else
	{
		starpu_tag_declare_deps(TAG22(k, i, j), 2, TAG12(k, j), TAG21(k, i));
	}

	ret = starpu_task_submit(task);
	if (ret != -ENODEV) STARPU_CHECK_RETURN_VALUE(ret, "starpu_task_submit");
	return ret;
}

/*
 *	code to bootstrap the factorization
 */

static int dw_codelet_facto_pivot(starpu_data_handle_t *dataAp,
				  struct piv_s *piv_description,
				  unsigned nblocks,
				  starpu_data_handle_t (* get_block)(starpu_data_handle_t *, unsigned, unsigned, unsigned),
				  double *timing, unsigned no_prio)
{
	int ret;

	double start;
	double end;

	struct starpu_task *entry_task = NULL;

	/* create all the DAG nodes */
	unsigned i,j,k;

	if (bound)
		starpu_bound_start(bounddeps, boundprio);

	for (k = 0; k < nblocks; k++)
	{
		starpu_iteration_push(k);
		struct starpu_task *task = create_task_11_pivot(dataAp, nblocks, k, piv_description, get_block, no_prio);

		/* we defer the launch of the first task */
		if (k == 0)
		{
			entry_task = task;
		}
		else
		{
			ret = starpu_task_submit(task);
			if (ret != -ENODEV) STARPU_CHECK_RETURN_VALUE(ret, "starpu_task_submit");
			if (ret == -ENODEV) return ret;
		}

		for (i = 0; i < nblocks; i++)
		{
			if (i != k)
			{
				ret = create_task_pivot(dataAp, nblocks, piv_description, k, i, get_block, no_prio);
				if (ret == -ENODEV) return ret;
			}
		}

		for (i = k+1; i<nblocks; i++)
		{
			ret = create_task_12(dataAp, nblocks, k, i, get_block, no_prio);
			if (ret == -ENODEV) return ret;
			ret = create_task_21(dataAp, nblocks, k, i, get_block, no_prio);
			if (ret == -ENODEV) return ret;
		}

		for (i = k+1; i<nblocks; i++)
		{
			for (j = k+1; j<nblocks; j++)
			{
			     ret = create_task_22(dataAp, nblocks, k, i, j, get_block, no_prio);
			     if (ret == -ENODEV) return ret;
			}
		}
		starpu_iteration_pop();
	}

	/* we wait the last task (TAG11(nblocks - 1)) and all the pivot tasks */
	starpu_tag_t *tags = malloc(nblocks*nblocks*sizeof(starpu_tag_t));
	unsigned ndeps = 0;

	tags[ndeps++] = TAG11(nblocks - 1);

	for (j = 0; j < nblocks; j++)
	{
		for (i = 0; i < j; i++)
		{
			tags[ndeps++] = PIVOT(j, i);
		}
	}

	/* schedule the codelet */
	start = starpu_timing_now();
	ret = starpu_task_submit(entry_task);
	if (ret != -ENODEV) STARPU_CHECK_RETURN_VALUE(ret, "starpu_task_submit");

	/* stall the application until the end of computations */
	starpu_tag_wait_array(ndeps, tags);
/*	starpu_task_wait_for_all(); */
	free(tags);

	end = starpu_timing_now();

	if (bound)
		starpu_bound_stop();

	*timing = end - start;
	return 0;
}

starpu_data_handle_t get_block_with_striding(starpu_data_handle_t *dataAp, unsigned nblocks, unsigned j, unsigned i)
{
	/* we use filters */
	(void)nblocks;
	return starpu_data_get_sub_data(*dataAp, 2, j, i);
}


int STARPU_LU(lu_decomposition_pivot)(TYPE *matA, unsigned *ipiv, unsigned size, unsigned ld, unsigned nblocks, unsigned no_prio)
{
	starpu_data_handle_t dataA;

	/* monitor and partition the A matrix into blocks :
	 * one block is now determined by 2 unsigned (i,j) */
	starpu_matrix_data_register(&dataA, STARPU_MAIN_RAM, (uintptr_t)matA, ld, size, size, sizeof(TYPE));

	/* We already enforce deps by hand */
	starpu_data_set_sequential_consistency_flag(dataA, 0);

	struct starpu_data_filter f =
	{
		.filter_func = starpu_matrix_filter_vertical_block,
		.nchildren = nblocks
	};

	struct starpu_data_filter f2 =
	{
		.filter_func = starpu_matrix_filter_block,
		.nchildren = nblocks
	};

	starpu_data_map_filters(dataA, 2, &f, &f2);

	unsigned i;
	for (i = 0; i < size; i++)
		ipiv[i] = i;

	struct piv_s *piv_description = malloc(nblocks*sizeof(struct piv_s));
	unsigned block;
	for (block = 0; block < nblocks; block++)
	{
		piv_description[block].piv = ipiv;
		piv_description[block].first = block * (size / nblocks);
		piv_description[block].last = (block + 1) * (size / nblocks);
	}

#if 0
	unsigned j;
	for (j = 0; j < nblocks; j++)
	for (i = 0; i < nblocks; i++)
	{
		printf("BLOCK %d %d	%p\n", i, j, &matA[i*(size/nblocks) + j * (size/nblocks)*ld]);
	}
#endif

	double timing=0.0;
	int ret = dw_codelet_facto_pivot(&dataA, piv_description, nblocks, get_block_with_striding, &timing, no_prio);

	unsigned n = starpu_matrix_get_nx(dataA);
	double flop = (2.0f*n*n*n)/3.0f;

	PRINTF("# size\tms\tGFlop/s");
	if (bound)
		PRINTF("\tTms\tTGFlop/s");
	PRINTF("\n");
	PRINTF("%u\t%.0f\t%.1f", n, timing/1000, flop/timing/1000.0f);
	if (bound)
	{
		double min;
		starpu_bound_compute(&min, NULL, 0);
		PRINTF("\t%.0f\t%.1f", min, flop/min/1000000.0f);
	}
	PRINTF("\n");

	/* gather all the data */
	starpu_data_unpartition(dataA, STARPU_MAIN_RAM);
	starpu_data_unregister(dataA);
	free(piv_description);

	return ret;
}


starpu_data_handle_t get_block_with_no_striding(starpu_data_handle_t *dataAp, unsigned nblocks, unsigned j, unsigned i)
{
	/* dataAp is an array of data handle */
	return dataAp[i+j*nblocks];
}

int STARPU_LU(lu_decomposition_pivot_no_stride)(TYPE **matA, unsigned *ipiv, unsigned size, unsigned ld, unsigned nblocks, unsigned no_prio)
{
	(void)ld;
	if (starpu_mic_worker_get_count() || starpu_mpi_ms_worker_get_count())
		/* These won't work with pivoting: we pass a pointer in cl_args */
		return -ENODEV;

	starpu_data_handle_t *dataAp = malloc(nblocks*nblocks*sizeof(starpu_data_handle_t));

	/* monitor and partition the A matrix into blocks :
	 * one block is now determined by 2 unsigned (i,j) */
	unsigned bi, bj;
	for (bj = 0; bj < nblocks; bj++)
	for (bi = 0; bi < nblocks; bi++)
	{
		starpu_matrix_data_register(&dataAp[bi+nblocks*bj], STARPU_MAIN_RAM,
			(uintptr_t)matA[bi+nblocks*bj], size/nblocks,
			size/nblocks, size/nblocks, sizeof(TYPE));

		/* We already enforce deps by hand */
		starpu_data_set_sequential_consistency_flag(dataAp[bi+nblocks*bj], 0);
	}

	unsigned i;
	for (i = 0; i < size; i++)
		ipiv[i] = i;

	struct piv_s *piv_description = malloc(nblocks*sizeof(struct piv_s));
	unsigned block;
	for (block = 0; block < nblocks; block++)
	{
		piv_description[block].piv = ipiv;
		piv_description[block].first = block * (size / nblocks);
		piv_description[block].last = (block + 1) * (size / nblocks);
	}

	double timing=0.0;
	int ret = dw_codelet_facto_pivot(dataAp, piv_description, nblocks, get_block_with_no_striding, &timing, no_prio);

	unsigned n = starpu_matrix_get_nx(dataAp[0])*nblocks;
	double flop = (2.0f*n*n*n)/3.0f;

	PRINTF("# size\tms\tGFlop/s");
	if (bound)
		PRINTF("\tTms\tTGFlop/s");
	PRINTF("\n");
	PRINTF("%u\t%.0f\t%.1f", n, timing/1000, flop/timing/1000.0f);
	if (bound)
	{
		double min;
		starpu_bound_compute(&min, NULL, 0);
		PRINTF("\t%.0f\t%.1f", min, flop/min/1000000.0f);
	}
	PRINTF("\n");

	for (bj = 0; bj < nblocks; bj++)
	for (bi = 0; bi < nblocks; bi++)
	{
		starpu_data_unregister(dataAp[bi+nblocks*bj]);
	}
	free(dataAp);

	return ret;
}
