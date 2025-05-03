/*
    Producer-Consumer Problem Using C++ with Multithreading

    This C++ program demonstrates the Producer-Consumer problem using threads,
    a mutex (std::mutex), and a condition variable (std::condition_variable).
    The Producer thread generates data and adds it to a shared buffer,
    while the Consumer thread consumes the data from the buffer.
    
    The program uses the following synchronization mechanisms:
    
    - Mutex (std::mutex): Ensures that only one thread can access the shared buffer at a time, 
      preventing data races.
      
    - Condition Variable (std::condition_variable): Used for synchronizing the threads based on 
      the condition (i.e., whether the buffer is full or empty).
      
    The program works as follows:
    1. The producer generates items and adds them to the buffer.
    2. If the buffer reaches its maximum size, the producer thread waits for the consumer to consume items.
    3. The consumer waits for the buffer to have items to consume.
    4. Once the consumer consumes an item, the producer is notified that space is available in the buffer.

    This pattern ensures safe and efficient communication between the producer and consumer threads.
    
    C++ Standard Library Features Used:
    - std::queue for the shared buffer
    - std::mutex for thread synchronization
    - std::condition_variable for blocking/waking threads
    - std::thread for creating and running threads
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::queue<int> buffer;
const unsigned int maxSize = 5;
std::mutex mtx;
std::condition_variable cv;

void producer() {
    for (int i = 1; i <= 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return buffer.size() < maxSize; });

        buffer.push(i);
        std::cout << "Produced: " << i << std::endl;

        cv.notify_all();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

void consumer() {
    for (int i = 1; i <= 10; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, [] { return !buffer.empty(); });

        int value = buffer.front();
        buffer.pop();
        std::cout << "Consumed: " << value << std::endl;

        cv.notify_all();
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
}

int main() {
    std::thread prod(producer);
    std::thread cons(consumer);

    prod.join();
    cons.join();

    return 0;
}
