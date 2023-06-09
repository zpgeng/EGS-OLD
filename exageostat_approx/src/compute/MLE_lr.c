/**
 *
 * Copyright (c) 2017-2020  King Abdullah University of Science and Technology
 * All rights reserved.
 *
 * ExaGeoStat is a software package provided by KAUST
 **/
/**
 *  @file MLE_lr.c
 *
 *  
 *  ExaGeoStat is a software package provided by KAUST,
 *  King Abdullah University of Science and Technology - ECRC
 *
 * @version 1.1.0
 * @author Sameh Abdulah
 * @date 2020-06-06
 *
 **/
#include "../include/MLE_lr.h"
//***************************************************************************************
//HiCMA global variables.
int store_only_diagonal_tiles = 1;
int print_index = 0;
STARSH_blrf *mpiF;
int use_scratch = 1;
int global_check = 0;  //used to create dense matrix for accuracy check
int print_mat = 0;
int calc_rank_stat = 0; //Calculate the rank. Set to 0 in normal execution. 
double *Ark_initial;
double *Ark_old;

int HICMA_MLE_dzvg_Tile (MLE_data *data,  double * Nrand, double * initial_theta, int n, int dts, int log, int p_grid, int q_grid) {
    //! Generate Observations Vector (Z) for testing Maximum
    /*! Likelihood function -- HICMA-sync
     * Returns Z observation vector
     * @param[in] data: MLE_data struct with different MLE inputs.
     * @param[in] Nrand: A uniform random vector with size n that is used to generate Z .
     * @param[in] initial_theta: Theta vector with three parameter (Variance, Range, Smoothness)
     *                           that is used to to generate the Covariance Matrix.
     * @param[in] n: Problem size (number spatial locations).
     * @param[in] dts: tile size (MB) is used only in the case of HiCMA not MORSE.
     * @param[in] log: equals one if the user needs to generate log files for his problem.
     * @param[in] p_grid: p_grid in the case of distributed system.
     * @param[in] q_grid: q_grid in the case of distributed system.
     * */
    //Initialization
    MORSE_sequence_t *msequence;
    MORSE_request_t  mrequest[2]     = { MORSE_REQUEST_INITIALIZER, MORSE_REQUEST_INITIALIZER };
    MORSE_desc_t *MORSE_descC       = NULL;
    MORSE_desc_t *MORSE_descZ       = NULL;
    double* univariate_theta;
    double* univariate2_theta;
    double* univariate3_theta;
    double nu12;
    double rho;
    double sigma_square12;

    //Create two dense descriptors to generate the measurment vectors
    MORSE_Sequence_Create(&msequence);    
    EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&MORSE_descC, NULL, MorseRealDouble, dts, dts, dts * dts, n, n, 0, 0, n, n, p_grid, q_grid);
    EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&MORSE_descZ, NULL, MorseRealDouble, dts, dts, dts * dts, n, 1, 0, 0, n, 1, p_grid, q_grid);


    //Generate the co-variance matrix C
    VERBOSE("LR: Initializing Covariance Matrix (Synthetic Dataset Dense Generation Phase).....");

    if(strcmp(data->kernel_fun, "bivariate_matern_parsimonious2")   == 0 || strcmp(data->kernel_fun, "bivariate_matern_parsimonious2_profile")   == 0)
    {

        univariate_theta =(double *) malloc(3 * sizeof(double));
        univariate2_theta =(double *) malloc(3 * sizeof(double));
        univariate3_theta =(double *) malloc(3 * sizeof(double));
        univariate_theta[0]=initial_theta[0];
        univariate_theta[1]=initial_theta[2];
        univariate_theta[2]=initial_theta[3];

        MORSE_MLE_dcmg_Tile_Async(MorseUpperLower, morse_desc_submatrix(MORSE_descC, 0,   0, MORSE_descC->m/2,
                    MORSE_descC->n/2), &data->l1, &data->l1, &data->lm, univariate_theta, data->dm,
                "univariate_matern_stationary",  msequence, mrequest);


        nu12 = 0.5 * (initial_theta[3] + initial_theta[4]);
        rho = initial_theta[5] * sqrt( (tgamma(initial_theta[3] + 1)*tgamma(initial_theta[4] + 1)) /
                (tgamma(initial_theta[3]) * tgamma(initial_theta[4])) ) *
            tgamma(nu12) / tgamma(nu12 + 1);
        sigma_square12 = rho * sqrt(initial_theta[0]*initial_theta[1]) ;

        univariate2_theta[0]=sigma_square12;
        univariate2_theta[1]=initial_theta[2];
        univariate2_theta[2]=nu12;
        MORSE_MLE_dcmg_Tile_Async(MorseUpperLower, morse_desc_submatrix(MORSE_descC, MORSE_descC->m/2,
                    0, MORSE_descC->m/2, MORSE_descC->n/2), &data->l1, &data->l1, &data->lm,
                univariate2_theta, data->dm, "univariate_matern_stationary",  msequence, mrequest);

        //      MORSE_MLE_dcmg_Tile_Async(MorseLower, data->descsubC21, &data->l1, &data->l1, &data->lm, univariate2_theta, data->dm, "univariate_matern_stationary",  msequence, &mrequest[0]);

        univariate3_theta[0]=initial_theta[1];
        univariate3_theta[1]=initial_theta[2];
        univariate3_theta[2]=initial_theta[4];
        MORSE_MLE_dcmg_Tile_Async(MorseUpperLower, morse_desc_submatrix(MORSE_descC, MORSE_descC->m/2,
                    MORSE_descC->n/2, MORSE_descC->m/2, MORSE_descC->n/2), &data->l1, &data->l1,
                &data->lm, univariate3_theta, data->dm, "univariate_matern_stationary",  msequence, mrequest);
    }
    else    if(strcmp(data->kernel_fun, "univariate_matern_non_stationary")   == 0)
    {
        MORSE_MLE_dcmg_Tile_Async(MorseLower, data->descC, &data->l1,
                &data->l1, &data->lm, initial_theta,
                data->dm, "univariate_matern_stationary",  msequence, mrequest);
    }
    else
    {
        MORSE_MLE_dcmg_Tile_Async(MorseLower, MORSE_descC, &data->l1,
                &data->l1, &data->lm, initial_theta,
                data->dm, data->kernel_fun,  msequence, mrequest);

        //  MORSE_MLE_dcmg_Tile_Async(MorseLower, MORSE_descC, &data->l1, &data->l1, &data->lm, initial_theta, data->dm, data->kernel_fun, msequence, mrequest);
    }

    MORSE_Sequence_Wait(msequence);
    VERBOSE(" Done.\n");



    //     double *C = (double *) malloc(n * n * sizeof(double));
    //       MORSE_Tile_to_Lapack( MORSE_descC, C, n);
    //         print_dmatrix("testC", 16, 16, C, 16);
    //        exit(0);

    //Copy Nrand to Z
    VERBOSE("LR: Generate Normal Random Distribution Vector Z (Synthetic Dataset Dense Generation Phase) .....");
    MORSE_MLE_dzcpy_Tile_Async(MORSE_descZ, Nrand, msequence, mrequest);
    VERBOSE(" Done.\n");

    //Cholesky factorization for the Co-variance matrix C
    VERBOSE("LR: Cholesky factorization of Sigma (Synthetic Dataset Dense Generation Phase) .....");
    int success = MORSE_dpotrf_Tile(MorseLower, MORSE_descC);
    SUCCESS(success, "LR: Factorization cannot be performed..\n The matrix is not positive definite\n\n");
    VERBOSE(" Done.\n");

    //Triangular matrix-matrix multiplication
    VERBOSE("LR: Triangular matrix-matrix multiplication Z=L.e (Synthetic Dataset Dense Generation Phase) .....");
    MORSE_dtrmm_Tile(MorseLeft, MorseLower, MorseNoTrans, MorseNonUnit, 1, MORSE_descC, MORSE_descZ);
    VERBOSE(" Done.\n");

    //if log==1 write vector to disk
    if(log==1)
    {
        double *z;
#if defined(CHAMELEON_USE_MPI)
        z = (double *) malloc(n * sizeof(double));
        MORSE_Tile_to_Lapack( MORSE_descZ, z, n);
#else
        z = MORSE_descZ->mat;
#endif
        write_vectors(z, data, n);
#if defined(CHAMELEON_USE_MPI)
        free(z);
#endif
    }

    VERBOSE("LR: Done Z Vector Dense Generation Phase. (Chameleon Synchronous)\n");
    VERBOSE("************************************************************\n");    


    data->descZ    = MORSE_descZ; 
    data->sequence  = msequence;
    data->request   = mrequest;
    //Destory dense descriptors to save memory.
    MORSE_Desc_Destroy(&MORSE_descC);    
    return 0;
}


void HICMA_MLE_zcpy( MLE_data *data, double *streamdata)
    //! Copy measurements vector from Lapack
    /*! format to Chameleon format.
     * @param[in] data: MLE_data struct with different MLE inputs.
     * @param[in] streamdata: measurments vector in lapack format.
     * */
{
    MORSE_sequence_t *hsequence     = (MORSE_sequence_t *) data->hsequence;
    MORSE_request_t  *hrequest      = (MORSE_request_t *) data->hrequest;
    VERBOSE("LR: Copy Z from vector to decriptor.\n");
    MORSE_MLE_dzcpy_Tile_Async(data->hicma_descZ, streamdata, hsequence, hrequest);
    MORSE_Sequence_Wait(hsequence);
    VERBOSE("LR: Done Z copying step.\n");
    VERBOSE("************************************************************\n");
}

//Generate Observations Vector (Z) for testing Maximum Likelihood function -- MORSE-sync
//int HICMA_MLE_dzvg_Tile (MLE_data *data,  double * Nrand, double * initial_theta, int n, int ts, int log) {

//    int compress_diag    = 0;
//    int success        = 0;
//    acc_struct acc;
//    MORSE_desc_t *hicma_descCD  = (MORSE_desc_t*) data->hicma_descCD;
//    MORSE_desc_t *hicma_descCUV = (MORSE_desc_t*) data->hicma_descCUV;
//    MORSE_desc_t *hicma_descCrk = (MORSE_desc_t*) data->hicma_descCrk;
//    MORSE_desc_t *MORSE_descZ   = (MORSE_desc_t*) data->descZ;
//    MORSE_desc_t *MORSE_descC   = (MORSE_desc_t*) data->descC;


