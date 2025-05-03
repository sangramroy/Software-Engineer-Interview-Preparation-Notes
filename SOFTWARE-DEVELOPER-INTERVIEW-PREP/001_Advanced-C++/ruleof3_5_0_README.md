# 🚀 Rule of 5 in C++ (Without Initializer List & Smart Pointers)

This project demonstrates the use of the **Rule of 5** in modern C++ with **manual memory management (raw pointers)** and **without initializer lists or smart pointers**.

---

## ❓ What is Rule of 3 / Rule of 5 / Rule of 0?

### 📌 Rule of 3:
If your class **manages a resource** (e.g., dynamically allocated memory), and you define **any one** of the following:
1. Destructor
2. Copy Constructor
3. Copy Assignment Operator

👉 Then you **must** define all **three** to avoid memory issues like double-free, leaks, or shallow copies.

---

### 📌 Rule of 5:
C++11 introduced **move semantics**. So, in addition to the Rule of 3, if your class handles resources, you should also define:
4. Move Constructor
5. Move Assignment Operator

👉 If your class defines **any of these five**, you should probably define all **five**. This prevents performance penalties and ensures safe resource ownership transfer.

---

### 📌 Rule of 0:
If your class **does not manage resources directly** (e.g., uses STL containers or smart pointers), then let the compiler generate special member functions.

👉 **No need to write destructors, copy/move constructors or assignment operators manually.**

---

## ✅ Why Rule of 5 Here?

In this project, the class uses a **raw pointer (`int* y`)** to manage dynamic memory. That means:

- We need to implement all **five** special functions manually to manage copy, assignment, and cleanup properly.
- We are not using smart pointers or STL containers, so **Rule of 0 does not apply**.
- This is a classic case to apply **Rule of 5**.

---

## 💡 Features

- Implements:
  - ✅ Default constructor
  - ✅ Parameterized constructor
  - ✅ Copy constructor (deep copy)
  - ✅ Move constructor (ownership transfer)
  - ✅ Copy assignment operator (deep copy)
  - ✅ Move assignment operator (ownership transfer)
  - ✅ Destructor
- Raw pointer management using `new` and `delete`
- No initializer lists used
- Verbose output to demonstrate when each function is called
