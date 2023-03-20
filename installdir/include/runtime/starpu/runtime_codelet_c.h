/**
 *
 * @file runtime_codelet_c.h
 *
 * @copyright 2009-2014 The University of Tennessee and The University of
 *                      Tennessee Research Foundation. All rights reserved.
 * @copyright 2012-2014 Bordeaux INP, CNRS (LaBRI UMR 5800), Inria,
 *                      Univ. Bordeaux. All rights reserved.
 *
 ***
 *
 * @brief Chameleon StarPU MORSE_Complex32_t codelets header
 *
 * @version 1.0.0
 * @author Cedric Augonnet
 * @author Mathieu Faverge
 * @author Cedric Castagnede
 * @date 2011-06-01
 * @generated c Tue Mar  7 11:20:04 2023
 *
 */
#ifndef _CODELETS_C_H_
#define _CODELETS_C_H_

#include <stdio.h>
#include "runtime_codelets.h"

#include "chameleon/morse_tasks_c.h"
#if !defined(CHAMELEON_SIMULATION)
#include "coreblas/coreblas_c.h"
#if defined(CHAMELEON_USE_CUDA)
#include "cudablas.h"
#endif
#endif

/*
 * Management functions
 */
CCODELETS_HEADER(tile_zero)

/*
 * BLAS 1 functions
 */
CCODELETS_HEADER(axpy)

/*
 * BLAS 3 functions
 */
CCODELETS_HEADER(gemm)
CCODELETS_HEADER(hemm)
CCODELETS_HEADER(her2k)
CCODELETS_HEADER(herk)
CCODELETS_HEADER(symm)
CCODELETS_HEADER(syr2k)
CCODELETS_HEADER(syrk)
CCODELETS_HEADER(trmm)
CCODELETS_HEADER(trsm)

/*
 * LAPACK functions
 */
CCODELETS_HEADER(gelqt)
CCODELETS_HEADER(geqrt)
CCODELETS_HEADER(gessm)
CCODELETS_HEADER(gessq)
CCODELETS_HEADER(getrf)
CCODELETS_HEADER(getrf_incpiv)
CCODELETS_HEADER(getrf_nopiv)
CCODELETS_HEADER(herfb)
CCODELETS_HEADER(lauum)
CCODELETS_HEADER(potrf)
CCODELETS_HEADER(ssssm)
CCODELETS_HEADER(syssq)
CCODELETS_HEADER(trasm)
CCODELETS_HEADER(trssq)
CCODELETS_HEADER(trtri)
CCODELETS_HEADER(tplqt)
CCODELETS_HEADER(tpqrt)
CCODELETS_HEADER(tpmlqt)
CCODELETS_HEADER(tpmqrt)
CCODELETS_HEADER(tslqt)
CCODELETS_HEADER(tsmlq)
CCODELETS_HEADER(tsmqr)
CCODELETS_HEADER(tsmlq_hetra1)
CCODELETS_HEADER(tsmqr_hetra1)
CCODELETS_HEADER(tsqrt)
CCODELETS_HEADER(tstrf)
CCODELETS_HEADER(ttlqt)
CCODELETS_HEADER(ttmlq)
CCODELETS_HEADER(ttmqr)
CCODELETS_HEADER(ttqrt)
CCODELETS_HEADER(unmlq)
CCODELETS_HEADER(unmqr)

/*
 * Auxiliary functions
 */
CCODELETS_HEADER(geadd)
CCODELETS_HEADER(he2ge)
CCODELETS_HEADER(lascal)
CCODELETS_HEADER(tradd)
CCODELETS_HEADER(lacpy)
CCODELETS_HEADER(lange)
CCODELETS_HEADER(lange_max)
CCODELETS_HEADER(lansy)
CCODELETS_HEADER(lantr)
CCODELETS_HEADER(laset)
CCODELETS_HEADER(laset2)
CCODELETS_HEADER(latro)
CCODELETS_HEADER(plssq)
CCODELETS_HEADER(plssq2)

/*
 * MIXED PRECISION functions
 */
CCODELETS_HEADER(lag2z)

/*
 * DZ functions
 */
CCODELETS_HEADER(asum)

/*
 * CPU only functions
 */
CCODELETS_HEADER(plrnt)
CCODELETS_HEADER(build)

#if defined(PRECISION_z) || defined(PRECISION_c)
CCODELETS_HEADER(hessq)
CCODELETS_HEADER(lanhe)
CCODELETS_HEADER(plghe)
CCODELETS_HEADER(sytrf_nopiv)
#endif
CCODELETS_HEADER(plgsy)

#endif /* _CODELETS_C_H_ */
