
# Kevin Yuan's makefile for Ginkgo
# August 17th, 2015

# $V=DEV for debugging
# else optimized for production
OPT_FLAGS=-g -Wall -D_DEBUG
CC=clang++ -std=c++11

CFLAGS=${OPT_FLAGS}

EXECUTABLE=linked_list_main.exe

CPP_HEADERS=linked_list.h

CPP_SRC=$(CPP_HEADERS:.h=.cc) linked_list_main.cc
OBJS=$(CPP_SRC:.cc=.o)

%.o: %.cc $(CPP_HEADERS)
	$(CC) -c $< -o $@ $(CFLAGS)

$(EXECUTABLE): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f *.o *.exe

.PHONY: all
all:
	make clean
	make
