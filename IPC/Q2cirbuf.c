/*Write the above program using "mutex and conditional variables" instead of "semaphores"*/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#define NUM 1000
#define N 16

int buf[N];
pthread_mutex_t Mutex;
pthread_cond_t cond;

void *producer(void *arg);
void *consumer(void *arg);

void *producer(void *arg)
{
	int item;

	for(int i = 1 ; i <= NUM ; i++)
	{
		pthread_mutex_lock(&Mutex);
		item = i;
		printf("Produced item = %d\n",item);

		while(!(buf[i%N] = item)) 
		{
			pthread_cond_wait(&cond,&Mutex);
		}	
	        pthread_mutex_unlock(&Mutex);	
	}

}

void *consumer(void *arg)
{
	int item;

	for(int i = 1 ; i <= NUM ; i++)
	{
		pthread_mutex_lock(&Mutex);
		item = buf[i%N];
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&Mutex);
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
	
	pthread_mutex_init(&Mutex,NULL);
	pthread_cond_init(&cond,NULL);

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
