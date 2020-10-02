#include "multiQ.h"
#include <stdio.h>
#define FILENAME "input10000.txt"
#define DELETENO 7000
#include <sys/time.h>

MultiQ loadData(FILE *f)
{
	MultiQ mq;
	mq=createMQ(10);
	Task t;
	taskID t1;
	Priority p1;
	while(!(feof(f)))
	{
		fscanf(f,"%d,%d",&t1,&p1);
		fgetc(f);
		t.tID=t1;
		t.p=p1;
		mq=addMQ(mq,t);

	}
	return mq;
}

MultiQ testDel(MultiQ mq,int num)
{
	for(int i=0;i<num;i++) mq=delNextMQ(mq);
	return mq;
}

int main()
{
	struct timeval t1, t2;
	double elapsedTime;
	FILE *f;
	f=fopen(FILENAME,"r");
	if(f==NULL)
	{
		printf("Error");
		exit(1);
	}
	gettimeofday(&t1,NULL);

	MultiQ mq=loadData(f);
	gettimeofday(&t2,NULL);
	elapsedTime=(t2.tv_sec-t1.tv_sec)*1000;
	elapsedTime+=(t2.tv_usec-t1.tv_usec)/1000;
	printf("\nTotal time for loading data is %f milliseconds\n",elapsedTime);
	fclose(f);
	gettimeofday(&t1,NULL);
	mq=testDel(mq,DELETENO);
	gettimeofday(&t2,NULL);
	elapsedTime=(t2.tv_sec-t1.tv_sec)*1000;
	elapsedTime+=(t2.tv_usec-t1.tv_usec)/1000;
	printf("\nTotal time for deleteing data is %f milliseconds\n",elapsedTime);

}