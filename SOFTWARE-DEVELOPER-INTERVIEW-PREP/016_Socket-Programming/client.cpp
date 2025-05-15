#include <iostream>
#include <cstring>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);  // 1. Create socket
    if (sock < 0) {
        std::cerr << "Socket creation error\n";
        return 1;
    }

    sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);         // Same port as server

    inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr);  // 2. Convert IP

    connect(sock, (sockaddr*)&serv_addr, sizeof(serv_addr));  // 3. Connect

    const char* msg = "Hello server!";
    send(sock, msg, strlen(msg), 0);         // 4. Send message

    char buffer[1024] = {0};
    read(sock, buffer, 1024);                // 5. Read reply
    std::cout << "Server says: " << buffer << "\n";

    close(sock);                             // 6. Close
    return 0;
}
