// C Program for Message Queue (Reader Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

// structure for message queue
struct mesg_buffer {
        long mesg_type;
        char mesg_text[500];
} message;

void read_cooking_recipe(int category){
        key_t key;
        int msgid;

        // ftok to generate unique key
        key = ftok("recipe", 65);

        // msgget creates a message queue
        // and returns identifier
        msgid = msgget(key, 0666 | IPC_CREAT);
        // msgrcv to receive message
        msgrcv(msgid, &message, sizeof(message), category, 0);

        printf("----------------------\n");
        // display the message
        printf("Data Received is:\n %s",message.mesg_text);

        printf("----------------------\n\n");

		msgctl(msgid, IPC_RMID, NULL);

}

int main()
{
        key_t key;
        int msgid;

        // ftok to generate unique key
        key = ftok("recipe", 65);

        // msgget creates a message queue
        // and returns identifier
        msgid = msgget(key, 0666 | IPC_CREAT);

        // while(1){
        //      // msgrcv to receive message
        //      msgrcv(msgid, &message, sizeof(message), message.mesg_type, 0);

        //      // display the message
        //      printf("Data Received is : %s \n",
        //                                      message.mesg_text);

        // }

        while(1){
                // Take the user's input
                read_cooking_recipe(1);
                read_cooking_recipe(2);
                read_cooking_recipe(3);
        }

        // to destroy the message queue
        // msgctl(msgid, IPC_RMID, NULL);

        return 0;
}