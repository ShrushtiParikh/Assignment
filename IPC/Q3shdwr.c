/*Understanding of shared memory. Below program demostrating usage of shared memory. 
   - One program to write strings to shared memory. 
   - Number of strings and string patterns will be given by user from command line.
   - Second program should read the number of strings and string patterns from shared memory region.
   - Strings should be reversed and stored to at the same location.
   - In both the programs, memory addresses should be printed where the strings are stored.*/


#include<stdio.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<string.h>
#include<stdlib.h>
#define SHM_SIZE 1024

int main(int argc,char *argv[])
{
	char *data,*shm;
	int shmid;
	key_t key;
	int mode;

	if(argc < 3)
	{
		printf("shmdemo[data to write]\n");
		exit(1);
	}

	if((shmid = shmget(111,SHM_SIZE,0644|IPC_CREAT)) == 1)
	{
		perror("Shmget:");
		exit(1);
	}

	data = shmat(shmid,(void*)0,0);

	if(data == (char *)(-1))
	{
		perror("Shmat");
		exit(1);
	}

	shm = (char*)data;
	
	printf("write to seg string : %s\n",argv[1]);
	strncpy(shm,argv[1],SHM_SIZE);
	*shm++;

	for(int i = 0 ; i < atoi(argv[1]) ; i++)
	{
		printf("write to seg string : %s\n",argv[2+i]);
       		strncpy(shm,argv[2+i],SHM_SIZE);
		printf("Data is : %s\n",(char*)shm);
		*shm == *shm++;
	}
	*shm = NULL;

	while(*shm != '*')
		sleep(1);

	if(shmdt(data) == -1)
	{
		perror("shmdt");
		exit(1);
	}


	return 0;
}
