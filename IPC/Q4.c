/*Copy data from file1 to file2 through named FIFO.*/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd,fd1,rb;

    char * fifo = "/tmp/myfifo";

    mkfifo(myfifo, 0666);

    char arr1[80], arr2[80];

    while(1)
    {
	    fd = open(file1,O_RDONLY);

	    if(fd < 0)
	    {
		    perror("open failed: ");
		    exit(0);
	    }

	    rb = read(fd,arr1,sizeof(arr1));

	    if(rb < 0)
	    {
		    perror("read: ");
	    }
		
	    close(fd);

	    fd1 = open(myfifo,OWRONLY);

	    if(fd1 < 0)
	    {
		    perror("open failed : ");
		    exit(1);
	    }

	    int wb = write(fd1,arr1,strlen(arr1)+1);

	    if(wb < 0)
	    {
		    printf("write failed\n");
	    }

	    printf("data written : %s\n",arr1);
	    close(fd1);

  	}
    return 0;
}


			 