//    if(data->check==0)
//        global_check=0;

//    if(strcmp(data->obsFPath, "")==0)
//    {

//        if (data->verbose == 1 && MORSE_My_Mpi_Rank() == 0)
//            fprintf(stderr, "LR: Initializing Co-variance Matrix (Synthetic Dataset Generation Phase) .....");
//Generate Co-variance matrix C
//MORSE_MLE_cmg_Tile_Async(data->descC, data->sequence, &data->request[0], &data->l1, &data->l1, initial_theta, data->dm);
//ddcay is any vale for GEOSTAT (not used)
//        HICMA_problem_t hicma_problem;
//        hicma_problem.theta    = initial_theta;
//        hicma_problem.noise    = 0.0;
//        hicma_problem.ndim    = 2;
//        HICMA_zgenerate_problem(HICMA_STARSH_PROB_GEOSTAT, 'S', 0, n, ts, hicma_descCUV->mt, hicma_descCUV->nt, &hicma_problem);
//        mpiF = hicma_problem.starsh_format;
//printf("hicma_maxrank:%d - compress_diag:%d - hicma_descCUV->mt:%d - hicma_descCD->mt:%d - hicma_descCrk->mt:%d - MORSE_descC->mt:%d\n", data->hicma_maxrank,  compress_diag, hicma_descCUV->mt, hicma_descCD->mt, hicma_descCrk->mt, MORSE_descC->mt);    
//        HICMA_zgytlr_Tile(MorseLower, hicma_descCUV, hicma_descCD, hicma_descCrk, 0, data->hicma_maxrank, pow(10, -1.0 * data->hicma_acc), compress_diag, MORSE_descC);    

//        if (data->verbose == 1 && MORSE_My_Mpi_Rank() == 0)
//            fprintf(stderr, " Done.\n");

//For checking accuracy
//        if(data->check==1 && n < 10000)
//        {
//if (data->verbose == 1 && MORSE_My_Mpi_Rank() == 0)
//        fprintf(stderr, "LR: allocating and coping original covariance matrix for accuracy checking (Synthetic Dataset Generation Phase) .....");

//data->Adense    = (double *) malloc(n * n * sizeof(double));
//data->Adense2   = (double *) malloc(n * n * sizeof(double));    

//printf("%d - %d\n",MORSE_descC->m,MORSE_descC->n);
// MORSE_Tile_to_Lapack(MORSE_descC, data->Adense, n);
//    MORSE_Tile_to_Lapack(MORSE_descC, data->Adense2, n);         

//fprintf(stderr," %6.4e", data->Adense[0]);
//print_matrix("test Hicma",n, n, data->Adense, n);
//PASTE_TILE_TO_LAPACK( MORSE_descC, data->Adense, data->check, double, M, M);
//PASTE_TILE_TO_LAPACK( MORSE_descC, data->Adense2, data->check, double, M, M);

//    if (data->verbose == 1 && MORSE_My_Mpi_Rank() == 0)
//        fprintf(stderr, " Done.\n");
//        }

//Generate Z Vector
//        if (data->verbose == 1 && MORSE_My_Mpi_Rank() == 0)
//                  fprintf(stderr, "LR:Generate Normal Random Distribution Vector Z (Synthetic Dataset Generation Phase) .....");
//        MORSE_MLE_dzcpy_Tile_Async(data->descZ, Nrand, data->sequence, &data->request[0]);
//        
//        if (data->verbose == 1 && MORSE_My_Mpi_Rank() == 0)
//                        fprintf(stderr, " Done.\n");

//Cholesky factorization
//        if (data->verbose == 1 && MORSE_My_Mpi_Rank() == 0)
//            fprintf(stderr, "Cholesky factorization of Sigma (Synthetic Dataset Generation Phase) .....");

//        int success = HICMA_zpotrf_Tile(MorseLower, hicma_descCUV, hicma_descCD, hicma_descCrk, 0, data->hicma_maxrank, pow(10, -1.0 * data->hicma_acc));
//        if (success != MORSE_SUCCESS) {
//                  printf("Factorization cannot be performed..\n The matrix is not positive definite\n\n");
//                        exit(EXIT_FAILURE);
//                }
//               if (data->verbose == 1 && MORSE_My_Mpi_Rank() == 0)
//                        fprintf(stderr, " Done.\n");

//For checking accuracy
//if(data->check==1 && n<10000)
//{
//acc=check_acc(data, n, ts);
//printf("normA:%.2e normDenseAppdiff:%.2e Accuracy: %.2e\n", acc.normA, acc.normDenseAppDiff,  acc.accuracyDenseAppDiff);
//}


//        exit(0);  //till dtrmv availability from HicMA    
//dtrmm is not supported yet by HiCMA

//Triangular solve dtrmm    
//            if (data->verbose == 1 && MORSE_My_Mpi_Rank() == 0)
//            fprintf(stderr, "LR:Triangular Solve dtrmm Z=L.e (Synthetic Dataset Generation Phase) .....");
//            MORSE_dtrmm_Tile(MorseLeft, MorseLower, MorseNoTrans, MorseNonUnit, 1, data->descC, data->descZ);
//            if (data->verbose == 1 && MORSE_My_Mpi_Rank() == 0)
//                      fprintf(stderr, " Done.\n");

//        if(log==1)
//        {
//                MORSE_desc_t *MORSE_descZ = (MORSE_desc_t *)(data->descZ);
//                write_vectors(MORSE_descZ->mat, data, n);
//        }

//    }
//    else
//    {
//        double * streamdata;

//        if (data->verbose == 1 && MORSE_My_Mpi_Rank() == 0)
//            fprintf(stderr,"Reading Observations from disk .....");

//        streamdata=(double *) malloc(n * sizeof(double));
//        streamdata = readObsFile(data->obsFPath, n);        
//                MORSE_MLE_dzcpy_Tile_Async(data->descZ, streamdata, data->sequence, &data->request[0]);

//        if (data->verbose == 1 && MORSE_My_Mpi_Rank() == 0)
//                  fprintf(stderr, "LR: Done.\n");

//        free(streamdata);
//    }

//Save a copy of descZ into descZcpy for restoring each iteration
//MORSE_dlacpy_Tile(MorseUpperLower, data->descZ, data->descZcpy);


//    if (data->verbose == 1 && MORSE_My_Mpi_Rank() == 0)
//    {
//          fprintf(stderr, "LR:Done Z Vector Generation Phase. (Chameleon Synchronous)\n");
//            fprintf(stderr, "LR:************************************************************\n");
//    }    

//    return 0;

//}




int HICMA_MLE_dzvg_Tile_Async (MLE_data *data,  double * Nrand, double * initial_theta, int n, int dts, int log, int p_grid, int q_grid) {
    //! Generate Observations Vector (Z) for testing Maximum
    /*! Likelihood function -- HICMA-async
     * Returns Z observation vector
     * @param[in] data: MLE_data struct with different MLE inputs.
     * @param[in] Nrand: A uniform random vector with size n that is used to generate Z .
     * @param[in] initial_theta: Theta vector with three parameter (Variance, Range, Smoothness)
     *                           that is used to to generate the Covariance Matrix.
     * @param[in] n: Problem size (number spatial locations).
     * @param[in] dts: tile size (MB) is used only in the case of HiCMA not MORSE.
     * @param[in] log: equals one if the user needs to generate log files for his problem.
     * @param[in] p_grid: p_grid in the case of distributed system.
     * @param[in] q_grid: q_grid in the case of distributed system.
     * */
    //Initialization
    MORSE_sequence_t *msequence;
    MORSE_request_t  mrequest[2]    = { MORSE_REQUEST_INITIALIZER, MORSE_REQUEST_INITIALIZER };
    MORSE_desc_t *MORSE_descC       = NULL;
    MORSE_desc_t *MORSE_descZ       = NULL;


    //Create two dense descriptors to generate the measurment vectors
    MORSE_Sequence_Create(&msequence);
    EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&MORSE_descC, NULL, MorseRealDouble, dts, dts, dts * dts, n, n, 0, 0, n, n, p_grid, q_grid);
    EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&MORSE_descZ, NULL, MorseRealDouble, dts, dts, dts * dts, n, 1, 0, 0, n, 1, p_grid, q_grid);


    //Generate the co-variance matrix C
    VERBOSE("LR: Initializing Covariance Matrix (Synthetic Dataset Dense Generation Phase).....");
    MORSE_MLE_dcmg_Tile_Async(MorseLower, MORSE_descC,  &data->l1, &data->l1, &data->lm, initial_theta, data->dm, data->kernel_fun, msequence, mrequest);
    VERBOSE(" Done.\n");

    //Copy Nrand to Z
    VERBOSE("LR: Generate Normal Random Distribution Vector Z (Synthetic Dataset Dense Generation Phase) .....");
    MORSE_MLE_dzcpy_Tile_Async(MORSE_descZ, Nrand, msequence, mrequest);
    VERBOSE(" Done.\n");

    //Cholesky factorization for the Co-variance matrix C
    VERBOSE("LR: Cholesky factorization of Sigma (Synthetic Dataset Dense Generation Phase) .....");
    int success = MORSE_dpotrf_Tile_Async(MorseLower, MORSE_descC, msequence, mrequest);
    SUCCESS(success, "LR: Factorization cannot be performed..\n The matrix is not positive definite\n\n");
    VERBOSE(" Done.\n");

    //Triangular matrix-matrix multiplication
    VERBOSE("LR: Triangular matrix-matrix multiplication Z=L.e (Synthetic Dataset Dense Generation Phase) .....");
    MORSE_dtrmm_Tile_Async(MorseLeft, MorseLower, MorseNoTrans, MorseNonUnit, 1, MORSE_descC, MORSE_descZ, msequence, mrequest);
    VERBOSE(" Done.\n");

    //if log==1 write vector to disk
    if(log==1)
    {
        double *z;
#if defined(CHAMELEON_USE_MPI)
        z = (double *) malloc(n * sizeof(double));
        MORSE_Tile_to_Lapack( MORSE_descZ, z, n);
#else
        z = MORSE_descZ->mat;
#endif
        write_vectors(z, data, n);
#if defined(CHAMELEON_USE_MPI)
        free(z);
#endif
    }

    VERBOSE("LR: Done Z Vector Dense Generation Phase. (Chameleon Synchronous)\n");
    VERBOSE("************************************************************\n");


    data->descZ     = MORSE_descZ;
    data->sequence  = msequence;
    data->request   = mrequest;
    //Destory dense descriptors to save memory.
    MORSE_Desc_Destroy(&MORSE_descC);
    return 0;

}


