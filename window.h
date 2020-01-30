/* /\*-*- c-basic-offset: 8 -*-*\/ */

/* #ifndef WINDOW_H */
/* #define WINDOW_H */

/* #include <SDL2/SDL.h> */
/* #include "types.h" */

/* /\* */
/*      HOWTO: */
/*      1) initialize_graphics(); */
/*      2) init window */
/*      3) set_pixels and draw */
/* *\/ */

/* typedef struct { */
/* 	int wwidth; */
/* 	int wheight; */
/* 	/\* rgb_t* pixbuf; *\/ */
/* 	/\* int videoflags; *\/ */
/* 	/\* int depth; *\/ */
/* 	/\* int resizeable; *\/ */
/*         SDL_Renderer* renderer; */
/*         SDL_Window* window; */
/* 	// SDL_Surface* screen; */
/* } window_t; */

/* void initialize_graphics(void); */

/* /\** Initializes the graphic context. */
/*  * @param window_a the window to initialize. */
/*  * @param xsize_a window width. */
/*  * @param ysize_a window height. */
/*  *\/ */
/* void window_init(window_t* window_a,int xsize_a,int ysize_a); */

/* /\** Make the window appear on the screen. */
/*  * @param window_a the window to open. */
/*  *\/ */
/* // void window_open(window_t* window_a); */

/* /\** Closes a window, and frees some resources. */
/*  * @param window_a the window to close. */
/*  *\/ */
/* void window_close(window_t* window_a); */

/* /\** Once the window is open, setup some OpenGL variables. */
/*  *\/ */
/* // void setup_opengl(void); */
 
/* /\** \def set_pixel(_w,_x,_y,_c) */
/*  * This macro sets a pixel in the image to be drawn. */
/*  *\/ */
/* /\* #define set_pixel(_w,_x,_y,_c) do {\ *\/ */
/* /\* 	(_w)->pixmap[(_y) * (_w)->wwidth + (_x)] = _c;\ *\/ */
/* /\* } while(0)\ *\/ */

/* static inline void set_pixel(window_t* window, int x, int y, rgb_t color) */
/* { */
/*         SDL_SetRenderDrawColor(window->renderer, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);; */
/*         SDL_RenderDrawPoint(window->renderer, x, y);; */
/* } */

/* void window_draw_rect(window_t* window_a, int x, int y, int w, int h, rgb_t c); */

/* void present(window_t* window_a); */


/* #endif /\* WINDOW_H *\/ */
