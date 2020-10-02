#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
int main(int argc, char *argv[])
{
	FILE * fileptr = fopen(argv[1], "r");
	struct stack * st = createStack();
	while (!feof(fileptr))
	{
		int temp;
		fscanf(fileptr, "%d ", &temp);
		push(st,temp);
	}
	fclose(fileptr);

	int temp;
	while((temp=pop(st))!=-1){
		printStack(st);
		printf("%d Element Deleted\n",temp);
	}
}
