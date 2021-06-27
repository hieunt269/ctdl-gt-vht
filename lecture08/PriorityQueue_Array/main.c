
#include <stdio.h>
#include "priority_queue.h"

int front = -1;
int rear = -1;

int main(int argc, const char * argv[])
{
    int keys[] =       {1, 2, 3, 4, 5, 6, 7};
    int priorities[] = {1, 1, 2, 1, 2, 3, 1};
    int n = 7;
    node queue[QUEUE_SIZE];
    
    printf("Queue:\n");

    node n = {keys[0], priorities[0]};

    for (int i = 1; i < n; ++i)
    {
        node n = {keys[i], priorities[i]};
        enqueue(queue, n);

        for (int j = i - 1; j >= 0; j--)
        {
            if (queue[i].priorities > queue[j].priorities)
            {
                swap(&queue[i], &queue[j]);
            }
        }
    }

    print_queue(queue);
    
    // printf("Dequeue:\n");
    // while (!is_empty())
    // {
    //     element e = dequeue(queue);
    //     printf("[%d, %d, %d] ", e.key, e.priority, e.order);
    // }
    // printf("\n");
    
    return 0;
}