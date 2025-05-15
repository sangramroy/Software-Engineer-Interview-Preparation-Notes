Linux internals
System calls

IPCs
Socket programming
Shared memory
Message Queues
Pipes

-----------------------------------------------------------------------------------------------------------------------------
Socket Programming

socket : end point at both client n server side : system call -> socket it returns file descriptor in int
devices are either little Indian (lsb) or big endian (msb) : apis used : htons(sender) or ntohs(receiver) depending upon device supports what format

cpu uses : little endian
network uses: big endian


Function	Converts	Used For
htons()	Host to Network (short, 16-bit)	Port numbers
ntohs()	Network to Host (short, 16-bit)	Port numbers
htonl()	Host to Network (long, 32-bit)	IP addresses
ntohl()	Network to Host (long, 32-bit)	IP addresses


| Function  | When to Use                   | Used By         | Why                         |
| --------- | ----------------------------- | --------------- | --------------------------- |
| `htons()` | Before sending (bind/connect) | Client & Server | To standardize port format  |
| `ntohs()` | After receiving (accept/recv) | Client & Server | To interpret port correctly |



| API        | Role                    | Return on Success | Return on Failure | Notes                                   |
| ---------- | ----------------------- | ----------------- | ----------------- | --------------------------------------- |
| `bind()`   | Bind socket to IP\:PORT | `0`               | `-1` with `errno` | Used by server before `listen()`        |
| `listen()` | Start listening queue   | `0`               | `-1` with `errno` | Used to accept incoming TCP connections |

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

## ✅ Full Flow Summary: Server Side

| **Step** | **Function / System Call** | **Purpose**                                                     |
| -------- | -------------------------- | --------------------------------------------------------------- |
| Step 1   | `socket()`                 | Create a socket endpoint for communication                      |
| Step 2   | `sockaddr_in` + `memset()` | Setup address structure with IP + port                          |
| Step 3   | `bind()`                   | Bind socket to local IP address and port                        |
| Step 4   | `listen()`                 | Mark the socket as passive (server ready to accept connections) |
| Step 5   | `accept()`                 | Wait and accept incoming client connection; returns new socket  |
| Step 6a  | `recv()`                   | Receive data from connected client                              |
| Step 6b  | `send()`                   | Send response/data to connected client                          |
| Step 7   | `close()`                  | Close both client socket and main server socket                 |


## ✅ Full Flow Summary: Client Side

| Step    | Function / System Call | Purpose                          |
| ------- | ---------------------- | -------------------------------- |
| Step 1  | `socket()`             | Create socket                    |
| Step 2  | `sockaddr_in`          | Setup server address             |
| Step 3  | `connect()`            | Establish connection with server |
| Step 4a | `send()`               | Send data to server              |
| Step 4b | `recv()`               | Receive server's response        |
| Step 5  | `close()`              | Close socket                     |

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
## ✅ Server Side Socket Programming Steps (with System Calls & Structure)

✅step1: socket() 
Creates an endpoint for communication — a socket.

int sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (sockfd < 0) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
}

| Parameter  | Description                                                                        |
| ---------- | ---------------------------------------------------------------------------------- |
| `domain`   | Address family: `AF_INET` (IPv4), `AF_INET6` (IPv6), `AF_UNIX` (local)             |
| `type`     | Socket type: `SOCK_STREAM` (TCP), `SOCK_DGRAM` (UDP)                               |
| `protocol` | Usually `0` (let system pick default: TCP for `SOCK_STREAM`, UDP for `SOCK_DGRAM`) |

----------------------------------------------------------------------------------------------------------------------------
✅step2 : structure address creation- ip+port

sockaddr_in

// definition
struct sockaddr_in {
    sa_family_t    sin_family;   // Address family (AF_INET)
    in_port_t      sin_port;     // Port number (in network byte order)
    struct in_addr sin_addr;     // IP address
};

struct in_addr {
    uint32_t       s_addr;       // IP address (in network byte order)
};


//how to fill
struct sockaddr_in address;

memset(&address, 0, sizeof(address));   // Zero out the structure
address.sin_family = AF_INET;           // IPv4
address.sin_port = htons(8080);         // Convert port to network byte order

// For server: listen on all interfaces
address.sin_addr.s_addr = INADDR_ANY;   // 0.0.0.0  

// OR for client: connect to a specific IP
// address.sin_addr.s_addr = inet_addr("127.0.0.1");

----------------------------------------------------------------------------------------------------------------------------
✅step 3 : bind()

Binds a socket to a local IP address and port number.
Used by servers to tell the OS: "Listen for connections on this IP:PORT."

int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);

