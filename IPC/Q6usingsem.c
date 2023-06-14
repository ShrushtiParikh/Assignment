#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
#include<stdlib.h>

int sharedvar = 0; //Shared var
		  
sem_t sem;
sem_t full;
sem_t empty;

void producer()
{
	while(1)
	{
		sem_wait(&empty);
		sem_wait(&sem);	
		sharedvar++;
		printf("Entered %d data to buffer\n",sharedvar);
		sem_post(&full);
		sem_post(&sem);
	}
}

void consumer()
{
	while(1)
	{
		sem_wait(&full);
		sem_wait(&sem);
		printf("recieved %d data from buffer\n",sharedvar);
		sem_post(&sem);
		sem_post(&empty);
	}
}

int main()
{
	sem_init(&sem,0,1);
	sem_init(&full,0,0);
	sem_init(&empty,0,10);
	
	while(1)
	{
		printf("Enter 1 for producer\nEnter 2 for consumer\n");
		int choice = 0;
		scanf("%d",&choice);
		if(choice == 1)
		{
			producer();
		}
		else if(choice == 2)
		{
			consumer();
		}
		else
		{
			exit(0);
		}
	}

	return 0;
}
	

