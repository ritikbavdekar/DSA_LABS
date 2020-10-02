#include <stdio.h>
#include <stdbool.h>
#include "linkedlist.h"

bool testcyclic(struct linkedlist* ll)
{
	struct node *hare,*tortoise;
	tortoise=ll->first;
	hare=ll->first;
	if(ll->first==NULL)
		 return false;
	if(tortoise->next==NULL)
		return false;

	while(1)
	{
		if(hare->next==NULL)
			return false;
		hare=hare->next;
		if (hare==tortoise)
			return true;
		if(hare->next==NULL)
			return false;
		hare=hare->next;
		if(hare==tortoise)
			return true;
		tortoise=tortoise->next;
	}
}