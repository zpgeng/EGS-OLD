/**
 *
 * @file coreblas_ds.h
 *
 * @copyright 2009-2014 The University of Tennessee and The University of
 *                      Tennessee Research Foundation. All rights reserved.
 * @copyright 2012-2014 Bordeaux INP, CNRS (LaBRI UMR 5800), Inria,
 *                      Univ. Bordeaux. All rights reserved.
 *
 ***
 *
 * @brief Chameleon CPU real mixed precision kernels header
 *
 * @version 1.0.0
 * @comment This file has been automatically generated
 *          from Plasma 2.5.0 for MORSE 1.0.0
 * @author Jakub Kurzak
 * @author Hatem Ltaief
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2010-11-15
 * @generated ds Tue Mar  7 11:20:05 2023
 *
 */
#ifndef _MORSE_SORE_DSBLAS_H_
#define _MORSE_SORE_DSBLAS_H_

/**
 *  Declarations of serial kernels - alphabetical order
 */
void CORE_slag2d(int m, int n,
                 const float *A, int lda,
                 double *B, int ldb);
void CORE_dlag2s(int m, int n,
                 const double *A, int lda,
                 float *B, int ldb, int *info);

#endif