//compute MLE function
double HICMA_dmle_Tile(unsigned n, const double * theta, double * grad, void * app_data) 
//! Maximum Likelihood Evaluation (MLE)
    /*!  -- HICMA-sync
     * Returns the loglikelihhod value for the given theta.
     * @param[in] n: unsigned variable used by NLOPT library.
     * @param[in] theta: theta Vector with three parameter (Variance, Range, Smoothness)
     *                           that is used to to generate the Covariance Matrix.
     * @param[in] grad: double variable used by NLOPT library.
     * @param[in] app_data: MLE_data struct with different MLE inputs.
     * */
{
    //Initialization
    double loglik        = 0.0;
    int compress_diag    = 0;
    //double  ddotproduct    = 0.0,
    double    logdet        = 0.0;
    double time_facto    = 0.0,
           time_solve    = 0.0,
           logdet_calculate    = 0.0,
           matrix_gen_time    = 0.0,
           test_time    = 0.0;
    double flops        = 0.0;
    int success, maxrank, acc;
    //int verbose;
    int  N, NRHS;
    int lts;//, dts;
    int hicma_data_type;
    int i = 0;
    int num_params=0;
    MLE_data *data            = (MLE_data*) app_data;        
    MORSE_desc_t *hicma_descC    = (MORSE_desc_t *)    data->hicma_descC;
    MORSE_desc_t *hicma_descCD    = (MORSE_desc_t *)    data->hicma_descCD;
    MORSE_desc_t *hicma_descCUV    = (MORSE_desc_t *)    data->hicma_descCUV;
    MORSE_desc_t *hicma_descCrk    = (MORSE_desc_t *)    data->hicma_descCrk;
    MORSE_desc_t *hicma_descZ     = (MORSE_desc_t *)    data->hicma_descZ;
    MORSE_desc_t *morse_descZ       = (MORSE_desc_t *)      data->descZ;    
    MORSE_desc_t *hicma_descZcpy    = (MORSE_desc_t *)    data->hicma_descZcpy;
    MORSE_desc_t *hicma_descdet     = (MORSE_desc_t *)    data->hicma_descdet;
    MORSE_desc_t *hicma_descproduct = (MORSE_desc_t *)    data->hicma_descproduct;
    MORSE_sequence_t *hsequence     = (MORSE_sequence_t *)    data->hsequence;
    MORSE_request_t  *hrequest      = (MORSE_request_t *)    data->hrequest;
    if(strcmp(data->kernel_fun, "univariate_matern_stationary")   == 0 || strcmp(data->kernel_fun, "univariate_pow_exp_stationary")   == 0 )
        num_params = 3;
    else if(strcmp(data->kernel_fun, "univariate_matern_nuggets_stationary")   == 0)
        num_params = 4;
    else if(strcmp(data->kernel_fun, "univariate_matern_non_stationary")   == 0)
        num_params = 9;
    else if(strcmp(data->kernel_fun, "bivariate_matern_flexible")   == 0)
        num_params = 11;
    else if(strcmp(data->kernel_fun, "bivariate_matern_parsimonious")   == 0)
        num_params = 6;
    else if(strcmp(data->kernel_fun, "bivariate_matern_parsimonious2")   == 0)
        num_params = 6;
    else if(strcmp(data->kernel_fun, "bivariate_matern_parsimonious_profile")   == 0)
        num_params = 6;
    else if(strcmp(data->kernel_fun, "bivariate_matern_parsimonious2_profile")   == 0)
        num_params = 6;
    else
    {
        fprintf(stderr,"Choosen kernel is not exist(2)!\n");
        fprintf(stderr, "Called function is: %s\n",__func__);
        exit(0);
    }    
    //to be removed
    /*	for(i=0;i<num_params; i++)
        {
        printf("%.8f", theta[i]);
        if (i <num_params-1)
        printf(",");
        }
        */
    //verbose               = data->verbose;
    N                      = hicma_descCD->m;
    NRHS                = hicma_descZ->n;
    lts                    = hicma_descZ->mb;  
    //dts                = morse_descZ->mb;
    maxrank                = ((MLE_data*)data)->hicma_maxrank;
    acc                    = ((MLE_data*)data)->hicma_acc;
    hicma_data_type            = ((MLE_data*)data)->hicma_data_type;
    data->det              = 0;
    data->dotp             = 0;




    //Save a copy of descZ into descZcpy for restoring each iteration
    if (data->iter_count == 0)
    {

        if (strcmp(data->locsFPath, "") == 0)
        {
            double *z = (double *) malloc(N * sizeof(double));
            MORSE_Tile_to_Lapack( morse_descZ, z, N);
            MORSE_Lapack_to_Tile( z, N, hicma_descZ);
            free(z);
            MORSE_Desc_Destroy(&morse_descZ);
        }
        MORSE_dlacpy_Tile(MorseUpperLower, hicma_descZ, hicma_descZcpy);
    }
    if(strcmp(data->recovery_file,"") != 0 && recover(data->recovery_file, data->iter_count, theta, &loglik, num_params));

    else{
        //Save a copy of descZ into descZcpy for restoring each iteration

        //Matrix generation part.       
        VERBOSE("LR:Generate New Covariance Matrix...");
        START_TIMING(matrix_gen_time);

        HICMA_problem_t hicma_problem;
        hicma_problem.theta= (double *)theta;
        hicma_problem.noise    = 1e-4;
        hicma_problem.ndim    = 2;

        //printf("N:%d\n", N);
        //exit(0);
        // I need to change the location struct to vector array (TO DO)
        double *xycoord = (double *) malloc( 2 * N * sizeof(double));

        //printf("N=%d\n", N);
        if(strcmp(data->kernel_fun, "bivariate_matern_parsimonious")   == 0 ||
                strcmp(data->kernel_fun, "bivariate_matern_parsimonious_profile")   == 0)
        {	    int j =0;
            for (i = 0; i < N; i++)
            {
                xycoord[i] = data->l1.x[j];
                xycoord[N+i] = data->l1.y[j];
                if(i % 2 != 0)
                    j++;
            }
            hicma_problem.kernel_type = strcmp(data->dm, "gc") == 0? STARSH_SPATIAL_PARSIMONIOUS_GCD : STARSH_SPATIAL_PARSIMONIOUS_SIMD;
        }
        else if(strcmp(data->kernel_fun, "bivariate_matern_parsimonious2")   == 0 ||
                strcmp(data->kernel_fun, "bivariate_matern_parsimonious2_profile")   == 0)
        {
            int j =0;
            for (i = 0; i < N; i++)
            {
                if(i == N/2)
                    j = 0;
                xycoord[i] = data->l1.x[j];
                xycoord[N+i] = data->l1.y[j];
                j++;
            }
            hicma_problem.kernel_type = strcmp(data->dm, "gc") == 0? STARSH_SPATIAL_PARSIMONIOUS2_GCD : STARSH_SPATIAL_PARSIMONIOUS2_SIMD;
        }

        else
        {	    for (i = 0; i < N; i++)
            {
                xycoord[i] = data->l1.x[i];
                xycoord[N+i] = data->l1.y[i];
            }

            hicma_problem.kernel_type = strcmp(data->dm, "gc") == 0? STARSH_SPATIAL_MATERN2_GCD : STARSH_SPATIAL_MATERN2_SIMD;
        }
        /*
           if( strcmp(data->dm, "gc") == 0)
           printf("gcd metric is used: %d\n", STARSH_SPATIAL_MATERN2_GCD);
           else
           printf("ed metric is used: %d\n", STARSH_SPATIAL_MATERN2_SIMD);
           */
        hicma_problem.point    =  xycoord;
        HICMA_zgenerate_problem(hicma_data_type, 'S', 0, N, lts, hicma_descCUV->mt, hicma_descCUV->nt, &hicma_problem);
        mpiF = hicma_problem.starsh_format; 
        HICMA_zgytlr_Tile(MorseLower, hicma_descCUV, hicma_descCD, hicma_descCrk, 0, maxrank, pow(10, -1.0 * acc), compress_diag, hicma_descC);    
        STOP_TIMING(matrix_gen_time);
        VERBOSE(" Done.\n");





        // MORSE_MLE_dcmg_Tile_Async(MorseLower, MORSE_descC, msequence, &mrequest[0], &data->l1, &data->l1, (double *)theta,  data->dm);
        //***************** check matrices
        //double *AA = (double *) malloc(N * N *sizeof(double));
        //double *BB = (double *) malloc(N * N * sizeof(double));
        // MORSE_Tile_to_Lapack(hicma_descC, BB, N);
        //MORSE_desc_t *descDense = ((MLE_data*)data)->descC;
        //HICMA_zuncompress(MorseUpperLower, hicma_descCUV, descDense, hicma_descCrk);
        //HICMA_zdiag_vec2mat(hicma_descCD, descDense);
        //MORSE_Tile_to_Lapack(descDense, AA, N);
        //int i=0;
        //double sum =0;
        //for ( i = 0;i< n*n ;i++)
        //sum += abs(AA[i]-BB[i]);
        //printf("Sum= %f \n", sum);     
        //exit(0);    
        //******************************
        VERBOSE("LR: re-Copy z...");    
        START_TIMING(test_time);
        //re-store old Z
        MORSE_dlacpy_Tile(MorseUpperLower, hicma_descZcpy, hicma_descZ);
        STOP_TIMING(test_time);
        VERBOSE(" Done.\n");

        //*************
        /*
           if(((MLE_data*)data)->check == 1 )
           {
           if (((MLE_data*)data)->verbose == 1 && MORSE_My_Mpi_Rank() == 0)
           fprintf(stderr, "LR: allocating and coping original covariance matrix for accuracy checking (Synthetic Dataset Generation Phase) .....");
           ((MLE_data*)data)->Adense    = (double *) malloc(N * N * sizeof(double));
           ((MLE_data*)data)->Adense2   = (double *) malloc(N * N * sizeof(double));
        //printf("%d - %d\n",MORSE_descC->m,MORSE_descC->n);
        MORSE_Tile_to_Lapack(MORSE_descC, ((MLE_data*)data)->Adense, N);
        MORSE_Tile_to_Lapack(MORSE_descC, ((MLE_data*)data)->Adense2, N);
        //fprintf(stderr," %6.4e", data->Adense[0]);
        //print_matrix("test Hicma",n, n, data->Adense, n);
        //PASTE_TILE_TO_LAPACK( MORSE_descC, data->Adense, data->check, double, M, M);
        //PASTE_TILE_TO_LAPACK( MORSE_descC, data->Adense2, data->check, double, M, M);
        if (((MLE_data*)data)->verbose == 1 && MORSE_My_Mpi_Rank() == 0)
        fprintf(stderr, " Done.\n");
        }
        */
        //**************
        //Calculate Cholesky Factorization (C=LL-1)
        VERBOSE("LR: Cholesky factorization of Sigma...");    
        START_TIMING(time_facto);
        //success = MORSE_dpotrf_Tile(MorseLower, MORSE_descC);
        //HICMA_set_print_index();
        success = HICMA_zpotrf_Tile(MorseLower, hicma_descCUV, hicma_descCD, hicma_descCrk, 0, maxrank, pow(10, -1.0 * acc));
        //printf("%s %d EARLY EXIT\n", __FILE__, __LINE__); exit(0);//@KA
        SUCCESS(success, "LR: Factorization cannot be performed..\n The matrix is not positive definite\n\n");
        STOP_TIMING(time_facto);
        flops = flops + FLOPS_DPOTRF(N);
        VERBOSE(" Done.");
        //For checking accuracy
        //if(((MLE_data*)data)->check == 1 )
        //{
        //        acc_struct  acc_s = check_acc(data, N, ts);
        //        printf("normA:%.2e normDenseAppdiff:%.2e Accuracy: %.2e\n", acc_s.normA, acc_s.normDenseAppDiff,  acc_s.accuracyDenseAppDiff);
        // }

        //***************Kadir  (should be removed)
        //double * ranks   = (double *) malloc( hicma_descCrk->mt * hicma_descCrk->nt * sizeof(double));
        //MORSE_Tile_to_Lapack(hicma_descCrk, ranks, hicma_descCrk->mt);
        //HICMA_stat_t hicma_statrk_initial;
        //zget_stat(MorseLower, ranks, hicma_descCrk->mt, hicma_descCrk->nt, hicma_descCrk->mt,  &hicma_statrk_initial);
        //printf("After LR cholesky max rank: %d\n", hicma_statrk_initial.max);
        //*********

        //Calculate log(|C|) --> log(square(|L|))
        VERBOSE("LR:Calculating the log determinant ...");
        START_TIMING(logdet_calculate);
        data->det    = 0;
        HICMA_MLE_dmdet_Tile_Async(hicma_descCD, hsequence, &hrequest[0], hicma_descdet);
        MORSE_Sequence_Wait(hsequence);
        logdet        = 2 * data->det;
        STOP_TIMING(logdet_calculate);
        VERBOSE(" Done.");

        //Solving Linear System (L*X=Z)--->inv(L)*Z
        VERBOSE("LR:Solving the linear system ...");    
        START_TIMING(time_solve);
        //Compute triangular solve LC*X = Z
        //MORSE_dtrsm_Tile(MorseLeft,MorseLower,MorseNoTrans,MorseNonUnit,1,MORSE_descC,MORSE_descZ);
        HICMA_ztrsmd_Tile(MorseLeft, MorseLower, MorseNoTrans, MorseNonUnit, 1, hicma_descCUV, hicma_descCD, hicma_descCrk, hicma_descZ, maxrank); 
        STOP_TIMING(time_solve);
        flops = flops + FLOPS_DTRSM(MorseLeft, N, NRHS);
        VERBOSE(" Done.");


        VERBOSE("LR:Calculating dot product...");
        MORSE_dgemm_Tile (MorseTrans, MorseNoTrans, 1, hicma_descZ, hicma_descZ, 0, hicma_descproduct); 
        loglik = -0.5 * ((MLE_data*)data)->dotp -  0.5*logdet - (double) (N / 2.0) * log(2.0 * PI);
        //  loglik = -(N /2) + (N /2)*log (N) -(N / 2 ) * log(data->dotp) -  0.5*logdet - (double) (N / 2.0) * log(2.0 * PI);
        VERBOSE(" Done.");


        //Calculate the ranks
        if(calc_rank_stat == 1) {
            int i       = 0;
            int MBrk    = 1;
            int NBrk    = 1;
            int Mrk    = hicma_descCUV->mt;
            int Nrk    = hicma_descCUV->mt;
            if (data->iter_count == 0)
            {
                Ark_initial = (double *) calloc( Mrk * Nrk, sizeof(double));
                Ark_old = (double *) calloc( Mrk * Nrk, sizeof(double));
            }
            MORSE_Tile_to_Lapack( hicma_descCrk, Ark_initial, Mrk);
            for(i=0;i<Mrk * Nrk;i++)
            {
                if(Ark_initial[i] > Ark_old[i])
                {
                    Ark_old[i] = Ark_initial[i];
                }
            }

            if(MORSE_My_Mpi_Rank()==0){
                fwrite_array(hicma_descCrk->m, hicma_descCrk->n, hicma_descCrk->m, Ark_old,"ranks.csv");
                print_array(hicma_descCrk->m, hicma_descCrk->n, hicma_descCrk->m, Ark_old, stdout);
                HICMA_stat_t hicma_statrk_initial;
                zget_stat(MorseLower, Ark_old, Mrk, Nrk, Mrk,  &hicma_statrk_initial);
                zprint_stat(hicma_statrk_initial);
                fflush(stderr);
                fflush(stdout);
            }
        }

        //multiplicative scale
        //    data->variance = (1.0/N) * data->dotp;
        data->variance = theta[0];
    }
#if defined(CHAMELEON_USE_MPI)
    MPI_Bcast(&loglik,1, MPI_DOUBLE, 0, MPI_COMM_WORLD );
    //MPI_Bcast(theta,num_params, MPI_DOUBLE, 0, MPI_COMM_WORLD );

    if(MORSE_My_Mpi_Rank() == 0)
    {
#endif
        //Print Iteration Summary
        //fprintf(stderr,"***************************************************\n");
        //fprintf(stderr,"\n------ddotproduct: %.8f ", ((MLE_data*)data)->dotp);
        //fprintf(stderr,"\n------logdet: %.8f ", logdet);
        //fprintf(stderr,"------det: %.*e ", det);
        //fprintf(stderr,"\n------expr2: %.8f ",((double) (N / 2) * log(2 * PI)));
        //fprintf(stderr," ---- Theta1: %.8f ----  Theta2: %.8f ---- Theta3: %.8f ----LogLi: %.8f\n", theta[0], theta[1], theta[2],loglik);

        //	if(strcmp(data->checkpoint_file,"") != 0)
        //		checkpointing(data->checkpoint_file, data->iter_count, theta, loglik, num_params);

        printf(" %3d- Model Parameters (",  ((MLE_data*)data)->iter_count+1);

        if(data->log == 1)
            fprintf(((MLE_data*)data)->pFileLog, " %3d- Model Parameters (",  ((MLE_data*)data)->iter_count+1);

        if(strcmp(((MLE_data*)data)->kernel_fun, "bivariate_matern_parsimonious_profile")   == 0 || strcmp(((MLE_data*)data)->kernel_fun, "bivariate_matern_parsimonious2_profile")   == 0)
        {
            printf("%.8f, %.8f,", ((MLE_data*)data)->variance1, ((MLE_data*)data)->variance2);
            i = 2;
            results.estimated_theta[0] = data->variance1;
            results.estimated_theta[1] = data->variance2;
        }
        else
            i=0;
        for(;i<num_params; i++)
        {
            printf("%.8f", theta[i]);
            if (i <num_params-1)
                printf(",");
            results.estimated_theta[i] = theta[i];

            if(((MLE_data*)data)->log == 1)
                fprintf(((MLE_data*)data)->pFileLog,"%.8f, ", theta[i]);
        }

        printf(")----> LogLi: %.18f\n", loglik);
        if(((MLE_data*)data)->log == 1)
            fprintf(((MLE_data*)data)->pFileLog, ")----> LogLi: %.18f\n", loglik);
        fprintf(stderr," ---- Facto Time: %.8f\n", time_facto);
        //fprintf(stderr," ---- logdet Time: %.8f\n", logdet_calculate);
        fprintf(stderr," ---- dtrsm Time: %.8f\n", time_solve);
        fprintf(stderr," ---- Matrix Generation Time: %.8f\n", matrix_gen_time);
        //fprintf(stderr," ---- re-store Z Vector Time: %.8f\n", test_time);
        fprintf(stderr," ---- Total Time: %.8f\n", matrix_gen_time+time_facto + logdet_calculate + time_solve);
        fprintf(stderr," ---- Gflop (ignore): %.8f\n", flops / 1e9 );    
        //fprintf(stderr," ---- Gflop/s: %.8f\n", flops / 1e9 / (time_facto  + time_solve));
        //fprintf(stderr," ---- Peak Performance: %.8f Gflops/s\n",  (ncores*p_grid*q_grid*1.8.3) );
        //fprintf(stderr,"***************************************************\n");
#if defined(CHAMELEON_USE_MPI)
    }
#endif

    ((MLE_data*)data)->iter_count++;
    // for experiments
    ((MLE_data*)data)->avg_exec_time_per_iter+=/*matrix_gen_time+*/time_facto + logdet_calculate + time_solve;
    ((MLE_data*)data)->avg_flops_per_iter+=flops / 1e9 / (time_facto +time_solve);
    ((MLE_data*)data)->final_loglik=loglik;

    results.final_loglik=loglik;
    return loglik;
}

