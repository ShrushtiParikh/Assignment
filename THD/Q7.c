#include<signal.h>
#include<stdio.h>
#include<time.h>

void sighand(int signum)
{
	printf("Sig invoked\n");
	signal(SIGUSR1,sighand);
	time_t curtime;
	time(&curtime);
	printf("Time is : %s\n",ctime(&curtime));
}

int main()
{
	clock_t start,end;
	start = clock();
	signal(SIGUSR1,sighand);	
	printf("HELLO\n");
	while(1){}
	return 0;
}
