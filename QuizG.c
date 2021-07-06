#include <stdio.h>
#include <signal.h>
#include <unistd.h>
void sig_handler(int signum);

int main()
{
    // Register signal handler
    signal(SIGINT, sig_handler);


    while(1)
    {
        printf("%d : Running an infinite loop\n");
        sleep(1);
    }
    return 0;
}

void sig_handler(int signum)

// this will run when user enters CTRL + C
{
    printf("\nRunning after loop\n");
}


