#ifndef VEC_ARRAY_H
#define VEC_ARRAY_H

#include <stdio.h>

#include "vec.h"

typedef struct {
     int    ne;
     vec_t* positions;
} vec_array_t;

static inline int vec_array_length(const vec_array_t* vec)
{
     return vec->ne;
}


static inline const vec_t* vec_array_get(const vec_array_t* vec, int i)
{
     return &(vec->positions[i]);
}

// alloue et initialise une veteur de points à (0.0, 0.0, 0.0) * ne
vec_array_t vec_array_alloc(int ne);

// alloue et initialise un tableau de positions en copiant les données de l'argument
vec_array_t vec_array_copy(const vec_array_t* source);

// désalloue un tableau de points
void vec_array_free(vec_array_t* vec_array);

// alloue une antenne de ne régulièrement espacée à partir de la position p0, dans la direction du vecteur v
vec_array_t vec_array_alloc_linear(int ne, const vec_t* p0, const vec_t* v);

vec_array_t vec_array_alloc_plan(const vec_t* p0 , const vec_t* v1 , const vec_t* v2 , int n1 , int n2);

void vec_array_write(const vec_array_t* vec_array, FILE* fd);

vec_array_t vec_array_read(FILE* fd) ;


#endif // VEC_ARRAY_H
