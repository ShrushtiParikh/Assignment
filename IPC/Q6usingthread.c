#include<pthread.h>
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

pthread_mutex_t MutexLock;

int var = 0;


void *Producer()
{
	pthread_mutex_lock(&MutexLock);
	var++;
	printf("buffer written to queue is : %d\n",var);
	pthread_mutex_unlock(&MutexLock);
}

void *Consumer()
{
	pthread_mutex_lock(&MutexLock);
	printf("buffer read from queue is : %d\n",var);
	var--;
	pthread_mutex_unlock(&MutexLock);
}

int main()
{
	pthread_t p[2];
	int Menu;
	pthread_mutex_init(&MutexLock,NULL);
	printf("Enter 1 for Menu->0 for exit\n");
	scanf("%d",&Menu);
	while(Menu != 0)
	{
		int choice;
		printf("Enter 1 for Producer\nEnter 2 for Consumer\nEnter 0 for exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				if(pthread_create(&p[1],NULL,&Producer,NULL) != 0)
				{
					printf("Pthread create failed\n");
				}
				if(pthread_join(p[1],NULL))
				{
					printf("join failed\n");
				}
				break;
			case 2:
				if(pthread_create(&p[2],NULL,&Consumer,NULL) != 0)
				{
					printf("Pthread create failed\n");
				}
				if(pthread_join(p[2],NULL))
				{
					printf("join failed\n");
				}
				break;
			case 0:
				printf("exiting program\n");
				exit(0);
				break;
			default:
				printf("Invalid option\n");
		}	
//		pthread_mutex_destroy(&MutexLock);
		printf("Enter 1 for Menu->0 for exit\n");
		scanf("%d",&Menu);
	}
	pthread_mutex_destroy(&MutexLock);
	return 0;
}
		

