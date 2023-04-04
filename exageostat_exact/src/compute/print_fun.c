#include <stdarg.h>

void Desc_fprintf(FILE *pointer, // The file to write to
                                  MORSE_desc_t *D, // The descriptor to print
                  int print_whole_desc, // 1: print the whole descriptor; 0: print the subdescriptor
                  char *name, // Name of the descriptor
                  int start_nrow, int end_nrow, int start_ncol, int end_ncol){

  int i=0, j=0, Descrow = D->lm, Desccol = D->ln;
  double *Desc_print = (double *) malloc(Descrow * Desccol * sizeof(double));

  // Input validation
  if(!print_whole_desc){
    if(start_nrow < 0 || end_nrow < 0){
      fprintf(stderr, "\nWrong number of rows (not positive)!\n");
      exit(-1);
    }else if(start_nrow > Descrow || end_nrow > Descrow){
      fprintf(stderr, "\nWrong number of rows (larger than the matrix size)!\n");
      exit(-2);
    }

    if(start_ncol < 0 || end_ncol < 0){
      fprintf(stderr, "\nWrong number of columns (not positive)!\n");
      exit(-3);
    }else if(start_ncol > Desccol || end_ncol > Desccol){
      fprintf(stderr, "\nWrong number of columns (larger than the matrix size)!\n");
      exit(-4);
    }
  }

  if(print_whole_desc != 0 && print_whole_desc != 1){
    fprintf(stderr, "\nWrong number for print_whole_desc (should be 0 or 1)!\n");
    exit(-5);
  }

  if(pointer == NULL){
    fprintf(stderr, "\nFILE *pointer is NULL!\n");
    exit(-6);
  }

  if(print_whole_desc){
    start_nrow = 0;
    end_nrow = Descrow;
    start_ncol = 0;
    end_ncol = Desccol;
  }else{
    end_nrow ++;
    end_ncol ++;
  }

  // Convert to Lapack form
  MORSE_Tile_to_Lapack(D, Desc_print, Descrow);

  if(MORSE_My_Mpi_Rank() == 0){
    // Info of the matrix
    if(print_whole_desc){
      fprintf(stderr, "\nDescriptor <%s> has %d rows and %d cols.\n", name, Descrow, Desccol);
      fprintf(stderr, "The tile size is: %d x %d\n", D->mb, D->nb);
    }else{
      fprintf(stderr, "\nDescriptor <%s> has %d rows and %d cols.\n", name, Descrow, Desccol);
      fprintf(stderr, "The submatrix printed is from row %d to %d; column %d to %d\n", start_nrow, end_nrow-1, start_ncol, end_ncol-1);
      fprintf(stderr, "The tile size is: %d x %d\n", D->mb, D->nb);
    }

    // Print the matrix
    if(pointer == stdout || pointer == stderr){
      for (i = start_nrow; i < end_nrow; i++) {
        for (j = start_ncol; j < end_ncol-1; j++) {
          fprintf(pointer, "%.2e\t", Desc_print[i + Descrow * j]);
        }
        fprintf(pointer, "%.2e\n", Desc_print[i + Descrow * j]);
      }
      fprintf(stderr, "\n");
    }else{
      for (i = start_nrow; i < end_nrow; i++) {
        for (j = start_ncol; j < end_ncol-1; j++) {
          fprintf(pointer, "%lf,", Desc_print[i + Descrow * j]);
        }
        fprintf(pointer, "%lf\n", Desc_print[i + Descrow * j]);
      }
    }
  }
}