#include <stdio.h>
#include "linkedlist.h"
#include <stdlib.h>

void insert_start(struct linkedlist* ll,int a)
{
	struct node* ele =(struct node*) malloc(sizeof(struct node));
	ele->value=a;
	ele->next=ll->first;
	ll->first=ele;
	ll->count++;
}

struct node* insert_end(struct linkedlist* ll,int a)
{
	struct node* ele=(struct node*) malloc(sizeof(struct node));
	ele->value=a;
	ele->next=NULL;
	ll->count++;
	struct node* temp;
	temp=ll->first;
	if(temp==NULL)
	{
		ll->first=ele;
		return ele;
	}
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp->next=ele;
	return ele;
}

void traverse(struct linkedlist* ll)
{
	struct node* temp;
	temp=ll->first;
	printf("\n[ ");
	while(temp!=NULL)
	{
		printf("%d ",temp->value);
		temp=temp->next;
	}
	printf(" ]");
}

void delete_start(struct linkedlist* ll)
{
	if(ll->first==NULL)
	{
		printf("Empty");
		return;
	}
	struct node* t;
	t=ll->first;
	ll->first=t->next;
	free(t);
	ll->count--;
	return;
}

void delete_end(struct linkedlist* ll)
{
	if(ll->first==NULL)
	{
		printf("Empty");
		return;
	}
	ll->count--;
	struct node* temp;
	struct node* ptemp;
	temp=ll->first;

	if(temp==NULL)
	{
		ll->first=NULL;
		return;
	}
	while(temp->next!=NULL)
	{
		ptemp=temp;
		temp=temp->next;
	}
	// free(temp);
	// printf("\n%d",ptemp->value);
	ptemp->next=NULL;
	return;
}

