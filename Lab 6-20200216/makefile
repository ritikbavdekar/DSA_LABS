CC=gcc
compMS: main.o mergesort.o
	$(CC) main.o mergesort.o -o MergeSorted.exe

runMS: compMS 
	./MergeSorted.exe

main.o: main.c
	$(CC) -c main.c

mergesort.o: mergesort.c mergesort.h
	$(CC) -c mergesort.c 
