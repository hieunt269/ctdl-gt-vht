
#ifndef priority_queue_h
#define priority_queue_h

#include <stdio.h>
#include <stdlib.h>

#define QUEUE_SIZE 7

extern int front;
extern int rear;

typedef struct str_node node;

struct str_node
{
	int key;
	int priority;
};

void clear_queue(void);
int is_empty(void);
int is_full(void);
void enqueue(node* queue, node n);
// int dequeue(void);
int size(void);
void print_queue(node* queue)
void overflow(char* msg);
void swap(node *a, node *b);

#endif /* priority_queue_h */