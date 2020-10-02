/***********file:   seqListOps.h *********/
#include "storage.h"

extern int inputJobs(JobList list);
extern void sortJobList(JobList list, int size);
extern void printJobList(JobList list, int size );
extern SeqList createList();
extern void printJob(Job j);
extern int inputJobs(JobList list);
extern int initialize_elements(JobList ele);
extern SeqList insert(Job j,SeqList sl);
extern void insertelements(JobList list,int size, SeqList s[3]);
extern void copy_sorted_ele(SeqList s[3],JobList ele);
extern void printseqlist(SeqList sl);
extern void assignmentSort(JobList list,int size);
extern void assignmentSort(JobList list, int size);