double HICMA_dmle_Tile_Async(unsigned n, const double * theta, double * grad, void * data) {
    //! Maximum Likelihood Evaluation (MLE)
    /*!  -- HICMA-async
     * Returns the loglikelihhod value for the given theta.
     * @param[in] n: unsigned variable used by NLOPT library.
     * @param[in] theta: theta Vector with three parameter (Variance, Range, Smoothness)
     *                           that is used to to generate the Covariance Matrix.
     * @param[in] grad: double variable used by NLOPT library.
     * @param[in] data: MLE_data struct with different MLE inputs.
     * */

    //Initialization
    /*        double loglik        = 0.0;
              double ddotproduct    = 0.0,
              logdet        = 0.0,
              compress_diag    = 0.0;
              double time_facto    = 0.0,
              time_solve     = 0.0,
              logdet_calculate = 0.0,
              matrix_gen_time  = 0.0,
              test_time    = 0.0;
              double flops         = 0.0;
              int success, maxrank, acc;
              int verbose, N, NRHS;
              int ts;

              MORSE_desc_t *MORSE_descC    = (MORSE_desc_t *)((MLE_data*)data)->descC;
              MORSE_desc_t *hicma_descCD    = (MORSE_desc_t *)((MLE_data*)data)->hicma_descCD;
              MORSE_desc_t *hicma_descCUV    = (MORSE_desc_t *)((MLE_data*)data)->hicma_descCUV;
              MORSE_desc_t *hicma_descCrk    = (MORSE_desc_t *)((MLE_data*)data)->hicma_descCrk;
              MORSE_desc_t *MORSE_descZ     = (MORSE_desc_t *)((MLE_data*)data)->descZ;
              MORSE_desc_t *MORSE_descZcpy     = (MORSE_desc_t *)((MLE_data*)data)->descZcpy;
              MORSE_desc_t *MORSE_descdet     = (MORSE_desc_t *)((MLE_data*)data)->descdet;
              MORSE_desc_t *MORSE_descproduct = (MORSE_desc_t *)((MLE_data*)data)->descproduct;
              MORSE_sequence_t *msequence     = (MORSE_sequence_t *)((MLE_data*)data)->sequence;
              MORSE_request_t  *mrequest      = (MORSE_request_t *)((MLE_data*)data)->request;
              verbose         = ((MLE_data*)data)->verbose;
              N             = hicma_descCD->m;
              NRHS               = MORSE_descZ->n;
              ts              = MORSE_descZ->mt;  //should be preinted to check
              maxrank         = ((MLE_data*)data)->hicma_maxrank;
              acc                = ((MLE_data*)data)->hicma_acc;
              ((MLE_data*)data)->det  = 0.0;
              ((MLE_data*)data)->dotp = 0.0;
              if (((MLE_data*)data)->iter_count==0)
    //Save a copy of descZ into descZcpy for restoring each iteration
    MORSE_dlacpy_Tile_Async(MorseUpperLower ,MORSE_descZcpy,MORSE_descZ,msequence,&mrequest[0]);
    //Generate new co-variance matrix C based on new theta
    if (verbose == 1 && MORSE_My_Mpi_Rank() == 0)
    fprintf(stderr, "LR:Generate New Covariance Matrix...");
    START_TIMING(matrix_gen_time);
    //MORSE_MLE_cmg_Tile_Async(MORSE_descC, msequence, &mrequest[0], &((MLE_data*)data)->l1, &((MLE_data*)data)->l1, theta,  ((MLE_data*)data)->dm);
    //ddcay is any vale for GEOSTAT (not used)
    HICMA_problem_t hicma_problem;
    hicma_problem.theta    = (double *)theta;
    hicma_problem.noise    = 0.0;
    hicma_problem.ndim    = 2;
    HICMA_zgenerate_problem(HICMA_STARSH_PROB_GEOSTAT, 'S', 0, n, ts, hicma_descCUV->mt, hicma_descCUV->nt, &hicma_problem);
    mpiF             = hicma_problem.starsh_format;    
    HICMA_zgytlr_Tile_Async(MorseLower, hicma_descCUV, hicma_descCD, hicma_descCrk, 0, maxrank, pow(10, -1.0 * acc), compress_diag, MORSE_descC, msequence, &mrequest[0]);
    STOP_TIMING(matrix_gen_time);
    if (verbose == 1 && MORSE_My_Mpi_Rank() == 0)
    fprintf(stderr, " Done.\n");    
    //Re-store old Z
    if (verbose == 1 && MORSE_My_Mpi_Rank() == 0)
    fprintf(stderr, "LR: Re-Copy z...");
    START_TIMING(test_time);
    MORSE_dlacpy_Tile_Async(MorseUpperLower, MORSE_descZcpy, MORSE_descZ, msequence, &mrequest[0]);
    STOP_TIMING(test_time);
    if (verbose == 1 && MORSE_My_Mpi_Rank() == 0)
    fprintf(stderr, " Done.\n");
    //Calculate Cholesky Factorization (C=LL-1)
    if (verbose == 1 && MORSE_My_Mpi_Rank() == 0)
    fprintf(stderr, "LR: Cholesky factorization of Sigma...");
    START_TIMING(time_facto);
    //success = MORSE_dpotrf_Tile(MorseLower, MORSE_descC);
    success = HICMA_zpotrf_Tile_Async(MorseLower, hicma_descCUV, hicma_descCD, hicma_descCrk, 0, maxrank, pow(10, -1.0 * acc), msequence, &mrequest[0]);
    STOP_TIMING(time_facto);
    if (success != MORSE_SUCCESS) {
    fprintf(stderr,"Factorization cannot be performed..\n"
    "The matrix is not positive definite\n\n");
    exit(0);
    }
    flops = flops + FLOPS_DPOTRF(N);
    if (verbose == 1 && MORSE_My_Mpi_Rank() == 0)
        fprintf(stderr, "LR: Done.\n");
    //Calculate log(|C|) --> log(square(|L|))
    if (verbose == 1 && MORSE_My_Mpi_Rank() == 0)
        fprintf(stderr, "LR:Calculating the log determinant ...");
    START_TIMING(logdet_calculate);
    ((MLE_data*)data)->det = 0;
    MORSE_MLE_dmdet_Tile_Async(MORSE_descC, msequence, &mrequest[0],MORSE_descdet);
    MORSE_Sequence_Wait(msequence);
    logdet = 2 * ((MLE_data*)data)->det;
    STOP_TIMING(logdet_calculate);
    if (verbose == 1 && MORSE_My_Mpi_Rank() == 0)
        fprintf(stderr, "LR: Done.\n");
    //Solving Linear System (L*X=Z)--->inv(L)*Z
    if (verbose == 1 && MORSE_My_Mpi_Rank() == 0)
        fprintf(stderr, "LR: Solving the linear system ...\n");
    START_TIMING(time_solve);
    //Compute triangular solve LC*X = Z
    //MORSE_dtrsm_Tile_Async(MorseLeft,MorseLower,MorseNoTrans,MorseNonUnit,1,MORSE_descC,MORSE_descZ,msequence,&mrequest[0]);
    HICMA_ztrsmd_Tile_Async( MorseLeft, MorseLower, MorseNoTrans, MorseNonUnit, 1, hicma_descCUV, hicma_descCD, hicma_descCrk, MORSE_descZ, maxrank, msequence, &mrequest[0]);    
    STOP_TIMING(time_solve);
    flops = flops + FLOPS_DTRSM(MorseLeft,N, NRHS);
    if (verbose == 1 && MORSE_My_Mpi_Rank() == 0)
        fprintf(stderr, " Done.\n");
    if (verbose == 1 && MORSE_My_Mpi_Rank() == 0)
        fprintf(stderr, "LR:Calculating dot product...");
    //dotp=0;
    //MORSE_MLE_core_ddotp_Async(MORSE_descZ,MORSE_descproduct,msequence, &mrequest[0]);
    //MORSE_Sequence_Wait(msequence);
    //((MLE_data*)data)->dotp=0;    
    MORSE_dgemm_Tile_Async(MorseTrans, MorseNoTrans, 1, MORSE_descZ, MORSE_descZ, 0, MORSE_descproduct,msequence,&mrequest[0]);
    //fprintf(stderr,"sucess: %d", success);
    //exit(0);
    loglik = -0.5 * ((MLE_data*)data)->dotp -  0.5*logdet - (double) (N / 2.0) * log(2.0 * PI);
    if (verbose == 1 && MORSE_My_Mpi_Rank() == 0)
        fprintf(stderr, "LR: Done.\n");
#if defined(CHAMELEON_USE_MPI)
    MPI_Bcast(&loglik,1, MPI_DOUBLE, 0, MPI_COMM_WORLD );
    MPI_Bcast(theta,3, MPI_DOUBLE, 0, MPI_COMM_WORLD );
    if(MORSE_My_Mpi_Rank() == 0)
    {
#endif
        //Print Iteration Summary
        //fprintf(stderr,"***************************************************\n");
        //fprintf(stderr,"------ddotproduct: %.8f ", ((MLE_data*)data)->dotp);
        //fprintf(stderr,"------logdet: %.8f ", logdet);
        //fprintf(stderr,"------det: %.*e ", det);
        //fprintf(stderr,"------expr2: %.8f ",((double) (N / 2) * log(2 * PI)));
        //fprintf(stderr," ---- Theta1: %.8f ----  Theta2: %.8f ---- Theta3: %.8f ----LogLi: %.8f\n", theta[0], theta[1], theta[2],loglik);
        fprintf(stderr," %3d- Model Parameters (varinace, range, smoothness): (%.8f, %.8f, %.8f) ----> LogLi: %.8f\n", ((MLE_data*)data)->iter_count+1,  theta[0], theta[1], theta[2],loglik);
        if(((MLE_data*)data)->log == 1)
            fprintf(((MLE_data*)data)->pFileLog, " %3d- Model Parameters (varinace, range, smoothness): (%.8f, %.8f, %.8f) ----> LogLi: %.8f\n", ((MLE_data*)data)->iter_count+1,  theta[0], theta[1], theta[2],loglik);
        //fprintf(stderr," ---- Facto Time: %.8f\n", time_facto);
        //fprintf(stderr," ---- logdet Time: %.8f\n", logdet_calculate);
        //fprintf(stderr," ---- dtrsm Time: %.8f\n", time_solve);
        //fprintf(stderr," ---- Matrix Generation Time: %.8f\n", matrix_gen_time);
        //fprintf(stderr," ---- re-store Z Vector Time: %.8f\n", test_time);
        //fprintf(stderr," ---- Total Time: %.8f\n", matrix_gen_time+time_facto + logdet_calculate + time_solve);
        //fprintf(stderr," ---- Gflop (ignore): %.8f\n", flops / 1e9 );
        //fprintf(stderr," ---- Gflop/s: %.8f\n", flops / 1e9 / (time_facto  + time_solve));
        //fprintf(stderr," ---- Peak Performance: %.8f Gflops/s\n",  (ncores*p_grid*q_grid*1.8.3) );
        //fprintf(stderr,"***************************************************\n");
#if defined(CHAMELEON_USE_MPI)
    }
#endif

    ((MLE_data*)data)->iter_count++;
    // for experiments
    ((MLE_data*)data)->avg_exec_time_per_iter+=matrix_gen_time+time_facto + logdet_calculate + time_solve;
    ((MLE_data*)data)->avg_flops_per_iter+=flops / 1e9 / (time_facto +time_solve);
    ((MLE_data*)data)->final_loglik=loglik;
    return loglik;
    */
}

