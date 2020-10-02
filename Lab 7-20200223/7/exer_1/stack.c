#include "stack.h"
#include <stdlib.h>

StackInt* newStack(){
	StackInt* stack = (StackInt*)malloc(sizeof(StackInt));
	stack->top = NULL;
	stack->size = 0;
	return stack;
}

void push(StackInt* stack, int a, int b){
	NodeInt* newNodePointer = (NodeInt*)malloc(sizeof(NodeInt));
	newNodePointer->l = a;
	newNodePointer->r = b;

	newNodePointer->next = stack->top;
	stack->top=newNodePointer;
	stack->size++;
}

NodeInt pop(StackInt* stack){
	NodeInt newNode;
	if(stack->size==0){
		newNode.l = -1;
		newNode.r = -1;
		newNode.next = NULL;
		return newNode;
	}

	newNode=*(stack->top);
	stack->top = (stack->top)->next;
	(stack->size)--;
	return newNode;
}