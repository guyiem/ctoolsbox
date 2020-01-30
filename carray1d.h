#ifndef CARRAY1D_H
#define CARRAY1D_H

#include <stdio.h>
#include "types.h"

typedef struct {
    int ne ;
    complex_t* data ;
} carray1_t ;


carray1_t carray1_alloc_zeros(int ne);
void carray1_free(carray1_t* ca);
void carray1_set_zeros(carray1_t* carr);
carray1_t carray1_copy(const carray1_t* source) ;

void carray1_write(const carray1_t* carr , FILE* fd) ;
carray1_t carray1_read(FILE* fd) ;

#endif // CARRAY1D_H
