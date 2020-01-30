/* /\* -*- c-basic-offset: 8 -*- *\/ */

/* #include <SDL2/SDL.h> */
/* #include <GL/gl.h> */
/* #include <GL/glu.h> */

/* #include <stdlib.h> */
/* #include <stdio.h> */

/* #include "mem_alloc.h" */
/* #include "window.h" */
/* #include "tools.h" */

/* void initialize_graphics(void) */
/* { */
/* 	// intialize SDL */
/* 	if(SDL_Init(SDL_INIT_VIDEO) < 0) { // check for an error */
/* 		failwith("Can't initialize SDL video"); */
/* 	} */

/* 	atexit(SDL_Quit); */
/* } */

/* void window_init(window_t* window_a, int xsize_a, int ysize_a) */
/* { */
/* 	window_a->wwidth  = xsize_a; */
/* 	window_a->wheight = ysize_a; */
	
/* 	/\* MEM_ALLOC(window_a->pixmap, rgb_t, xsize_a * ysize_a); *\/ */

/* 	/\* window_a->videoflags = 0; *\/ */

/*         SDL_CreateWindowAndRenderer(xsize_a, ysize_a, 0, &(window_a->window), &(window_a->renderer)); */

/*         if(!window_a->window) { */
/*                 failwith("Could not open window"); */
/*         } */

/*         if(!window_a->renderer) { */
/*                 failwith("Could not open renderer"); */
/*         } */

/*         SDL_SetRenderDrawColor(window_a->renderer, 0, 0, 0, 0); */
/*         SDL_RenderClear(window_a->renderer); */
/* } */

/* void window_close(window_t* window_a) */
/* { */
/*         SDL_DestroyRenderer(window_a->renderer); */
/*         SDL_DestroyWindow(window_a->window); */
/* } */

/* void window_draw_rect(window_t* window_a, int x, int y, int w, int h, rgb_t c) */
/* { */
/*         SDL_Rect r; */

/*         r.x = x; */
/*         r.y = y; */
/*         r.w = w; */
/*         r.h = h; */

/*         SDL_SetRenderDrawColor(window_a->renderer, c.r, c.g, c.b, SDL_ALPHA_OPAQUE);; */

/*         SDL_RenderDrawRect(window_a->renderer, &r); */
/* } */

/* void present(window_t* window_a) */
/* { */
/*         SDL_RenderPresent(window_a->renderer); */
/* } */

/* void test(window_t* window_a) */
/* { */
/*         int min = window_a->wwidth < window_a->wheight ? window_a->wwidth : window_a->wheight; */

/*         for(int i = 0; i < min; i++) { */
/*                 SDL_SetRenderDrawColor(window_a->renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);; */
/*                 SDL_RenderDrawPoint(window_a->renderer, i, i);; */
/*         } */
/* } */
