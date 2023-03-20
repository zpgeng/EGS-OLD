/**
 *
 * @file morse_tasks_d.h
 *
 * @copyright 2009-2014 The University of Tennessee and The University of
 *                      Tennessee Research Foundation. All rights reserved.
 * @copyright 2012-2016 Bordeaux INP, CNRS (LaBRI UMR 5800), Inria,
 *                      Univ. Bordeaux. All rights reserved.
 *
 ***
 *
 * @brief Chameleon double elementary tasks header
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
 * @generated d Tue Mar  7 11:20:05 2023
 *
 */
#ifndef _MORSE_TASKS_D_H_
#define _MORSE_TASKS_D_H_


/**
 *  Declarations of QUARK wrappers (called by MORSE) - alphabetical order
 */
void MORSE_TASK_dasum(const MORSE_option_t *options,
                       MORSE_enum storev, MORSE_enum uplo, int M, int N,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_dgeadd(const MORSE_option_t *options,
                       MORSE_enum trans, int m, int n, int nb,
                       double alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                       double beta,  const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_dlascal(const MORSE_option_t *options,
                        MORSE_enum uplo,
                        int m, int n, int nb,
                        double alpha,
                        const MORSE_desc_t *A, int Am, int An, int lda);
void MORSE_TASK_dbrdalg(const MORSE_option_t *options,
                        MORSE_enum uplo,
                        int N, int NB,
                        const MORSE_desc_t *A,
                        const MORSE_desc_t *C, int Cm, int Cn,
                        const MORSE_desc_t *S, int Sm, int Sn,
                        int i, int j, int m, int grsiz, int BAND,
                        int *PCOL, int *ACOL, int *MCOL);
void MORSE_TASK_dgelqt(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dgemm(const MORSE_option_t *options,
                      MORSE_enum transA, MORSE_enum transB,
                      int m, int n, int k, int nb,
                      double alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                      double beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dgemm2( const MORSE_option_t *options,
                        MORSE_enum transA, MORSE_enum transB,
                        int m, int n, int k, int nb,
                        double alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                        const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                        double beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dgemm_f2(const MORSE_option_t *options,
                         MORSE_enum transA, MORSE_enum transB,
                         int m, int n, int k, int nb,
                         double alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                         const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                         double beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc,
                         const MORSE_desc_t *fake1, int fake1m, int fake1n, int szefake1, int flag1,
                         const MORSE_desc_t *fake2, int fake2m, int fake2n, int szefake2, int flag2);
void MORSE_TASK_dgemm_p2(const MORSE_option_t *options,
                         MORSE_enum transA, MORSE_enum transB,
                         int m, int n, int k, int nb,
                         double alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                         const double **B, int ldb,
                         double beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dgemm_p2f1(const MORSE_option_t *options,
                           MORSE_enum transA, MORSE_enum transB,
                           int m, int n, int k, int nb,
                           double alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                           const double **B, int ldb,
                           double beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc,
                           const MORSE_desc_t *fake1, int fake1m, int fake1n, int szefake1, int flag1);
void MORSE_TASK_dgemm_p3(const MORSE_option_t *options,
                         MORSE_enum transA, MORSE_enum transB,
                         int m, int n, int k, int nb,
                         double alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                         const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                         double beta, double **C, int ldc);
void MORSE_TASK_dgeqrt(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dgessm(const MORSE_option_t *options,
                       int m, int n, int k, int ib, int nb,
                       int *IPIV,
                       const MORSE_desc_t *L, int Lm, int Ln, int ldl,
                       const MORSE_desc_t *D, int Dm, int Dn, int ldd,
                       const MORSE_desc_t *A, int Am, int An, int lda);
void MORSE_TASK_dgessq( const MORSE_option_t *options,
                        int m, int n,
                        const MORSE_desc_t *A, int Am, int An, int lda,
                        const MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn);
void MORSE_TASK_dgetrf(const MORSE_option_t *options,
                       int m, int n, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       int *IPIV,

                       MORSE_bool check_info, int iinfo);
void MORSE_TASK_dgetrf_incpiv(const MORSE_option_t *options,
                              int m, int n, int ib, int nb,
                              const MORSE_desc_t *A, int Am, int An, int lda,
                              const MORSE_desc_t *L, int Lm, int Ln, int ldl,
                              int *IPIV,
                              MORSE_bool check_info, int iinfo);
void MORSE_TASK_dgetrf_nopiv(const MORSE_option_t *options,
                             int m, int n, int ib, int nb,
                             const MORSE_desc_t *A, int Am, int An, int lda, int iinfo);
void MORSE_TASK_dgetrf_reclap(const MORSE_option_t *options,
                              int m, int n, int nb,
                              const MORSE_desc_t *A, int Am, int An, int lda,
                              int *IPIV,

                              MORSE_bool check_info, int iinfo,
                              int nbthread);
void MORSE_TASK_dgetrf_rectil(const MORSE_option_t *options,
                              const MORSE_desc_t A, const MORSE_desc_t *Amn, int Amnm, int Amnn, int size,
                              int *IPIV,

                              MORSE_bool check_info, int iinfo,
                              int nbthread);
void MORSE_TASK_dgetrip(const MORSE_option_t *options,
                        int m, int n, const MORSE_desc_t *A, int Am, int An, int szeA);
void MORSE_TASK_dgetrip_f1(const MORSE_option_t *options,
                           int m, int n, const MORSE_desc_t *A, int Am, int An, int szeA,
                           const MORSE_desc_t *fake, int fakem, int faken, int szeF, int paramF);
void MORSE_TASK_dgetrip_f2(const MORSE_option_t *options,
                           int m, int n, const MORSE_desc_t *A, int Am, int An, int szeA,
                           const MORSE_desc_t *fake1, int fake1m, int fake1n, int szeF1, int paramF1,
                           const MORSE_desc_t *fake2, int fake2m, int fake2n, int szeF2, int paramF2);
void MORSE_TASK_dhe2ge(const MORSE_option_t *options,
                       MORSE_enum uplo,
                       int m, int n, int mb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_dsymm(const MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo,
                      int m, int n, int nb,
                      double alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                      double beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dsygst(const MORSE_option_t *options,
                       int itype, MORSE_enum uplo, int N,
                       const MORSE_desc_t *A, int Am, int An, int LDA,
                       const MORSE_desc_t *B, int Bm, int Bn, int LDB,
                       int iinfo);
void MORSE_TASK_dsyrk(const MORSE_option_t *options,
                      MORSE_enum uplo, MORSE_enum trans,
                      int n, int k, int nb,
                      double alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      double beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dsyr2k(const MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum trans,
                       int n, int k, int nb,
                       double alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int LDB,
                       double beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dsyrfb(const MORSE_option_t *options,
                       MORSE_enum uplo,
                       int n, int k, int ib, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt,
                       const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dlacpy(const MORSE_option_t *options,
                       MORSE_enum uplo, int m, int n, int mb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_dlacpyx(const MORSE_option_t *options,
                        MORSE_enum uplo, int m, int n, int mb,
                        int displA, const MORSE_desc_t *A, int Am, int An, int lda,
                        int displB, const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_dlange(const MORSE_option_t *options,
                       MORSE_enum norm, int M, int N, int NB,
                       const MORSE_desc_t *A, int Am, int An, int LDA,
                       const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_dlange_max(const MORSE_option_t *options,
                           const MORSE_desc_t *A, int Am, int An,
                           const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_dsyssq( const MORSE_option_t *options,
                        MORSE_enum uplo, int n,
                        const MORSE_desc_t *A, int Am, int An, int lda,
                        const MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn );
void MORSE_TASK_dlansy(const MORSE_option_t *options,
                       MORSE_enum norm, MORSE_enum uplo, int N, int NB,
                       const MORSE_desc_t *A, int Am, int An, int LDA,
                       const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_dlansy(const MORSE_option_t *options,
                       MORSE_enum norm, MORSE_enum uplo, int N, int NB,
                       const MORSE_desc_t *A, int Am, int An, int LDA,
                       const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_dlantr(const MORSE_option_t *options,
                       MORSE_enum norm, MORSE_enum uplo, MORSE_enum diag,
                       int M, int N, int NB,
                       const MORSE_desc_t *A, int Am, int An, int LDA,
                       const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_dlaset(const MORSE_option_t *options,
                       MORSE_enum uplo, int n1, int n2, double alpha,
                       double beta, const MORSE_desc_t *tileA, int tileAm, int tileAn, int ldtilea);
void MORSE_TASK_dlaset2(const MORSE_option_t *options,
                        MORSE_enum uplo, int n1, int n2, double alpha,
                        const MORSE_desc_t *tileA, int tileAm, int tileAn, int ldtilea);
void MORSE_TASK_dlaswp(const MORSE_option_t *options,
                       int n, const MORSE_desc_t *A, int Am, int An, int lda,
                       int i1,  int i2, int *ipiv, int inc);
void MORSE_TASK_dlaswp_f2(const MORSE_option_t *options,
                          int n, const MORSE_desc_t *A, int Am, int An, int lda,
                          int i1,  int i2, int *ipiv, int inc,
                          const MORSE_desc_t *fake1, int fake1m, int fake1n, int szefake1, int flag1,
                          const MORSE_desc_t *fake2, int fake2m, int fake2n, int szefake2, int flag2);
void MORSE_TASK_dlaswp_ontile(const MORSE_option_t *options,
                              const MORSE_desc_t descA, const MORSE_desc_t *A, int Am, int An,
                              int i1,  int i2, int *ipiv, int inc, double *fakepanel);
void MORSE_TASK_dlaswp_ontile_f2(const MORSE_option_t *options,
                                 const MORSE_desc_t descA, const MORSE_desc_t *A, int Am, int An,
                                 int i1,  int i2, int *ipiv, int inc,
                                 const MORSE_desc_t *fake1, int fake1m, int fake1n, int szefake1, int flag1,
                                 const MORSE_desc_t *fake2, int fake2m, int fake2n, int szefake2, int flag2);
void MORSE_TASK_dlaswpc_ontile(const MORSE_option_t *options,
                               const MORSE_desc_t descA, const MORSE_desc_t *A, int Am, int An,
                               int i1,  int i2, int *ipiv, int inc, double *fakepanel);
void MORSE_TASK_dlatro(const MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum trans, int m, int n, int mb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_dlauum(const MORSE_option_t *options,
                       MORSE_enum uplo, int n, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda);
void MORSE_TASK_dplgsy(const MORSE_option_t *options,
                       double bump, int m, int n, const MORSE_desc_t *A, int Am, int An, int lda,
                       int bigM, int m0, int n0, unsigned long long int seed );
void MORSE_TASK_dplgsy(const MORSE_option_t *options,
                       double bump, int m, int n, const MORSE_desc_t *A, int Am, int An, int lda,
                       int bigM, int m0, int n0, unsigned long long int seed );
void MORSE_TASK_dplrnt(const MORSE_option_t *options,
                       int m, int n, const MORSE_desc_t *A, int Am, int An, int lda,
                       int bigM, int m0, int n0, unsigned long long int seed );
void MORSE_TASK_dpotrf(const MORSE_option_t *options,
                       MORSE_enum uplo, int n, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,

                       int iinfo);
void MORSE_TASK_dshift( const MORSE_option_t *options,
                        int s, int m, int n, int L,
                        double *A);
void MORSE_TASK_dshiftw(const MORSE_option_t *options,
                        int s, int cl, int m, int n, int L,
                        const MORSE_desc_t *A, int Am, int An, double *W);
void MORSE_TASK_dssssm(const MORSE_option_t *options,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *L1, int L1m, int L1n, int ldl1,
                       const MORSE_desc_t *L2, int L2m, int L2n, int ldl2,
                       const int *IPIV);
void MORSE_TASK_dsymm(const MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo,
                      int m, int n, int nb,
                      double alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                      double beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dsyrk(const MORSE_option_t *options,
                      MORSE_enum uplo, MORSE_enum trans,
                      int n, int k, int nb,
                      double alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      double beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dsyr2k(const MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum trans,
                       int n, int k, int nb,
                       double alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int LDB,
                       double beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dsyssq( const MORSE_option_t *options,
                        MORSE_enum uplo, int n,
                        const MORSE_desc_t *A, int Am, int An, int lda,
                        const MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn );
void MORSE_TASK_dsytrf_nopiv(const MORSE_option_t *options,
                             MORSE_enum uplo, int n, int nb,
                             const MORSE_desc_t *A, int Am, int An, int lda,
                             int iinfo);
void MORSE_TASK_dswpab(const MORSE_option_t *options,
                       int i, int n1, int n2,
                       const MORSE_desc_t *A, int Am, int An, int szeA);
void MORSE_TASK_dswptr_ontile(const MORSE_option_t *options,
                              const MORSE_desc_t descA, const MORSE_desc_t *Aij, int Aijm, int Aijn,
                              int i1,  int i2, int *ipiv, int inc,
                              const MORSE_desc_t *Akk, int Akkm, int Akkn, int ldak);
void MORSE_TASK_dtplqt(const MORSE_option_t *options,
                       int m, int n, int l, int ib, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt );
void MORSE_TASK_dtpmlqt( const MORSE_option_t *options,
                         MORSE_enum side, MORSE_enum trans,
                         int M, int N, int K, int L, int ib, int nb,
                         const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                         const MORSE_desc_t *T, int Tm, int Tn, int ldt,
                         const MORSE_desc_t *A, int Am, int An, int lda,
                         const MORSE_desc_t *B, int Bm, int Bn, int ldb );
void MORSE_TASK_dtpmqrt(const MORSE_option_t *options,
                        MORSE_enum side, MORSE_enum trans,
                        int m, int n, int k, int l, int ib, int nb,
                        const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                        const MORSE_desc_t *T, int Tm, int Tn, int ldt,
                        const MORSE_desc_t *A, int Am, int An, int lda,
                        const MORSE_desc_t *B, int Bm, int Bn, int ldb );
void MORSE_TASK_dtpqrt(const MORSE_option_t *options,
                       int m, int n, int l, int ib, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt );
void MORSE_TASK_dtrdalg(const MORSE_option_t *options,
                        MORSE_enum uplo,
                        int N, int NB,
                        const MORSE_desc_t *A,
                        const MORSE_desc_t *C, int Cm, int Cn,
                        const MORSE_desc_t *S, int Sm, int Sn,
                        int i, int j, int m, int grsiz, int BAND,
                        int *PCOL, int *ACOL, int *MCOL);
void MORSE_TASK_dtradd(const MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum trans, int m, int n, int nb,
                       double alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                       double beta,  const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_dtrasm(const MORSE_option_t *options,
                       MORSE_enum storev, MORSE_enum uplo, MORSE_enum diag, int M, int N,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_dtrmm(const MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag,
                      int m, int n, int nb,
                      double alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_dtrmm_p2(const MORSE_option_t *options,
                         MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag,
                         int m, int n, int nb,
                         double alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                         double **B, int ldb);
void MORSE_TASK_dtrsm(const MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag,
                      int m, int n, int nb,
                      double alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_dtrssq( const MORSE_option_t *options,
                        MORSE_enum uplo, MORSE_enum diag,
                        int m, int n,
                        const MORSE_desc_t *A, int Am, int An, int lda,
                        const MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn );
void MORSE_TASK_dtrtri(const MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum diag, int n, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,

                       int iinfo);
void MORSE_TASK_dtslqt(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dtsmlq(const MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dtsmlq_hetra1(const MORSE_option_t *options,
                              MORSE_enum side, MORSE_enum trans,
                              int m1, int n1, int m2, int n2, int k, int ib, int nb,
                              const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                              const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                              const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                              const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dtsmqr(const MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dtsmqr_hetra1(const MORSE_option_t *options,
                              MORSE_enum side, MORSE_enum trans,
                              int m1, int n1, int m2, int n2, int k, int ib, int nb,
                              const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                              const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                              const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                              const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dtsqrt(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dtstrf(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *U, int Um, int Un, int ldu,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *L, int Lm, int Ln, int ldl,
                       int *IPIV,

                       MORSE_bool check_info, int iinfo);
void MORSE_TASK_dttmqr(const MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dttqrt(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dttmlq(const MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dttlqt(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_dpamm(const MORSE_option_t *options,
                       int op, MORSE_enum side, MORSE_enum storev,
                       int m, int n, int k, int l,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       const MORSE_desc_t *W, int Wm, int Wn, int ldw);
void MORSE_TASK_dplssq( const MORSE_option_t *options,
                        const MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn,
                        const MORSE_desc_t *SCLSSQ,     int SCLSSQm,     int SCLSSQn );
void MORSE_TASK_dplssq2( const MORSE_option_t *options,
                         const MORSE_desc_t *RESULT, int RESULTm, int RESULTn );
void MORSE_TASK_dormlq(const MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m, int n, int ib,  int nb, int k,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt,
                       const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dormqr(const MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m, int n, int k, int ib, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt,
                       const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_dbuild( const MORSE_option_t *options,
                        const MORSE_desc_t *A, int Am, int An, int lda,
                        void *user_data, void* user_build_callback );

#endif
