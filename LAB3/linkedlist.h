#include <stdio.h>
 struct node
 {
 	struct node* next;
 	int value;
 };

 struct linkedlist{
 	int count;
 	struct node* first;
 };

void insert_start(struct linkedlist*,int a);
struct node* insert_end(struct linkedlist*,int a);
void traverse(struct linkedlist*);
void delete_start(struct linkedlist*);
void delete_end(struct linkedlist*);
// void search();
