#include <stdio.h>
#include "multiQ.h"

int main()
{
	MultiQ mq;
	mq=createMQ(5);

	bool check=isEmptyMQ(mq);
	printf("%d",check);

	Task t;
	t.tID=4;
	t.p=3;


	mq=addMQ(mq,t);

	t.tID=2;
	t.p=1;

	mq=addMQ(mq,t);
	t.tID=54;
	t.p=2;


	mq=addMQ(mq,t);
	t.tID=56;
	t.p=2;
	mq=addMQ(mq,t);


	// t=nextMQ(mq);
	// printf("%d",t.tID);
	// printf("\n%d",sizeMQ(mq));
	// mq=delNextMQ(mq);
	struct Queue q;
	q=getQueueFromMQ(mq,2);
	// mq=delNextMQ(mq);
	// printf("\n%d",sizeMQbyPriority(mq,2));
	// t=nextMQ(mq);
	traverse(q.ll);


	// printf("%d",t.tID);







	// Task t[5];
	// for(int i=0;i<5;i++)
	// {
	// 	t[i].tID=i;
	// 	t[i].p=i;
	// 	mq=addMQ(mq,t[i]);

	// }

}