#include <stdlib.h>
#include <stdio.h>

#include "tools.h"
#include "mem_alloc.h"
#include "vec_array.h"


vec_array_t vec_array_alloc(int ne)
{
     vec_array_t result;

     result.ne = ne;

     MEM_ALLOC(result.positions, vec_t, ne);
     
     for(int i = 0; i < ne; i++) {
          vec_set_zero(&(result.positions[i]));
     }

     return result;
}

vec_array_t vec_array_copy(const vec_array_t* source)
{
     vec_array_t result;

     result.ne = source->ne;

     MEM_ALLOC(result.positions, vec_t, result.ne);

     for(int i = 0; i < result.ne; i++) {
          result.positions[i] = source->positions[i];
     }

     return result;
}

void vec_array_free(vec_array_t* vec_array)
{
     vec_array->ne = 0;
     
     free(vec_array->positions);

     vec_array->positions = NULL;
}

vec_array_t vec_array_alloc_linear(int ne, const vec_t* p0, const vec_t* v)
{
     vec_array_t result;

     vec_t acc = *p0;

     result = vec_array_alloc(ne);

     for(int i = 0; i < ne; i++) {
          result.positions[i] = acc;

          vec_add_(&acc, v);
     }

     return result;
}

vec_array_t vec_array_alloc_plan(const vec_t* p0 , const vec_t* v1 , const vec_t* v2 , int n1 , int n2)
{
    vec_array_t result ;
    int compteur = 0 ;
    result = vec_array_alloc(n1*n2) ;
    for (int i1 = 0 ; i1<n1 ; i1 ++ )
    {
	const vec_t tmp1 = vec_smul(v1,(double)(i1)) ;
	for (int i2 = 0 ; i2<n2 ; i2 ++ )
	{
	    const vec_t tmp2 = vec_smul(v2,(double)(i2)) ;
	    const vec_t somme = vec_add(&tmp1,&tmp2) ;
	    result.positions[compteur] = vec_add( p0 , &somme ) ;
	    compteur += 1 ;
	}
    }
    return result ;
}

void vec_array_write(const vec_array_t* vec_array, FILE* fd)
{
     fwrite((void*) &(vec_array->ne), sizeof(int), 1, fd);

     for(int i = 0; i < vec_array->ne; i++) {
          vec_write(&(vec_array->positions[i]), fd);
     }
}

vec_array_t vec_array_read(FILE* fd)
{
    int ne = 0;
    int verif = fread((void*)&ne,sizeof(int),1,fd);
    ensure(verif==1) ;

    vec_array_t result = vec_array_alloc(ne);

    for (int k = 0 ; k<ne ; k++ )
    {
         result.positions[k] = vec_read(fd);
         // fread((void*)&(result.position[k]),sizeof(vec_t),1,fd) ;
    }

    return result;
}
