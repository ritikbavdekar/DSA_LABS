#include "collision_count.h"


int collision(char** elements,int baseNumber,int tableSize,int size)
{
	int flag[tableSize];
	for(int i=0;i<tableSize;i++)
	{
		flag[i]=-1;
	}

	int index;
	// printf("\n\n%d\n\n",hash_function(elements[5],baseNumber,tableSize));
	for (int i=0;i<size;i++)
	{
		index=hash_function(elements[i],baseNumber,tableSize);
		flag[index]=flag[index]+1;
	}
	int collisions=0;
	// for(int i=0;i<tableSize;i++)
	// {
	// 	if(flag[i]!=-1)
	// 	printf("\n%d",flag[i]);
	// }
	for(int i=0;i<tableSize;i++)
	{
		if(flag[i]==-1) continue;
		else collisions+=flag[i];
	}
	return collisions;

}