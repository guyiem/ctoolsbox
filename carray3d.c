#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <float.h>

#include "carray3d.h"
#include "mem_alloc.h"
#include "tools.h"

carray3_t carray3_alloc(int xdim, int ydim, int zdim)
{
     carray3_t result;

     result.xdim = xdim;
     result.ydim = ydim;
     result.zdim = zdim;
     
     MEM_ALLOC(result.data, complex_t, xdim * ydim * zdim);

     for(int i = 0; i < xdim * ydim * zdim; i++) {
          result.data[i] = 0.0;
     }

     return result;     
}

void carray_free(carray3_t* carr)
{
     carr->xdim = 0;
     carr->ydim = 0;
     carr->zdim = 0;

     MEM_FREE(carr->data);
}

void carray3_set_zero(carray3_t* carr)
{
     for(int i = 0; i < carr->xdim * carr->ydim * carr->zdim; i++) {
          carr->data[i] = 0.0;
     }     
}

void carray3_sub(const carray3_t* carr1, const carray3_t* carr2, carray3_t* result)
{
     ensure(carr1->xdim == carr2->xdim);
     ensure(carr2->xdim == result->xdim);
     ensure(carr1->ydim == carr2->ydim);
     ensure(carr2->ydim == result->ydim);
     ensure(carr1->zdim == carr2->zdim);
     ensure(carr2->zdim == result->zdim);

     const int sz = carr1->xdim * carr1->ydim * carr1->zdim;

     for(int i = 0; i < sz; i++) {
          result->data[i] = carr1->data[i] - carr2->data[i];
     }
}

void carray3_abs_min_max(const carray3_t* carr, double* min, double* max)
{
     double lmin = DBL_MAX;
     double lmax = -DBL_MAX;

     for(int i = 0; i < carr->xdim; i++) {
          for(int j = 0; j < carr->ydim; j++) {
               for(int k = 0; k < carr->zdim; k++) {
                    
                    const double v = cabs(carray3_get(carr, i, j, k));
                    
                    lmin = lmin < v ? lmin : v;
                    lmax = lmax > v ? lmax : v;
               }
          }
     }

     *min = lmin;
     *max = lmax;
}

void carray3_write(const carray3_t* carr, FILE* fd)
{
     fwrite((void*) &(carr->xdim), sizeof(int), 1, fd);
     fwrite((void*) &(carr->ydim), sizeof(int), 1, fd);
     fwrite((void*) &(carr->zdim), sizeof(int), 1, fd);

     const int sz = carr->xdim * carr->ydim * carr->zdim;

     fwrite((void*) carr->data, sizeof(complex_t), sz, fd);
}

carray3_t carray3_read(FILE* fd)
{
     int nx, ny, nz;
     
     const int rx = fread((void*)&nx,sizeof(int),1,fd);
     ensure(rx == 1);

     const int ry = fread((void*)&ny,sizeof(int),1,fd);
     ensure(ry == 1);

     const int rz = fread((void*)&nz,sizeof(int),1,fd);
     ensure(rz == 1);

     carray3_t result = carray3_alloc(nx,ny,nz) ;
     
     const int rd = fread((void*) result.data, sizeof(complex_t), nx * ny * nz, fd);
     ensure(rd == nx * ny * nz);
     
     return result;
}
