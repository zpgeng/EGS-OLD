/**
 *
 * @file cudablas_d.h
 *
 * @copyright 2009-2014 The University of Tennessee and The University of
 *                      Tennessee Research Foundation. All rights reserved.
 * @copyright 2012-2016 Bordeaux INP, CNRS (LaBRI UMR 5800), Inria,
 *                      Univ. Bordeaux. All rights reserved.
 *
 ***
 *
 * @brief Chameleon GPU double kernels header
 *
 * @version 1.0.0
 * @author Florent Pruvost
 * @date 2015-09-16
 * @generated d Tue Mar  7 11:20:05 2023
 *
 */
#ifndef _MORSE_CUDA_DBLAS_H_
#define _MORSE_CUDA_DBLAS_H_

/**
 *  Declarations of cuda kernels - alphabetical order
 */
int CUDA_dgeadd( MORSE_enum trans, int m, int n, const double *alpha, const double *A, int lda, const double *beta, double *B, int ldb, CUBLAS_STREAM_PARAM );
int CUDA_dgemerge( MORSE_enum side, MORSE_enum diag, int M, int N, double *A, int LDA, double *B, int LDB, CUBLAS_STREAM_PARAM );
int CUDA_dgemm(  MORSE_enum transa, MORSE_enum transb, int m, int n, int k, double *alpha, const double *A, int lda, const double *B, int ldb, double *beta, double *C, int ldc, CUBLAS_STREAM_PARAM );
int CUDA_dsymm(  MORSE_enum side, MORSE_enum uplo, int m, int n, double *alpha, const double *A, int lda, const double *B, int ldb, double *beta, double *C, int ldc, CUBLAS_STREAM_PARAM );
int CUDA_dsyr2k( MORSE_enum uplo, MORSE_enum trans, int n, int k, double *alpha, const double *A, int lda, const double *B, int ldb, double *beta, double *C, int ldc, CUBLAS_STREAM_PARAM );
int CUDA_dsyrfb( MORSE_enum uplo, int n, int k, int ib, int nb, const double *A, int lda, const double *T, int ldt, double *C, int ldc, double *WORK, int ldwork, CUBLAS_STREAM_PARAM );
int CUDA_dsyrk(  MORSE_enum uplo, MORSE_enum trans, int n, int k, double *alpha, const double *A, int lda, double *beta, double *B, int ldb, CUBLAS_STREAM_PARAM );
int CUDA_dlarfb(MORSE_enum side, MORSE_enum trans, MORSE_enum direct, MORSE_enum storev, int M, int N, int K, const double *V, int LDV, const double *T, int LDT, double *C, int LDC, double *WORK, int LDWORK, CUBLAS_STREAM_PARAM );
int CUDA_dparfb(MORSE_enum side, MORSE_enum trans, MORSE_enum direct, MORSE_enum storev, int M1, int N1, int M2, int N2, int K, int L, double *A1, int LDA1, double *A2, int LDA2, const double *V, int LDV, const double *T, int LDT, double *WORK, int LDWORK, double *WORKC, int LDWORKC, CUBLAS_STREAM_PARAM );
int CUDA_dsymm(  MORSE_enum side, MORSE_enum uplo, int m, int n, double *alpha, const double *A, int lda, const double *B, int ldb, double *beta, double *C, int ldc, CUBLAS_STREAM_PARAM );
int CUDA_dsyr2k( MORSE_enum uplo, MORSE_enum trans, int n, int k, double *alpha, const double *A, int lda, const double *B, int ldb, double *beta, double *C, int ldc, CUBLAS_STREAM_PARAM );
int CUDA_dsyrk(  MORSE_enum uplo, MORSE_enum trans, int n, int k, double *alpha, const double *A, int lda, double *beta, double *C, int ldc, CUBLAS_STREAM_PARAM );
int CUDA_dtpmqrt( MORSE_enum side, MORSE_enum trans, int M, int N, int K, int L, int IB, const double *V, int LDV, const double *T, int LDT, double *A, int LDA, double *B, int LDB, double *WORK, CUBLAS_STREAM_PARAM );
int CUDA_dtrmm(  MORSE_enum side, MORSE_enum uplo, MORSE_enum transa, MORSE_enum diag, int m, int n, double *alpha, const double *A, int lda, double *B, int ldb, CUBLAS_STREAM_PARAM );
int CUDA_dtrsm(  MORSE_enum side, MORSE_enum uplo, MORSE_enum transa, MORSE_enum diag, int m, int n, double *alpha, const double *A, int lda, double *B, int ldb, CUBLAS_STREAM_PARAM );
int CUDA_dtsmlq( MORSE_enum side, MORSE_enum trans, int M1, int N1, int M2, int N2, int K, int IB, double *A1, int LDA1, double *A2, int LDA2, const double *V, int LDV, const double *T, int LDT, double *WORK, int LDWORK, double *WORKC, int LDWORKC, CUBLAS_STREAM_PARAM );
int CUDA_dtsmqr( MORSE_enum side, MORSE_enum trans, int M1, int N1, int M2, int N2, int K, int IB, double *A1, int LDA1, double *A2, int LDA2, const double *V, int LDV, const double *T, int LDT, double *WORK, int LDWORK, double *WORKC, int LDWORKC, CUBLAS_STREAM_PARAM );
int CUDA_dttmqr( MORSE_enum side, MORSE_enum trans, int M1, int N1, int M2, int N2, int K, int IB, double *A1, int LDA1, double *A2, int LDA2, const double *V, int LDV, const double *T, int LDT, double *WORK, int LDWORK, double *WORKC, int LDWORKC, CUBLAS_STREAM_PARAM );
int CUDA_dormlqt(MORSE_enum side, MORSE_enum trans, int M, int N, int K, int IB, const double *A,    int LDA, const double *T,    int LDT, double *C,    int LDC, double *WORK, int LDWORK, CUBLAS_STREAM_PARAM );
int CUDA_dormqrt(MORSE_enum side, MORSE_enum trans, int M, int N, int K, int IB, const double *A,    int LDA, const double *T,    int LDT, double *C,    int LDC, double *WORK, int LDWORK, CUBLAS_STREAM_PARAM );

#endif
