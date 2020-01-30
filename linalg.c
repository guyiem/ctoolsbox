#include <string.h>

#include "tools.h"
#include "mem_alloc.h"

#include "linalg.h"

cmatrix_t cmatrix_alloc(int rows, int cols)
{
     cmatrix_t result;

     result.rows = rows;
     result.cols = cols;
     
     MEM_ALLOC(result.data, complex_t, rows * cols);

     return result;     
}

void cmatrix_free(cmatrix_t* cmat)
{
     cmat->rows = 0;
     cmat->cols = 0;
     
     MEM_FREE(cmat->data);
}

cmatrix_t cmatrix_copy(const cmatrix_t* cmat)
{
     cmatrix_t result = cmatrix_alloc(cmat->rows, cmat->cols);

     memcpy(cmat->data, result.data, sizeof(complex_t) * cmat->rows * cmat->cols);

     return result;          
}

void cmatrix_conjugate(cmatrix_t* cmat)
{
     for(int i = 0; i < cmat->rows * cmat->cols; i++) {
          cmat->data[i] = conj(cmat->data[i]);
     }
}

/* inline void xchng(complex_t* c1, complex_t* c2) */
/* { */
/*      complex_t tmp = *c1; */
/*      *c1 = c2; */
/*      *c2 = tmp;      */
/* } */

/* void cmatrix_transpose(cmatrix_t* cmat) */
/* { */
/*      for(int i = 0; i < cmat->rows * cmat->cols; i++) { */
          
/*      } */
/* } */

void cmatrix_multiply(const cmatrix_t* lhs, const cmatrix_t* rhs, cmatrix_t* target)
{
     ensure(lhs->cols == rhs->rows);
     ensure(lhs->rows == target->rows);
     ensure(rhs->cols == target->cols);

     for(int i = 0; i < lhs->rows; i++) {
          for(int j = 0; j < rhs->cols; j++) {
               
               complex_t acc = 0.0;

               for(int k = 0; k < lhs->cols; k++) {
                    acc += cmatrix_get(lhs, i, k) * cmatrix_get(rhs, k, j);
               }

               cmatrix_set(target, i, j, acc);
          }
     }
}

void cmatrix_print(const cmatrix_t* cmat)
{
     for(int j = 0; j < cmat->rows; j++) {
          printf("row %d: ", j);
          for(int i = 0; i < cmat->cols; i++) {
               const complex_t c = cmatrix_get(cmat, j, i);
               const double re   = creal(c);
               const double im   = cimag(c);
               printf("%.3f+%.3fi ", re, im);
          }
          printf("\n");
     }
}
