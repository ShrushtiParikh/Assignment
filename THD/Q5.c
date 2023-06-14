/*Write a program to create a thread, thread routine should increment a number in infinite loop.
 *  For both the programs, when user presses CTRL+C, the program should stop printing the number and should exit gracefully.*/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<signal.h>

void* routine(void *num)
{
	int number = *(int *)num;
	while(1)
	{
		printf("%d\n",number);
		number++;
	}
	free(num);
}

void sighandler(int sig)
{
	printf("Ctrl+C pressed : %d\n",sig);
	signal(sig,SIG_DFL);
}

int main()
{
	pthread_t t;
	signal(SIGINT,sighandler);
	int num;
	printf("enter number to start: \n");
	scanf("%d",&num);
	if(fork() == 0)
	{
		while(1)
		{
			printf("%d\n",num);
			num++;
		}
	}	
	int *a = malloc(sizeof(int));
	*a = num;
	if(pthread_create(&t,NULL,&routine,a) != 0)
	{
		perror("create : ");
		exit(0);
	}

	if(pthread_join(t,NULL) != 0)
	{
		perror("Join : ");
		exit(1);
	}
}
