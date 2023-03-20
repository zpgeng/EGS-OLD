/* StarPU --- Runtime system for heterogeneous multicore architectures.
 *
 * Copyright (C) 2008-2021  Université de Bordeaux, CNRS (LaBRI UMR 5800), Inria
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

/*
 * These are standard BLAS kernels for the LU factorization
 */
#include "dw_factolu.h"

#ifdef STARPU_HAVE_VALGRIND_H
#include <valgrind/valgrind.h>
#endif

#ifdef STARPU_USE_CUDA
#include <cublas.h>
#include <starpu_cublas_v2.h>
static const float p1 =  1.0;
static const float m1 = -1.0;
#endif

unsigned count_11_per_worker[STARPU_NMAXWORKERS] = {0};
unsigned count_12_per_worker[STARPU_NMAXWORKERS] = {0};
unsigned count_21_per_worker[STARPU_NMAXWORKERS] = {0};
unsigned count_22_per_worker[STARPU_NMAXWORKERS] = {0};

unsigned count_total_per_worker[STARPU_NMAXWORKERS] = {0};

unsigned count_11_total = 0;
unsigned count_12_total = 0;
unsigned count_21_total = 0;
unsigned count_22_total = 0;

void display_stat_heat(void)
{
	unsigned nworkers = starpu_worker_get_count();

	FPRINTF(stderr, "STATS : \n");

	unsigned worker;
	for (worker = 0; worker < nworkers; worker++)
	{
		count_total_per_worker[worker] = count_11_per_worker[worker]
					+ count_12_per_worker[worker]
					+ count_21_per_worker[worker]
					+ count_22_per_worker[worker];

		count_11_total += count_11_per_worker[worker];
		count_12_total += count_12_per_worker[worker];
		count_21_total += count_21_per_worker[worker];
		count_22_total += count_22_per_worker[worker];
	}

	FPRINTF(stderr, "\t11 (diagonal block LU)\n");
	for (worker = 0; worker < nworkers; worker++)
	{
		if (count_total_per_worker[worker])
		{
			char name[64];
			starpu_worker_get_name(worker, name, sizeof(name));

			FPRINTF(stderr, "\t\t%s -> %u / %u (%2.2f %%)\n", name, count_11_per_worker[worker], count_11_total, (100.0*count_11_per_worker[worker])/count_11_total);
		}
	}

	FPRINTF(stderr, "\t12 (TRSM)\n");
	for (worker = 0; worker < nworkers; worker++)
	{
		if (count_total_per_worker[worker])
		{
			char name[64];
			starpu_worker_get_name(worker, name, sizeof(name));

			FPRINTF(stderr, "\t\t%s -> %u / %u (%2.2f %%)\n", name, count_12_per_worker[worker], count_12_total, (100.0*count_12_per_worker[worker])/count_12_total);
		}
	}


	FPRINTF(stderr, "\t21 (TRSM)\n");
	for (worker = 0; worker < nworkers; worker++)
	{
		if (count_total_per_worker[worker])
		{
			char name[64];
			starpu_worker_get_name(worker, name, sizeof(name));

			FPRINTF(stderr, "\t\t%s -> %u / %u (%2.2f %%)\n", name, count_21_per_worker[worker], count_21_total, (100.0*count_21_per_worker[worker])/count_21_total);
		}
	}

	FPRINTF(stderr, "\t22 (SGEMM)\n");
	for (worker = 0; worker < nworkers; worker++)
	{
		if (count_total_per_worker[worker])
		{
			char name[64];
			starpu_worker_get_name(worker, name, sizeof(name));

			FPRINTF(stderr, "\t\t%s -> %u / %u (%2.2f %%)\n", name, count_22_per_worker[worker], count_22_total, (100.0*count_22_per_worker[worker])/count_22_total);
		}
	}
}

/*
 *   U22
 */

static inline void dw_common_cpu_codelet_update_u22(void *descr[], int s, void *_args)
{
	(void)_args;
	float *left 	= (float *)STARPU_MATRIX_GET_PTR(descr[0]);
	float *right 	= (float *)STARPU_MATRIX_GET_PTR(descr[1]);
	float *center 	= (float *)STARPU_MATRIX_GET_PTR(descr[2]);

	unsigned dx = STARPU_MATRIX_GET_NX(descr[2]);
	unsigned dy = STARPU_MATRIX_GET_NY(descr[2]);
	unsigned dz = STARPU_MATRIX_GET_NY(descr[0]);

	unsigned ld12 = STARPU_MATRIX_GET_LD(descr[0]);
	unsigned ld21 = STARPU_MATRIX_GET_LD(descr[1]);
	unsigned ld22 = STARPU_MATRIX_GET_LD(descr[2]);

#ifdef STARPU_USE_CUDA
	cublasStatus status;
#endif

	switch (s)
	{
		case 0:
			STARPU_SGEMM("N", "N",	dy, dx, dz,
				-1.0f, left, ld21, right, ld12,
					     1.0f, center, ld22);
			break;

#ifdef STARPU_USE_CUDA
		case 1:
			status = cublasSgemm(starpu_cublas_get_local_handle(),
					CUBLAS_OP_N, CUBLAS_OP_N,
					dx, dy, dz, &m1, left, ld21,
					right, ld12, &p1, center, ld22);
			if (status != CUBLAS_STATUS_SUCCESS)
				STARPU_CUBLAS_REPORT_ERROR(status);

			break;
#endif
		default:
			STARPU_ABORT();
			break;
	}
}

