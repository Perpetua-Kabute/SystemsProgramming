A process can replace the default signal handler 

#include<stdio.h>
#include<signal.h>
  
int main()
{
    signal(SIGINT, handle_sigint);
    while (1)
    {
        printf(“hello world\n”);
        sleep(1);
    }
    return 0;


// -Sending signals via kill()
	int status;
	pid_t pid;
	if ((pid = fork()) == 0)
		while(1) ;
	else
	{
		kill(pid, SIGINT);
		wait(&status);
		if (WIFSIGNALED(status))
		psignal(WTERMSIG(status), "Child term due to");
	}
}

