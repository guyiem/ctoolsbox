#ifndef FREQS_H
#define FREQS_H

#include <stdio.h>
#include <math.h>
#include "tools.h"

typedef struct {
     int nf;
     double df;
     double* data;
} freqs_t;

freqs_t freqs_alloc_create_arange(double fmin, double df, int num_freq);
freqs_t freqs_alloc_create_tf(double duree, double freq_ech, double fmin, double fmax);
freqs_t freqs_alloc_create_linspace(double fmin, double fmax, int num_freq);
freqs_t freqs_spectre_fft(double duree , double freq_ech) ;

freqs_t freqs_copy(const freqs_t* freqs);


static inline int freqs_geti(const freqs_t* freqs, double freq0)
{
    printf("%d , %f , %f , %f \n " , freqs->nf , freqs->df , freqs->data[0] , freqs->data[freqs->nf-1] ) ;
    const double eps = (freqs->df)/10.0 ;
    double err = 1 ;
    int kf = -1 ;
    while( (err>eps) && (kf+1<freqs->nf) )
    {
	kf += 1 ;
	const double freq = freqs->data[kf] ;
	err = abs( freq - freq0) ;
    }
    printf(" %d , %f  \n ",kf,freqs->data[kf]) ;
    ensure( kf<freqs->nf ) ;
    return kf ;
}

static inline double freqs_get(const freqs_t* freqs, int i)
{
     ensure(0 <= i && i < freqs->nf);

     return freqs->data[i];
}

static inline int freqs_length(const freqs_t* freqs)
{
     return freqs->nf;
}

static inline double freqs_start(const freqs_t* freqs)
{
     ensure(freqs->nf > 0);

     return freqs->data[0];
}

static inline double freqs_end(const freqs_t* freqs)
{
     ensure(freqs->nf > 0);

     return freqs->data[freqs->nf - 1];
}


static inline double freqs_df(const freqs_t* freqs)
{
     return freqs->df;
}

void freqs_write(const freqs_t* freqs, FILE* fd);

freqs_t freqs_read(FILE* fd);

#endif // FREQS_H
