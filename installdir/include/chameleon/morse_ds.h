/**
 *
 * @file morse_ds.h
 *
 * @copyright 2009-2014 The University of Tennessee and The University of
 *                      Tennessee Research Foundation. All rights reserved.
 * @copyright 2012-2014 Bordeaux INP, CNRS (LaBRI UMR 5800), Inria,
 *                      Univ. Bordeaux. All rights reserved.
 *
 ***
 *
 * @brief Chameleon mixed precision wrappers header
 *
 * @version 1.0.0
 * @comment This file has been automatically generated
 *          from Plasma 2.5.0 for MORSE 1.0.0
 * @author Mathieu Faverge
 * @author Emmanuel Agullo
 * @author Cedric Castagnede
 * @date 2010-11-15
 * @generated ds Tue Mar  7 11:20:05 2023
 *
 */
#ifndef _MORSE_DS_H_
#define _MORSE_DS_H_

BEGIN_C_DECLS

/**
 *  Declarations of math functions (LAPACK layout) - alphabetical order
 */
//int MORSE_dsgesv(int N, int NRHS, double *A, int LDA, int * IPIV, double *B, int LDB, double *X, int LDX, int *ITER);
//int MORSE_dsposv(MORSE_enum uplo, int N, int NRHS, double *A, int LDA, double *B, int LDB, double *X, int LDX, int *ITER);
//int MORSE_dsgels(MORSE_enum trans, int M, int N, int NRHS, double *A, int LDA, double *B, int LDB, double *X, int LDX, int *ITER);
//int MORSE_dsungesv(MORSE_enum trans, int N, int NRHS, double *A, int LDA, double *B, int LDB, double *X, int LDX, int *ITER);

/**
 *  Declarations of math functions (tile layout) - alphabetical order
 */
//int MORSE_dsgesv_Tile(MORSE_desc_t *A, int *IPIV, MORSE_desc_t *B, MORSE_desc_t *X, int *ITER);
//int MORSE_dsposv_Tile(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_desc_t *X, int *ITER);
/* int MORSE_dsgels_Tile(MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_desc_t *X, int *ITER); */
//int MORSE_dsungesv_Tile(MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_desc_t *X, int *ITER);

/**
 *  Declarations of math functions (tile layout, asynchronous execution) - alphabetical order
 */
//int MORSE_dsgesv_Tile_Async(MORSE_desc_t *A, int *IPIV, MORSE_desc_t *B, MORSE_desc_t *X, int *ITER, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_dsposv_Tile_Async(MORSE_enum uplo, MORSE_desc_t *A, MORSE_desc_t *B, MORSE_desc_t *X, int *ITER, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_dsgels_Tile_Async(MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_desc_t *X, int *ITER, MORSE_sequence_t *sequence, MORSE_request_t *request);
//int MORSE_dsungesv_Tile_Async(MORSE_enum trans, MORSE_desc_t *A, MORSE_desc_t *T, MORSE_desc_t *B, MORSE_desc_t *X, int *ITER, MORSE_sequence_t *sequence, MORSE_request_t *request);

END_C_DECLS

#endif
