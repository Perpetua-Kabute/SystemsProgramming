#include <sys/types.h> 
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

int main(){

    pid_t pid;
    int status;

    pid = fork();

    if(pid == -1){
        printf("Error");
        exit(EXIT_FAILURE);
    }
// executed by child
    if(pid == 0){
            printf("Child PID is %ld\n", (long) getpid());
         
    }
    
    // executed by parent 
   do{
        waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                printf("exited, status=%d\n", WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("killed by signal %d\n", WTERMSIG(status));
            } else if (WIFSTOPPED(status)) {
                printf("stopped by signal %d\n", WSTOPSIG(status));
            } else if (WIFCONTINUED(status)) {
                printf("continued\n");
            }
   }while(!WIFEXITED(status) && !WIFSIGNALED(status)) ;
    return 0;
}