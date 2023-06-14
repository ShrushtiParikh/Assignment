#include<stdio.h>
#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/shm.h>
#include<stdlib.h>

int main()
{
	char *r,*shd;
	int id;
	id = shmget(111,1024,IPC_CREAT|0644);

	if(id < 0)
	{
		perror("shmget");
		return 0;
	}

	printf("id = %d\n",id);
	r = shmat(id,0,0);

	if(r == (char*)(-1))
	{
		perror("Shmat:");
		exit(1);
	}

	for(shd = r ; *shd != NULL ; shd++)
	{
		printf("Data is : %s\n",(char*)shd);
		*shd = *shd++;
	}
//	putchar('\n');
	*shd = '*';

	
	return 0;
}
