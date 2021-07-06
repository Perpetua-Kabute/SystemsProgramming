#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    fork();
    printf("Forking this process\n");
    return 0;
}