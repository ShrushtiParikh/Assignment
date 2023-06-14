/* Make a program where two threads simultaneously works. One thread writing capital 'ABCD..' into file & another thread writing 
   small 'abcd ..' into file.   [by mutex / semaphore*/


#include<pthread.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

pthread_mutex_t mutex;
FILE *fp;
int i = 0;
int j = 0;
void *capital()
{
	do
	{
		pthread_mutex_lock(&mutex);
		printf("Mutex cap acq lock\n");
		
		int p = fprintf(fp,"%c",65+j);
		printf("%d\n",p);
		j++;
		sleep(1);
		if(p > 0)
		{
			pthread_mutex_unlock(&mutex);
			printf("Mutex cap unlocked\n");
		}
	}while(j<25);
}

void *small()
{	
	do
	{
		pthread_mutex_lock(&mutex);
		printf("Mutex small acq locked\n");
		int p = fprintf(fp,"%c",97+ i);
		printf("%d\n",p);
		i++;
		sleep(1);
		if(p  > 0)
		{
			pthread_mutex_unlock(&mutex);
			printf("Mutex small unlocked\n");
		}
	}while(i<25);
}

int main()
{
	pthread_t p[2];
	pthread_mutex_init(&mutex,NULL);

	fp = fopen("letters.txt","w+");
	if(pthread_create(&p[1],NULL,capital,NULL) != 0)
	{
		printf("create failed\n");
	}
	if(pthread_create(&p[2],NULL,small,NULL) != 0)
	{
		printf("create failed\n");
	}

	if(pthread_join(p[1],NULL)!= 0)
	{
		printf("Join failed\n");
	}

	if(pthread_join(p[2],NULL)!= 0)
	{
		printf("Join failed\n");
	}

	pthread_mutex_destroy(&mutex);
	fclose(fp);
	return 0;

}
