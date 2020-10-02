#include <stdio.h>
#include "queue.h"
int main()
{
	struct Queue q=newQ();
	q=addQ(q,5);
	q=addQ(q,7);
	q=addQ(q,8);
	q=addQ(q,9);
	bool r = isEmpty(q);

	if(r==false)
	{
		printf("false");
	}
	else
	{
		printf("true");
	}
	q=delQ(q);
	traverse(q.ll);
	Element a= front(q);
	printf("%d",a);
	printf("%d",lengthQ(q));
	q=delQ(q);
	q=delQ(q);
	traverse(q.ll);
	q=delQ(q);
	q=delQ(q);
	q=delQ(q);

}