#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/resource.h>
int main()
{

printf("Process ID: %d\n", getpid() );
printf("Parent Process ID: %d\n", getppid() );
printf("The process priority = %d\n", getpriority(PRIO_PROCESS, getpid()));
printf("The parent process priority = %d\n", getpriority(PRIO_PROCESS, getppid()));

return 0;
}
