/**
 *
 * @file morse_tasks_s.h
 *
 * @copyright 2009-2014 The University of Tennessee and The University of
 *                      Tennessee Research Foundation. All rights reserved.
 * @copyright 2012-2016 Bordeaux INP, CNRS (LaBRI UMR 5800), Inria,
 *                      Univ. Bordeaux. All rights reserved.
 *
 ***
 *
 * @brief Chameleon float elementary tasks header
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
 * @generated s Tue Mar  7 11:20:04 2023
 *
 */
#ifndef _MORSE_TASKS_S_H_
#define _MORSE_TASKS_S_H_


/**
 *  Declarations of QUARK wrappers (called by MORSE) - alphabetical order
 */
void MORSE_TASK_sasum(const MORSE_option_t *options,
                       MORSE_enum storev, MORSE_enum uplo, int M, int N,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_sgeadd(const MORSE_option_t *options,
                       MORSE_enum trans, int m, int n, int nb,
                       float alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                       float beta,  const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_slascal(const MORSE_option_t *options,
                        MORSE_enum uplo,
                        int m, int n, int nb,
                        float alpha,
                        const MORSE_desc_t *A, int Am, int An, int lda);
void MORSE_TASK_sbrdalg(const MORSE_option_t *options,
                        MORSE_enum uplo,
                        int N, int NB,
                        const MORSE_desc_t *A,
                        const MORSE_desc_t *C, int Cm, int Cn,
                        const MORSE_desc_t *S, int Sm, int Sn,
                        int i, int j, int m, int grsiz, int BAND,
                        int *PCOL, int *ACOL, int *MCOL);
void MORSE_TASK_sgelqt(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_sgemm(const MORSE_option_t *options,
                      MORSE_enum transA, MORSE_enum transB,
                      int m, int n, int k, int nb,
                      float alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                      float beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_sgemm2( const MORSE_option_t *options,
                        MORSE_enum transA, MORSE_enum transB,
                        int m, int n, int k, int nb,
                        float alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                        const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                        float beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_sgemm_f2(const MORSE_option_t *options,
                         MORSE_enum transA, MORSE_enum transB,
                         int m, int n, int k, int nb,
                         float alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                         const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                         float beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc,
                         const MORSE_desc_t *fake1, int fake1m, int fake1n, int szefake1, int flag1,
                         const MORSE_desc_t *fake2, int fake2m, int fake2n, int szefake2, int flag2);
void MORSE_TASK_sgemm_p2(const MORSE_option_t *options,
                         MORSE_enum transA, MORSE_enum transB,
                         int m, int n, int k, int nb,
                         float alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                         const float **B, int ldb,
                         float beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_sgemm_p2f1(const MORSE_option_t *options,
                           MORSE_enum transA, MORSE_enum transB,
                           int m, int n, int k, int nb,
                           float alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                           const float **B, int ldb,
                           float beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc,
                           const MORSE_desc_t *fake1, int fake1m, int fake1n, int szefake1, int flag1);
void MORSE_TASK_sgemm_p3(const MORSE_option_t *options,
                         MORSE_enum transA, MORSE_enum transB,
                         int m, int n, int k, int nb,
                         float alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                         const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                         float beta, float **C, int ldc);
void MORSE_TASK_sgeqrt(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_sgessm(const MORSE_option_t *options,
                       int m, int n, int k, int ib, int nb,
                       int *IPIV,
                       const MORSE_desc_t *L, int Lm, int Ln, int ldl,
                       const MORSE_desc_t *D, int Dm, int Dn, int ldd,
                       const MORSE_desc_t *A, int Am, int An, int lda);
void MORSE_TASK_sgessq( const MORSE_option_t *options,
                        int m, int n,
                        const MORSE_desc_t *A, int Am, int An, int lda,
                        const MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn);
void MORSE_TASK_sgetrf(const MORSE_option_t *options,
                       int m, int n, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       int *IPIV,

                       MORSE_bool check_info, int iinfo);
void MORSE_TASK_sgetrf_incpiv(const MORSE_option_t *options,
                              int m, int n, int ib, int nb,
                              const MORSE_desc_t *A, int Am, int An, int lda,
                              const MORSE_desc_t *L, int Lm, int Ln, int ldl,
                              int *IPIV,
                              MORSE_bool check_info, int iinfo);
void MORSE_TASK_sgetrf_nopiv(const MORSE_option_t *options,
                             int m, int n, int ib, int nb,
                             const MORSE_desc_t *A, int Am, int An, int lda, int iinfo);
void MORSE_TASK_sgetrf_reclap(const MORSE_option_t *options,
                              int m, int n, int nb,
                              const MORSE_desc_t *A, int Am, int An, int lda,
                              int *IPIV,

                              MORSE_bool check_info, int iinfo,
                              int nbthread);
void MORSE_TASK_sgetrf_rectil(const MORSE_option_t *options,
                              const MORSE_desc_t A, const MORSE_desc_t *Amn, int Amnm, int Amnn, int size,
                              int *IPIV,

                              MORSE_bool check_info, int iinfo,
                              int nbthread);
void MORSE_TASK_sgetrip(const MORSE_option_t *options,
                        int m, int n, const MORSE_desc_t *A, int Am, int An, int szeA);
void MORSE_TASK_sgetrip_f1(const MORSE_option_t *options,
                           int m, int n, const MORSE_desc_t *A, int Am, int An, int szeA,
                           const MORSE_desc_t *fake, int fakem, int faken, int szeF, int paramF);
void MORSE_TASK_sgetrip_f2(const MORSE_option_t *options,
                           int m, int n, const MORSE_desc_t *A, int Am, int An, int szeA,
                           const MORSE_desc_t *fake1, int fake1m, int fake1n, int szeF1, int paramF1,
                           const MORSE_desc_t *fake2, int fake2m, int fake2n, int szeF2, int paramF2);
void MORSE_TASK_she2ge(const MORSE_option_t *options,
                       MORSE_enum uplo,
                       int m, int n, int mb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_ssymm(const MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo,
                      int m, int n, int nb,
                      float alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                      float beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_ssygst(const MORSE_option_t *options,
                       int itype, MORSE_enum uplo, int N,
                       const MORSE_desc_t *A, int Am, int An, int LDA,
                       const MORSE_desc_t *B, int Bm, int Bn, int LDB,
                       int iinfo);
void MORSE_TASK_ssyrk(const MORSE_option_t *options,
                      MORSE_enum uplo, MORSE_enum trans,
                      int n, int k, int nb,
                      float alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      float beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_ssyr2k(const MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum trans,
                       int n, int k, int nb,
                       float alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int LDB,
                       float beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_ssyrfb(const MORSE_option_t *options,
                       MORSE_enum uplo,
                       int n, int k, int ib, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt,
                       const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_slacpy(const MORSE_option_t *options,
                       MORSE_enum uplo, int m, int n, int mb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_slacpyx(const MORSE_option_t *options,
                        MORSE_enum uplo, int m, int n, int mb,
                        int displA, const MORSE_desc_t *A, int Am, int An, int lda,
                        int displB, const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_slange(const MORSE_option_t *options,
                       MORSE_enum norm, int M, int N, int NB,
                       const MORSE_desc_t *A, int Am, int An, int LDA,
                       const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_slange_max(const MORSE_option_t *options,
                           const MORSE_desc_t *A, int Am, int An,
                           const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_ssyssq( const MORSE_option_t *options,
                        MORSE_enum uplo, int n,
                        const MORSE_desc_t *A, int Am, int An, int lda,
                        const MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn );
void MORSE_TASK_slansy(const MORSE_option_t *options,
                       MORSE_enum norm, MORSE_enum uplo, int N, int NB,
                       const MORSE_desc_t *A, int Am, int An, int LDA,
                       const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_slansy(const MORSE_option_t *options,
                       MORSE_enum norm, MORSE_enum uplo, int N, int NB,
                       const MORSE_desc_t *A, int Am, int An, int LDA,
                       const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_slantr(const MORSE_option_t *options,
                       MORSE_enum norm, MORSE_enum uplo, MORSE_enum diag,
                       int M, int N, int NB,
                       const MORSE_desc_t *A, int Am, int An, int LDA,
                       const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_slaset(const MORSE_option_t *options,
                       MORSE_enum uplo, int n1, int n2, float alpha,
                       float beta, const MORSE_desc_t *tileA, int tileAm, int tileAn, int ldtilea);
void MORSE_TASK_slaset2(const MORSE_option_t *options,
                        MORSE_enum uplo, int n1, int n2, float alpha,
                        const MORSE_desc_t *tileA, int tileAm, int tileAn, int ldtilea);
void MORSE_TASK_slaswp(const MORSE_option_t *options,
                       int n, const MORSE_desc_t *A, int Am, int An, int lda,
                       int i1,  int i2, int *ipiv, int inc);
void MORSE_TASK_slaswp_f2(const MORSE_option_t *options,
                          int n, const MORSE_desc_t *A, int Am, int An, int lda,
                          int i1,  int i2, int *ipiv, int inc,
                          const MORSE_desc_t *fake1, int fake1m, int fake1n, int szefake1, int flag1,
                          const MORSE_desc_t *fake2, int fake2m, int fake2n, int szefake2, int flag2);
void MORSE_TASK_slaswp_ontile(const MORSE_option_t *options,
                              const MORSE_desc_t descA, const MORSE_desc_t *A, int Am, int An,
                              int i1,  int i2, int *ipiv, int inc, float *fakepanel);
void MORSE_TASK_slaswp_ontile_f2(const MORSE_option_t *options,
                                 const MORSE_desc_t descA, const MORSE_desc_t *A, int Am, int An,
                                 int i1,  int i2, int *ipiv, int inc,
                                 const MORSE_desc_t *fake1, int fake1m, int fake1n, int szefake1, int flag1,
                                 const MORSE_desc_t *fake2, int fake2m, int fake2n, int szefake2, int flag2);
void MORSE_TASK_slaswpc_ontile(const MORSE_option_t *options,
                               const MORSE_desc_t descA, const MORSE_desc_t *A, int Am, int An,
                               int i1,  int i2, int *ipiv, int inc, float *fakepanel);
void MORSE_TASK_slatro(const MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum trans, int m, int n, int mb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_slauum(const MORSE_option_t *options,
                       MORSE_enum uplo, int n, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda);
void MORSE_TASK_splgsy(const MORSE_option_t *options,
                       float bump, int m, int n, const MORSE_desc_t *A, int Am, int An, int lda,
                       int bigM, int m0, int n0, unsigned long long int seed );
void MORSE_TASK_splgsy(const MORSE_option_t *options,
                       float bump, int m, int n, const MORSE_desc_t *A, int Am, int An, int lda,
                       int bigM, int m0, int n0, unsigned long long int seed );
void MORSE_TASK_splrnt(const MORSE_option_t *options,
                       int m, int n, const MORSE_desc_t *A, int Am, int An, int lda,
                       int bigM, int m0, int n0, unsigned long long int seed );
void MORSE_TASK_spotrf(const MORSE_option_t *options,
                       MORSE_enum uplo, int n, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,

                       int iinfo);
void MORSE_TASK_sshift( const MORSE_option_t *options,
                        int s, int m, int n, int L,
                        float *A);
void MORSE_TASK_sshiftw(const MORSE_option_t *options,
                        int s, int cl, int m, int n, int L,
                        const MORSE_desc_t *A, int Am, int An, float *W);
void MORSE_TASK_sssssm(const MORSE_option_t *options,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *L1, int L1m, int L1n, int ldl1,
                       const MORSE_desc_t *L2, int L2m, int L2n, int ldl2,
                       const int *IPIV);
void MORSE_TASK_ssymm(const MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo,
                      int m, int n, int nb,
                      float alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                      float beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_ssyrk(const MORSE_option_t *options,
                      MORSE_enum uplo, MORSE_enum trans,
                      int n, int k, int nb,
                      float alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      float beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_ssyr2k(const MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum trans,
                       int n, int k, int nb,
                       float alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int LDB,
                       float beta, const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_ssyssq( const MORSE_option_t *options,
                        MORSE_enum uplo, int n,
                        const MORSE_desc_t *A, int Am, int An, int lda,
                        const MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn );
void MORSE_TASK_ssytrf_nopiv(const MORSE_option_t *options,
                             MORSE_enum uplo, int n, int nb,
                             const MORSE_desc_t *A, int Am, int An, int lda,
                             int iinfo);
void MORSE_TASK_sswpab(const MORSE_option_t *options,
                       int i, int n1, int n2,
                       const MORSE_desc_t *A, int Am, int An, int szeA);
void MORSE_TASK_sswptr_ontile(const MORSE_option_t *options,
                              const MORSE_desc_t descA, const MORSE_desc_t *Aij, int Aijm, int Aijn,
                              int i1,  int i2, int *ipiv, int inc,
                              const MORSE_desc_t *Akk, int Akkm, int Akkn, int ldak);
void MORSE_TASK_stplqt(const MORSE_option_t *options,
                       int m, int n, int l, int ib, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt );
void MORSE_TASK_stpmlqt( const MORSE_option_t *options,
                         MORSE_enum side, MORSE_enum trans,
                         int M, int N, int K, int L, int ib, int nb,
                         const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                         const MORSE_desc_t *T, int Tm, int Tn, int ldt,
                         const MORSE_desc_t *A, int Am, int An, int lda,
                         const MORSE_desc_t *B, int Bm, int Bn, int ldb );
void MORSE_TASK_stpmqrt(const MORSE_option_t *options,
                        MORSE_enum side, MORSE_enum trans,
                        int m, int n, int k, int l, int ib, int nb,
                        const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                        const MORSE_desc_t *T, int Tm, int Tn, int ldt,
                        const MORSE_desc_t *A, int Am, int An, int lda,
                        const MORSE_desc_t *B, int Bm, int Bn, int ldb );
void MORSE_TASK_stpqrt(const MORSE_option_t *options,
                       int m, int n, int l, int ib, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn, int ldb,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt );
void MORSE_TASK_strdalg(const MORSE_option_t *options,
                        MORSE_enum uplo,
                        int N, int NB,
                        const MORSE_desc_t *A,
                        const MORSE_desc_t *C, int Cm, int Cn,
                        const MORSE_desc_t *S, int Sm, int Sn,
                        int i, int j, int m, int grsiz, int BAND,
                        int *PCOL, int *ACOL, int *MCOL);
void MORSE_TASK_stradd(const MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum trans, int m, int n, int nb,
                       float alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                       float beta,  const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_strasm(const MORSE_option_t *options,
                       MORSE_enum storev, MORSE_enum uplo, MORSE_enum diag, int M, int N,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *B, int Bm, int Bn);
void MORSE_TASK_strmm(const MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag,
                      int m, int n, int nb,
                      float alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_strmm_p2(const MORSE_option_t *options,
                         MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag,
                         int m, int n, int nb,
                         float alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                         float **B, int ldb);
void MORSE_TASK_strsm(const MORSE_option_t *options,
                      MORSE_enum side, MORSE_enum uplo, MORSE_enum transA, MORSE_enum diag,
                      int m, int n, int nb,
                      float alpha, const MORSE_desc_t *A, int Am, int An, int lda,
                      const MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_strssq( const MORSE_option_t *options,
                        MORSE_enum uplo, MORSE_enum diag,
                        int m, int n,
                        const MORSE_desc_t *A, int Am, int An, int lda,
                        const MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn );
void MORSE_TASK_strtri(const MORSE_option_t *options,
                       MORSE_enum uplo, MORSE_enum diag, int n, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,

                       int iinfo);
void MORSE_TASK_stslqt(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_stsmlq(const MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_stsmlq_hetra1(const MORSE_option_t *options,
                              MORSE_enum side, MORSE_enum trans,
                              int m1, int n1, int m2, int n2, int k, int ib, int nb,
                              const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                              const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                              const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                              const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_stsmqr(const MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_stsmqr_hetra1(const MORSE_option_t *options,
                              MORSE_enum side, MORSE_enum trans,
                              int m1, int n1, int m2, int n2, int k, int ib, int nb,
                              const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                              const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                              const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                              const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_stsqrt(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_ststrf(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *U, int Um, int Un, int ldu,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *L, int Lm, int Ln, int ldl,
                       int *IPIV,

                       MORSE_bool check_info, int iinfo);
void MORSE_TASK_sttmqr(const MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_sttqrt(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_sttmlq(const MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m1, int n1, int m2, int n2, int k, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_sttlqt(const MORSE_option_t *options,
                       int m, int n, int ib, int nb,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt);
void MORSE_TASK_spamm(const MORSE_option_t *options,
                       int op, MORSE_enum side, MORSE_enum storev,
                       int m, int n, int k, int l,
                       const MORSE_desc_t *A1, int A1m, int A1n, int lda1,
                       const MORSE_desc_t *A2, int A2m, int A2n, int lda2,
                       const MORSE_desc_t *V, int Vm, int Vn, int ldv,
                       const MORSE_desc_t *W, int Wm, int Wn, int ldw);
void MORSE_TASK_splssq( const MORSE_option_t *options,
                        const MORSE_desc_t *SCALESUMSQ, int SCALESUMSQm, int SCALESUMSQn,
                        const MORSE_desc_t *SCLSSQ,     int SCLSSQm,     int SCLSSQn );
void MORSE_TASK_splssq2( const MORSE_option_t *options,
                         const MORSE_desc_t *RESULT, int RESULTm, int RESULTn );
void MORSE_TASK_sormlq(const MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m, int n, int ib,  int nb, int k,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt,
                       const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_sormqr(const MORSE_option_t *options,
                       MORSE_enum side, MORSE_enum trans,
                       int m, int n, int k, int ib, int nb,
                       const MORSE_desc_t *A, int Am, int An, int lda,
                       const MORSE_desc_t *T, int Tm, int Tn, int ldt,
                       const MORSE_desc_t *C, int Cm, int Cn, int ldc);
void MORSE_TASK_sbuild( const MORSE_option_t *options,
                        const MORSE_desc_t *A, int Am, int An, int lda,
                        void *user_data, void* user_build_callback );

#endif
