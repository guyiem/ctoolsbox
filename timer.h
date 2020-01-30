/* -*- c-basic-offset: 8 -*- */
#ifndef TIMER_H
#define TIMER_H

#include <sys/time.h>


/** A timer class, with microsecond resolution.
 */

typedef struct {
	struct timeval tv_start;
	struct timeval tv_stop;

	int startusec;
	int stopusec;
} ztimer_t;

static inline void ztimer_start(ztimer_t* timer_a)
{
	gettimeofday(&timer_a->tv_start,NULL); 
	timer_a->startusec = 
		timer_a->tv_start.tv_sec * 1000000 
		+ timer_a->tv_start.tv_usec;
}

static inline int ztimer_get_usec(ztimer_t* timer_a)
{
	gettimeofday(&timer_a->tv_stop,NULL);
	timer_a->stopusec = timer_a->tv_stop.tv_sec * 1000000 
		+ timer_a->tv_stop.tv_usec;
	return timer_a->stopusec - timer_a->startusec;
}

static inline double ztimer_get_sec(ztimer_t* timer_a)
{
	return (double)(ztimer_get_usec(timer_a)) / 1000000.0;
}

#endif /* TIMER_H */
