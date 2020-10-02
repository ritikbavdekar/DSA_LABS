#include <stdio.h>
#include <stdlib.h>
#include "multiQ.h"

MultiQ createMQ(int num)
{
	MultiQ mq;
	mq.length=num;
	mq.qarr=malloc(sizeof(Queue)*num);
	for(int i=0;i<num;i++)
	{
		mq.qarr[i]=newQ();

	}
	return mq;
}

MultiQ addMQ(MultiQ mq,Task t)
{
	int index=(t.p)-1;
	mq.qarr[index]=addQ(mq.qarr[index],t.tID);
	return mq;
}

Task nextMQ(MultiQ mq)
{
	if(isEmptyMQ(mq))
	{
		printf("Empty MultiQ");
		Task t;
		t.tID=-1;
		t.p=-1;
		return t;
	}
	int i=mq.length-1;
	while(isEmptyQ(mq.qarr[i]))
	{
		i--;
	}
	Task t;
	t.tID=front(mq.qarr[i]);
	t.p=i+1;
	return t;

}

MultiQ delNextMQ(MultiQ mq)
{
	if(isEmptyMQ(mq)) return mq;
	int i=mq.length-1;
	while(isEmptyQ(mq.qarr[i])) i--;
	mq.qarr[i]=delQ(mq.qarr[i]);
	return mq;
}

bool isEmptyMQ(MultiQ mq)
{
	for (int i = mq.length-1; i > -1; i--)
	{
		if(isEmptyQ(mq.qarr[i]))
		{
		}
		else return false;
	}
	return true;
}

int sizeMQ(MultiQ mq)
{
	int size=0;
	for(int i=0;i<mq.length;i++)
	{
		if(isEmptyQ(mq.qarr[i])) continue;
		size=size+lengthQ(mq.qarr[i]);

	}
	return size;
}

int sizeMQbyPriority(MultiQ mq, Priority p)
{
	return lengthQ(mq.qarr[p-1]);
}

Queue getQueueFromMQ(MultiQ mq,Priority p)
{
	return mq.qarr[p-1];
}