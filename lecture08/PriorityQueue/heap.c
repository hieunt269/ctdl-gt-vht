//
//  heap.c
//  PriorityQueue
//
//  Created by TungDT on 7/24/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "heap.h"


void swap(element *a, element *b)
{
    element temp = *a;
    *a = *b;
    *b = temp;
}

void print_queue(element* queue)
{
    for (int i = 0; i < qsize; i++)
        printf("[%d, %d, %d] ", queue[i].key, queue[i].priority, queue[i].order);
    printf("\n");
}

void heapify(element* queue, int i)
{
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    int imax = i;
    
    if (left < qsize && greater(queue[left], queue[imax]))
        imax = left;
    if (right < qsize && greater(queue[right], queue[imax]))
        imax = right;
    
    if (imax != i)
    {
        swap(&queue[i], &queue[imax]);
        heapify(queue, imax);
    }
}

// compare if a is "greater" than b by priority and order
int greater(element a, element b)
{
    // TODO:
    // First compare by priority
    // Then compare by order (remind: queue is FIFO)
    if (a.priority > b.priority)
    {   
        // printf("a.p, b.p: %d - %d\n", a.priority, b.priority);
        return TRUE;
    }
    else if (a.priority == b.priority)
    {
        if (a.order < b.order)
        {
            // printf("a.o, b.o: %d - %d\n", a.order, b.order);
            return TRUE;
        }
    }

    return FALSE;
}

void enqueue(element* queue, element e)
{
    // TODO:
    // Add e to the end of the queue
    // Heapify the whole tree bottom-up
    queue[qsize++] = e;

    for (int i = qsize/2 - 1; i >= 0; i--)
    {
        heapify(queue, i);
    }
}

element dequeue(element* queue)
{
    // TODO:
    // Get 1st element, save to e
    // Swap 1st element with last element
    // Exclude last element
    // Heapify new tree bottom-up
    // Return e
    element e = queue[0];
    
    swap(&queue[0], &queue[qsize-1]);
    
    qsize--;

    for (int i = qsize/2 - 1; i >= 0; i--)
    {
        heapify(queue, i);
    }

    return e;
}

int is_empty()
{
    return qsize == 0;
}
