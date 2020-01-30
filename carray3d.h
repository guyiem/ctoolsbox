#ifndef CARRAY3D_H
#define CARRAY3D_H

#include <stdio.h>

#include "types.h"
#include "tools.h"

typedef struct {
     int        xdim;
     int        ydim;
     int        zdim;
     complex_t* data;
} carray3_t;

carray3_t carray3_alloc(int xdim, int ydim, int zdim);

void carray3_free(carray3_t* carr);

void carray3_set_zero(carray3_t* carr);

static inline int carray3_xdim(const carray3_t* carr)
{
     return carr->xdim;
}

static inline int carray3_ydim(const carray3_t* carr)
{
     return carr->ydim;
}

static inline int carray3_zdim(const carray3_t* carr)
{
     return carr->zdim;
}


static inline complex_t carray3_get(const carray3_t* carr, int i, int j, int k)
{
     ensure(i < carr->xdim);
     ensure(j < carr->ydim);
     ensure(k < carr->zdim);

     return carr->data[(i * carr->ydim + j) * carr->zdim + k];
}

static inline void carray3_set(const carray3_t* carr, int i, int j, int k, complex_t val)
{
     ensure(i < carr->xdim);
     ensure(j < carr->ydim);
     ensure(k < carr->zdim);

     const int index = (i * carr->ydim + j) * carr->zdim + k;

     carr->data[index] = val;

}

static inline void carray3_incr(const carray3_t* carr, int i, int j, int k, complex_t val)
{
     ensure(i < carr->xdim);
     ensure(j < carr->ydim);
     ensure(k < carr->zdim);

     const int index = (i * carr->ydim + j) * carr->zdim + k;

     carr->data[index] += val;
}

void carray3_sub(const carray3_t* carr1, const carray3_t* carr2, carray3_t* result);

void carray3_abs_min_max(const carray3_t* carr, double* min, double* max);

void carray3_write(const carray3_t* carr, FILE* fd);
carray3_t carray3_read(FILE* fd);

#endif // CARRAY3D_H
