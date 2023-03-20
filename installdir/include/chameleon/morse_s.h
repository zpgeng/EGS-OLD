/**
 *
 * @file morse_s.h
 *
 * @copyright 2009-2014 The University of Tennessee and The University of
 *                      Tennessee Research Foundation. All rights reserved.
 * @copyright 2012-2014 Bordeaux INP, CNRS (LaBRI UMR 5800), Inria,
 *                      Univ. Bordeaux. All rights reserved.
 *
 ***
 *
 * @brief Chameleon MORSE_complex64_t wrappers
 *
 * @version 1.0.0
 * @comment This file has been automatically generated
 *          from Plasma 2.5.0 for MORSE 1.0.0
 * @author Jakub Kurzak
 * @author Hatem Ltaief
 * @author Azzam Haidar
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2010-11-15
 * @generated s Tue Mar  7 11:20:05 2023
 *
 */
#ifndef _MORSE_S_H_
#define _MORSE_S_H_

BEGIN_C_DECLS

/**
 *  Declarations of math functions (LAPACK layout) - alphabetical order
 */
int MORSE_sgeadd(MORSE_enum trans, int M, int N, float alpha, float *A, int LDA, float beta, float *B, int LDB);
//int MORSE_sgebrd(int M, int N, float *A, int LDA, float *D, float *E, MORSE_desc_t *descT);
//int MORSE_sgecon(MORSE_enum norm, int N, float *A, int LDA, float anorm, float *rcond);
//int MORSE_spocon(MORSE_enum uplo, int N, float *A, int LDA, float anorm, float *rcond);
int MORSE_sgelqf(int M, int N, float *A, int LDA, MORSE_desc_t *descT);
int MORSE_sgelqs(int M, int N, int NRHS, float *A, int LDA, MORSE_desc_t *descT, float *B, int LDB);
int MORSE_sgels(MORSE_enum trans, int M, int N, int NRHS, float *A, int LDA, MORSE_desc_t *descT, float *B, int LDB);
int MORSE_sgemm(MORSE_enum transA, MORSE_enum transB, int M, int N, int K, float alpha, float *A, int LDA, float *B, int LDB, float beta, float *C, int LDC);
int MORSE_sgeqrf(int M, int N, float *A, int LDA, MORSE_desc_t *descT);
int MORSE_sgeqrs(int M, int N, int NRHS, float *A, int LDA, MORSE_desc_t *descT, float *B, int LDB);
//int MORSE_sgesv(int N, int NRHS, float *A, int LDA, int *IPIV, float *B, int LDB);
int MORSE_sgesv_incpiv(int N, int NRHS, float *A, int LDA, MORSE_desc_t *descL, int *IPIV, float *B, int LDB);
int MORSE_sgesv_nopiv(int N, int NRHS, float *A, int LDA, float *B, int LDB);
int MORSE_sgesvd(MORSE_enum jobu, MORSE_enum jobvt, int M, int N, float *A, int LDA, float *S, MORSE_desc_t *descT, float *U, int LDU, float *VT, int LDVT);
//int MORSE_sgetrf(int M, int N, float *A, int LDA, int *IPIV);
int MORSE_sgetrf_incpiv(int M, int N, float *A, int LDA, MORSE_desc_t *descL, int *IPIV);
int MORSE_sgetrf_nopiv(int M, int N, float *A, int LDA);
//int MORSE_sgetri(int N, float *A, int LDA, int *IPIV);
//int MORSE_sgetrs(MORSE_enum trans, int N, int NRHS, float *A, int LDA, int *IPIV, float *B, int LDB);
int MORSE_sgetrs_incpiv(MORSE_enum trans, int N, int NRHS, float *A, int LDA, MORSE_desc_t *descL, int *IPIV, float *B, int LDB);
int MORSE_sgetrs_nopiv(MORSE_enum trans, int N, int NRHS, float *A, int LDA, float *B, int LDB);
int MORSE_ssymm(MORSE_enum side, MORSE_enum uplo, int M, int N, float alpha, float *A, int LDA, float *B, int LDB, float beta, float *C, int LDC);
int MORSE_ssyrk(MORSE_enum uplo, MORSE_enum trans, int N, int K, float alpha, float *A, int LDA, float beta, float *C, int LDC);
int MORSE_ssyr2k(MORSE_enum uplo, MORSE_enum trans, int N, int K, float alpha, float *A, int LDA, float *B, int LDB, float beta, float *C, int LDC);
//int MORSE_ssyev(MORSE_enum jobz, MORSE_enum uplo, int N, float *A, int LDA, float *W, MORSE_desc_t *descT, float *Q, int LDQ);
int MORSE_ssyevd(MORSE_enum jobz, MORSE_enum uplo, int N, float *A, int LDA, float *W, MORSE_desc_t *descT);
//int MORSE_shegv(MORSE_enum itype, MORSE_enum jobz, MORSE_enum uplo, int N, float *A, int LDA, float *B, int LDB, float *W, MORSE_desc_t *descT, float *Q, int LDQ);
//int MORSE_ssygvd(MORSE_enum itype, MORSE_enum jobz, MORSE_enum uplo, int N, float *A, int LDA, float *B, int LDB, float *W, MORSE_desc_t *descT, float *Q, int LDQ);
//int MORSE_ssygst(MORSE_enum itype, MORSE_enum uplo, int N, float *A, int LDA, float *B, int LDB);
int MORSE_ssytrd(MORSE_enum jobz, MORSE_enum uplo, int N, float *A, int LDA, float *D, float *E, MORSE_desc_t *descT, float *Q, int LDQ);
int MORSE_slacpy(MORSE_enum uplo, int M, int N, float *A, int LDA, float *B, int LDB);
float MORSE_slange(MORSE_enum norm, int M, int N, float *A, int LDA);
float MORSE_slansy(MORSE_enum norm, MORSE_enum uplo, int N, float *A, int LDA);
float MORSE_slansy(MORSE_enum norm, MORSE_enum uplo, int N, float *A, int LDA);
float MORSE_slantr(MORSE_enum norm, MORSE_enum uplo, MORSE_enum diag, int M, int N, float *A, int LDA);
int MORSE_slascal(MORSE_enum uplo, int M, int N, float alpha, float *A, int LDA);
int MORSE_slaset(MORSE_enum uplo, int M, int N, float alpha, float beta, float *A, int LDA);
//int MORSE_slaswp(int N, float *A, int LDA, int K1, int K2, int *IPIV, int INCX);
//int MORSE_slaswpc(int N, float *A, int LDA, int K1, int K2, int *IPIV, int INCX);
int MORSE_slauum(MORSE_enum uplo, int N, float *A, int LDA);
int MORSE_splgsy( float bump, MORSE_enum uplo, int N, float *A, int LDA, unsigned long long int seed );
int MORSE_splgsy( float bump, MORSE_enum uplo, int N, float *A, int LDA, unsigned long long int seed );
int MORSE_splrnt( int M, int N, float *A, int LDA, unsigned long long int seed );
int MORSE_sposv(MORSE_enum uplo, int N, int NRHS, float *A, int LDA, float *B, int LDB);
int MORSE_spotrf(MORSE_enum uplo, int N, float *A, int LDA);
int MORSE_ssytrf(MORSE_enum uplo, int N, float *A, int LDA);
int MORSE_spotri(MORSE_enum uplo, int N, float *A, int LDA);
int MORSE_spotrimm(MORSE_enum uplo, int N, float *A, int LDA, float *B, int LDB, float *C, int LDC);
int MORSE_spotrs(MORSE_enum uplo, int N, int NRHS, float *A, int LDA, float *B, int LDB);
int MORSE_ssymm(MORSE_enum side, MORSE_enum uplo, int M, int N, float alpha, float *A, int LDA, float *B, int LDB, float beta, float *C, int LDC);
int MORSE_ssyrk(MORSE_enum uplo, MORSE_enum trans, int N, int K, float alpha, float *A, int LDA, float beta, float *C, int LDC);
int MORSE_ssyr2k(MORSE_enum uplo, MORSE_enum trans, int N, int K, float alpha, float *A, int LDA, float *B, int LDB, float beta, float *C, int LDC);
int MORSE_ssysv(MORSE_enum uplo, int N, int NRHS, float *A, int LDA, float *B, int LDB);
int MORSE_ssytrs(MORSE_enum uplo, int N, int NRHS, float *A, int LDA, float *B, int LDB);
int MORSE_stpgqrt( int M, int N, int K, int L, float *V1, int LDV1, MORSE_desc_t *descT1, float *V2, int LDV2, MORSE_desc_t *descT2, float *Q1, int LDQ1, float *Q2, int LDQ2 );
int MORSE_stpqrt( int M, int N, int L, float *A, int LDA, float *B, int LDB, MORSE_desc_t *descT );
int MORSE_stradd(MORSE_enum uplo, MORSE_enum trans, int M, int N, float alpha, float *A, int LDA, float beta, float *B, int LDB);
int MORSE_strmm(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, int N, int NRHS, float alpha, float *A, int LDA, float *B, int LDB);
int MORSE_strsm(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, int N, int NRHS, float alpha, float *A, int LDA, float *B, int LDB);
int MORSE_strsmpl(int N, int NRHS, float *A, int LDA, MORSE_desc_t *descL, int *IPIV, float *B, int LDB);
int MORSE_strsmrv(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, int N, int NRHS, float alpha, float *A, int LDA, float *B, int LDB);
int MORSE_strtri(MORSE_enum uplo, MORSE_enum diag, int N, float *A, int LDA);
int MORSE_sorglq(int M, int N, int K, float *A, int LDA, MORSE_desc_t *descT, float *B, int LDB);
int MORSE_sorgqr(int M, int N, int K, float *A, int LDA, MORSE_desc_t *descT, float *B, int LDB);
int MORSE_sormlq(MORSE_enum side, MORSE_enum trans, int M, int N, int K, float *A, int LDA, MORSE_desc_t *descT, float *B, int LDB);
int MORSE_sormqr(MORSE_enum side, MORSE_enum trans, int M, int N, int K, float *A, int LDA, MORSE_desc_t *descT, float *B, int LDB);

