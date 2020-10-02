#include "collision_count.h"
#include "parser.h"
#include <stdio.h>
#include <stdlib.h>

int tablesize[3]={5000,50000,500000};
int prime[3][6]={{5623,7607,9067,5001001,5021279,6003623},{50551,75511,99733,50001499,75002761,99001031},{501719,752833,992861,500012069,750008443,900024611}};
// int prime_2[]={50551,75511,99733,50001499,75002761,99001031};
// int prime_3[]={501719,752833,992861,500012069,750008443,900024611};

int main()
{
	int size=get_size("aliceinwonderland.txt");
	char** book=parse("aliceinwonderland.txt",size);
	int min_tablesize;
	int min_prime;
	int min_collide;
	int collide=0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<6;j++)
		{
		collide=collision(book,prime[i][j],tablesize[i],size);
		printf("\nFor basenumber=%d and tablesize=%d collisions=%d\n",prime[i][j],tablesize[i],collide);
		if(i==0 && j==0)
		{
			min_collide=collide;
			min_prime=j;
			min_tablesize=i;
		}
		else
		{
			if(collide<min_collide)
			{
			min_collide=collide;
			min_prime=j;
			min_tablesize=i;
			}
		}
		}
	}
	printf("\nMinimum collisions at index i=%d and j=%d \n",min_tablesize,min_prime);
	printf("collisions=%d \n",min_collide);
	printf("basenumber=%d \n",prime[min_tablesize][min_prime]);
	printf("tablesize=%d \n",tablesize[min_tablesize]);
	free(book);
	return 0;
}