#include<signal.h>
#include<stdio.h>
#include<time.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>

void sighand(int signum)
{
	printf("First alarm\n");
}

void sign(int signum)
{
	printf("Second alarm\n");
}

int main()
{
	if(fork() == 0)
	{
		signal(SIGALRM,sighand);	
		alarm(5);
	}
	else
	{
		wait(NULL);
		struct sigaction sa;
		sa.sa_flags = SA_RESTART;
		sa.sa_handler = &sign;
		sigaction(SIGALRM,&sa,NULL);
		alarm(12);
		printf("HELLO\n");
		while(1){}
		return 0;

	}
	//signal(SIGALRM,sign);
//	alarm(12);
/*	printf("HELLO\n");
	while(1){}
	return 0;*/
}
