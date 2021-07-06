//Shared memory IPC techniques

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<sys/types.h>
#include<string.h>
#include<errno.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

#define SHM_SIZE 1023

int main(){
    key_t sh_key;
    int shm_id;
    char *str;
    
    //create the key
    if ((sh_key = ftok("file.txt", 'w')) == -1)
    {
        perror("ftok error");
        exit(1);
    }

    //get the shared memory id
    if ((shm_id = shmget(sh_key, SHM_SIZE, 0644 | IPC_CREAT)) == -1)
    {
        perror("shmget");
        exit(1);
    }

    // attach the shared memory segment with shmat
    str = shmat(shm_id, NULL, 0);
    if (str == (char *)(-1))
    {
        perror("shmat");
        exit(1);
    }

    printf("Data to be written: \n");

    gets(str);
    printf("Data in memory is: %s\n", str);
   

    printf("Data in memory is: %s \n", str);

    //detach the segment
    shmdt(str);


}