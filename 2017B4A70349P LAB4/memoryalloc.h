#include <stdio.h>

extern long long int heapspace;

void* myalloc(int x);
void myfree(void* ptr);
