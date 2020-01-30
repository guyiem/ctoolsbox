CC = gcc-7
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
BIN = main

DEFINES = #-DNOASSERT
CFLAGS = -O3 -W -Wall -std=gnu99 -ffast-math -fopenmp $(DEFINES) # -c99
#STATIC = lib3ds.a
LDFLAGS = -lm -lSDL2 -lfftw3 -lgsl -lgslcblas -lgomp -DHAVE_INLINE #  -lGL -lGLU

all: $(OBJS)
	$(CC) -o $(BIN) $(OBJS) $(STATIC) $(LDFLAGS)

debug: $(OBJS)
	$(CC) -g -o $(BIN) $(OBJS) $(STATIC) $(LDFLAGS)


%.o:%.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -rf *~
	rm -rf $(OBJS)


