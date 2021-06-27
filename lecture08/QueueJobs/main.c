//
//  main.c
//  QueueJobs
//
//  Created by TungDT on 8/2/20.
//  Copyright © 2020 macOne. All rights reserved.
//

#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include "jobs.h"

#define JOB_TIME 5
#define WAIT_TIME 5
#define NJOBS 5
#define NAGENTS 3

void* generate_jobs(void* threadid);
void* handle_jobs(void* threadid);

job_data create_job_data(const int id, const int agent_id);
void waiting_job(void);
void quit_handle(void);
void handle_job(void);

job* jobs_queue;
int njobs = 0;
pthread_mutex_t locker;

int main(int argc, const char * argv[])
{
    pthread_t tid;
    
    init_queue(&jobs_queue);
    // init randomizer
    time_t t;
    srand((unsigned) time(&t));
    
    // init locker
    pthread_mutex_init(&locker,NULL);
    
    // create threads to generate jobs in parallel
    for (int agent_id = 1; agent_id <= NAGENTS; agent_id++)
        pthread_create(&tid, NULL, generate_jobs, (void*)agent_id);
    // create thread to handle generated jobs
    pthread_create(&tid, NULL, handle_jobs, NULL);
    
    pthread_exit(NULL);
}

job_data create_job_data(const int id, const int agent_id)
{
    job_data jd;
    jd.job_id = id;
    jd.agent_id = agent_id;
    jd.duration = rand() % JOB_TIME;
    return jd;
}

void* generate_jobs(void* threadid)
{
    int agent_id = (int) threadid;
    
    for (int i = 1; i <= NJOBS; i++)
    {
        pthread_mutex_lock(&locker); // lock the locker
        
        // TODO:
        // increase number of jobs
        // create job data
        // enqueue job data
        njobs++;

        job_data job_created = create_job_data(njobs, agent_id);

        enqueue(&jobs_queue, job_created);

        printf("Agent id %d create job %d \n", job_created.agent_id, job_created.job_id);
        
        pthread_mutex_unlock(&locker); // unlock the locker
        
        sleep(rand() % WAIT_TIME);
    }
    pthread_exit(NULL);
}

void* handle_jobs(void* threadid)
{
// TODO:
//    Endless loop
//        Lock the locker
//        If jobs queue is empty and no more jobs in future
//            Quit handle thread
//        Else If queue is not empty
//            Handle a job
//        Else
//            Wait for a job
    
    while(1)
    {
        pthread_mutex_lock(&locker); // lock the locker
        if (is_empty(jobs_queue) && (njobs == NJOBS*NAGENTS))
        {
            quit_handle();
            break;
        }
        else if (!is_empty(jobs_queue))
            handle_job();
        else
            waiting_job();
    }
    
    pthread_exit(NULL);
}

void quit_handle()
{
    printf("No more jobs. Quitting...\n");
    pthread_mutex_unlock(&locker);
}
void handle_job(void)
{
    // TODO:
    // Print number of waiting jobs
    // Get job from queue
    // Print job information
    // Unlock the locker
    // Sleep for a while to simulate job duration needed to finish it
    printf("Number of waiting job: %d\n", get_size(jobs_queue));
    
    job_data job_to_handle = dequeue(&jobs_queue);

    pthread_mutex_unlock(&locker);

    sleep(2);

    printf("Handle job %d of agent %d in %ds\n", job_to_handle.job_id, job_to_handle.agent_id, job_to_handle.duration);

}
void waiting_job(void)
{
    printf("No jobs. Waiting for 1s\n");
    pthread_mutex_unlock(&locker);
    sleep(1);
}

