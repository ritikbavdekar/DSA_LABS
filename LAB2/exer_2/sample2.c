#include <stdio.h>
int main()
{
	FILE *fptr;
	int num;
	fptr=fopen("program.txt","r");

	if(fptr==NULL)
	{
		printf("Error!");
		exit(1);
	}
	fscanf(fptr,"%d",&num);
	printf("%d",num);
	return 0;

}