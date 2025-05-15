Here is a well-structured, README-style content you can use for your GitHub project to document **Shared Memory IPC in Linux**, including flow, system calls, and code explanation.

---

## 🧠 Shared Memory IPC in Linux

### 📌 What is Shared Memory?

**Shared Memory** is a form of **Inter-Process Communication (IPC)** where **two or more processes** can communicate by **sharing a common memory segment**. It is **fastest among IPCs** because it avoids kernel involvement after setup.

---

### 🧭 Flow of Shared Memory Communication

| Step | Sender (Writer)                            | Receiver (Reader)                         |
| ---- | ------------------------------------------ | ----------------------------------------- |
| 1    | Generate key using `ftok()`                | Generate the same key using `ftok()`      |
| 2    | Create shared memory using `shmget()`      | Access the shared memory using `shmget()` |
| 3    | Attach the memory using `shmat()`          | Attach the memory using `shmat()`         |
| 4    | Write to the shared memory                 | Read from the shared memory               |
| 5    | Detach the memory using `shmdt()`          | Detach the memory using `shmdt()`         |
| 6    | (Optional) Destroy memory using `shmctl()` | —                                         |

---

### 🛠️ System Calls Used

#### 1. `ftok(pathname, proj_id)`

Generates a **unique key** based on a file and a project ID.

```cpp
key_t key = ftok("shmfile", 65);  // "shmfile" must exist
```

#### 2. `shmget(key, size, flags)`

Creates or accesses a shared memory segment.

```cpp
int shmid = shmget(key, 1024, 0666|IPC_CREAT);
```

* `1024` = size in bytes
* `0666` = permissions
* `IPC_CREAT` = create if it doesn’t exist

#### 3. `shmat(shmid, NULL, 0)`

Attaches shared memory to process's address space.

```cpp
char *str = (char*) shmat(shmid, (void*)0, 0);
```

#### 4. `shmdt(str)`

Detaches the shared memory from the process.

```cpp
shmdt(str);
```

#### 5. `shmctl(shmid, IPC_RMID, NULL)`

Destroys the shared memory segment.

```cpp
shmctl(shmid, IPC_RMID, NULL);
```

---

### 🔄 Sender & Receiver Code Summary

#### 📝 Sender (Writer)

```cpp
key_t key = ftok("shmfile", 65);
int shmid = shmget(key, 1024, 0666|IPC_CREAT);
char* str = (char*) shmat(shmid, nullptr, 0);
strcpy(str, "Hello from sender");
shmdt(str);
```

#### 📝 Receiver (Reader)

```cpp
key_t key = ftok("shmfile", 65);
int shmid = shmget(key, 1024, 0666);
char* str = (char*) shmat(shmid, nullptr, 0);
printf("Data read: %s\n", str);
shmdt(str);
shmctl(shmid, IPC_RMID, NULL);
```

---

### 📎 Notes

* File passed to `ftok()` must exist (e.g., `"shmfile"`).
* Memory is shared **only among processes on the same system**.
* Ensure synchronization (like semaphores) if multiple processes write simultaneously.

---

### 📂 Folder Structure (Optional)

```
shared_memory_ipc/
│
├── sender.cpp         # Writer program
├── receiver.cpp       # Reader program
├── shmfile            # Dummy file used by ftok()
├── README.md          # This documentation
```


