

ifeq ($(V), DEV)
	OPT_FLAGS=-g -Wall -D_DEBUG
else
	OPT_FLAGS=
endif

CC=g++
CFLAGS=${OPT_FLAGS}

EXECUTABLE=main

CPP_HEADERS= \
						 util.hpp

CPP_SRC=$(CPP_HEADERS:.hpp=.cpp) main.cpp
OBJS=$(CPP_SRC:.hpp=.o)

%.o: %.cpp $(CPP_HEADERS)
	$(CC) -c $< -o $@ $(CFLAGS)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean

clean:
	rm -f *.o main

.PHONY: all

all:
	make clean
	make
