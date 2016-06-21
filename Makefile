CC = g++
CFLAGS = -Wall -g -std=c++11

all: main

clean:
	rm -rf *o
	rm prime_nums

main.o:
	${CC} ${CFLAGS} -c prime_num.cc prime_num.h includes.h

main: main.o
	${CC} ${CFLAGS} prime_num.o -o prime_nums
