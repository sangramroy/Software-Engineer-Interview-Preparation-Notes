#include <sys/ipc.h>    // For IPC mechanisms
#include <sys/msg.h>    // For msgrcv() and msgctl()
#include <stdio.h>      // For printf()
#include <string.h>     // For string operations

// Define the same message structure
struct msg_buffer {
    long msg_type;          // Message type to receive
    char msg_text[100];     // Buffer to store message text
};

int main() {
    // Step 1: Generate the same key as the sender using ftok
    key_t key = ftok("msgfile", 65);  // Same path and ID as sender

    // Step 2: Access the existing message queue
    int msgid = msgget(key, 0666 | IPC_CREAT);  // Same flags to ensure access

    // Step 3: Receive the message from the queue
    msg_buffer message;
    msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);  // 1 = msg_type to receive, 0 = default flags

    // Step 4: Print the received message
    printf("Message received: %s\n", message.msg_text);

    // Step 5: Optional – Remove the message queue (cleanup)
    msgctl(msgid, IPC_RMID, NULL);  // IPC_RMID tells kernel to delete the queue

    return 0;
}
