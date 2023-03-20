/**
 *
 * @file drawsystolic.c
 *
 * Binary to draw systolic trees.
 *
 * @copyright 2017      Bordeaux INP, CNRS (LaBRI UMR 5800), Inria,
 *                      Univ. Bordeaux. All rights reserved.
 *
 * @version 1.0.0
 * @author Raphael Boucherie
 * @author Mathieu Faverge
 * @date 2017-04-04
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libhqr.h>
#include "common.h"

int
main(int argc, char ** argv)
{
    libhqr_tree_t qrtree;
    libhqr_matrix_t matrix;
    int iparam[IPARAM_SIZEOF];

    /* Get options */
    parse_arguments( &argc, &argv, iparam );
    PASTE_CODE_IPARAM_LOCALS( iparam );

    matrix.nodes = nodes;
    matrix.p     = P;
    matrix.mt    = MT;
    matrix.nt    = NT;

    libhqr_init_sys( &qrtree, LIBHQR_QR, &matrix, P, Q );
    libhqr_print_svg( &qrtree, "systolic.svg" );
    libhqr_finalize( &qrtree );

    return 1;
}
