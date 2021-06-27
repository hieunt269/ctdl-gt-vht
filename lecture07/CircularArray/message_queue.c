//
//  message_queue.c
//  CircularArray
//
//  Created by TungDT on 8/1/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "message_queue.h"
#include <string.h>
void clear_queue(void)
{    
    front = rear = -1;
}
int is_empty(void)
{
    return front == -1;
}
int is_full(void)
{
    if (front == rear + 1) return TRUE;
    if (front == 0 && rear == BUFFER_SIZE - 1) return TRUE;
    return FALSE;
}
void enqueue(char* msg)
{
// TODO:
//    Check if queue is full
//    Else
//        If queue is empty front = 0
//        Increase rear (go back if needed)
//        Add message to rear position
    if (is_full())
    {
        overflow("Queue is full!");
    }
    else
    {
        if (is_empty) front = 0;
        rear = (rear + 1) % BUFFER_SIZE;
        msg_queue[rear] = msg;
    }
}
char* dequeue(void)
{
//TODO:
//    Check if message is empty
//        Else
//        Get message at front
//        If there is one message, clear queue
//        Else increase front (go back if needed)
    if (is_empty())
    {
        overflow("Queue is empty!");
        exit(1);
    }
    else
    {
        char *temp = msg_queue[front];
        if (size() == 1) clear_queue();
        else front = (front + 1) % BUFFER_SIZE;
        return temp;
    }
}
int size(void)
{
    // [][][r][][][][f][][][]
    if (front <= rear) return rear - front + 1;
    else return BUFFER_SIZE - (front - rear - 1);
}
void overflow(char* msg)
{
    printf("%s\n", msg);
    exit(1);
}
