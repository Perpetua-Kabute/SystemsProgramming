#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


int
main(int argc, char *argv[])
{
    pid_t cpid, w;
    int status;


    cpid = fork();
    if (cpid == -1) { perror("fork"); exit(EXIT_FAILURE); }


    if (cpid == 0) {            /* Code executed by child */
        printf("Child PID is %ld\n", (long) getpid());
        


    } else {                    /* Code executed by parent */
        do {
            w = waitpid(cpid, &status, 0);
            
            if (WIFEXITED(status)) {
                printf("exited, status=%d\n", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("killed: Signal =  %d\n", WTERMSIG(status));
            } else if (WIFSTOPPED(status)) {
                printf("stopped: signal = %d\n", WSTOPSIG(status));
            } else if (WIFCONTINUED(status)) {
                printf("continued successfully\n");
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
        exit(EXIT_SUCCESS);
    }
}