void dw_cpu_codelet_update_u22(void *descr[], void *_args)
{
	dw_common_cpu_codelet_update_u22(descr, 0, _args);

	int id = starpu_worker_get_id_check();
	count_22_per_worker[id]++;
}

#ifdef STARPU_USE_CUDA
void dw_cublas_codelet_update_u22(void *descr[], void *_args)
{
	dw_common_cpu_codelet_update_u22(descr, 1, _args);

	int id = starpu_worker_get_id_check();
	count_22_per_worker[id]++;
}
#endif /* STARPU_USE_CUDA */

/*
 * U12
 */

static inline void dw_common_codelet_update_u12(void *descr[], int s, void *_args)
{
	(void)_args;
	float *sub11;
	float *sub12;

	sub11 = (float *)STARPU_MATRIX_GET_PTR(descr[0]);
	sub12 = (float *)STARPU_MATRIX_GET_PTR(descr[1]);

	unsigned ld11 = STARPU_MATRIX_GET_LD(descr[0]);
	unsigned ld12 = STARPU_MATRIX_GET_LD(descr[1]);

	unsigned nx12 = STARPU_MATRIX_GET_NX(descr[1]);
	unsigned ny12 = STARPU_MATRIX_GET_NY(descr[1]);

#ifdef STARPU_USE_CUDA
	cublasStatus status;
#endif

	/* solve L11 U12 = A12 (find U12) */
	switch (s)
	{
		case 0:
			STARPU_STRSM("L", "L", "N", "N",
					 nx12, ny12, 1.0f, sub11, ld11, sub12, ld12);
			break;
#ifdef STARPU_USE_CUDA
		case 1:
			status = cublasStrsm(starpu_cublas_get_local_handle(),
					CUBLAS_SIDE_LEFT, CUBLAS_FILL_MODE_LOWER, CUBLAS_OP_N, CUBLAS_DIAG_NON_UNIT,
					ny12, nx12,
					&p1, sub11, ld11, sub12, ld12);
			if (status != CUBLAS_STATUS_SUCCESS)
				STARPU_CUBLAS_REPORT_ERROR(status);

			break;
#endif
		default:
			STARPU_ABORT();
			break;
	}
}

void dw_cpu_codelet_update_u12(void *descr[], void *_args)
{
	dw_common_codelet_update_u12(descr, 0, _args);

	int id = starpu_worker_get_id_check();
	count_12_per_worker[id]++;
}

#ifdef STARPU_USE_CUDA
void dw_cublas_codelet_update_u12(void *descr[], void *_args)
{
	 dw_common_codelet_update_u12(descr, 1, _args);

	int id = starpu_worker_get_id_check();
	count_12_per_worker[id]++;
}
#endif /* STARPU_USE_CUDA */

/*
 * U21
 */

static inline void dw_common_codelet_update_u21(void *descr[], int s, void *_args)
{
	(void)_args;
	float *sub11;
	float *sub21;

	sub11 = (float *)STARPU_MATRIX_GET_PTR(descr[0]);
	sub21 = (float *)STARPU_MATRIX_GET_PTR(descr[1]);

	unsigned ld11 = STARPU_MATRIX_GET_LD(descr[0]);
	unsigned ld21 = STARPU_MATRIX_GET_LD(descr[1]);

	unsigned nx21 = STARPU_MATRIX_GET_NX(descr[1]);
	unsigned ny21 = STARPU_MATRIX_GET_NY(descr[1]);

#ifdef STARPU_USE_CUDA
	cublasStatus status;
#endif

	switch (s)
	{
		case 0:
			STARPU_STRSM("R", "U", "N", "U", nx21, ny21, 1.0f, sub11, ld11, sub21, ld21);
			break;
#ifdef STARPU_USE_CUDA
		case 1:
			status = cublasStrsm(starpu_cublas_get_local_handle(),
					CUBLAS_SIDE_RIGHT, CUBLAS_FILL_MODE_UPPER, CUBLAS_OP_N, CUBLAS_DIAG_UNIT,
					ny21, nx21, &p1, sub11, ld11, sub21, ld21);
			if (status != CUBLAS_STATUS_SUCCESS)
				STARPU_CUBLAS_REPORT_ERROR(status);

			break;
#endif
		default:
			STARPU_ABORT();
			break;
	}
}

