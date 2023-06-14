/*copy data from file1 t file2 using FIFO*/

#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#define FIFO "namedfifo"
#define TEXT "file2.txt"

int main()
{
	int fd;
	int fd2;

	char arr[80];

	fd = open(FIFO,O_RDONLY);

	if(fd < 0)
	{
		perror(" open : \n");
		printf("open failed\n");
	}

	int rb = read(fd,arr,sizeof(arr));

	if(rb < 0)
	{
		printf("read errpr");
	}

	fd2 = open(TEXT,O_CREAT|O_WRONLY,0777);

	int wb = write(fd2,arr,sizeof(arr));

	if(wb < 0)
	{
		printf("write error\n");
	}
	printf("file 2 contains : %s\n",arr);

	return 0;
}
