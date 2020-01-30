#include <stdio.h>

#include "tools.h"
#include "vec.h"

void vec_write(const vec_t* p, FILE* fd)
{
     const int wnum = fwrite((void*) p, sizeof(vec_t), 1, fd);

     ensure(wnum == 1);
}

vec_t vec_read(FILE* fd)
{
    vec_t result = vec_zero() ;
    int verif = fread((void*)&result.x,sizeof(double),1,fd) ;
    ensure(verif==1) ;
    verif = fread((void*)&result.y,sizeof(double),1,fd) ;
    ensure(verif==1) ;
    verif = fread((void*)&result.z,sizeof(double),1,fd) ;
    ensure(verif==1) ;
    return result ;
}
