#include <stdio.h>
#include "linkedlist.h"

int main()
{
	struct linkedlist* ll= (struct linkedlist *)malloc(sizeof(struct linkedlist));
	insert_start(ll,4);
	insert_start(ll,5);
	insert_start(ll,6);
	insert_start(ll,7);
	insert_start(ll,8);
	traverse(ll);
	insert_end(ll,3);
	traverse(ll);
	delete_start(ll);
	traverse(ll);
	delete_end(ll);
	traverse(ll);

}