#include <sys/ipc.h>    // For IPC mechanisms: ftok(), msgget()
#include <sys/msg.h>    // For message queue system calls: msgsnd()
#include <stdio.h>      // For printf()
#include <string.h>     // For strcpy()

// Define the message structure
struct msg_buffer {
    long msg_type;           // Message type, must be > 0
    char msg_text[100];      // Message content (payload)
};

int main() {
    // Step 1: Generate a unique key using ftok (needs a valid file and ID)
    key_t key = ftok("msgfile", 65);  // "msgfile" must exist in current dir

    // Step 2: Create or access a message queue using msgget
    int msgid = msgget(key, 0666 | IPC_CREAT);  // 0666 = RW access; IPC_CREAT creates if not present

    // Step 3: Prepare the message
    msg_buffer message;
    message.msg_type = 1;  // Set message type (required)
    strcpy(message.msg_text, "Hello from sender");  // Set message data

    // Step 4: Send the message to the queue using msgsnd
    msgsnd(msgid, &message, sizeof(message.msg_text), 0);  // 0 = default flags

    // Step 5: Print confirmation
    printf("Message sent: %s\n", message.msg_text);

    return 0;
}