void HICMA_dmle_Predict_Allocate(MLE_data *MORSE_data, int nZmiss, int nZobs, int lts, int p_grid, int q_grid, int mse_flag)
    //! Allocate prediction operation descriptors.
    /*!
     * Returns MLE_data data with initial values and new descriptors locations.
     * @param[in] MORSE_data: MLE_data struct with different MLE inputs.
     * @param[in] nZmiss: number of missing values (unknown observations).
     * @param[in] nZobs: number of observed values (known observations).
     * @param[in] dts: tile size (MB).
     * @param[in] p_grid: p_grid in the case of distributed system.
     * @param[in] q_grid: q_grid in the case of distributed system.
     * @param[in] mse_flag: flag to enable or disable Mean Square Error (MSE) computing.
     * */
{
    int MBC, NBC, MC, NC;
    int MBD, NBD, MD, ND;
    int MBUV, NBUV, MUV, NUV;
    int MBrk, NBrk, Mrk, Nrk;
    MORSE_desc_t *MORSE_descZmiss   = NULL;
    MORSE_desc_t *hicma_descC       = NULL;
    MORSE_desc_t *MORSE_descC12     = NULL;
    MORSE_desc_t *hicma_descC22D    = NULL;
    MORSE_desc_t *hicma_descC22UV   = NULL;
    MORSE_desc_t *hicma_descC22rk   = NULL;
    MORSE_desc_t *MORSE_descmse     = NULL;
    MORSE_desc_t *MORSE_descZactual = NULL;
    MORSE_desc_t *MORSE_descZobs    = NULL;

    MLE_data     *data              = (MLE_data*) MORSE_data;

    if(nZmiss <= 0)
    {
        fprintf(stderr," Number of missing values should be positive value\n");
        return;
    }

    //Descriptors Creation
    EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&MORSE_descZobs, NULL, MorseRealDouble, lts, lts, lts * lts, nZobs, 1, 0, 0, nZobs, 1, p_grid, q_grid);

    if( mse_flag == 1)
    {
        EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&MORSE_descZactual, NULL, MorseRealDouble, lts, lts, lts * lts,  nZmiss, 1,  0, 0, nZmiss, 1, p_grid, q_grid);
        EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&MORSE_descmse, &data->mserror, MorseRealDouble, lts, lts, lts * lts, 1, 1, 0, 0, 1, 1, p_grid, q_grid);
    }
    EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&MORSE_descZmiss, NULL, MorseRealDouble, lts, lts, lts * lts, nZmiss, 1, 0, 0, nZmiss, 1, p_grid, q_grid);



    EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&MORSE_descC12, NULL, MorseRealDouble, lts, lts, lts * lts, nZmiss, nZobs, 0, 0, nZmiss, nZobs, p_grid, q_grid);
    //**********************************************************

    //Sameh
    //CDense Descriptor
    if(data->check == 1)
    {
        MBC     = lts;
        NBC     = lts;
        MC      = nZobs;
        NC      = nZobs;
    }
    else
    {
        MBC     = 1;
        NBC     = 1;
        MC      = lts;
        NC      = lts;
    }

    EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descC, NULL , MorseRealDouble, MBC, NBC , MBC * NBC, MC, NC, 0, 0, MC, NC, p_grid, q_grid);
    //printf("(1)%d - %d\n", MC, NC);

    MBD     = lts;
    NBD     = lts;
    MD      = nZobs;
    ND      = MBD;

    EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descC22D, NULL , MorseRealDouble, MBD, NBD, MBD * NBD, MD, ND, 0, 0, MD, ND, p_grid,q_grid);
    //printf("(2)%d - %d\n", MD, ND);
    //CAD Descriptor
    MBUV    = lts;
    NBUV    = 2 * data->hicma_maxrank;
    MUV     = -1;
    int N_over_lts_times_lts = nZobs / lts * lts;
    if(N_over_lts_times_lts < nZobs) {
        MUV = N_over_lts_times_lts + lts;
    }
    else if (N_over_lts_times_lts == nZobs) {
        MUV = N_over_lts_times_lts;
    }
    else {
        printf("%s %d: This case should not happen\n", __FILE__, __LINE__);
        exit(-1);
    }
    double expr = (double)MUV / (double)lts;
    NUV     = 2 * expr * data->hicma_maxrank;
    EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descC22UV, NULL , MorseRealDouble, MBUV, NBUV, MBUV * NBUV, MUV, NUV, 0, 0, MUV, NUV, p_grid, q_grid);
    //printf("(3)%d - %d\n", MUV, NUV);

    //CUV Descriptor
    MBrk    = 1;
    NBrk    = 1;
    Mrk     = hicma_descC22UV->mt;
    Nrk     = hicma_descC22UV->mt;
    EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descC22rk, NULL , MorseRealDouble, MBrk, NBrk, MBrk * NBrk, Mrk, Nrk, 0, 0, Mrk, Nrk, p_grid, q_grid);

    //Initiate data descriptors
    data->descZmiss         = MORSE_descZmiss;
    data->hicma_descC       = hicma_descC;
    data->hicma_descC22D    = hicma_descC22D;
    data->hicma_descC22UV   = hicma_descC22UV;
    data->hicma_descC22rk   = hicma_descC22rk;
    data->descC12           = MORSE_descC12;
    data->descmse           = MORSE_descmse;
    data->descZactual       = MORSE_descZactual;
    data->descZobs          = MORSE_descZobs;

}

