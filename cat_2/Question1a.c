//implementing shared memory
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

//make it a 1K shared memory segment
#define SHM_SIZE 1024

int main(int argc, char *argv[])
{
    key_t key;
    int shared_id;
    char *data;
    int mode;

    FILE *file = fopen("program_file.txt", "w");

    if (argc > 2)
    {
        fprintf(stderr, "usage: shmdemo [data_to_write]\n");
        exit(1);
    }

    /* make the key: */
    if ((key = ftok("program_file.txt", 'w')) == -1)
    {
        perror("ftok");
        exit(1);
    }

    /*  create the memory segment: */
    if ((shared_id = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) == -1)
    {
        perror("shmget");
        exit(1);
    }

    // attach to the segment to get a pointer to it:
    data = shmat(shared_id, NULL, 0);
    if (data == (char *)(-1))
    {
        perror("shmat");
        exit(1);
    }

    // read or modify the segment, based on the command line:
    // pass to argument when executing the program
    if (argc == 2)
    {
        printf("write to segment: \"%s\"\n", argv[1]);
        strncpy(data, argv[1], SHM_SIZE);
        //output the command line argument also to the file
        fprintf(file, "%s", argv[1]);
    }
    else
        printf("The segment contains: \"%s\"\n", data);

    //detach from the segment:
    if (shmdt(data) == -1)
    {
        perror("shmdt");
        exit(1);
    }

    return 0;
}