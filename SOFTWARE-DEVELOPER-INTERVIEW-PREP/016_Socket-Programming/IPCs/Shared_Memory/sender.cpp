#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstring>   // For strcpy

int main() {
    // Generate unique key
    key_t key = ftok("shmfile", 65);

    // Create shared memory segment of size 1024 bytes
    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    // Attach to the shared memory
    char* str = (char*) shmat(shmid, nullptr, 0);

    // Write data
    std::string message = "Hello from C++ shared memory!";
    strcpy(str, message.c_str());

    std::cout << "Data written to shared memory: " << message << std::endl;

    // Detach
    shmdt(str);

    return 0;
}
