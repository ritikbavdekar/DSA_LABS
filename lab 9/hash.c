// #include "hash.h"
#include <stdio.h>
#include <string.h>

int sum_ascii(char* element)
{
	int size=strlen(element);
	size--;
	int sum=0;
	while(size>=0)
	{
		sum=sum+(int)element[size--];
	}
	return sum;

}
int hash_function(char* element,int baseNumber,int tableSize)
{
	int sum=sum_ascii(element);
	return (sum%baseNumber)%tableSize;
}