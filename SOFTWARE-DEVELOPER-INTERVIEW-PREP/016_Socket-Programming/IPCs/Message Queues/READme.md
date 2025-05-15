Great! Let’s now dive into **Message Queues** — another powerful Inter-Process Communication (IPC) mechanism in Linux.

---

## 📬 Message Queues IPC in Linux

### 📌 What is a Message Queue?

A **Message Queue** allows processes to **communicate by sending and receiving messages** in a structured way. It’s **asynchronous**, meaning the sender and receiver don’t need to interact at the same time.

Each message queue is identified by a unique key and managed by the kernel.

---

### 🧭 Flow of Communication via Message Queues

| Step | Sender (Writer)                              | Receiver (Reader)                            |
| ---- | -------------------------------------------- | -------------------------------------------- |
| 1    | Generate key using `ftok()`                  | Generate same key using `ftok()`             |
| 2    | Create/access message queue using `msgget()` | Create/access message queue using `msgget()` |
| 3    | Send message using `msgsnd()`                | Receive message using `msgrcv()`             |
| 4    | Optional: Remove queue using `msgctl()`      | Optional: Remove queue using `msgctl()`      |

---

### 🛠️ System Calls Used

#### 1. `ftok(pathname, proj_id)`

Generates a unique key:


key_t key = ftok("msgfile", 65);  // "msgfile" must exist

#### 2. `msgget(key, flags)`

Creates or accesses a message queue:


int msgid = msgget(key, 0666 | IPC_CREAT);

#### 3. Define Message Structure


struct msg_buffer {
    long msg_type;
    char msg_text[100];
};

* `msg_type` must be > 0. Used to distinguish between different kinds of messages.
* `msg_text` holds the actual message data.

#### 4. `msgsnd()`

Sends a message to the queue:

msg_buffer message;
message.msg_type = 1;
strcpy(message.msg_text, "Hello from sender");
msgsnd(msgid, &message, sizeof(message.msg_text), 0);

#### 5. `msgrcv()`

Receives a message from the queue:


msg_buffer message;
msgrcv(msgid, &message, sizeof(message.msg_text), 1, 0);

#### 6. `msgctl()`

Used to control the queue (e.g., delete it):
msgctl(msgid, IPC_RMID, NULL);  // Remove the queue

### 📎 Notes

* Messages can be prioritized using `msg_type`.
* Message queues are **asynchronous** — sender and receiver don’t need to be running simultaneously.
* Synchronization is typically handled via `msg_type`.

---

### 📂 Suggested GitHub Folder Structure

message_queue_ipc/
│
├── sender.cpp         # Writer program
├── receiver.cpp       # Reader program
├── msgfile            # Dummy file used by ftok()
├── README.md          # This documentation


