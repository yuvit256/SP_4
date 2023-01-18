CC = gcc
FLAGS = -Wall -g
AR = ar
.PHONY: clean all

all: graph

graph: main.o graphlib.a
	$(CC) $(FLAGS) -o graph main.o graphlib.a

main.o: main.c graph.h 
	$(CC) $(FLAGS) -c main.c 

graph.o: graph.c graph.h
	$(CC) $(FLAGS) -c graph.c

graphlib.a: graph.o
	$(AR) -rcs graphlib.a graph.o

clean: 
	rm -f *.o *.a graph


