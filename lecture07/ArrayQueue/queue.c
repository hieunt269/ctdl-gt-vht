//
//  queue.c
//  ArrayQueue
//
//  Created by TungDT on 7/30/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "queue.h"

void clear_queue(void)
{
    front = rear = -1;
}
int is_empty(void)
{
    return front == -1 || front > rear;
}
int is_full(void)
{
    return rear == QUEUE_SIZE - 1;
}
void enqueue(const int n)
{
    if (is_full())
        overflow("Queue is full\n");
    else
        queue[++rear] = n;
}
int dequeue(void)
{
    if (is_empty())
        //overflow("Queue is empty!\n");
        exit(1);
    else if (front < rear)
        return queue[front++];
    else
    {
        int n = queue[front];
        front = rear = -1;
        return n;
    }
}
int size(void)
{
    if (is_empty()) return 0;
    else return rear - front + 1;
}

void overflow(char* msg)
{
    printf("Error: %s\n", msg);
}
