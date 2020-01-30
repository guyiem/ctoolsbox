#ifndef PT_H
#define PT_H

#include <math.h>
#include <stdio.h>

typedef struct {
     double x;
     double y;
     double z;
} vec_t;

static inline vec_t vec(const double x, const double y, const double z)
{
     vec_t result;

     result.x = x;
     result.y = y;
     result.z = z;

     return result;
}

static inline vec_t vec_zero(void)
{
     return vec(0.0, 0.0, 0.0);
}

static inline void vec_set(vec_t* vec, const double x, const double y, const double z)
{
     vec->x = x;
     vec->y = y;
     vec->z = z;
}

static inline void vec_set_zero(vec_t* vec)
{
     vec_set(vec, 0.0, 0.0, 0.0);
}

static inline vec_t vec_add(const vec_t* p1, const vec_t* p2)
{
     vec_t result;

     result.x = p1->x + p2->x;
     result.y = p1->y + p2->y;
     result.z = p1->z + p2->z;

     return result;
}

static inline void vec_add_(vec_t* p1, const vec_t* p2)
{
     p1->x = p1->x + p2->x;
     p1->y = p1->y + p2->y;
     p1->z = p1->z + p2->z;
}

static inline vec_t vec_sub(const vec_t* p1, const vec_t* p2)
{
     vec_t result;

     result.x = p1->x - p2->x;
     result.y = p1->y - p2->y;
     result.z = p1->z - p2->z;

     return result;
}

static inline void vec_sub_(vec_t* p1, const vec_t* p2)
{
     p1->x = p1->x - p2->x;
     p1->y = p1->y - p2->y;
     p1->z = p1->z - p2->z;
}

static inline vec_t vec_smul(const vec_t* p1, const double s)
{
     vec_t result;

     result.x = p1->x * s;
     result.y = p1->y * s;
     result.z = p1->z * s;

     return result;
}

static inline void vec_smul_(vec_t* p1, const double s)
{
     p1->x = p1->x * s;
     p1->y = p1->y * s;
     p1->z = p1->z * s;
}

static inline double vec_dot(const vec_t* p1, const vec_t* p2)
{
     return (p1->x * p2->x + p1->y * p2->y + p1->z * p2->z);
}

static inline double vec_norm(const vec_t* p)
{
     return sqrt(p->x * p->x + p->y * p->y + p->z * p->z);
}

static inline double vec_dist(const vec_t* p1, const vec_t* p2)
{
     const vec_t v = vec_sub(p1, p2);
     return vec_norm(&v);
}

static inline void vec_print(const vec_t* p)
{
     printf("(%f, %f, %f)", p->x, p->y, p->z);
}



//début fonctions de symétrie
static inline vec_t vec_sym_z(const vec_t* p)
{
    return vec(p->x,p->y,- p->z);
}

void vec_write(const vec_t* p, FILE* fd);

vec_t vec_read(FILE* fd);

#endif // VEC_H
