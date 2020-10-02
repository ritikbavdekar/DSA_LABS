#include "employee.h"

#ifndef STACK_H
#define STACK_H

struct node{
	int l;
	int r;
	struct node* next;
};

typedef struct node NodeInt;

typedef struct {
	NodeInt* top;
	int size;
} StackInt;

StackInt* newStack();
void push(StackInt* stack, int a, int b);
NodeInt pop(StackInt* stack);
#endif