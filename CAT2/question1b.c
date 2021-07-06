#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 100


//Message struct
struct message
{
    long message_type;
    char message_text[100];
} message;

int main()
{

    key_t key;
    int message_id;

    // ftok to generate unique key
    key = ftok("file", 65);

    // msgget creates a message queue and returns identifier
    message_id = msgget(key, 0666 | IPC_CREAT);
    message.mesg_type = 1;

    printf("Enter message : ");
    fgets(message.mesg_text, MAX, stdin);

    // msgsnd to send message
    msgsnd(message_id, &message, sizeof(message), 0);

    
    printf("Sent message : %s \n", message.message_text);

    pid_t parentpid = getpid();
    pid_t childpid = fork();


    if (childpid < 0){
        printf("Error: failed to fork\n");
        return 1;
    }
    else if (childpid == 0){
        msgrcv(message_id, &message, sizeof(message.mesg_text), 1, 0);
        printf("Child message : %s\n", message.mesg_text);
    }
    else{ 
        wait(NULL);
        message.mesg_type = 1;
        msgrcv(message_id, &message, sizeof(message.message_text), 1, 0);
        printf("Parent message : %s\n", message.message_text);
    }
    return 0;
}