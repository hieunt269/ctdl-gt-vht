//
//  jobs.c
//  QueueJobs
//
//  Created by TungDT on 8/2/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include "jobs.h"

job* create_job(job_data data)
{
    job* j = (job*) malloc(sizeof(job));
    j->data = data;
    j->next = NULL;
    return j;
}
void init_queue(job** jobs_queue)
{
    if (*jobs_queue != NULL) clear_queue(jobs_queue);
}
void clear_queue(job** jobs_queue)
{
    while (*jobs_queue != NULL)
    {
        job* j = *jobs_queue;
        *jobs_queue = j->next;
        free(j);
    }
    
}
void enqueue(job** jobs_queue, job_data ajob)
{
    job* j = create_job(ajob);
    
    if (is_empty(*jobs_queue)) *jobs_queue = j;
    else
    {
        job* rear = *jobs_queue;
        while (rear->next != NULL) rear = rear->next;
        rear->next = j;
    }
}
job_data dequeue(job** jobs_queue)
{
    if (is_empty(*jobs_queue))
    {
        printf("Jobs queue is empty!");
        exit(1);
    }
    else
    {
        job* j = *jobs_queue;
        *jobs_queue = j->next;
        job_data data = j->data;
        free(j);
        return data;
    }
}

int is_empty(job* jobs_queue)
{
    return jobs_queue == NULL;
}
int get_size(job* jobs_queue)
{
    int size = 0;
    while (jobs_queue != NULL)
    {
        size++;
        jobs_queue = jobs_queue->next;
    }
    return size;
}
