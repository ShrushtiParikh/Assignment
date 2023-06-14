/*Copy data from file1 to file2 through named FIFO.*/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define FIFO "namedfifo"

int main()
{
    int fd1,rb;
    FILE* fd;
    char arr2[80];
    fd = fopen("file.txt","r");
    if(fd == NULL)
    {
	    perror("open failed: ");
//	    exit(0);
    }

    char arr1[80];
    rb = fread(arr1,sizeof(arr1),1,fd);
    if(rb < 0)
    {
	    perror("read: ");
    }
    printf("Data read is : %s\n",arr1);
    fclose(fd);
    
    int f = open(FIFO,O_WRONLY|O_CREAT,0777);
    if(f < 0)
    {
	    perror("open failed : ");
	    exit(1);
    }	
    int wb = write(f,arr1,sizeof(arr1));

    printf("data written is : %s\n",arr1);
    if(wb < 0)
    {
	    printf("write failed\n");
    }

    printf("data written : %s\n",arr1);
    close(fd1);
 
    return 0;
}


			 
