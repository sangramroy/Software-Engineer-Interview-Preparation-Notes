#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);  // 1. Create socket
    if (server_fd == 0) {
        std::cerr << "Socket failed\n";
        return 1;
    }

    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;     // 0.0.0.0 (accept any IP)
    address.sin_port = htons(8080);           // Port 8080

    bind(server_fd, (sockaddr*)&address, sizeof(address)); // 2. Bind IP & Port
    listen(server_fd, 3);                                 // 3. Listen

    int addrlen = sizeof(address);
    int client_fd = accept(server_fd, (sockaddr*)&address, (socklen_t*)&addrlen);  // 4. Accept

    char buffer[1024] = {0};
    read(client_fd, buffer, 1024);            // 5. Read from client
    std::cout << "Client says: " << buffer << "\n";

    const char* reply = "Hello from server!";
    send(client_fd, reply, strlen(reply), 0);  // 6. Send reply

    close(client_fd);                         // 7. Close connection
    close(server_fd);
    return 0;
}
