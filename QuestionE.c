#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    //int gui_process = system("htop");
    int gui_process = system("sar -u 2");
}