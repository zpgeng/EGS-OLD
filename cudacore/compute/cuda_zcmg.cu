/**
 *
 * Copyright (c) 2017-2021  King Abdullah University of Science and Technology
 * All rights reserved.
 *
 * ExaGeoStat is a software package provided by KAUST
 **/
/**
 *
 * @file cuda_zcmg.c
 *
 * CUDA Covariance Matrix Generation
 *
 * @version 1.2.0
 *
 * @author Sameh Abdulah
 * @date 2020-06-06
 *
 **/

#define CHUNKSIZE 32

#include <cublas.h>
#include <stdio.h>
#include "../include/exageostatcudacore.h"

__global__ void dcmg_powexp_kernel(double *A, int m, int n, int m0,
        int n0, double* l1_x_cuda, double* l1_y_cuda, double* l2_x_cuda, double* l2_y_cuda,
        double localtheta0, double localtheta1, double localtheta2, int distance_metric)
    //! Power-Exponential Kernel
    /*!
     * Returns covariance matrix tile using the aforementioned kernel.
     * @param[in] A: 1D array which saves the matrix entries by column.
     * @param[in] m: number of rows of tile.
     * @param[in] n: number of columns of tile.
     * @param[in] m0: Global row start point of tile.
     * @param[in] n0: Global column start point of tile.
     * @param[in] l1_x_cuda: value of x-axis of locaton vector l1.
     * @param[in] l1_y_cuda: value of y-axis of locaton vector l1.
     * @param[in] l2_x_cuda: value of x-axis of locaton vector l2.
     * @param[in] l2_y_cuda: value of y-axis of locaton vector l2.
     * @param[in] localtheta: there are three parameters to define this kernel.
     * @param[in] distance_metric: unused arguments
     * */
{
   int idx = blockIdx.x * blockDim.x + threadIdx.x;
   int idy = blockIdx.y * blockDim.y + threadIdx.y;

    if(idx >= m || idy >= n) return;

    double expr  = 0.0;
    double expr1 = 0.0;
    double sigma_square = localtheta0;
    expr = sqrt(pow((l2_x_cuda[idy] - l1_x_cuda[idx]), 2) +
            pow((l2_y_cuda[idy] - l1_y_cuda[idx]), 2));
    expr1 = pow(expr, localtheta2);
    if(expr == 0){
        A[idx + idy * m] = sigma_square /*+ 1e-4*/;
    }
    else{
        A[idx + idy * m] = sigma_square *  exp(-(expr1/localtheta1)); // power-exp kernel
    }
    

}

void dcmg_powexp( double *A, int m, int n, int m0,
        int n0, double* l1_x_cuda, double* l1_y_cuda, double* l2_x_cuda, double* l2_y_cuda,
        double *localtheta, int distance_metric, cudaStream_t stream){

    int nBlockx= (m+CHUNKSIZE-1)/CHUNKSIZE;
    int nBlocky= (n+CHUNKSIZE-1)/CHUNKSIZE;
    dim3 dimBlock(CHUNKSIZE,CHUNKSIZE);
    dim3 dimGrid(nBlockx,nBlocky);

    dcmg_powexp_kernel<<<dimGrid, dimBlock, 0, stream>>>(A, m, n, m0, n0, l1_x_cuda, l1_y_cuda, l2_x_cuda, l2_y_cuda, localtheta[0],localtheta[1],localtheta[2], distance_metric);

    cudaStreamSynchronize(stream);

}


// TO-DO: Matern kernel implementation
// __global__ void dcmg_matern_kernel(double *A, int m, int n, int m0,
//         int n0, double* l1_x_cuda, double* l1_y_cuda, double* l2_x_cuda, double* l2_y_cuda,
//         double localtheta0, double localtheta1, double localtheta2, int distance_metric)
//     //! Matern Kernel
//     /*!
//      * Returns covariance matrix tile using the aforementioned kernel.
//      * @param[in] A: 1D array which saves the matrix entries by column.
//      * @param[in] m: number of rows of tile.
//      * @param[in] n: number of columns of tile.
//      * @param[in] m0: Global row start point of tile.
//      * @param[in] n0: Global column start point of tile.
//      * @param[in] l1_x_cuda: value of x-axis of locaton vector l1.
//      * @param[in] l1_y_cuda: value of y-axis of locaton vector l1.
//      * @param[in] l2_x_cuda: value of x-axis of locaton vector l2.
//      * @param[in] l2_y_cuda: value of y-axis of locaton vector l2.
//      * @param[in] localtheta: there are three parameters to define this kernel.
//      * @param[in] distance_metric: unused arguments
//      * */
// {
//    int idx = blockIdx.x * blockDim.x + threadIdx.x;
//    int idy = blockIdx.y * blockDim.y + threadIdx.y;

//     if(idx >= m || idy >= n) return;

//     double expr  = 0.0;
//     double expr1 = 0.0;
//     double sigma_square = localtheta0;
//     expr = sqrt(pow((l2_x_cuda[idy] - l1_x_cuda[idx]), 2) +
//             pow((l2_y_cuda[idy] - l1_y_cuda[idx]), 2));

//     expr1 = pow(expr, localtheta2);
//     if(expr == 0){
//         A[idx + idy * m] = sigma_square /*+ 1e-4*/;
//     }
//     else{
//         A[idx + idy * m] = sigma_square *  exp(-(expr1/localtheta1)); // power-exp kernel
//     }
    

// }

// void dcmg_matern( double *A, int m, int n, int m0,
//         int n0, double* l1_x_cuda, double* l1_y_cuda, double* l2_x_cuda, double* l2_y_cuda,
//         double *localtheta, int distance_metric, cudaStream_t stream){

//     int nBlockx= (m+CHUNKSIZE-1)/CHUNKSIZE;
//     int nBlocky= (n+CHUNKSIZE-1)/CHUNKSIZE;
//     dim3 dimBlock(CHUNKSIZE,CHUNKSIZE);
//     dim3 dimGrid(nBlockx,nBlocky);

//     dcmg_matern_kernel<<<dimGrid, dimBlock, 0, stream>>>(A, m, n, m0, n0, l1_x_cuda, l1_y_cuda, l2_x_cuda, l2_y_cuda, localtheta[0],localtheta[1],localtheta[2], distance_metric);

//     cudaStreamSynchronize(stream);

// }
