#ifndef TOOLS_H
#define TOOLS_H

#ifdef __USE_GNU
#undef __USE_GNU
#include <stdio.h>
#else
#include <stdio.h>
#endif

#include <stdlib.h>

#define failwith(_s) do {\
                     fprintf(stderr,"Error raised in function %s, in file %s, at line %d. %s.\n",\
                     __FUNCTION__, \
                     __FILE__, \
                     __LINE__, \
		     _s);\
                     abort();\
                     } while(1) 

#ifndef NOASSERT
#define ensure(_b) do {\
	if(!(_b)) {\
		failwith("Assertion " #_b " failed");\
	}\
} while(0)
#else
#define ensure(_b) ;
#endif

#ifdef DEBUGOUTPUT
#define MESS(_s) do {\
                    fprintf(stderr,"%d : At line %d in function %s in file %s : %s\n",\
                            getpid(),\
                            __LINE__,\
                            __FUNCTION__,\
                            __FILE__,\
                            _s); } while (0) 
#else
#define MESS(_s) ;
#endif

#endif // TOOLS_H
