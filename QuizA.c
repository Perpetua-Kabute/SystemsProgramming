#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>
 int main(){
     pid_t pId = getpid();
     pid_t parentspid = getppid();
     int priority = getpriority(PRIO_PROCESS, pId);

     printf("Process Id = %d\n", pId);
     printf("Parent Process Id = %d\n", parentspid);
     printf("Priority = %d\n", priority);
     return 0;
 }