#ifndef CONSTANTES_H
#define CONSTANTES_H

#include "types.h"

#ifndef M_PI
#define M_PI 3.14159265359
#endif

static const double  CEAU = 1500.0;   // vitesse du son dans l'eau
static const double RHOE = 1000.0 ;
static const complex_t BSI = 0.0 ;

static const rgb_t red_color = { 0, 0, 255 };
static const rgb_t green_color = { 0, 255, 0 };
static const rgb_t blue_color = { 255, 0, 0 };

#endif // CONSTANTES_H
