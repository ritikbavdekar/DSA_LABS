#include <stdio.h>
#include "queue.h"
typedef struct 
{
	Queue* qarr;
	int length;
	
}MultiQ;

typedef int taskID;
typedef int Priority;
typedef struct 
{
	taskID tID;
	Priority p;
	
}Task;

MultiQ createMQ(int num); 
MultiQ addMQ(MultiQ mq, Task t);
Task nextMQ(MultiQ mq); 
MultiQ delNextMQ(MultiQ mq);
bool isEmptyMQ(MultiQ mq);
int sizeMQ(MultiQ mq); 
int sizeMQbyPriority(MultiQ mq, Priority p); 
Queue getQueueFromMQ(MultiQ mq, Priority p);

