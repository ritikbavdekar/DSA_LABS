#include "linkedlist.h"
#include <stdio.h>
#include <stdbool.h>

typedef struct
{
	struct linkedlist* ll;
	struct node* front;
	struct node* rear;
}Queue;

typedef int Element;
Queue newQ();
bool isEmptyQ(Queue q);
Queue delQ( Queue q);
Element front( Queue q);
Queue addQ( Queue q,Element e);
int lengthQ( Queue q);