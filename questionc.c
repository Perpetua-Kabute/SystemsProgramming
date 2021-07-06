#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    
    fork();
    printf("Hello unix\n"); //gets printed twice
    return 0;
}