/* -*- mode: c; c-basic-offset: 8 -*- */
#ifndef MEM_ALLOC_H
#define MEM_ALLOC_H

#include <stdlib.h>
#include <stdio.h>

#ifdef PARANOID
#include <string.h>
#endif

/*
\file file.h
* Fichier contenant les macro fonctions permettant l'allocation ainsi que la liberation de la memoire. 
*/


/**
*  \def MEM_ALLOC(_o,_t,_n)
*   Macro fonction allouant de la memoire a son parametre _o de type _t et de taille _n
*/
#ifdef PARANOID
#define MEM_ALLOC(_o,_t,_n) do { \
  if (!(_o=(_t *)malloc (sizeof (_t)*(_n)))) \
    fprintf (stderr, "ERREUR allocation memoire" \
             " impossible de %s de type %s[%1d], dans %s"\
             " ligne %1d\n", #_o, #_t, (_n), \
             __FILE__, __LINE__), abort (); \
  memset(_o, 0, sizeof(_t)*(_n));\
  } \
  while (0)
#else
#define MEM_ALLOC(_o,_t,_n) do { \
  if (!(_o=(_t *)malloc (sizeof (_t)*(_n)))) \
    fprintf (stderr, "ERREUR allocation memoire" \
             " impossible de %s de type %s[%1d], dans %s"\
             " ligne %1d\n", #_o, #_t, (_n), \
             __FILE__, __LINE__), abort (); \
  } \
 while (0)
#endif


/**
* \def MEM_REALLOC(_o,_t,_n)
* Macro fonction reallouant de la memoire a son parametre _o de type _t et de taille _n 
*/	     
#define MEM_REALLOC(_o,_t,_n) do { \
  if (!(_o=(_t *)realloc ((_o),sizeof (_t)*(_n)))) \
    fprintf (stderr, "ERREUR re-allocation memoire" \
             " impossible de %s de type %s[%1d], dans %s"\
             " ligne %1d\n", #_o, #_t, (_n), \
             __FILE__, __LINE__), abort (); } while (0)

/**
* \def MEM_FREE(_o)
* Macro fonction liberant la memoire allouer a l'objet (_o)
*/
#define MEM_FREE(_o)  do { free (_o); _o=NULL; } while(0)


#endif /* MEM_ALLOC_H */
