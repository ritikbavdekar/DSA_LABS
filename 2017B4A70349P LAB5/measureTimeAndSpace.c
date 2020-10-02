#include "measureTimeAndSpace.h"
#include <math.h>

void timeForReading(){
	creditCard* cardArray;
	int size;
	FILE* timing = fopen("results.txt","w");

	char filename[10];

	struct timeval t1, t2;
	double elapsedTime;

	int tocheck;
	for(int i=1;i<8;i++){
		tocheck = pow(10,i);
		
		gettimeofday(&t1, NULL);
		if(i<6){
			sprintf(filename,"%d", tocheck);
			cardArray = readCard(cardArray,filename,&size);
		}
		else{
			for(int j=0;j<tocheck/100000;j++)
				cardArray = readCard(cardArray,filename,&size);
		}
		gettimeofday(&t2, NULL);
		elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
		elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
		fprintf(timing, "Read %d structs in %lf milliseconds.\n",tocheck,elapsedTime);
	}
	fclose(timing);
}

void timeForSorting(){
	creditCard* cardArray;
	int size;
	FILE* timing = fopen("resultsSort.txt","w");

	char filename[10];

	struct timeval t1, t2;
	double elapsedTime;

	int tocheck;
	for(int i=1;i<6;i++){
		tocheck = pow(10,i);
		
		gettimeofday(&t1, NULL);
		if(i<6){
			sprintf(filename,"%d", tocheck);
			cardArray = readCard(cardArray,filename,&size);
		}
		else{
			for(int j=0;j<tocheck/100000;j++)
				cardArray = readCard(cardArray,filename,&size);
		}
		insertionSort(cardArray,size);
		gettimeofday(&t2, NULL);
		elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
		elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
		fprintf(timing, "Sorted %d structs in %lf milliseconds.\n",tocheck,elapsedTime);
	}
	fclose(timing);
}

void spaceForSorting(){
	creditCard* cardArray;
	int size;
	FILE* timing = fopen("resultsSortspace.txt","w");
	char filename[10];

	int tocheck;
	for(int i=1;i<6;i++){
		int asd;
		tocheck = pow(10,i);
		
		if(i<6){
			sprintf(filename,"%d", tocheck);
			cardArray = readCard(cardArray,filename,&size);
		}
		else{
			for(int j=0;j<tocheck/100000;j++)
				cardArray = readCard(cardArray,filename,&size);
		}
		insertionSort(cardArray,size);
		fprintf(timing, "Number Of elements sorted:%d, Top Of Stack:%d, Bottom Of Stack:%d, Difference: %d.\n",tocheck,topstack,&asd,(unsigned long long)&asd-(unsigned long long)topstack);
	}
	fclose(timing);
}

void timeForReadingTest(char* filename,char* targetfile){
	creditCard* cardArray;
	int size;
	FILE* timing = fopen(targetfile,"a");

	struct timeval t1, t2;
	double elapsedTime;
		
	gettimeofday(&t1, NULL);
	cardArray = readCard(cardArray,filename,&size);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	fprintf(timing, "Read %d structs in %lf milliseconds.\n",size,elapsedTime);
	fclose(timing);
}

void timeForSortingTest(char* filename,char* targetfile){
	creditCard* cardArray;
	int size;
	FILE* timing = fopen(targetfile,"a");

	struct timeval t1, t2;
	double elapsedTime;
		
	gettimeofday(&t1, NULL);
	cardArray = readCard(cardArray,filename,&size);
	insertionSort(cardArray,size);
	gettimeofday(&t2, NULL);
	elapsedTime = (t2.tv_sec - t1.tv_sec) * 1000.0;
	elapsedTime += (t2.tv_usec - t1.tv_usec) / 1000.0;
	fprintf(timing, "Sorted %d structs in %lf milliseconds.\n",size,elapsedTime);
	fclose(timing);
}

void spaceForSortingTest(char* filename,char* targetfile){
	creditCard* cardArray;
	int size;
	FILE* timing = fopen(targetfile,"a");
	int asd;		
	cardArray = readCard(cardArray,filename,&size);
	insertionSort(cardArray,size);
	fprintf(timing, "Number Of elements sorted:%d, Top Of Stack:%d, Bottom Of Stack:%d, Difference: %d.\n",size,topstack,&asd,(unsigned long long)&asd-(unsigned long long)topstack);
	fclose(timing);
}