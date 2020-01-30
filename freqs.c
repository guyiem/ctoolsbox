#include "freqs.h"
#include "mem_alloc.h"

freqs_t freqs_alloc_create_arange(double fmin, double df, int num_freq)
{
    freqs_t freqs ;
    freqs.nf = num_freq ;
    freqs.df = df ;
    MEM_ALLOC(freqs.data, double, num_freq) ;
    for (int kf=0 ; kf<num_freq ; kf ++)
    {
	freqs.data[kf] = (double)(kf)*df + fmin ;
    }
    printf(" fréquences crées (arange) \n fmin = %f \n fmax = %f \n df = %f \n \n ",fmin,freqs.data[num_freq-1],df) ;
    return freqs;
}

freqs_t freqs_alloc_create_linspace(double fmin, double fmax, int num_freq)
{
    freqs_t freqs ;
    freqs.nf = num_freq ;
    freqs.df = (fmax-fmin)/((double) (num_freq-1));

    MEM_ALLOC(freqs.data, double, num_freq) ;
    for (int kf=0 ; kf<num_freq ; kf ++)
    {
	freqs.data[kf] = ((double) kf)*freqs.df + fmin ;
    }
    printf(" fréquences crées (linspace) \n fmin = %f \n fmax = %f \n df = %f \n \n ",fmin,freqs.data[num_freq-1],freqs.df) ;
    return freqs;
}

freqs_t freqs_alloc_create_tf(double duree, double freq_ech, double fmin, double fmax)
{
    const double freq_max = fmax>(freq_ech/2.0) ? (freq_ech/2.0):fmax ;
    const double delta_f = 1.0/duree ;
    const int NF = (int)((freq_max - fmin)/delta_f) ;
    const freqs_t freqs = freqs_alloc_create_arange(fmin,delta_f,NF+1) ;
    printf(" fréquences crées (tf) \n fmin = %f \n fmax = %f \n df = %f \n \n ",fmin,freqs.data[freqs.nf-1],delta_f) ;
    return freqs ;
}

freqs_t freqs_spectre_fft(double duree , double freq_ech)
{
    const double fmax = freq_ech/2.0 ;
    const int Nf = (int)(fmax*duree) + 1 ;
    freqs_t freqs = freqs_alloc_create_linspace(0.0,fmax,Nf) ;
    return freqs ;
}

freqs_t freqs_copy(const freqs_t* freqs)
{
     freqs_t result;

     result.nf = freqs->nf;
     result.df = freqs->df;

     MEM_ALLOC(result.data, double, result.nf);

     for(int kf = 0; kf < result.nf; kf++) {
          result.data[kf] = freqs->data[kf];
     }

     return result;     
}

void freqs_write(const freqs_t* freqs, FILE* fd)
{
     fwrite((void*) &(freqs->nf), sizeof(int), 1, fd);
     fwrite((void*) &(freqs->df), sizeof(double), 1, fd);
     fwrite((void*) freqs->data, sizeof(double), freqs->nf, fd);
}

freqs_t freqs_read(FILE* fd)
{
    freqs_t freqs;

    const int rnf = fread((void*)&(freqs.nf) , sizeof(int) , 1 , fd ) ;
    ensure(rnf == 1);

    const int rdf = fread((void*)&(freqs.df) , sizeof(double) , 1 , fd ) ;
    ensure(rdf == 1);

    MEM_ALLOC(freqs.data, double, freqs.nf);

    const int rd  = fread((void*) freqs.data, sizeof(double), freqs.nf, fd);
    ensure(rd == freqs.nf);

    return freqs;
}
