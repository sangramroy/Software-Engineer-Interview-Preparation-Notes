#include <iostream>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <cstring>

int main() {
    key_t key = ftok("shmfile", 65);

    // Access shared memory
    int shmid = shmget(key, 1024, 0666);

    // Attach
    char* str = (char*) shmat(shmid, nullptr, 0);

    std::cout << "Data read from shared memory: " << str << std::endl;

    // Detach and destroy
    shmdt(str);
    shmctl(shmid, IPC_RMID, nullptr);

    return 0;
}
