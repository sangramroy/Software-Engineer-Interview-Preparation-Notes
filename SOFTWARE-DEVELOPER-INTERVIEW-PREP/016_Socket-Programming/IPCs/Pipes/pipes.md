Great! Let's dive into **Pipes**, another important IPC (Inter-Process Communication) mechanism in Unix/Linux.



## 🧵 What is a Pipe?

A **pipe** is a unidirectional communication channel that allows data to flow **from one process to another**. It's typically used between **parent and child processes**.

* Data flows in **one direction only** (read from one end, write to the other).
* Uses file descriptors internally (like `fd[0]` for read, `fd[1]` for write).
* The OS handles synchronization automatically (FIFO behavior).



## 🔧 System Call: `pipe()`

### Syntax:

```c
int pipe(int fd[2]);
```

* `fd[0]` → Read end
* `fd[1]` → Write end
* Returns: `0` on success, `-1` on error.



## 🔁 Typical Flow

Here’s how pipes work step-by-step:

### 🔸 Parent Process:

1. Calls `pipe(fd)` to create the pipe.
2. Forks a child process with `fork()`.
3. Uses `write(fd[1], ...)` to send data to the pipe.

### 🔸 Child Process:

1. Inherits file descriptors from parent.
2. Uses `read(fd[0], ...)` to receive data from the pipe.



## 🧪 Example: Pipe Between Parent and Child

```c
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main() {
    int fd[2];  // fd[0] for reading, fd[1] for writing
    char write_msg[] = "Hello from parent!";
    char read_msg[100];

    if (pipe(fd) == -1) {
        perror("pipe");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        return 1;
    } else if (pid == 0) {
        // 👶 Child process
        close(fd[1]); // Close write end (child only reads)
        read(fd[0], read_msg, sizeof(read_msg));
        printf("Child received: %s\n", read_msg);
        close(fd[0]);
    } else {
        // 👨 Parent process
        close(fd[0]); // Close read end (parent only writes)
        write(fd[1], write_msg, strlen(write_msg) + 1);
        close(fd[1]);
    }

    return 0;
}
```



## 💬 Comments for Each Line

| Code Line                  | What It's Doing                                                   |
| -- | -- |
| `pipe(fd)`                 | Creates the pipe with two FDs (fd\[0] for read, fd\[1] for write) |
| `fork()`                   | Creates a child process                                           |
| `if (pid == 0)`            | Code inside this block is run by the child                        |
| `close(fd[1])`             | Child closes write-end — only wants to read                       |
| `read(fd[0], ...)`         | Child reads from pipe                                             |
| `close(fd[0])`             | Child closes read-end                                             |
| `close(fd[0])` (in parent) | Parent closes read-end — only writes                              |
| `write(fd[1], ...)`        | Parent writes to the pipe                                         |
| `close(fd[1])`             | Closes write-end in parent                                        |



## ⚠️ Key Points

| Aspect      | Value                                                 |
| -- | -- |
| Direction   | Unidirectional (use two pipes for bidirectional)      |
| Usage Scope | Parent-child processes only (not unrelated processes) |
| Sync        | Automatically handles blocking reads/writes           |
| Buffering   | OS buffers the data                                   |
| Lifetime    | Pipe exists until process terminates                  |
