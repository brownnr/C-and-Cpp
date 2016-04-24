all: prog

prog: animal.o main.o
	gcc -g -Wall -std=c99 -o prog animal.o main.o

main.o: main.c
	gcc -g -Wall -std=c99 -c main.c
		
animal.o: animal.c animal.h
	gcc -g -Wall -std=c99 -c animal.c

clean:	
	rm animal.o
	rm main.o
	rm prog
