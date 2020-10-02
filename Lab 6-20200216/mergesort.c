#include <stdio.h>
#include "mergesort.h"


Element* read(char* filename,int size)
{
	FILE* f= fopen(filename,"r");
	if(f==NULL)
	{
		printf("FILE Doesn't exist");
		exit(0);
	}
	char* name;
	float cgpa;
	Element temp;
	Element array[size];
	int index=0;

	while(!feof(f))
	{
		fscanf(f,"%s %f",&(temp.name),&(temp.cgpa));
		array[index++]=temp;
	}
	return array;
}

void merge(Element Ls1[],int sz1,Element Ls2[],int sz2,Element Ls[])
{
	int sz=sz1+sz2;
	int a=0,b=0;
	for (int i=0;i<sz;i++)
	{
		if(Ls1[a].cgpa>Ls2[b].cgpa)
		{
			Ls[i]=Ls2[b];
			b++;
		}
		else
		{
			Ls[i]=Ls1[a];
			a++;
		}

	}
}


void mergeSort(int arr[],int l,int r)
{
	if(r>l)
	{
		int mid;
		mid=(r-l)/2;
		mergeSort(arr,l,mid);
		mergeSort(arr,mid,r);
		Element newarr[r-l+1];
		merge(arr+1,mid-l+1,arr+mid+1,r-mid,newarr);
		for(int i=0;i<r-l+1;i++)
		{
			arr[i]=newarr[i].cgpa;
		}

	}
}