sockfd: The socket file descriptor (created via socket()).
addr: Pointer to sockaddr_in or similar struct specifying IP and port.
addrlen: Size of the addr struct.

if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("bind failed");
    exit(EXIT_FAILURE);
}

----------------------------------------------------------------------------------------------------------------------------
✅step 4 : listen()

Marks the socket as passive, i.e., ready to accept incoming connections.
Only used on TCP sockets (not UDP).

int listen(int sockfd, int backlog);

sockfd: The socket file descriptor that was bound with bind().
backlog: Maximum number of pending connections in the queue.

if (listen(sockfd, 5) < 0) {
    perror("listen failed");
    exit(EXIT_FAILURE);
}

----------------------------------------------------------------------------------------------------------------------------
✅step 5 : accept()      ----------------  used at server side

waits for a client to connect via connect() system call to the server.
It returns a new socket dedicated to that connection.


int clientfd = accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);

📥 Parameters:
sockfd: Server socket from socket() + bind() + listen()
addr: (Optional) stores client's IP info
addrlen: size of the address struct


----------------------------------------------------------------------------------------------------------------------------
after connection gets established:

✅step 6: send() and recv() system calls come into picture for communication

. send() / recv() — Used on Both Sides
After the connection is established:

Server (with client_fd from accept()) can send/recv
Client (with sockfd from connect()) can send/recv

📘 send() Syntax:
ssize_t send(int sockfd, const void *buf, size_t len, int flags);

📘 recv() Syntax:
ssize_t recv(int sockfd, void *buf, size_t len, int flags);

🔄 Communication Direction:
Who Calls	Direction	Function
Client	→	send()
Server	←	recv()
Server	→	send()
Client	←	recv()

----------------------------------------------------------------------------------------------------------------------------
✅step 7: Close the socket (optional but recommended)

close(sockfd);

++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
## ✅ Client Side Socket Programming Steps (with System Calls & Structure)

### 🔹 Step 1: `socket()`

Creates a socket for communication (like the server).

int sockfd = socket(AF_INET, SOCK_STREAM, 0);
if (sockfd < 0) {
    perror("socket creation failed");
    exit(EXIT_FAILURE);
}


| Parameter     | Description                                     |
| ------------- | ----------------------------------------------- |
| `AF_INET`     | Address family for IPv4                         |
| `SOCK_STREAM` | TCP (reliable, connection-oriented)             |
| `0`           | Let OS choose default protocol (TCP for stream) |

----------------------------------------------------------------------------------------------------------------------------

### 🔹 Step 2: Structure Address Creation – IP + Port

The client **specifies the server's IP and port** to connect to.


struct sockaddr_in serv_addr;
memset(&serv_addr, 0, sizeof(serv_addr));   // Clear the struct
serv_addr.sin_family = AF_INET;             // IPv4
serv_addr.sin_port = htons(8080);           // Server port (converted to network byte order)


// Convert IP string to binary (127.0.0.1 or server IP)
if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
    perror("Invalid address or Address not supported");
    exit(EXIT_FAILURE);
}

| Field             | Description                                |
| ----------------- | ------------------------------------------ |
| `sin_family`      | Address family (`AF_INET`)                 |
| `sin_port`        | Server's port (use `htons()`)              |
| `sin_addr.s_addr` | IP address of the server                   |
| `inet_pton()`     | Converts IP from text to binary (portable) |

----------------------------------------------------------------------------------------------------------------------------

### 🔹 Step 3: `connect()`

Initiates a connection to the server.


if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Connection to server failed");
    exit(EXIT_FAILURE);
}


| Parameter     | Description                                |
| ------------- | ------------------------------------------ |
| `sockfd`      | Socket descriptor (created via `socket()`) |
| `serv_addr`   | Contains server IP and port                |
| `sizeof(...)` | Size of the struct                         |

* If server is **not listening**, this call will fail.

----------------------------------------------------------------------------------------------------------------------------

### 🔹 Step 4: `send()` and `recv()`

Once connected, client and server can exchange data.


#### ✅ `send()` — Client Sends Data to Server

char *message = "Hello from client";
send(sockfd, message, strlen(message), 0);

#### ✅ `recv()` — Client Receives Response from Server


char buffer[1024] = {0};
int bytes_read = recv(sockfd, buffer, sizeof(buffer), 0);
if (bytes_read > 0) {
    printf("Server: %s\n", buffer);
}


| System Call | Direction       | Used By |
| ----------- | --------------- | ------- |
| `send()`    | Client → Server | Client  |
| `recv()`    | Server → Client | Client  |

----------------------------------------------------------------------------------------------------------------------------

### 🔹 Step 5: Close the socket (optional but recommended)

close(sockfd);








