#ifndef LINALG_H
#define LINALG_H

#include "types.h"
#include "tools.h"

// On ferait mieux d'utiliser LAPACKE ou OpenBLAS afin d'avoir du code vectorialisé.

typedef struct {
     int        rows;
     int        cols;
     complex_t* data;
} cmatrix_t;

cmatrix_t cmatrix_alloc(int rows, int cols);
void cmatrix_free(cmatrix_t* cmat);

static inline int cmatrix_rows(const cmatrix_t* cmat)
{
     return cmat->rows;
}

static inline int cmatrix_cols(const cmatrix_t* cmat)
{
     return cmat->cols;
}

static inline complex_t cmatrix_get(const cmatrix_t* cmat, int i, int j)
{
     ensure(i >= 0 && i < cmat->rows &&
            j >= 0 && j < cmat->cols);

     return cmat->data[i * cmat->cols + j];
}

static inline void cmatrix_set(cmatrix_t* cmat, int i, int j, complex_t val)
{
     ensure(i >= 0 && i < cmat->rows &&
            j >= 0 && j < cmat->cols);

     cmat->data[i * cmat->cols + j] = val;
}

static inline void cmatrix_reshape(cmatrix_t* cmat, int rows, int cols)
{
     if(rows * cols != cmat->rows * cmat->cols) {
          failwith("dimensions mismatch");
     }

     cmat->rows = rows;
     cmat->cols = cols;
}

cmatrix_t cmatrix_copy(const cmatrix_t* cmat);

void cmatrix_conjugate(cmatrix_t* cmat);
// void cmatrix_transpose(cmatrix_t* cmat);

void cmatrix_multiply(const cmatrix_t* lhs, const cmatrix_t* rhs, cmatrix_t* target);

void cmatrix_print(const cmatrix_t* mat);

#endif // LINALG_H
