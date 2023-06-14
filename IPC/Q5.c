/*One program will open a pipe, write a number to pipe.                  
   - Other program will open the same pipe, will read the number and print them.
   - Close both the pipes
*/

#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>


int main()
{
	int fd[2];
	
	if(pipe(fd) == -1)
	{
		printf("Error while openining file\n");
		return 1;
	}

	int x;
	close(fd[0]);
	printf("Enter Num to send\n");
	scanf("%d",&x);

	write(fd[1],&x,sizeof(int));
	close(fd[1]);
	
	return 0;
}
