#include <stdio.h>
#include "memoryalloc.h"
#include <stdlib.h>

long long int heapspace=0;
void* myalloc(int x)
{
	void* ptr;
	ptr=malloc(x);
	heapspace+=x;
	return ptr;
}

void myfree(void* ptr)
{
	long int size=sizeof(*ptr);
	heapspace-=size;
	free(ptr);
	return;
}
