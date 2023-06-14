/*Producer - Consumer program using threads and semaphore 
   - A queue will be shared among two threads 
         a. Producer thread 
         b. Consumer thread
   - Producer thread will write a number in the queue
   - Consumer should read the number from queue and print it on console only if the queue is not empty.*/


#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

int mutex = 1;
int empty = 0;
int full = 10;
int val = 0;

void Producer()
{
	mutex--;
	empty++;
	val++;
	printf("val written to queue is : %d\n",val);
	full--;
	mutex++;
}

void Consumer()
{
	mutex--;
	empty--;
	printf("val read from queue is : %d\n",val);
	val--;
	full++;
	mutex++;
}

int main()
{
	int a = 1;
	int n;
	while(a == 1)
	{
		printf("1.Enter 1 for Producer\n2.Enter 2 for consumer\n3.Enter 3 for Exit\n");
		scanf("%d",&n);
		if(n == 1)
		{
			printf("Producer Queue\n");
			if((mutex == 1) && (full != 0))
			{
				Producer();
			}
			else
			{
				printf("Buffer is full\n");
			}
		}
		else if(n == 2)
		{
			printf("Consumer Queue\n");
			if((mutex == 1) && (empty != 0))
			{
				Consumer();
			}
			else
			{
				printf("Buffer is full\n");
			}
		}
		else if(n == 3)
		{
			exit(0);
		}
		else
		{
			printf("invalid option\n");
		}
		printf("Do you still want to enter data->enter 1\n");
		scanf("%d",&a);
	}
	return 0;
}
