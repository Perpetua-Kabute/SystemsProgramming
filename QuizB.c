#include <stdio.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

int main(){
    system("./BB12.sh");
    kill();
    return 0;
}