//int MORSE_sgecfi(int m, int n, float *A, MORSE_enum fin, int imb, int inb, MORSE_enum fout, int omb, int onb);
//int MORSE_sgetmi(int m, int n, float *A, MORSE_enum fin, int mb,  int nb);

/**
 *  Declarations of math functions (tile layout) - alphabetical order
 */
int MORSE_sgeadd_Tile(MORSE_enum trans, float alpha, MORSE_desc_t *A, float beta, MORSE_desc_t *B);
//int MORSE_sgebrd_Tile(MORSE_desc_t *A, float *D, float *E, MORSE_desc_t *T);
//int MORSE_sgecon_Tile(MORSE_enum norm, MORSE_desc_t *A, float anorm, float *rcond);
//int MORSE_spocon_Tile(MORSE_enum uplo, MORSE_desc_t *A, float anorm, float *rcond);
int MORSE_sgelqf_Tile(MORSE_desc_t *A, MORSE_desc_t *T);
int MORSE_sgelqs_Tile(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);
int MORSE_sgels_Tile(MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);
int MORSE_sgemm_Tile(MORSE_enum transA, MORSE_enum transB, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C);
int MORSE_sgeqrf_Tile(MORSE_desc_t *A, MORSE_desc_t *T);
int MORSE_sgeqrs_Tile(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);
//int MORSE_sgesv_Tile(MORSE_desc_t *A, int *IPIV, MORSE_desc_t *B);
int MORSE_sgesv_incpiv_Tile(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_desc_t *B);
int MORSE_sgesv_nopiv_Tile(MORSE_desc_t *A, MORSE_desc_t *B);
int MORSE_sgesvd_Tile(MORSE_enum jobu, MORSE_enum jobvt, MORSE_desc_t *A, float *S, MORSE_desc_t *T, float *U, int LDU, float *VT, int LDVT);
//int MORSE_sgetrf_Tile(MORSE_desc_t *A, int *IPIV);
int MORSE_sgetrf_incpiv_Tile(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV);
int MORSE_sgetrf_nopiv_Tile(MORSE_desc_t *A);
//int MORSE_sgetri_Tile(MORSE_desc_t *A, int *IPIV);
//int MORSE_sgetrs_Tile(MORSE_enum trans, MORSE_desc_t *A, int *IPIV, MORSE_desc_t *B);
int MORSE_sgetrs_incpiv_Tile(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_desc_t *B);
int MORSE_sgetrs_nopiv_Tile(MORSE_desc_t *A, MORSE_desc_t *B);
int MORSE_ssymm_Tile(MORSE_enum side, MORSE_enum uplo, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C);
int MORSE_ssyrk_Tile(MORSE_enum uplo, MORSE_enum trans, float alpha, MORSE_desc_t *A, float beta, MORSE_desc_t *C);
int MORSE_ssyr2k_Tile(MORSE_enum uplo, MORSE_enum trans, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C);
//int MORSE_ssyev_Tile(MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, float *W, MORSE_desc_t *T, float *Q, int LDQ);
int MORSE_ssyevd_Tile(MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, float *W, MORSE_desc_t *T);
//int MORSE_shegv_Tile( MORSE_enum itype, MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, float *W, MORSE_desc_t *T, MORSE_desc_t *Q);
//int MORSE_ssygvd_Tile(MORSE_enum itype, MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, float *W, MORSE_desc_t *T, MORSE_desc_t *Q);
//int MORSE_ssygst_Tile(MORSE_enum itype, MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B);
int MORSE_ssytrd_Tile(MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, float *D, float *E, MORSE_desc_t *T, float *Q, int LDQ);
int MORSE_slacpy_Tile(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B);
float MORSE_slange_Tile(MORSE_enum norm, MORSE_desc_t *A);
float MORSE_slansy_Tile(MORSE_enum norm, MORSE_enum uplo, MORSE_desc_t *A);
float MORSE_slansy_Tile(MORSE_enum norm, MORSE_enum uplo, MORSE_desc_t *A);
float MORSE_slantr_Tile(MORSE_enum norm, MORSE_enum uplo, MORSE_enum diag, MORSE_desc_t *A);
int MORSE_slascal_Tile(MORSE_enum uplo, float alpha, MORSE_desc_t *A);
int MORSE_slaset_Tile(MORSE_enum uplo, float alpha, float beta, MORSE_desc_t *A);
//int MORSE_slaswp_Tile(MORSE_desc_t *A, int K1, int K2, int *IPIV, int INCX);
//int MORSE_slaswpc_Tile(MORSE_desc_t *A, int K1, int K2, int *IPIV, int INCX);
int MORSE_slauum_Tile(MORSE_enum uplo, MORSE_desc_t *A);
int MORSE_splgsy_Tile(float bump, MORSE_enum uplo, MORSE_desc_t *A, unsigned long long int seed );
int MORSE_splgsy_Tile(float bump, MORSE_enum uplo, MORSE_desc_t *A, unsigned long long int seed );
int MORSE_splrnt_Tile(MORSE_desc_t *A, unsigned long long int seed );
int MORSE_sposv_Tile(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B);
int MORSE_spotrf_Tile(MORSE_enum uplo, MORSE_desc_t *A);
int MORSE_ssytrf_Tile(MORSE_enum uplo, MORSE_desc_t *A);
int MORSE_spotri_Tile(MORSE_enum uplo, MORSE_desc_t *A);
int MORSE_spotrimm_Tile(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_desc_t *C);
int MORSE_spotrs_Tile(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B);
int MORSE_ssymm_Tile(MORSE_enum side, MORSE_enum uplo, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C);
int MORSE_ssyrk_Tile(MORSE_enum uplo, MORSE_enum trans, float alpha, MORSE_desc_t *A, float beta, MORSE_desc_t *C);
int MORSE_ssyr2k_Tile(MORSE_enum uplo, MORSE_enum trans, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C);
int MORSE_ssysv_Tile(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B);
int MORSE_ssytrs_Tile(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B);
int MORSE_stpgqrt_Tile( int L, MORSE_desc_t *V1, MORSE_desc_t *T1, MORSE_desc_t *V2, MORSE_desc_t *T2, MORSE_desc_t *Q1, MORSE_desc_t *Q2 );
int MORSE_stpqrt_Tile( int L, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_desc_t *T );
int MORSE_stradd_Tile(MORSE_enum uplo, MORSE_enum trans, float alpha, MORSE_desc_t *A, float beta, MORSE_desc_t *B);
int MORSE_strmm_Tile(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, float alpha, MORSE_desc_t *A, MORSE_desc_t *B);
int MORSE_strsm_Tile(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, float alpha, MORSE_desc_t *A, MORSE_desc_t *B);
int MORSE_strsmpl_Tile(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_desc_t *B);
int MORSE_strsmrv_Tile(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, float alpha, MORSE_desc_t *A, MORSE_desc_t *B);
int MORSE_strtri_Tile(MORSE_enum uplo, MORSE_enum diag, MORSE_desc_t *A);
int MORSE_sorglq_Tile(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);
int MORSE_sorgqr_Tile(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);
int MORSE_sormlq_Tile(MORSE_enum side, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);
int MORSE_sormqr_Tile(MORSE_enum side, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B);