void dw_cpu_codelet_update_u21(void *descr[], void *_args)
{
	dw_common_codelet_update_u21(descr, 0, _args);

	int id = starpu_worker_get_id_check();
	count_21_per_worker[id]++;
}

#ifdef STARPU_USE_CUDA
void dw_cublas_codelet_update_u21(void *descr[], void *_args)
{
	dw_common_codelet_update_u21(descr, 1, _args);

	int id = starpu_worker_get_id_check();
	count_21_per_worker[id]++;
}
#endif

/*
 *	U11
 */

static inline void debug_print(float *tab, unsigned ld, unsigned n)
{
	unsigned j,i;
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n; i++)
		{
			FPRINTF(stderr, "%2.2f\t", tab[(size_t)j+(size_t)i*ld]);
		}
		FPRINTF(stderr, "\n");
	}

	FPRINTF(stderr, "\n");
}

static inline void dw_common_codelet_update_u11(void *descr[], int s, void *_args)
{
	(void)_args;
	float *sub11;

	sub11 = (float *)STARPU_MATRIX_GET_PTR(descr[0]);

	unsigned long nx = STARPU_MATRIX_GET_NX(descr[0]);
	unsigned long ld = STARPU_MATRIX_GET_LD(descr[0]);

	unsigned long z;

#ifdef STARPU_USE_CUDA
	cudaStream_t stream;
	cublasHandle_t handle;
	cublasStatus_t status;
#endif

	switch (s)
	{
		case 0:
			for (z = 0; z < nx; z++)
			{
				float pivot;
				pivot = sub11[z+z*ld];

#ifdef STARPU_HAVE_VALGRIND_H
				if (RUNNING_ON_VALGRIND)
				{
					if (fpclassify(pivot) == FP_ZERO)
						/* Running in valgrind, don't care about the result */
						pivot = 1.0f;
				}
				else
#endif
					STARPU_ASSERT(fpclassify(pivot) != FP_ZERO);

				STARPU_SSCAL(nx - z - 1, (1.0f/pivot), &sub11[z+(z+1)*ld], ld);

				STARPU_SGER(nx - z - 1, nx - z - 1, -1.0f,
						&sub11[z+(z+1)*ld], ld,
						&sub11[(z+1)+z*ld], 1,
						&sub11[(z+1) + (z+1)*ld],ld);
			}
			break;
#ifdef STARPU_USE_CUDA
		case 1:
			stream = starpu_cuda_get_local_stream();
			handle = starpu_cublas_get_local_handle();
			for (z = 0; z < nx; z++)
			{
				float pivot;
				cudaMemcpyAsync(&pivot, &sub11[z+z*ld], sizeof(float), cudaMemcpyDeviceToHost, stream);
				cudaStreamSynchronize(stream);

#ifdef STARPU_HAVE_VALGRIND_H
				if (RUNNING_ON_VALGRIND)
				{
					if (fpclassify(pivot) == FP_ZERO)
						/* Running in valgrind, don't care about the result */
						pivot = 1.0f;
				}
				else
#endif
					STARPU_ASSERT(fpclassify(pivot) != FP_ZERO);

				float scal = 1.0f/pivot;

				status = cublasSscal(starpu_cublas_get_local_handle(),
						     nx - z - 1, &scal, &sub11[z+(z+1)*ld], ld);
				if (status != CUBLAS_STATUS_SUCCESS)
					STARPU_CUBLAS_REPORT_ERROR(status);

				status = cublasSger(starpu_cublas_get_local_handle(),
						    nx - z - 1, nx - z - 1, &m1,
						    &sub11[z+(z+1)*ld], ld,
						    &sub11[(z+1)+z*ld], 1,
						    &sub11[(z+1) + (z+1)*ld],ld);
				if (status != CUBLAS_STATUS_SUCCESS)
					STARPU_CUBLAS_REPORT_ERROR(status);
			}

			cudaStreamSynchronize(stream);

			break;
#endif
		default:
			STARPU_ABORT();
			break;
	}
}


void dw_cpu_codelet_update_u11(void *descr[], void *_args)
{
	dw_common_codelet_update_u11(descr, 0, _args);

	int id = starpu_worker_get_id_check();
	count_11_per_worker[id]++;
}

#ifdef STARPU_USE_CUDA
void dw_cublas_codelet_update_u11(void *descr[], void *_args)
{
	dw_common_codelet_update_u11(descr, 1, _args);

	int id = starpu_worker_get_id_check();
	count_11_per_worker[id]++;
}
#endif /* STARPU_USE_CUDA */