//Predict missing values base on a set of given values and covariance matrix
double HICMA_dmle_Predict_Tile(MLE_data *MORSE_data, double * theta, int nZmiss, int nZobs, double *Zobs, double *Zactual, double *Zmiss, int n, int lts)
    //! //Predict missing values base on a set of given values and covariance matrix
    /*!  -- HICMA-sync
     * Returns the prediction Mean Square Error (MSE) as double
     * @param[in] MORSE_data: MLE_data struct with different MLE inputs.
     * @param[in] theta: theta Vector with three parameter (Variance, Range, Smoothness)
     *                           that is used to to generate the Covariance Matrix.
     * @param[in] nZmiss: number of missing values (unknown observations).
     * @param[in] nZobs: number of observed values (known observations).
     * @param[in] Zobs: observed values vector (known observations).
     * @param[in] Zmiss missing values vector (unknown observations).
     * @param[in] Zactual: actual missing values vector (in the case of testing MSE).
     * @param[in] n: number of spatial locations.
     * */
{
    //initialization
    //double *z = NULL;
    //double *streamdata      = NULL;
    double time_solve    = 0.0;
    double mat_gen_time    = 0.0;
    double time_gemm    = 0.0;
    double time_mse        = 0.0;
    double flops        = 0.0;
    //int MBC, NBC, MC, NC;
    //int MBD, NBD, MD, ND;
    //int MBUV, NBUV, MUV, NUV;
    //int MBrk, NBrk, Mrk, Nrk;
    int maxrank         = 0;
    int acc         = 0;
    int hicma_data_type     = 0;
    int compress_diag       = 0;

    MORSE_desc_t *MORSE_descZmiss   = NULL;
    MORSE_desc_t *hicma_descC    = NULL;
    MORSE_desc_t *MORSE_descC12     = NULL;
    MORSE_desc_t *hicma_descC22D    = NULL;
    MORSE_desc_t *hicma_descC22UV   = NULL;
    MORSE_desc_t *hicma_descC22rk   = NULL;
    MORSE_desc_t *MORSE_descmse     = NULL;
    MORSE_desc_t *MORSE_descZactual = NULL;
    MORSE_desc_t *MORSE_descZobs    = NULL;

    MLE_data     *data              = (MLE_data*) MORSE_data;
    MORSE_sequence_t *hsequence     = (MORSE_sequence_t *) data->hsequence;
    MORSE_request_t *hrequest       = (MORSE_request_t  *) data->hrequest;
    data->mserror                   = 0;
    maxrank                         = data->hicma_maxrank;
    acc                             = data->hicma_acc;
    hicma_data_type                 = data->hicma_data_type;

    if(nZmiss <= 0)
    {
        fprintf(stderr," Number of missing values should be positive value\n");
        return -1;
    }




    //Descriptors Creation
    // EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&MORSE_descZobs, NULL, MorseRealDouble, lts, lts, lts * lts, nZobs, 1, 0, 0, nZobs, 1, p_grid, q_grid);

    // if( Zactual != NULL)
    // {
    //        EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&MORSE_descZactual, NULL, MorseRealDouble, lts, lts, lts * lts,  nZmiss, 1,  0, 0, nZmiss, 1, p_grid, q_grid);
    //      EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&MORSE_descmse, &data->mserror, MorseRealDouble, lts, lts, lts * lts, 1, 1, 0, 0, 1, 1, p_grid, q_grid);
    //}
    //EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&MORSE_descZmiss, NULL, MorseRealDouble, lts, lts, lts * lts, nZmiss, 1, 0, 0, nZmiss, 1, p_grid, q_grid);



    //EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&MORSE_descC12, NULL, MorseRealDouble, lts, lts, lts * lts, nZmiss, nZobs, 0, 0, nZmiss, nZobs, p_grid, q_grid);
    //**********************************************************

    //Sameh
    //CDense Descriptor
    //if(data->check == 1)
    // {
    //       MBC     = lts;
    //      NBC     = lts;
    //     MC      = nZobs;
    //        NC      = nZobs;
    // }
    // else
    //{
    //      MBC     = 1;
    //    NBC     = 1;
    //    MC      = lts;
    //   NC      = lts;
    // }

    // EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descC, NULL , MorseRealDouble, MBC, NBC , MBC * NBC, MC, NC, 0, 0, MC, NC, p_grid, q_grid);
    //   printf("(1)%d - %d\n", MC, NC);

    //MBD     = lts;
    // NBD     = lts;
    // MD      = nZobs;
    //ND      = MBD;

    //EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descC22D, NULL , MorseRealDouble, MBD, NBD, MBD * NBD, MD, ND, 0, 0, MD, ND, p_grid,q_grid);
    //printf("(2)%d - %d\n", MD, ND);
    //CAD Descriptor
    //MBUV    = lts;
    //NBUV    = 2 * data->hicma_maxrank;
    //MUV     = -1;
    //int N_over_lts_times_lts = nZobs / lts * lts;
    //if(N_over_lts_times_lts < nZobs) {
    //        MUV = N_over_lts_times_lts + lts;
    //}
    //else if (N_over_lts_times_lts == nZobs) {
    //        MUV = N_over_lts_times_lts;
    // }
    // else {
    //printf("%s %d: This case should not happen\n", __FILE__, __LINE__);
    //exit(-1);
    //}
    //double expr = (double)MUV / (double)lts;
    //NUV     = 2 * expr * data->hicma_maxrank;
    //EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descC22UV, NULL , MorseRealDouble, MBUV, NBUV, MBUV * NBUV, MUV, NUV, 0, 0, MUV, NUV, p_grid, q_grid);
    //printf("(3)%d - %d\n", MUV, NUV);

    //CUV Descriptor
    //MBrk    = 1;
    //NBrk    = 1;
    //Mrk     = hicma_descC22UV->mt;
    //Nrk     = hicma_descC22UV->mt;
    //EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descC22rk, NULL , MorseRealDouble, MBrk, NBrk, MBrk * NBrk, Mrk, Nrk, 0, 0, Mrk, Nrk, p_grid, q_grid);



    //Initiate data descriptors
    MORSE_descZmiss        = data->descZmiss;
    hicma_descC        = data->hicma_descC;       
    hicma_descC22D        = data->hicma_descC22D;    
    hicma_descC22UV        = data->hicma_descC22UV;
    hicma_descC22rk        = data->hicma_descC22rk;   
    MORSE_descC12        = data->descC12;           
    MORSE_descmse        = data->descmse;           
    MORSE_descZactual    = data->descZactual;       
    MORSE_descZobs        = data->descZobs;          
    //****
    //data->descZmiss         = MORSE_descZmiss;
    //data->hicma_descC    = hicma_descC;
    //data->hicma_descC22D    = hicma_descC22D;
    //data->hicma_descC22UV    = hicma_descC22UV;
    //data->hicma_descC22rk    = hicma_descC22rk;
    //data->descC12           = MORSE_descC12;
    //data->descmse           = MORSE_descmse;
    //data->descZactual       = MORSE_descZactual;
    //data->descZobs          = MORSE_descZobs;


    //Copy data to vectors
    VERBOSE("Copy measurments vector to descZobs descriptor...");
    //MORSE_MLE_dzcpy_Tile_Async(MORSE_descZobs, Zobs, msequence, mrequest);
    MORSE_Lapack_to_Tile( Zobs, nZobs, MORSE_descZobs);
    VERBOSE(" Done.\n");

    if( Zactual != NULL)
    {
        VERBOSE("Copy actual measurments vector to descZactual descriptor...");
        //MORSE_MLE_dzcpy_Tile_Async(MORSE_descZactual, Zactual, msequence, mrequest);
        MORSE_Lapack_to_Tile( Zactual, nZmiss, MORSE_descZactual);
        VERBOSE(" Done.\n");
    }

    //*********************************************

#if defined(CHAMELEON_USE_MPI)
    MPI_Bcast(&data->variance,1, MPI_DOUBLE, 0, MPI_COMM_WORLD );
#endif
    theta[0]=data->variance;
    printf("estimated parameters: %f - %f - %f\n", theta[0], theta[1], theta[2]);
    VERBOSE(" LR: Generate C22 Covariance Matrix... (Prediction Stage)");
    START_TIMING(mat_gen_time);

    HICMA_problem_t hicma_problem;
    hicma_problem.theta= (double *)theta;
    hicma_problem.noise     = 1e-4;
    hicma_problem.ndim      = 2;

    double *xycoord = (double *) malloc( 4 * nZobs * sizeof(double));
    int i;


    if(strcmp(data->kernel_fun, "bivariate_matern_parsimonious")   == 0 ||
            strcmp(data->kernel_fun, "bivariate_matern_parsimonious_profile")   == 0)
    {           int j =0;
        for (i = 0; i < 2*nZobs; i++)
        {
            xycoord[i] = data->lobs.x[j];
            xycoord[2*nZobs+i] = data->lobs.y[j];
            if(i % 2 != 0)
                j++;
            //	printf ("%f - %f\n", data->lobs.x[j], data->lobs.y[j]);
        }
        hicma_problem.kernel_type = strcmp(data->dm, "gc") == 0? STARSH_SPATIAL_PARSIMONIOUS_GCD : STARSH_SPATIAL_PARSIMONIOUS_SIMD;
    }
    else if(strcmp(data->kernel_fun, "bivariate_matern_parsimonious2")   == 0 ||
            strcmp(data->kernel_fun, "bivariate_matern_parsimonious2_profile")   == 0)
    {
        int j =0;
        for (i = 0; i < nZobs; i++)
        {
            if(i == nZobs/2)
                j = 0;
            xycoord[i] = data->lobs.x[i];
            xycoord[nZobs+i] = data->lobs.y[i];
            j++;
        }
        hicma_problem.kernel_type = strcmp(data->dm, "gc") == 0? STARSH_SPATIAL_PARSIMONIOUS2_GCD : STARSH_SPATIAL_PARSIMONIOUS2_SIMD;
    }
    else
    {
        // I need to change the location struct to vector array (TO DO)
        for (i = 0; i < nZobs; i++)
        {
            xycoord[i] = data->lobs.x[i];
            xycoord[nZobs+i] = data->lobs.y[i];
            //	   printf ("%f - %f\n", data->lobs.x[i], data->lobs.y[i]);
        }
        hicma_problem.kernel_type = strcmp(data->dm, "gc") == 0? STARSH_SPATIAL_MATERN2_GCD : STARSH_SPATIAL_MATERN2_SIMD;
    }
    hicma_problem.point     =  xycoord;

    HICMA_zgenerate_problem(hicma_data_type, 'S', 0, nZobs, lts, hicma_descC22UV->mt, hicma_descC22UV->nt, &hicma_problem);
    mpiF = hicma_problem.starsh_format;
    HICMA_zgytlr_Tile(MorseLower, hicma_descC22UV, hicma_descC22D, hicma_descC22rk, 0, maxrank, pow(10, -1.0 * acc), compress_diag, hicma_descC);
    VERBOSE(" Done.\n");

    //Generate C12 covariance matrix
    VERBOSE("LR: Generate C12 Covariance Matrix... (Prediction Stage)");
    MORSE_MLE_dcmg_Tile_Async(MorseLower, MORSE_descC12,   &data->lmiss, &data->lobs, &data->lm, theta, data->dm, data->kernel_fun, hsequence, hrequest);
    MORSE_Sequence_Wait(hsequence);
    //flops = flops + FLOPS_DPOTRF(nZmiss);
    VERBOSE(" Done.\n");
    STOP_TIMING(mat_gen_time);

    //***************************************
    START_TIMING(time_solve);    
    VERBOSE("Calculate dposv C22 Covariance Matrix... (Prediction Stage)");
    HICMA_zpotrf_Tile(MorseLower, hicma_descC22UV, hicma_descC22D, hicma_descC22rk, 0, maxrank, pow(10, -1.0 * acc));
    HICMA_ztrsmd_Tile(MorseLeft, MorseLower, MorseNoTrans, MorseNonUnit, 1, hicma_descC22UV, hicma_descC22D, hicma_descC22rk, MORSE_descZobs, maxrank);
    HICMA_ztrsmd_Tile(MorseLeft, MorseLower, MorseTrans, MorseNonUnit, 1, hicma_descC22UV, hicma_descC22D, hicma_descC22rk, MORSE_descZobs, maxrank);
    flops = flops + FLOPS_DPOTRF(nZobs);
    flops = flops + FLOPS_DTRSM(MorseLeft, nZobs, nZobs);
    VERBOSE(" Done.\n");
    STOP_TIMING(time_solve);

    //****************************************
    //HICMA_zuncompress(MorseUpperLower, hicma_descCUV, MORSE_descC22, hicma_descCrk);
    // HICMA_zdiag_vec2mat(hicma_descCD, MORSE_descC22);

    //**********************************dgemm
    START_TIMING(time_gemm);
    VERBOSE("Calculate dgemm Zmiss= C12 * Zobs Covariance Matrix... (Prediction Stage)");
    MORSE_dgemm_Tile (MorseNoTrans, MorseNoTrans, 1, MORSE_descC12, MORSE_descZobs, 0, MORSE_descZmiss);
    flops = flops + FLOPS_DGEMM(nZmiss, nZobs, nZobs);
    VERBOSE(" Done.\n");
    STOP_TIMING(time_gemm);    

    //return back descZmiss to zmiss vector
    MORSE_Tile_to_Lapack( MORSE_descZmiss, Zmiss, nZmiss);

    //Estimate Mean Square Error
    if( Zactual != NULL)
    {
        START_TIMING(time_mse);
        VERBOSE("Calculate Mean Square Error (MSE) ... (Prediction Stage) \n");
        MORSE_MLE_dmse_Tile_Async(MORSE_descZactual, MORSE_descZmiss, MORSE_descmse, hsequence, hrequest);
        VERBOSE(" Done.\n");

        MORSE_Sequence_Wait(hsequence);
        STOP_TIMING(time_mse);
        data->mserror /= nZmiss;
    }
    else
        data->mserror = -1;

#if defined(CHAMELEON_USE_MPI)
    if(MORSE_My_Mpi_Rank() == 0)
    {
#endif
        if(data->log == 1)
            fprintf(data->pFileLog, "\n\n# of missing observations :%d\n\nPrediction Execution Time: %.8f, Flops: %.8f, Mean Square Error (MSE): %.8f\n\n", nZmiss,  (mat_gen_time+time_solve+time_mse), (flops / 1e9 / (time_solve)), data->mserror );

        write_prediction_result("predict_result.dat", n, data->hicma_acc, 0, 0,data->mserror, (mat_gen_time+time_solve+ time_gemm), (flops / 1e9 / (time_solve)));

#if defined(CHAMELEON_USE_MPI)
    }
#endif


    return data->mserror;


}


