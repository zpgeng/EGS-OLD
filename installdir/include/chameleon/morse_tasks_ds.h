/**
 *
 * @file morse_tasks_ds.h
 *
 * @copyright 2009-2014 The University of Tennessee and The University of
 *                      Tennessee Research Foundation. All rights reserved.
 * @copyright 2012-2014 Bordeaux INP, CNRS (LaBRI UMR 5800), Inria,
 *                      Univ. Bordeaux. All rights reserved.
 *
 ***
 *
 * @brief Chameleon real mixed precision elementary tasks header
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
#ifndef _MORSE_TASKS_D_H_
#define _MORSE_TASKS_D_H_

/**
 *  Declarations of QUARK wrappers (called by MORSE) - alphabetical order
 */
void MORSE_TASK_slag2d(MORSE_option_t *options,
                       int m, int n, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *B, int Bm, int Bn, int ldb);
void MORSE_TASK_dlag2s(MORSE_option_t *options,
                       int m, int n, int nb,
                       MORSE_desc_t *A, int Am, int An, int lda,
                       MORSE_desc_t *B, int Bm, int Bn, int ldb);

#endif
