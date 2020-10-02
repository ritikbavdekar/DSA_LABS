#include <stdio.h>
#include "mergesort.h"

int main()
{
	Element* arr;
	arr=read("1024.txt",1024);
	for (int i=0;i<1024;i++)
	{
		printf(" %d ,",arr[i]);
	}
	mergeSort(arr,0,1023);
		for (int i=0;i<1024;i++)
	{
		printf(" %d ,",arr[i]);
	}

}