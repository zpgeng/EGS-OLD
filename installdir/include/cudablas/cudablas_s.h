/**
 *
 * @file cudablas_s.h
 *
 * @copyright 2009-2014 The University of Tennessee and The University of
 *                      Tennessee Research Foundation. All rights reserved.
 * @copyright 2012-2016 Bordeaux INP, CNRS (LaBRI UMR 5800), Inria,
 *                      Univ. Bordeaux. All rights reserved.
 *
 ***
 *
 * @brief Chameleon GPU float kernels header
 *
 * @version 1.0.0
 * @author Florent Pruvost
 * @date 2015-09-16
 * @generated s Tue Mar  7 11:20:05 2023
 *
 */
#ifndef _MORSE_CUDA_SBLAS_H_
#define _MORSE_CUDA_SBLAS_H_

/**
 *  Declarations of cuda kernels - alphabetical order
 */
int CUDA_sgeadd( MORSE_enum trans, int m, int n, const float *alpha, const float *A, int lda, const float *beta, float *B, int ldb, CUBLAS_STREAM_PARAM );
int CUDA_sgemerge( MORSE_enum side, MORSE_enum diag, int M, int N, float *A, int LDA, float *B, int LDB, CUBLAS_STREAM_PARAM );
int CUDA_sgemm(  MORSE_enum transa, MORSE_enum transb, int m, int n, int k, float *alpha, const float *A, int lda, const float *B, int ldb, float *beta, float *C, int ldc, CUBLAS_STREAM_PARAM );
int CUDA_ssymm(  MORSE_enum side, MORSE_enum uplo, int m, int n, float *alpha, const float *A, int lda, const float *B, int ldb, float *beta, float *C, int ldc, CUBLAS_STREAM_PARAM );
int CUDA_ssyr2k( MORSE_enum uplo, MORSE_enum trans, int n, int k, float *alpha, const float *A, int lda, const float *B, int ldb, float *beta, float *C, int ldc, CUBLAS_STREAM_PARAM );
int CUDA_ssyrfb( MORSE_enum uplo, int n, int k, int ib, int nb, const float *A, int lda, const float *T, int ldt, float *C, int ldc, float *WORK, int ldwork, CUBLAS_STREAM_PARAM );
int CUDA_ssyrk(  MORSE_enum uplo, MORSE_enum trans, int n, int k, float *alpha, const float *A, int lda, float *beta, float *B, int ldb, CUBLAS_STREAM_PARAM );
int CUDA_slarfb(MORSE_enum side, MORSE_enum trans, MORSE_enum direct, MORSE_enum storev, int M, int N, int K, const float *V, int LDV, const float *T, int LDT, float *C, int LDC, float *WORK, int LDWORK, CUBLAS_STREAM_PARAM );
int CUDA_sparfb(MORSE_enum side, MORSE_enum trans, MORSE_enum direct, MORSE_enum storev, int M1, int N1, int M2, int N2, int K, int L, float *A1, int LDA1, float *A2, int LDA2, const float *V, int LDV, const float *T, int LDT, float *WORK, int LDWORK, float *WORKC, int LDWORKC, CUBLAS_STREAM_PARAM );
int CUDA_ssymm(  MORSE_enum side, MORSE_enum uplo, int m, int n, float *alpha, const float *A, int lda, const float *B, int ldb, float *beta, float *C, int ldc, CUBLAS_STREAM_PARAM );
int CUDA_ssyr2k( MORSE_enum uplo, MORSE_enum trans, int n, int k, float *alpha, const float *A, int lda, const float *B, int ldb, float *beta, float *C, int ldc, CUBLAS_STREAM_PARAM );
int CUDA_ssyrk(  MORSE_enum uplo, MORSE_enum trans, int n, int k, float *alpha, const float *A, int lda, float *beta, float *C, int ldc, CUBLAS_STREAM_PARAM );
int CUDA_stpmqrt( MORSE_enum side, MORSE_enum trans, int M, int N, int K, int L, int IB, const float *V, int LDV, const float *T, int LDT, float *A, int LDA, float *B, int LDB, float *WORK, CUBLAS_STREAM_PARAM );
int CUDA_strmm(  MORSE_enum side, MORSE_enum uplo, MORSE_enum transa, MORSE_enum diag, int m, int n, float *alpha, const float *A, int lda, float *B, int ldb, CUBLAS_STREAM_PARAM );
int CUDA_strsm(  MORSE_enum side, MORSE_enum uplo, MORSE_enum transa, MORSE_enum diag, int m, int n, float *alpha, const float *A, int lda, float *B, int ldb, CUBLAS_STREAM_PARAM );
int CUDA_stsmlq( MORSE_enum side, MORSE_enum trans, int M1, int N1, int M2, int N2, int K, int IB, float *A1, int LDA1, float *A2, int LDA2, const float *V, int LDV, const float *T, int LDT, float *WORK, int LDWORK, float *WORKC, int LDWORKC, CUBLAS_STREAM_PARAM );
int CUDA_stsmqr( MORSE_enum side, MORSE_enum trans, int M1, int N1, int M2, int N2, int K, int IB, float *A1, int LDA1, float *A2, int LDA2, const float *V, int LDV, const float *T, int LDT, float *WORK, int LDWORK, float *WORKC, int LDWORKC, CUBLAS_STREAM_PARAM );
int CUDA_sttmqr( MORSE_enum side, MORSE_enum trans, int M1, int N1, int M2, int N2, int K, int IB, float *A1, int LDA1, float *A2, int LDA2, const float *V, int LDV, const float *T, int LDT, float *WORK, int LDWORK, float *WORKC, int LDWORKC, CUBLAS_STREAM_PARAM );
int CUDA_sormlqt(MORSE_enum side, MORSE_enum trans, int M, int N, int K, int IB, const float *A,    int LDA, const float *T,    int LDT, float *C,    int LDC, float *WORK, int LDWORK, CUBLAS_STREAM_PARAM );
int CUDA_sormqrt(MORSE_enum side, MORSE_enum trans, int M, int N, int K, int IB, const float *A,    int LDA, const float *T,    int LDT, float *C,    int LDC, float *WORK, int LDWORK, CUBLAS_STREAM_PARAM );

#endif
