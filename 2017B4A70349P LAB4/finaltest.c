#include <stdio.h>
#include <stdlib.h>
#include "create.h"
#include <stdbool.h>
#include <sys/time.h>
#include "memoryalloc.h"
#define NO_of_Elements 5000

int main()
{
	printf("\nHeap Memory before program starts is %lld \n",heapspace);
	struct linkedlist* ll;
	ll=createList(NO_of_Elements);
	ll=createCycle(ll);
	struct timeval t1, t2;
	double elapsedTime;
	gettimeofday(&t1,NULL);
	bool test=testcyclic(ll);
	gettimeofday(&t2,NULL);
	elapsedTime=(t2.tv_usec-t1.tv_usec);
	printf("\nHeap Memory after program ends is %lld \n",heapspace);
	printf("\nTotal time for algorithm is %f microseconds \n",elapsedTime);
	if (test==true)
	{
		printf("\nTrue:LinkedList IS cyclic\n");
	}
	else
		printf("\nLinkedList is NOT cyclic!!!!\n");
}