/**
 *  Declarations of math functions (tile layout, asynchronous execution) - alphabetical order
 */
int MORSE_sgeadd_Tile_Async(MORSE_enum trans, float alpha, MORSE_desc_t *A, float beta, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_sgebrd_Tile_Async(MORSE_desc_t *A, float *D, float *E, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_sgecon_Tile_Async(MORSE_enum norm, MORSE_desc_t *A, float anorm, float *rcond, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_spocon_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, float anorm, float *rcond, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgelqf_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgelqs_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgels_Tile_Async(MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgemm_Tile_Async(MORSE_enum transA, MORSE_enum transB, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgeqrf_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgeqrs_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_sgesv_Tile_Async(MORSE_desc_t *A, int *IPIV, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgesv_incpiv_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgesv_nopiv_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgesvd_Tile_Async(MORSE_enum jobu, MORSE_enum jobvt, MORSE_desc_t *A, float *S, MORSE_desc_t *T, float *U, int LDU, float *VT, int LDVT, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_sgetrf_Tile_Async(MORSE_desc_t *A, int *IPIV, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgetrf_incpiv_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgetrf_nopiv_Tile_Async(MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_sgetri_Tile_Async(MORSE_desc_t *A, int *IPIV, MORSE_desc_t *W, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_sgetrs_Tile_Async(MORSE_enum trans, MORSE_desc_t *A, int *IPIV, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgetrs_incpiv_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgetrs_nopiv_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ssymm_Tile_Async(MORSE_enum side, MORSE_enum uplo, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ssyrk_Tile_Async(MORSE_enum uplo, MORSE_enum trans, float alpha, MORSE_desc_t *A, float beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ssyr2k_Tile_Async(MORSE_enum uplo, MORSE_enum trans, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_ssyev_Tile_Async(MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, float *W, MORSE_desc_t *T, float *Q, int LDQ, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ssyevd_Tile_Async(MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, float *W, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_shegv_Tile_Async( MORSE_enum itype, MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, float *W, MORSE_desc_t *T, MORSE_desc_t *Q, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_ssygvd_Tile_Async(MORSE_enum itype, MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, float *W, MORSE_desc_t *T, MORSE_desc_t *Q, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_ssygst_Tile_Async(MORSE_enum itype, MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ssytrd_Tile_Async(MORSE_enum jobz, MORSE_enum uplo, MORSE_desc_t *A, float *D, float *E, MORSE_desc_t *T, float *Q, int LDQ, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_slacpy_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_slange_Tile_Async(MORSE_enum norm, MORSE_desc_t *A, float *value, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_slansy_Tile_Async(MORSE_enum norm, MORSE_enum uplo, MORSE_desc_t *A, float *value, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_slansy_Tile_Async(MORSE_enum norm, MORSE_enum uplo, MORSE_desc_t *A, float *value, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_slantr_Tile_Async(MORSE_enum norm, MORSE_enum uplo, MORSE_enum diag, MORSE_desc_t *A, float *value, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_slascal_Tile_Async(MORSE_enum uplo, float alpha, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_slaset_Tile_Async(MORSE_enum uplo, float alpha, float beta, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_slaswp_Tile_Async(MORSE_desc_t *A, int K1, int K2, int *IPIV, int INCX, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_slaswpc_Tile_Async(MORSE_desc_t *A, int K1, int K2, int *IPIV, int INCX, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_slauum_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_splgsy_Tile_Async(float bump, MORSE_enum uplo, MORSE_desc_t *A, unsigned long long int seed, MORSE_sequence_t *sequence, MORSE_request_t *request );
int MORSE_splgsy_Tile_Async(float bump, MORSE_enum uplo, MORSE_desc_t *A, unsigned long long int seed, MORSE_sequence_t *sequence, MORSE_request_t *request );
int MORSE_splrnt_Tile_Async(MORSE_desc_t *A, unsigned long long int seed, MORSE_sequence_t *sequence, MORSE_request_t *request );
int MORSE_sposv_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_spotrf_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ssytrf_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_spotri_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_spotrimm_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_spotrs_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ssysv_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ssytrs_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ssymm_Tile_Async(MORSE_enum side, MORSE_enum uplo, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ssyrk_Tile_Async(MORSE_enum uplo, MORSE_enum trans, float alpha, MORSE_desc_t *A, float beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_ssyr2k_Tile_Async(MORSE_enum uplo, MORSE_enum trans, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, float beta, MORSE_desc_t *C, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_stpgqrt_Tile_Async( int L, MORSE_desc_t *V1, MORSE_desc_t *T1, MORSE_desc_t *V2, MORSE_desc_t *T2, MORSE_desc_t *Q1, MORSE_desc_t *Q2, MORSE_sequence_t *sequence, MORSE_request_t *request );
int MORSE_stpqrt_Tile_Async( int L, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_desc_t *T, MORSE_sequence_t *sequence, MORSE_request_t *request );
int MORSE_stradd_Tile_Async(MORSE_enum uplo, MORSE_enum trans, float alpha, MORSE_desc_t *A, float beta, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_strmm_Tile_Async(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_strsm_Tile_Async(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_strsmpl_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *L, int *IPIV, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_strsmrv_Tile_Async(MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag, float alpha, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_strtri_Tile_Async(MORSE_enum uplo, MORSE_enum diag, MORSE_desc_t *A, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sorglq_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sorgqr_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sormlq_Tile_Async(MORSE_enum side, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sormqr_Tile_Async(MORSE_enum side, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);

//int MORSE_sgecfi_Async(int m, int n, float *A, MORSE_enum f_in, int imb, int inb, MORSE_enum f_out, int omb, int onb, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_sgetmi_Async(int m, int n, float *A, MORSE_enum f_in, int mb,  int inb, MORSE_sequence_t *sequence, MORSE_request_t *request);

/**
 *  Declarations of libhqr dependent functions.
 */
/**
 *  Declarations of math functions (LAPACK layout) - alphabetical order
 */
int MORSE_sgels_param(const libhqr_tree_t *qrtree, MORSE_enum trans, int M, int N, int NRHS, float *A, int LDA, MORSE_desc_t *descTS, MORSE_desc_t *descTT, float *B, int LDB);
int MORSE_sgelqf_param(const libhqr_tree_t *qrtree, int M, int N, float *A, int LDA, MORSE_desc_t *descTS, MORSE_desc_t *descTT);
int MORSE_sgelqs_param(const libhqr_tree_t *qrtree, int M, int N, int NRHS, float *A, int LDA, MORSE_desc_t *descTS, MORSE_desc_t *descTT, float *B, int LDB);
int MORSE_sgeqrf_param(const libhqr_tree_t *qrtree, int M, int N, float *A, int LDA, MORSE_desc_t *descTS, MORSE_desc_t *descTT);
int MORSE_sgeqrs_param(const libhqr_tree_t *qrtree, int M, int N, int NRHS, float *A, int LDA, MORSE_desc_t *descTS, MORSE_desc_t *TT, float *B, int LDB);
int MORSE_sorglq_param(const libhqr_tree_t *qrtree, int M, int N, int K, float *A, int LDA, MORSE_desc_t *descTS, MORSE_desc_t *TT, float *B, int LDB);
int MORSE_sorgqr_param(const libhqr_tree_t *qrtree, int M, int N, int K, float *A, int LDA, MORSE_desc_t *descTS, MORSE_desc_t *descTT, float *B, int LDB);
int MORSE_sormlq_param(const libhqr_tree_t *qrtree, MORSE_enum side, MORSE_enum trans, int M, int N, int K, float *A, int LDA, MORSE_desc_t *descT, MORSE_desc_t *TT, float *B, int LDB);
int MORSE_sormlq_param(const libhqr_tree_t *qrtree, MORSE_enum side, MORSE_enum trans, int M, int N, int K, float *A, int LDA, MORSE_desc_t *descT, MORSE_desc_t *TT, float *B, int LDB);
int MORSE_sormqr_param(const libhqr_tree_t *qrtree, MORSE_enum side, MORSE_enum trans, int M, int N, int K, float *A, int LDA, MORSE_desc_t *descTS, MORSE_desc_t *TT, float *B, int LDB);
/**
 *  Declarations of math functions (tile layout) - alphabetical order
 */
int MORSE_sgels_param_Tile(const libhqr_tree_t *qrtree, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *TS, MORSE_desc_t *TT, MORSE_desc_t *B);
int MORSE_sgelqf_param_Tile(const libhqr_tree_t *qrtree, MORSE_desc_t *A, MORSE_desc_t *TS, MORSE_desc_t *TT);
int MORSE_sgelqs_param_Tile(const libhqr_tree_t *qrtree, MORSE_desc_t *A, MORSE_desc_t *TS, MORSE_desc_t *TT, MORSE_desc_t *B);
int MORSE_sgeqrf_param_Tile(const libhqr_tree_t *qrtree, MORSE_desc_t *A, MORSE_desc_t *TS, MORSE_desc_t *TT);
int MORSE_sgeqrs_param_Tile(const libhqr_tree_t *qrtree, MORSE_desc_t *A, MORSE_desc_t *TS, MORSE_desc_t *TT, MORSE_desc_t *B);
int MORSE_sorglq_param_Tile(const libhqr_tree_t *qrtree, MORSE_desc_t *A, MORSE_desc_t *TS, MORSE_desc_t *TT, MORSE_desc_t *B);
int MORSE_sorgqr_param_Tile(const libhqr_tree_t *qrtree, MORSE_desc_t *A, MORSE_desc_t *TS, MORSE_desc_t *TT, MORSE_desc_t *B);
int MORSE_sorgqr_param_Tile(const libhqr_tree_t *qrtree, MORSE_desc_t *A, MORSE_desc_t *TS, MORSE_desc_t *TT, MORSE_desc_t *B);
int MORSE_sormlq_param_Tile(const libhqr_tree_t *qrtree, MORSE_enum side, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *TS, MORSE_desc_t *TT, MORSE_desc_t *B);
int MORSE_sormqr_param_Tile(const libhqr_tree_t *qrtree, MORSE_enum side, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *TS, MORSE_desc_t *TT, MORSE_desc_t *B);
/**
 *  Declarations of math functions (tile layout, asynchronous execution) - alphabetical order
 */
int MORSE_sgels_param_Tile_Async(const libhqr_tree_t *qrtree, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *TS, MORSE_desc_t *TT, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgelqf_param_Tile_Async(const libhqr_tree_t *qrtree, MORSE_desc_t *A, MORSE_desc_t *TS, MORSE_desc_t *TT, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgelqs_param_Tile_Async(const libhqr_tree_t *qrtree, MORSE_desc_t *A, MORSE_desc_t *TS, MORSE_desc_t *TT, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgeqrf_param_Tile_Async(const libhqr_tree_t *qrtree, MORSE_desc_t *A, MORSE_desc_t *TS, MORSE_desc_t *TT, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sgeqrs_param_Tile_Async(const libhqr_tree_t *qrtree, MORSE_desc_t *A, MORSE_desc_t *TS, MORSE_desc_t *TT, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sorglq_param_Tile_Async(const libhqr_tree_t *qrtree, MORSE_desc_t *A, MORSE_desc_t *TS, MORSE_desc_t *TT, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sorgqr_param_Tile_Async(const libhqr_tree_t *qrtree, MORSE_desc_t *A, MORSE_desc_t *TS, MORSE_desc_t *TT, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sormlq_param_Tile_Async(const libhqr_tree_t *qrtree, MORSE_enum side, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *TS, MORSE_desc_t *TT, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);
int MORSE_sormqr_param_Tile_Async(const libhqr_tree_t *qrtree, MORSE_enum side, MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *TS, MORSE_desc_t *TT, MORSE_desc_t *B, MORSE_sequence_t *sequence, MORSE_request_t *request);

/**
 *  Declarations of workspace allocation functions (tile layout) - alphabetical order
 */
int MORSE_Alloc_Workspace_sgesv_incpiv(        int N, MORSE_desc_t **descL, int **IPIV, int p, int q);
int MORSE_Alloc_Workspace_sgetrf_incpiv(int M, int N, MORSE_desc_t **descL, int **IPIV, int p, int q);

int MORSE_Alloc_Workspace_sgebrd(int M, int N, MORSE_desc_t **descT, int p, int q);
int MORSE_Alloc_Workspace_sgeev( int N,        MORSE_desc_t **descT, int p, int q);
int MORSE_Alloc_Workspace_sgehrd(int N,        MORSE_desc_t **descT, int p, int q);
int MORSE_Alloc_Workspace_sgelqf(int M, int N, MORSE_desc_t **T, int p, int q);
int MORSE_Alloc_Workspace_sgels( int M, int N, MORSE_desc_t **T, int p, int q);
int MORSE_Alloc_Workspace_sgeqrf(int M, int N, MORSE_desc_t **T, int p, int q);
int MORSE_Alloc_Workspace_sgesvd(int M, int N, MORSE_desc_t **descT, int p, int q);
int MORSE_Alloc_Workspace_ssyev( int M, int N, MORSE_desc_t **descT, int p, int q);
int MORSE_Alloc_Workspace_ssyevd( int M, int N, MORSE_desc_t **descT, int p, int q);
int MORSE_Alloc_Workspace_shegv( int M, int N, MORSE_desc_t **descT, int p, int q);
int MORSE_Alloc_Workspace_ssygvd( int M, int N, MORSE_desc_t **descT, int p, int q);
int MORSE_Alloc_Workspace_ssytrd(int M, int N, MORSE_desc_t **descT, int p, int q);

/**
 *  Declarations of workspace allocation functions (tile layout, asynchronous execution) - alphabetical order
 */
int MORSE_Alloc_Workspace_sgetri_Tile_Async(MORSE_desc_t *A, MORSE_desc_t *W);

/* Warning: Those functions are deprecated */
int MORSE_Alloc_Workspace_sgelqf_Tile(int M, int N, MORSE_desc_t **descT, int p, int q);
int MORSE_Alloc_Workspace_sgels_Tile( int M, int N, MORSE_desc_t **descT, int p, int q);
int MORSE_Alloc_Workspace_sgeqrf_Tile(int M, int N, MORSE_desc_t **descT, int p, int q);
int MORSE_Alloc_Workspace_sgesv_incpiv_Tile (int N, MORSE_desc_t **descL, int **IPIV, int p, int q);
int MORSE_Alloc_Workspace_sgetrf_incpiv_Tile(int N, MORSE_desc_t **descL, int **IPIV, int p, int q);

/**
 *  Auxiliary function prototypes
 */
int MORSE_sLapack_to_Tile(float *Af77, int LDA, MORSE_desc_t *A);
int MORSE_sTile_to_Lapack(MORSE_desc_t *A, float *Af77, int LDA);

/**
 *  User Builder function prototypes
 */
int MORSE_sbuild(MORSE_enum uplo, int M, int N, float *A, int LDA, void *user_data, void* user_build_callback);
int MORSE_sbuild_Tile(MORSE_enum uplo,  MORSE_desc_t *A, void *user_data, void* user_build_callback );
int MORSE_sbuild_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, void *user_data, void* user_build_callback, MORSE_sequence_t *sequence, MORSE_request_t  *request);

END_C_DECLS

#endif
