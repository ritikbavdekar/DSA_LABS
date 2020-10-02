// #include "linkedlist.h"
#include "queue.h"

Queue newQ()
{
	Queue q;
	q.ll=(struct ll*) malloc(sizeof(struct linkedlist));
	q.front=NULL;
	q.rear=NULL;
	return q;
}

bool isEmptyQ( Queue q)
{
	if (q.front==NULL)
		return true;
	else return false;
}

Queue delQ( Queue q)
{
	if(q.front==NULL)
		{
			printf("queue is empty");
			return q;
		}
	delete_start(q.ll);
	q.front=(q.ll)->first;
	return q;
}

Element front( Queue q)
{
	struct node* t;
	t=(q.ll)->first;
	Element e=t->value;
	return e;
}
Queue addQ(Queue q,Element e)
{
	struct linkedlist* list=q.ll;
	struct node* n=insert_end(list,e);
	if(q.front==NULL)
	{
		q.front=q.rear=n;
	}
	if(q.rear==NULL)
	{
		q.rear=n;
	}
	return q;
}

int lengthQ(Queue q)
{
	struct linkedlist* list= q.ll;
	return list->count;
}