//init Hicma decriptors
void HICMA_dmle_Call(MLE_data  *data, int ncores, int gpus, int lts,  int p_grid, int q_grid, int N, int nZobs, int nZmiss)
    //! //Initiate HICMA and allocate different descriptors for
    /*!  HICMA
     * Returns MLE_data data with initial values and new descriptors locations.
     * @param[in] data: MLE_data struct with different MLE inputs.
     * @param[in] ncores: number of CPU workers.
     * @param[in] gpus: number of GPU workers.
     * @param[in] dts: tile size (MB).
     * @param[in] p_grid: p_grid in the case of distributed system.
     * @param[in] q_grid: q_grid in the case of distributed system.
     * @param[in] N: number of spatial locations.
     * @param[in] nZobs: number of observed values (known observations).
     * @param[in] nZmiss: number of missing values (unknown observations).
     * */
{

    MORSE_sequence_t *msequence;
    MORSE_request_t mrequest[2] = { MORSE_REQUEST_INITIALIZER, MORSE_REQUEST_INITIALIZER };
    MORSE_desc_t *hicma_descC       = NULL;
    MORSE_desc_t *hicma_descZ       = NULL;
    MORSE_desc_t *hicma_descZcpy    = NULL;
    MORSE_desc_t *hicma_descproduct    = NULL;
    MORSE_desc_t *hicma_descdet        = NULL;
    MORSE_desc_t *MORSE_descZmiss   = NULL;
    //MORSE_desc_t *MORSE_descC12     = NULL;
    //MORSE_desc_t *MORSE_descC22     = NULL;
    MORSE_desc_t *MORSE_descmse     = NULL;
    MORSE_desc_t *MORSE_descZactual = NULL;
    MORSE_desc_t *MORSE_descZobs    = NULL;
    MORSE_desc_t *hicma_descCD    = NULL;
    MORSE_desc_t *hicma_descCUV     = NULL;
    MORSE_desc_t *hicma_descCrk     = NULL;
    MORSE_desc_t *hicma_descC12D    = NULL;
    MORSE_desc_t *hicma_descC12UV   = NULL;
    MORSE_desc_t *hicma_descC12rk   = NULL;
    MORSE_desc_t *hicma_descC22D    = NULL;
    MORSE_desc_t *hicma_descC22UV   = NULL;
    MORSE_desc_t *hicma_descC22rk   = NULL;
    int MBC, NBC, MC, NC;    
    int MBD, NBD, MD, ND;
    int MBUV, NBUV, MUV, NUV;
    int MBrk, NBrk, Mrk, Nrk;

    //For ditributed system and should be removed
    double *Zcpy=(double *) malloc(N * sizeof(double));

    //CDense Descriptor
    if(data->check == 1)
    {
        MBC    = lts; 
        NBC    = lts;    
        MC    = N;
        NC    = N;
    }
    else
    {
        MBC    = 1;
        NBC     = 1;
        MC      = lts;
        NC      = lts;    
    }

    EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descC, NULL , MorseRealDouble, MBC, NBC , MBC * NBC, MC, NC, 0, 0, MC, NC, p_grid, q_grid);
    printf("(1)%d - %d\n", MC, NC);

    //CAD Descriptor
    MBD    = lts;
    NBD    = lts;
    MD    = N;
    ND    = MBD;
    EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descCD, NULL , MorseRealDouble, MBD, NBD, MBD * NBD, MD, ND, 0, 0, MD, ND, p_grid,q_grid);
    printf("(2)%d - %d\n", MD, ND);
    //CAD Descriptor    
    MBUV    = lts;
    NBUV    = 2 * data->hicma_maxrank;
    MUV    = -1; 
    int N_over_lts_times_lts = N / lts * lts;
    if(N_over_lts_times_lts < N) {
        MUV = N_over_lts_times_lts + lts;
    }
    else if (N_over_lts_times_lts == N) {
        MUV = N_over_lts_times_lts;
    }
    else {
        printf("%s %d: This case should not happen\n", __FILE__, __LINE__);
        exit(-1);
    }

    double expr = (double)MUV / (double)lts;
    NUV    = 2 * expr * data->hicma_maxrank;
    EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descCUV, NULL , MorseRealDouble, MBUV, NBUV, MBUV * NBUV, MUV, NUV, 0, 0, MUV, NUV, p_grid, q_grid);
    printf("(3)%d - %d\n", MUV, NUV);

    //CUV Descriptor
    MBrk    = 1;
    NBrk    = 1;
    Mrk    = hicma_descCUV->mt;
    Nrk    = hicma_descCUV->mt;
    EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descCrk, NULL , MorseRealDouble, MBrk, NBrk, MBrk * NBrk, Mrk, Nrk, 0, 0, Mrk, Nrk, p_grid, q_grid);
    MORSE_Sequence_Create(&msequence);
    printf("(4)%d - %d\n", Mrk, Nrk);
    EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descZ, NULL, MorseRealDouble, lts, lts, lts*lts, N, 1,  0, 0, N , 1, p_grid, q_grid);
    EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descZcpy, Zcpy, MorseRealDouble, lts, lts, lts*lts, N, 1, 0, 0, N, 1, p_grid, q_grid);
    EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descproduct, &data->dotp, MorseRealDouble, lts, lts, lts*lts, 1, 1, 0, 0, 1, 1, p_grid,q_grid);
    EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descdet, &data->det, MorseRealDouble, lts, lts, lts*lts, 1, 1, 0, 0,1, 1, p_grid,q_grid);


    if(nZmiss!=0)
    {
        if(strcmp(data->actualZFPath,"")==0)
        {
            //EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&MORSE_descZobs, &MORSE_descZcpy->mat[sizeof(double)*nZmiss], MorseRealDouble, ts, ts, ts * ts, nZobs, 1, 0, 0, nZobs, 1,p_grid,q_grid);
            //MORSE_descZactual=morse_desc_submatrix(MORSE_descZcpy, 0, 0, nZmiss, 1);
            EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&MORSE_descZobs, &Zcpy[nZmiss], MorseRealDouble, lts, lts, lts * lts, nZobs, 1, 0, 0, nZobs, 1,p_grid,q_grid);
            EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&MORSE_descZactual, Zcpy, MorseRealDouble, lts, lts, lts * lts,  nZmiss, 1,  0, 0, nZmiss, 1,p_grid,q_grid);
        }
        else
        {
            MORSE_descZobs = hicma_descZcpy;
            EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&MORSE_descZactual, NULL, MorseRealDouble, lts, lts, lts * lts,  nZmiss, 1,  0, 0, nZmiss, 1,p_grid,q_grid);
        }


        //C12AD Descriptor    
        MBD    = lts;
        NBD    = lts;
        MD    = nZmiss;
        ND    = MBD;
        EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descC12D, NULL, MorseRealDouble, MBD, NBD, MBD * NBD, MD, ND, 0, 0, MD, ND, p_grid, q_grid);

        //C12UV Descriptor
        MBUV    = lts;
        NBUV    = 2 * data->hicma_maxrank;
        MUV    = nZmiss;
        NUV    = 2 * MUV / lts * data->hicma_maxrank;
        EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descC12UV, NULL, MorseRealDouble, MBUV, NBUV, MBUV * NBUV, MBUV, NBUV, 0, 0, MBUV, NBUV, p_grid, q_grid);    

        //C12Ark Descriptor
        MBrk    = 1;
        NBrk    = 1;
        Mrk    = hicma_descC12UV->mt;
        Nrk     = hicma_descC12UV->mt;
        EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descC12rk, NULL, MorseRealDouble, MBrk, NBrk, MBrk * NBrk, Mrk, Nrk, 0, 0, Mrk, Nrk, p_grid, q_grid);

        //C11AD Descriptor
        MBD     = lts;
        NBD     = lts;
        MD      = nZobs;
        ND      = MBD;
        EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descC22D, NULL, MorseRealDouble, MBD, NBD, MBD * NBD, MD, ND, 0, 0, MD, ND, p_grid,q_grid);

        //C12UV Descriptor
        MBUV    = lts;
        NBUV    = 2 * data->hicma_maxrank;
        MUV    = nZobs;
        NUV    = 2 * MUV / lts * data->hicma_maxrank;
        EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descC22UV, NULL, MorseRealDouble, MBUV, NBUV, MBUV * NBUV, MBUV, NBUV, 0, 0, MBUV, NBUV, p_grid, q_grid);                        
        //C12Ark Descriptor            
        MBrk    = 1;
        NBrk    = 1;
        Mrk    = hicma_descC22UV->mt;
        Nrk    = hicma_descC22UV->mt;
        EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&hicma_descC22rk,NULL , MorseRealDouble, MBrk, NBrk, MBrk * NBrk, Mrk, Nrk, 0, 0, Mrk, Nrk, p_grid, q_grid);


        //Other descriptors
        EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&MORSE_descZmiss, NULL, MorseRealDouble, lts, lts, lts * lts, nZmiss, 1, 0, 0, nZmiss, 1, p_grid, q_grid);
        EXAGEOSTAT_ALLOCATE_MATRIX_TILE(&MORSE_descmse, &data->mserror,  MorseRealDouble, lts, lts, lts * lts, 1, 1, 0, 0, 1, 1, p_grid, q_grid);
    }


    //Fill data struct
    data->hicma_descC    = hicma_descC;
    data->hicma_descCD    = hicma_descCD;
    data->hicma_descCUV    = hicma_descCUV;
    data->hicma_descCrk    = hicma_descCrk;
    data->hicma_descZ       = hicma_descZ;
    data->hicma_descZcpy    = hicma_descZcpy;
    data->hicma_descdet     = hicma_descdet;
    data->hicma_descproduct = hicma_descproduct;
    data->descZmiss         = MORSE_descZmiss;
    data->hicma_descC12D    = hicma_descC12D;
    data->hicma_descC12UV   = hicma_descC12UV;
    data->hicma_descC12rk   = hicma_descC12rk;
    data->hicma_descC22D    = hicma_descC22D;
    data->hicma_descC22UV    = hicma_descC22UV;
    data->hicma_descC22rk    = hicma_descC22rk;
    data->descmse           = MORSE_descmse;
    data->descZactual       = MORSE_descZactual;
    data->descZobs          = MORSE_descZobs;
    data->hsequence         = msequence;
    data->hrequest          = mrequest;
    data->mserror        = 0;
    //stop gsl error handler
    gsl_set_error_handler_off () ;

}
