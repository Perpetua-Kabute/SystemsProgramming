-Sending signals via kill()

#include<stdio.h>
#include<wait.h>
#include<signal.h>
int main()
{
	int status;
	pid_t pid;

	if ((pid = fork()) == 0)
		while(1) ;
	else
	{
		kill(pid, SIGINT);
		wait(&stat);
		if (WIFSIGNALED(status))
		psignal(WTERMSIG(status), "due");
	}
}

