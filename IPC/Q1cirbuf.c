/*Producer - Consumer program using semaphores 
   - A "circular buffer" will be shared among two threads 
         a. Producer thread 
         b. Consumer thread
   - Producer thread will write a number/numbers in the circular buffer
   - Consumer should read the number from circular buffer and print it on console
   - Write all numbers from 0 to 1000.
   - Size of "circular buffer" is 16
   - Display exact time taken for the program to execute.
*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<pthread.h>
#include<time.h>
#define N 16
#define NUM 1000

sem_t full;
sem_t empty;
int buf[N];

void *producer(void *arg);
void *consumer(void *arg);

void *producer(void *arg)
{
	int item;

	for(int i = 1 ; i <= NUM ; i++)
	{
		sem_wait(&empty);
		item = i;
		printf("Produced item = %d\n",item);

		buf[i%N] = item;
		sem_post(&full);
	}

}

void *consumer(void *arg)
{
	int item;

	for(int i = 1 ; i <= NUM ; i++)
	{
		sem_wait(&full);
		item = buf[i%N];
		sem_post(&empty);
		printf("Consumed item = %d\n",item);
	}

}

int main()
{
	pthread_t t_consumer;
	pthread_t t_producer;
	
	clock_t start, end;
	double execution_time;
	start = clock();

	if(sem_init(&empty,0,N) != 0)
	{
		printf("shared empty sem failed\n");
	}
	if(sem_init(&full,0,0) != 0)
	{
		printf("shared full sem failed\n");
	}

	if(pthread_create(&t_consumer,NULL,consumer,NULL) != 0)
	{
		printf("Thd consumer creation failed\n");
	}

	if(pthread_create(&t_producer,NULL,producer,NULL) != 0)
	{
		printf("Thd producer creation failed\n");
	}

	if(pthread_join(t_producer,NULL) != 0)
	{
		printf("Thd producer join failed\n");
	}

	if(pthread_join(t_consumer,NULL) != 0)
	{
		printf("Thd consumer join failed\n");
	}
	
	end = clock();
	double duration = ((double)end - start)/CLOCKS_PER_SEC;
    	printf("Time taken to execute in seconds : %f\n", duration);
	return 0;
}
