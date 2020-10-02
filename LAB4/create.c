#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "memoryalloc.h"
#include "create.h"

struct linkedlist* createList(int n)
{
	struct linkedlist* ll = (struct linkedlist*)myalloc(sizeof(struct linkedlist));
	srand(time(0));
	for(int i=0;i<n;i++)
	{
		insert_end(ll,rand());
	}
	return ll;
}

struct linkedlist* createCycle(struct linkedlist* ll)
{
	srand(time(0));
	int n =rand();
	if(n%2==0)
	{
		return ll;
	}
	int size=ll->count;
	n=rand();
	n=n%size;
	if(n>0) n=n-1;
	struct node* temp;
	temp=ll->first;
	if(temp==NULL)
	{
		return ll;
	}
	while(n--!=0)
	{
		temp=temp->next;
	}
	struct node* end;
	end=ll->first;
	while(end->next!=NULL)
	{
		end=end->next;
	}
	end->next=temp->next;
	return ll;

}