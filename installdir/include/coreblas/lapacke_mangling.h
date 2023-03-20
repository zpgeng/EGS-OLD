/**
 *
 * @file lapacke_mangling.h
 *
 * @copyright 2009-2014 The University of Tennessee and The University of
 *                      Tennessee Research Foundation. All rights reserved.
 * @copyright 2012-2014 Bordeaux INP, CNRS (LaBRI UMR 5800), Inria,
 *                      Univ. Bordeaux. All rights reserved.
 *
 ***
 *
 * @brief Chameleon lapacke mangling header
 *
 * @version 1.0.0
 *
 */
#ifndef LAPACK_HEADER_INCLUDED
#define LAPACK_HEADER_INCLUDED

/* Mangling for Fortran global symbols without underscores. */
#define LAPACK_GLOBAL(name,NAME) name##_

/* Mangling for Fortran global symbols with underscores. */
#define LAPACK_GLOBAL_(name,NAME) name##_

/* Mangling for Fortran module symbols without underscores. */
#define LAPACK_MODULE(mod_name,name, mod_NAME,NAME) __##mod_name##_MOD_##name

/* Mangling for Fortran module symbols with underscores. */
#define LAPACK_MODULE_(mod_name,name, mod_NAME,NAME) __##mod_name##_MOD_##name

#endif
