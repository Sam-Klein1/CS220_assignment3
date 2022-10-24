CC = gcc
CFLAGS = -Wall 

test : main
	./main

test1 : main
	./main 1

test2 : main
	./main 2

main : add_arrays_asm.o reverse_in_place_asm.o
	${CC} ${CFLAGS} main.c add_arrays_asm.o reverse_in_place_asm.o -o main

add_arrays_asm.o:
	${CC} -c add_arrays_asm.S -o add_arrays_asm.o

reverse_in_place_asm.o:
	${CC} -c reverse_in_place_asm.S -o reverse_in_place_asm.o

clean:
	-rm main reverse_in_place_asm.o add_arrays_asm.o
