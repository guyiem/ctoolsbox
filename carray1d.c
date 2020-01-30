#include "carray1d.h"
#include "types.h"
#include "mem_alloc.h"
#include "tools.h"

carray1_t carray1_alloc_zeros(int ne)
{
    carray1_t result ;
    result.ne = ne ;
    MEM_ALLOC(result.data , complex_t, ne ) ;
    for (int i = 0 ; i < ne ; i ++)
    {
	result.data[i] = 0.0 ;
    }
    return result ;
}

void carray1_free(carray1_t* ca)
{
    ca->ne = 0.0 ;
    MEM_FREE(ca->data) ;
}


void carray1_set_zeros(carray1_t* carr)
{
    for (int ke = 0 ; ke < carr->ne ; ke ++ )
    {
	carr->data[ke] = 0.0 ;
    }
}

carray1_t carray1_copy(const carray1_t* source)
{
    carray1_t sortie ;
    sortie.ne = source->ne ;
    MEM_ALLOC(sortie.data,complex_t,sortie.ne) ;
    for ( int i = 0 ; i < sortie.ne ; i++)
    {
	sortie.data[i] = source->data[i] ;
    }
    return sortie ;      
}

void carray1_write( const carray1_t* carr , FILE* fd)
{
    fwrite((void*) &(carr->ne), sizeof(int) , 1 , fd ) ;
    fwrite((void*) (carr->data) , sizeof(complex_t) , carr->ne , fd ) ;
}

carray1_t carray1_read(FILE* fd)
{
    //printf(" ON RENTRE DANS CARRAY1_READ \n ") ;
    int ne = -1 ;
    int verif = fread((void*)&ne , sizeof(int) , 1 , fd ) ;
    ensure(verif==1) ;
    //printf("car1_r ne = %d \n",ne) ;
    carray1_t sortie = carray1_alloc_zeros(ne) ;
    complex_t *data ;
    MEM_ALLOC(data,complex_t,ne) ;
    verif = fread((void*)data,sizeof(complex_t),ne,fd) ;
    ensure(verif==ne) ;
    for (int k = 0 ; k < ne ; k++)
    {
	sortie.data[k] = data[k] ;
    }
    //fread((void*)((&sortie)->data),sizeof(complex_t),ne,fd) ;
    /* for ( int ke = 0 ; ke < ne ; ke++ ) */
    /* { */
    /* 	fread( (void*)&sortie.data[ke] , sizeof(complex_t) , 1 , fd ) ; */
    /* } */
    return sortie ;
}
