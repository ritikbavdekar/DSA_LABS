#include <stdio.h>

#include "storage.h"
#include "compare.h"
int nextfreeloc = 0;
Store st;

void printJob (Job j)
{
printf ("JOB ID = %d, Priority = %d, Estimated time = %d, Arrival time = %d \n",j.id,j.pri,j.et,j.at);
}


int inputJobs (JobList list)
{
 int i; int size;

 printf("\n Enter the Number of Jobs :");
 scanf("%d", &size);

 for (i=0;i<size;i++)
 {
  printf ("\nEnter job ID");
  scanf ("%d",&list[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&list[i].pri);
  printf ("Execution Time");
  scanf ("%d",&list[i].et);
  printf ("Arrival Time");
  scanf ("%d",&list[i].at);
 }
 return size;
}

int initialize_elements (JobList ele)
{
 int i,size;
 printf ("No of Jobs");
  scanf ("%d",&size);
 for (i=0;i<size;i++)
 {
  printf ("Enter job ID");
  scanf ("%d",&ele[i].id);
  printf ("Enter Priority (from 0 - 2)");
  scanf ("%d",&ele[i].pri);
  printf ("Execution Time");
  scanf ("%d",&ele[i].et);
  printf ("Arrival Time");
  scanf ("%d",&ele[i].at);
 }
 return size;
//  i=0;
//  ele[0].id=1;
//  ele[0].pri=0;
//  ele[0].at=1;
//  ele[0].et=5;
//  ele[1].id=2;
//   ele[1].pri=1;
//    ele[1].at=9;
//     ele[1].et=3;
// ele[2].id=3;
//  ele[2].pri=2;
//   ele[2].at=11;
//    ele[2].et=12;
// ele[3].id=4;
//  ele[3].pri=0;
//   ele[3].at=4;
//    ele[3].et=7;
// ele[4].id=5;
//  ele[4].pri=1;
//   ele[4].at=8;
//    ele[4].et=2;
// ele[5].id=6;
//  ele[5].pri=2;
//   ele[5].at=12;
//    ele[5].et=11;
// ele[6].id=7;
//  ele[6].pri=0;
//   ele[6].at=3;
//    ele[6].et=9;
// ele[7].id=8;
//  ele[7].pri=1;
//   ele[7].at=7;
//    ele[7].et=4;
// ele[8].id=9;
//  ele[8].pri=2;
//   ele[8].at=13;
//    ele[8].et=10;
// ele[9].id=10;
//  ele[9].pri=0;
//   ele[9].at=2;
//    ele[9].et=15;
//  return 10;

/* ele[0].pri = ele[3].pri = ele[6].pri = PRI_0;
 ele[1].pri = ele[4].pri = ele[7].pri = PRI_1;
 ele[2].pri = ele[5].pri = ele[8].pri = ele[9].pri = PRI_2;
 for (i=0;i<MAX;i++)
 {
  ele[i].id = i+1;
  ele[i].et = i+2;
  ele[i].at = i;
 }
 ele[2].at = 10;
 ele[5].at = 1;
 ele[6].at = 5;*/
}


void printJobList(JobList list, int size)
{
	int i;
	for(i=0;i<size;i++)
	{
		printJob(list[i]);
	}

// Implement this function

}

ORDER compareit(Job j1,Job j2)                                       //Used to compare in insertion sort algorithm. It compares priorities and then arrival time or estimated time to sort in the store array 
{
	if (j1.pri>j2.pri) return LESSER;
	else if(j1.pri<j2.pri) return GREATER;
	else
	{
		return compare(j1,j2);

	}

}

void insert_sort(Job j,int count)                                  //Insertion sort algorithm used to sort the elements of the store array during insertion
{
	if(count==0)
	{
		st[0].ele=j;
	}
	else
	{	
		int i=count-1;
		st[i].next=1;
		while(compareit(j,st[i].ele)==LESSER && i>=0)
		{
			st[i+1]=st[i];
			i--;
		}
		st[i+1].ele=j;
	}
}


// }

void copy_sorted_ele(JobList list,int size) 
{
	for(int i=0;i<size;i++)
	{
		list[i]=st[i].ele;
	}

}

void assignmentSort(JobList list ,int size)
{	int count=0;
	for(int i=0;i<size;i++)
	{
		st[i].next=-1;
	}

	for(int i=0;i<size;i++)             //traversing joblist for priority 2
	{
		if(list[i].pri == PRI_2)
		{
			insert_sort(list[i],count++);

		}
	}
		for(int i=0;i<size;i++)             //traversing joblist for priority 2
	{
		if(list[i].pri == PRI_1)
		{
			insert_sort(list[i],count++);
		}
	}
		for(int i=0;i<size;i++)             //traversing joblist for priority 2
	{
		if(list[i].pri == PRI_0)
		{
			insert_sort(list[i],count++);
		}
	}

	copy_sorted_ele(list,size);
}
