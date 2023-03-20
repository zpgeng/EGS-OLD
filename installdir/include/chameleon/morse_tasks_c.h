/**
 *
 * @file morse_tasks_c.h
 *
 * @copyright 2009-2014 The University of Tennessee and The University of
 *                      Tennessee Research Foundation. All rights reserved.
 * @copyright 2012-2016 Bordeaux INP, CNRS (LaBRI UMR 5800), Inria,
 *                      Univ. Bordeaux. All rights reserved.
 *
 ***
 *
 * @brief Chameleon MORSE_Complex32_t elementary tasks header
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
 * @generated c Tue Mar  7 11:20:05 2023
 *
 */
#ifndef _MORSE_TASKS_C_H_
#define _MORSE_TASKS_C_H_


/**
 *  Declarations of QUARK wrappers (called by MORSE) - alphabetical order
 */
void MORSE_TASK_scasum(const MORSE_option_t *options,
                       MORSE_enum storev, MORSE_enum uplo, int M, int N,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_cgeadd(const MORSE_option_t *options,
                       MORSE_enum trans, int m, int n, int nb,
                       MORSE_Complex32_t alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_Complex32_t beta,  const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_clascal(const MORSE_option_t *options,
                        MORSE_enum uplo,
                        int m, int n, int nb,
                        MORSE_Complex32_t alpha,
                        const MORSE_desc_t *A, int Am, int An, int lda);
void MORSE_TASK_cbrdalg(const MORSE_option_t *options,
                        MORSE_enum uplo,
                        int N, int NB,
                        const MORSE_desc_t *A,
                        const MORSE_desc_t *C, int Cm, int Cn,
                        const MORSE_desc_t *S, int Sm, int Sn,
                        int i, int j, int m, int grsiz, int BAND,
                        int *PCOL, int *ACOL, int *MCOL);
void MORSE_TASK_cgelqt(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_cgemm(const MORSE_option_t *options,
                      MORSE_enum transA, MORSE_enum transB,
                      int m, int n, int k, int nb,
                      MORSE_Complex32_t alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                      MORSE_Complex32_t beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_cgemm2( const MORSE_option_t *options,
                        MORSE_enum transA, MORSE_enum transB,
                        int m, int n, int k, int nb,
                        MORSE_Complex32_t alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                        const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                        MORSE_Complex32_t beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_cgemm_f2(const MORSE_option_t *options,
                         MORSE_enum transA, MORSE_enum transB,
                         int m, int n, int k, int nb,
                         MORSE_Complex32_t alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                         const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                         MORSE_Complex32_t beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc,
                         const MORSE_desc_t *fake1, int fake1m, int fake1n, int szefake1, int flag1,
                         const MORSE_desc_t *fake2, int fake2m, int fake2n, int szefake2, int flag2);
void MORSE_TASK_cgemm_p2(const MORSE_option_t *options,
                         MORSE_enum transA, MORSE_enum transB,
                         int m, int n, int k, int nb,
                         MORSE_Complex32_t alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                         const MORSE_Complex32_t **B, int ldb,
                         MORSE_Complex32_t beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_cgemm_p2f1(const MORSE_option_t *options,
                           MORSE_enum transA, MORSE_enum transB,
                           int m, int n, int k, int nb,
                           MORSE_Complex32_t alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                           const MORSE_Complex32_t **B, int ldb,
                           MORSE_Complex32_t beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc,
                           const MORSE_desc_t *fake1, int fake1m, int fake1n, int szefake1, int flag1);
void MORSE_TASK_cgemm_p3(const MORSE_option_t *options,
                         MORSE_enum transA, MORSE_enum transB,
                         int m, int n, int k, int nb,
                         MORSE_Complex32_t alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                         const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                         MORSE_Complex32_t beta, MORSE_Complex32_t **C, int ldc);
void MORSE_TASK_cgeqrt(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_cgessm(const MORSE_option_t *options,
                       int m, int n, int k, int ib, int nb,
                       int *IPIV,
                       const MORSE_desc_t *L, int Lm, int Ln, int ldl,
                       const MORSE_desc_t *D, int Dm, int Dn, int ldd,
                       const MORSE_desc_t *A, int Am, int An, int lda);
void MORSE_TASK_cgessq( const MORSE_option_t *options,
                        int m, int n,
                        const MORSE_desc_t *A, int Am, int An, int lda,
                        const MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn);
void MORSE_TASK_cgetrf(const MORSE_option_t *options,
                       int m, int n, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       int *IPIV,

                       MORSE_bool check_info, int iinfo);
void MORSE_TASK_cgetrf_incpiv(const MORSE_option_t *options,
                              int m, int n, int ib, int nb,
                              const MORSE_desc_t *A, int Am, int An, int lda,
                              const MORSE_desc_t *L, int Lm, int Ln, int ldl,
                              int *IPIV,
                              MORSE_bool check_info, int iinfo);
void MORSE_TASK_cgetrf_nopiv(const MORSE_option_t *options,
                             int m, int n, int ib, int nb,
                             const MORSE_desc_t *A, int Am, int An, int lda, int iinfo);
void MORSE_TASK_cgetrf_reclap(const MORSE_option_t *options,
                              int m, int n, int nb,
                              const MORSE_desc_t *A, int Am, int An, int lda,
                              int *IPIV,

                              MORSE_bool check_info, int iinfo,
                              int nbthread);
void MORSE_TASK_cgetrf_rectil(const MORSE_option_t *options,
                              const MORSE_desc_t A, const MORSE_desc_t *Amn, int Amnm, int Amnn, int size,
                              int *IPIV,

                              MORSE_bool check_info, int iinfo,
                              int nbthread);
void MORSE_TASK_cgetrip(const MORSE_option_t *options,
                        int m, int n, const MORSE_desc_t *A, int Am, int An, int szeA);
void MORSE_TASK_cgetrip_f1(const MORSE_option_t *options,
                           int m, int n, const MORSE_desc_t *A, int Am, int An, int szeA,
                           const MORSE_desc_t *fake, int fakem, int faken, int szeF, int paramF);
void MORSE_TASK_cgetrip_f2(const MORSE_option_t *options,
                           int m, int n, const MORSE_desc_t *A, int Am, int An, int szeA,
                           const MORSE_desc_t *fake1, int fake1m, int fake1n, int szeF1, int paramF1,
                           const MORSE_desc_t *fake2, int fake2m, int fake2n, int szeF2, int paramF2);
void MORSE_TASK_che2ge(const MORSE_option_t *options,
                       MORSE_enum uplo,
                       int m, int n, int mb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_chemm(const MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo,
                      int m, int n, int nb,
                      MORSE_Complex32_t alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                      MORSE_Complex32_t beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_chegst(const MORSE_option_t *options,
                       int itype, MORSE_enum uplo, int N,
                       const MORSE_desc_t *A, int Am, int An, int LDA,
                       const MORSE_desc_t *B, int Bm, int Bn, int LDB,
                       int iinfo);
void MORSE_TASK_cherk(const MORSE_option_t *options,
                      MORSE_enum uplo, MORSE_enum trans,
                      int n, int k, int nb,
                      float alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      float beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_cher2k(const MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum trans,
                       int n, int k, int nb,
                       MORSE_Complex32_t alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int LDB,
                       float beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_cherfb(const MORSE_option_t *options,
                       MORSE_enum uplo,
                       int n, int k, int ib, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt,
                       const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_clacpy(const MORSE_option_t *options,
                       MORSE_enum uplo, int m, int n, int mb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_clacpyx(const MORSE_option_t *options,
                        MORSE_enum uplo, int m, int n, int mb,
                        int displA, const MORSE_desc_t *A, int Am, int An, int lda,
                        int displB, const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_clange(const MORSE_option_t *options,
                       MORSE_enum norm, int M, int N, int NB,
                       const MORSE_desc_t *A, int Am, int An, int LDA,
                       const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_clange_max(const MORSE_option_t *options,
                           const MORSE_desc_t *A, int Am, int An,
                           const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_chessq( const MORSE_option_t *options,
                        MORSE_enum uplo, int n,
                        const MORSE_desc_t *A, int Am, int An, int lda,
                        const MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn );
void MORSE_TASK_clanhe(const MORSE_option_t *options,
                       MORSE_enum norm, MORSE_enum uplo, int N, int NB,
                       const MORSE_desc_t *A, int Am, int An, int LDA,
                       const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_clansy(const MORSE_option_t *options,
                       MORSE_enum norm, MORSE_enum uplo, int N, int NB,
                       const MORSE_desc_t *A, int Am, int An, int LDA,
                       const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_clantr(const MORSE_option_t *options,
                       MORSE_enum norm, MORSE_enum uplo, MORSE_enum diag,
                       int M, int N, int NB,
                       const MORSE_desc_t *A, int Am, int An, int LDA,
                       const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_claset(const MORSE_option_t *options,
                       MORSE_enum uplo, int n1, int n2, MORSE_Complex32_t alpha,
                       MORSE_Complex32_t beta, const MORSE_desc_t *tileA, int tileAm, int tileAn, int ldtilea);
void MORSE_TASK_claset2(const MORSE_option_t *options,
                        MORSE_enum uplo, int n1, int n2, MORSE_Complex32_t alpha,
                        const MORSE_desc_t *tileA, int tileAm, int tileAn, int ldtilea);
void MORSE_TASK_claswp(const MORSE_option_t *options,
                       int n, const MORSE_desc_t *A, int Am, int An, int lda,
                       int i1,  int i2, int *ipiv, int inc);
void MORSE_TASK_claswp_f2(const MORSE_option_t *options,
                          int n, const MORSE_desc_t *A, int Am, int An, int lda,
                          int i1,  int i2, int *ipiv, int inc,
                          const MORSE_desc_t *fake1, int fake1m, int fake1n, int szefake1, int flag1,
                          const MORSE_desc_t *fake2, int fake2m, int fake2n, int szefake2, int flag2);
void MORSE_TASK_claswp_ontile(const MORSE_option_t *options,
                              const MORSE_desc_t descA, const MORSE_desc_t *A, int Am, int An,
                              int i1,  int i2, int *ipiv, int inc, MORSE_Complex32_t *fakepanel);
void MORSE_TASK_claswp_ontile_f2(const MORSE_option_t *options,
                                 const MORSE_desc_t descA, const MORSE_desc_t *A, int Am, int An,
                                 int i1,  int i2, int *ipiv, int inc,
                                 const MORSE_desc_t *fake1, int fake1m, int fake1n, int szefake1, int flag1,
                                 const MORSE_desc_t *fake2, int fake2m, int fake2n, int szefake2, int flag2);
void MORSE_TASK_claswpc_ontile(const MORSE_option_t *options,
                               const MORSE_desc_t descA, const MORSE_desc_t *A, int Am, int An,
                               int i1,  int i2, int *ipiv, int inc, MORSE_Complex32_t *fakepanel);
void MORSE_TASK_clatro(const MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum trans, int m, int n, int mb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_clauum(const MORSE_option_t *options,
                       MORSE_enum uplo, int n, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda);
void MORSE_TASK_cplghe(const MORSE_option_t *options,
                       float bump, int m, int n, const MORSE_desc_t *A, int Am, int An, int lda,
                       int bigM, int m0, int n0, unsigned long long int seed );
void MORSE_TASK_cplgsy(const MORSE_option_t *options,
                       MORSE_Complex32_t bump, int m, int n, const MORSE_desc_t *A, int Am, int An, int lda,
                       int bigM, int m0, int n0, unsigned long long int seed );
void MORSE_TASK_cplrnt(const MORSE_option_t *options,
                       int m, int n, const MORSE_desc_t *A, int Am, int An, int lda,
                       int bigM, int m0, int n0, unsigned long long int seed );
void MORSE_TASK_cpotrf(const MORSE_option_t *options,
                       MORSE_enum uplo, int n, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,

                       int iinfo);
void MORSE_TASK_cshift( const MORSE_option_t *options,
                        int s, int m, int n, int L,
                        MORSE_Complex32_t *A);
void MORSE_TASK_cshiftw(const MORSE_option_t *options,
                        int s, int cl, int m, int n, int L,
                        const MORSE_desc_t *A, int Am, int An, MORSE_Complex32_t *W);
void MORSE_TASK_cssssm(const MORSE_option_t *options,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *L1, int L1m, int L1n, int ldl1,
                       const MORSE_desc_t *L2, int L2m, int L2n, int ldl2,
                       const int *IPIV);
void MORSE_TASK_csymm(const MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo,
                      int m, int n, int nb,
                      MORSE_Complex32_t alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                      MORSE_Complex32_t beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_csyrk(const MORSE_option_t *options,
                      MORSE_enum uplo, MORSE_enum trans,
                      int n, int k, int nb,
                      MORSE_Complex32_t alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      MORSE_Complex32_t beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_csyr2k(const MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum trans,
                       int n, int k, int nb,
                       MORSE_Complex32_t alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int LDB,
                       MORSE_Complex32_t beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_csyssq( const MORSE_option_t *options,
                        MORSE_enum uplo, int n,
                        const MORSE_desc_t *A, int Am, int An, int lda,
                        const MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn );
void MORSE_TASK_csytrf_nopiv(const MORSE_option_t *options,
                             MORSE_enum uplo, int n, int nb,
                             const MORSE_desc_t *A, int Am, int An, int lda,
                             int iinfo);
void MORSE_TASK_cswpab(const MORSE_option_t *options,
                       int i, int n1, int n2,
                       const MORSE_desc_t *A, int Am, int An, int szeA);
void MORSE_TASK_cswptr_ontile(const MORSE_option_t *options,
                              const MORSE_desc_t descA, const MORSE_desc_t *Aij, int Aijm, int Aijn,
                              int i1,  int i2, int *ipiv, int inc,
                              const MORSE_desc_t *Akk, int Akkm, int Akkn, int ldak);
void MORSE_TASK_ctplqt(const MORSE_option_t *options,
                       int m, int n, int l, int ib, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt );
void MORSE_TASK_ctpmlqt( const MORSE_option_t *options,
                         MORSE_enum side, MORSE_enum trans,
                         int M, int N, int K, int L, int ib, int nb,
                         const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                         const MORSE_desc_t *T, int Tm, int Tn, int ldt,
                         const MORSE_desc_t *A, int Am, int An, int lda,
                         const MORSE_desc_t *B, int Bm, int Bn, int ldb );
void MORSE_TASK_ctpmqrt(const MORSE_option_t *options,
                        MORSE_enum side, MORSE_enum trans,
                        int m, int n, int k, int l, int ib, int nb,
                        const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                        const MORSE_desc_t *T, int Tm, int Tn, int ldt,
                        const MORSE_desc_t *A, int Am, int An, int lda,
                        const MORSE_desc_t *B, int Bm, int Bn, int ldb );
void MORSE_TASK_ctpqrt(const MORSE_option_t *options,
                       int m, int n, int l, int ib, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt );
void MORSE_TASK_ctrdalg(const MORSE_option_t *options,
                        MORSE_enum uplo,
                        int N, int NB,
                        const MORSE_desc_t *A,
                        const MORSE_desc_t *C, int Cm, int Cn,
                        const MORSE_desc_t *S, int Sm, int Sn,
                        int i, int j, int m, int grsiz, int BAND,
                        int *PCOL, int *ACOL, int *MCOL);
void MORSE_TASK_ctradd(const MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum trans, int m, int n, int nb,
                       MORSE_Complex32_t alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_Complex32_t beta,  const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_ctrasm(const MORSE_option_t *options,
                       MORSE_enum storev, MORSE_enum uplo, MORSE_enum diag, int M, int N,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_ctrmm(const MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag,
                      int m, int n, int nb,
                      MORSE_Complex32_t alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_ctrmm_p2(const MORSE_option_t *options,
                         MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag,
                         int m, int n, int nb,
                         MORSE_Complex32_t alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                         MORSE_Complex32_t **B, int ldb);
void MORSE_TASK_ctrsm(const MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag,
                      int m, int n, int nb,
                      MORSE_Complex32_t alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_ctrssq( const MORSE_option_t *options,
                        MORSE_enum uplo, MORSE_enum diag,
                        int m, int n,
                        const MORSE_desc_t *A, int Am, int An, int lda,
                        const MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn );
void MORSE_TASK_ctrtri(const MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum diag, int n, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,

                       int iinfo);
void MORSE_TASK_ctslqt(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_ctsmlq(const MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_ctsmlq_hetra1(const MORSE_option_t *options,
                              MORSE_enum side, MORSE_enum trans,
                              int m1, int n1, int m2, int n2, int k, int ib, int nb,
                              const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                              const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                              const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                              const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_ctsmqr(const MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_ctsmqr_hetra1(const MORSE_option_t *options,
                              MORSE_enum side, MORSE_enum trans,
                              int m1, int n1, int m2, int n2, int k, int ib, int nb,
                              const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                              const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                              const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                              const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_ctsqrt(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_ctstrf(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *U, int Um, int Un, int ldu,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *L, int Lm, int Ln, int ldl,
                       int *IPIV,

                       MORSE_bool check_info, int iinfo);
void MORSE_TASK_cttmqr(const MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_cttqrt(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_cttmlq(const MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_cttlqt(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_cpamm(const MORSE_option_t *options,
                       int op, MORSE_enum side, MORSE_enum storev,
                       int m, int n, int k, int l,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       const MORSE_desc_t *W, int Wm, int Wn, int ldw);
void MORSE_TASK_cplssq( const MORSE_option_t *options,
                        const MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn,
                        const MORSE_desc_t *SCLSSQ,     int SCLSSQm,     int SCLSSQn );
void MORSE_TASK_cplssq2( const MORSE_option_t *options,
                         const MORSE_desc_t *RESULT, int RESULTm, int RESULTn );
void MORSE_TASK_cunmlq(const MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m, int n, int ib,  int nb, int k,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt,
                       const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_cunmqr(const MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m, int n, int k, int ib, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt,
                       const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_cbuild( const MORSE_option_t *options,
                        const MORSE_desc_t *A, int Am, int An, int lda,
                        void *user_data, void* user_build_callback );

#endif
