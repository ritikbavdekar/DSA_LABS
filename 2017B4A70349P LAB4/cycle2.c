#include <stdio.h>
#include "linkedlist.h"
#include <stdbool.h>

bool testcyclic(struct linkedlist* ll)
{
	struct node *node1,*node2,*node3;
	if(ll->first==NULL)
		 return false;
	node1=ll->first;
	node2=ll->first;
	node3=ll->first;
	if(node1->next==NULL)
		return false;
	node2=node1->next;
	if(node2->next==NULL)
		return false;
	node3=node2->next;
	int count=0;
	node1->next=NULL;
	while(node3!=NULL)
	{
		node2->next=node1;
		node1=node2;
		node2=node3;
		node3=node3->next;
		count++;
	}
	while(count--!=0 && node1!=NULL)
	{
		node1=node1->next;
	}
	if (node1->next==NULL)
		return false;
	return true;



}