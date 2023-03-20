/**
 *
 * @file cudablas_c.h
 *
 * @copyright 2009-2014 The University of Tennessee and The University of
 *                      Tennessee Research Foundation. All rights reserved.
 * @copyright 2012-2016 Bordeaux INP, CNRS (LaBRI UMR 5800), Inria,
 *                      Univ. Bordeaux. All rights reserved.
 *
 ***
 *
 * @brief Chameleon GPU MORSE_Complex32_t kernels header
 *
 * @version 1.0.0
 * @author Florent Pruvost
 * @date 2015-09-16
 * @generated c Tue Mar  7 11:20:04 2023
 *
 */
#ifndef _MORSE_CUDA_CBLAS_H_
#define _MORSE_CUDA_CBLAS_H_

/**
 *  Declarations of cuda kernels - alphabetical order
 */
int CUDA_cgeadd( MORSE_enum trans, int m, int n, const cuFloatComplex *alpha, const cuFloatComplex *A, int lda, const cuFloatComplex *beta, cuFloatComplex *B, int ldb, CUBLAS_STREAM_PARAM );
int CUDA_cgemerge( MORSE_enum side, MORSE_enum diag, int M, int N, cuFloatComplex *A, int LDA, cuFloatComplex *B, int LDB, CUBLAS_STREAM_PARAM );
int CUDA_cgemm(  MORSE_enum transa, MORSE_enum transb, int m, int n, int k, cuFloatComplex *alpha, const cuFloatComplex *A, int lda, const cuFloatComplex *B, int ldb, cuFloatComplex *beta, cuFloatComplex *C, int ldc, CUBLAS_STREAM_PARAM );
int CUDA_chemm(  MORSE_enum side, MORSE_enum uplo, int m, int n, cuFloatComplex *alpha, const cuFloatComplex *A, int lda, const cuFloatComplex *B, int ldb, cuFloatComplex *beta, cuFloatComplex *C, int ldc, CUBLAS_STREAM_PARAM );
int CUDA_cher2k( MORSE_enum uplo, MORSE_enum trans, int n, int k, cuFloatComplex *alpha, const cuFloatComplex *A, int lda, const cuFloatComplex *B, int ldb, float *beta, cuFloatComplex *C, int ldc, CUBLAS_STREAM_PARAM );
int CUDA_cherfb( MORSE_enum uplo, int n, int k, int ib, int nb, const cuFloatComplex *A, int lda, const cuFloatComplex *T, int ldt, cuFloatComplex *C, int ldc, cuFloatComplex *WORK, int ldwork, CUBLAS_STREAM_PARAM );
int CUDA_cherk(  MORSE_enum uplo, MORSE_enum trans, int n, int k, float *alpha, const cuFloatComplex *A, int lda, float *beta, cuFloatComplex *B, int ldb, CUBLAS_STREAM_PARAM );
int CUDA_clarfb(MORSE_enum side, MORSE_enum trans, MORSE_enum direct, MORSE_enum storev, int M, int N, int K, const cuFloatComplex *V, int LDV, const cuFloatComplex *T, int LDT, cuFloatComplex *C, int LDC, cuFloatComplex *WORK, int LDWORK, CUBLAS_STREAM_PARAM );
int CUDA_cparfb(MORSE_enum side, MORSE_enum trans, MORSE_enum direct, MORSE_enum storev, int M1, int N1, int M2, int N2, int K, int L, cuFloatComplex *A1, int LDA1, cuFloatComplex *A2, int LDA2, const cuFloatComplex *V, int LDV, const cuFloatComplex *T, int LDT, cuFloatComplex *WORK, int LDWORK, cuFloatComplex *WORKC, int LDWORKC, CUBLAS_STREAM_PARAM );
int CUDA_csymm(  MORSE_enum side, MORSE_enum uplo, int m, int n, cuFloatComplex *alpha, const cuFloatComplex *A, int lda, const cuFloatComplex *B, int ldb, cuFloatComplex *beta, cuFloatComplex *C, int ldc, CUBLAS_STREAM_PARAM );
int CUDA_csyr2k( MORSE_enum uplo, MORSE_enum trans, int n, int k, cuFloatComplex *alpha, const cuFloatComplex *A, int lda, const cuFloatComplex *B, int ldb, cuFloatComplex *beta, cuFloatComplex *C, int ldc, CUBLAS_STREAM_PARAM );
int CUDA_csyrk(  MORSE_enum uplo, MORSE_enum trans, int n, int k, cuFloatComplex *alpha, const cuFloatComplex *A, int lda, cuFloatComplex *beta, cuFloatComplex *C, int ldc, CUBLAS_STREAM_PARAM );
int CUDA_ctpmqrt( MORSE_enum side, MORSE_enum trans, int M, int N, int K, int L, int IB, const cuFloatComplex *V, int LDV, const cuFloatComplex *T, int LDT, cuFloatComplex *A, int LDA, cuFloatComplex *B, int LDB, cuFloatComplex *WORK, CUBLAS_STREAM_PARAM );
int CUDA_ctrmm(  MORSE_enum side, MORSE_enum uplo, MORSE_enum transa, MORSE_enum diag, int m, int n, cuFloatComplex *alpha, const cuFloatComplex *A, int lda, cuFloatComplex *B, int ldb, CUBLAS_STREAM_PARAM );
int CUDA_ctrsm(  MORSE_enum side, MORSE_enum uplo, MORSE_enum transa, MORSE_enum diag, int m, int n, cuFloatComplex *alpha, const cuFloatComplex *A, int lda, cuFloatComplex *B, int ldb, CUBLAS_STREAM_PARAM );
int CUDA_ctsmlq( MORSE_enum side, MORSE_enum trans, int M1, int N1, int M2, int N2, int K, int IB, cuFloatComplex *A1, int LDA1, cuFloatComplex *A2, int LDA2, const cuFloatComplex *V, int LDV, const cuFloatComplex *T, int LDT, cuFloatComplex *WORK, int LDWORK, cuFloatComplex *WORKC, int LDWORKC, CUBLAS_STREAM_PARAM );
int CUDA_ctsmqr( MORSE_enum side, MORSE_enum trans, int M1, int N1, int M2, int N2, int K, int IB, cuFloatComplex *A1, int LDA1, cuFloatComplex *A2, int LDA2, const cuFloatComplex *V, int LDV, const cuFloatComplex *T, int LDT, cuFloatComplex *WORK, int LDWORK, cuFloatComplex *WORKC, int LDWORKC, CUBLAS_STREAM_PARAM );
int CUDA_cttmqr( MORSE_enum side, MORSE_enum trans, int M1, int N1, int M2, int N2, int K, int IB, cuFloatComplex *A1, int LDA1, cuFloatComplex *A2, int LDA2, const cuFloatComplex *V, int LDV, const cuFloatComplex *T, int LDT, cuFloatComplex *WORK, int LDWORK, cuFloatComplex *WORKC, int LDWORKC, CUBLAS_STREAM_PARAM );
int CUDA_cunmlqt(MORSE_enum side, MORSE_enum trans, int M, int N, int K, int IB, const cuFloatComplex *A,    int LDA, const cuFloatComplex *T,    int LDT, cuFloatComplex *C,    int LDC, cuFloatComplex *WORK, int LDWORK, CUBLAS_STREAM_PARAM );
int CUDA_cunmqrt(MORSE_enum side, MORSE_enum trans, int M, int N, int K, int IB, const cuFloatComplex *A,    int LDA, const cuFloatComplex *T,    int LDT, cuFloatComplex *C,    int LDC, cuFloatComplex *WORK, int LDWORK, CUBLAS_STREAM_PARAM );

#endif
