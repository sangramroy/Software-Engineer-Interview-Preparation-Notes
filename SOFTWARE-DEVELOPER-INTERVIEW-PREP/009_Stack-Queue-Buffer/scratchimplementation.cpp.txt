                                                Stack

#include <iostream>
#include <vector>
using namespace std;

class stack{
  int data;
  int top;
  int *arr;
  int size;
  public:
  
  stack(int siz){
      size=siz;
      arr=new int[size];
      top=-1;
      cout<<"\n stack created with size : "<<size<<endl;
  }
  void push(int val)
  {
      //stack empty
      if(isfull()){
          cout<<"\nstack is full:\n";
      }
      //stack not full
      else
      {
         top++;
         arr[top]=val;
         cout<<"\n element pushed in stack: "<<arr[top];
      }
  }
  
  void pop()
  {
      //stack empty
      if(isempty())
      {
          cout<<"\n stack is empty:\n";
      }
      else
      {
          int val=arr[top];
          top--;
          cout<<"\n elment popped from stack: "<<val<<endl;
      }
  }
  
  bool isfull() 
  {
      return top==size-1?1:0;
  }
  bool isempty() 
  {
      return top==-1?1:0;
  }
  void topelement()
  {
      cout<<"\n top element is: "<<arr[top]<<endl;
  }
  ~stack()
  {
      delete []arr;
      cout<<"\n deleted array"<<endl;
  }
};

int main() {
   cout<<"\n implementing custom stack:\n";
   vector<int> v={45,23,76,98,1,3};
   stack st(6);
   for(int i=0;i<v.size();i++)
   {
       st.push(v[i]);
   }
   st.pop();
   st.topelement();
   st.pop();
   st.topelement();
    return 0;
}


-----------------------------------------------------------------------------------------------------
                                                     Queue
#include <iostream>
#include <vector>
using namespace std;

class queue {
    int front;
    int rear;
    int* arr;
    int size;

public:
    queue(int siz) {
        this->size = siz;
        arr = new int[size];
        front = -1;
        rear = -1;
        cout << "\nQueue created with size: " << size << endl;
    }

    void push(int val) {
        if (isfull()) {
            cout << "\nQueue is full.\n";
        } else {
            rear++;
            arr[rear] = val;
            cout << "\nElement pushed in queue: " << arr[rear];
        }
    }

    void pop() {
        if (isempty()) {
            cout << "\nQueue is empty.\n";
        } else {
            front++;
            cout << "\nElement popped from queue: " << arr[front] << endl;
        }
    }

    bool isfull() {
        return rear == size - 1;
    }

    bool isempty() {
        return front == rear;
    }

    void frontelement() {
        if (isempty()) {
            cout << "\nQueue is empty.\n";
        } else {
            cout << "\nFront element is: " << arr[front + 1] << endl;
        }
    }

    ~queue() {
        delete[] arr;
        cout << "\nDeleted queue memory.\n";
    }
};

int main() {
    cout << "\nImplementing custom queue:\n";
    vector<int> v = {45, 23, 76, 98, 1, 3};
    queue st(6);

    for (int i = 0; i < v.size(); i++) {
        st.push(v[i]);
    }

    st.pop();
    st.frontelement();
    st.pop();
    st.frontelement();

    return 0;
}
------------------------------------------------------------------------------------------------------------
                                                       CircularQueue
#include <iostream>
#include <vector>
using namespace std;

class CircularQueue {
    int front;
    int rear;
    int* arr;
    int size;

public:
    CircularQueue(int siz) {
        this->size = siz;
        arr = new int[size];
        front = -1;
        rear = -1;
        cout << "\nCircular Queue created with size: " << size << endl;
    }

    bool isfull() {
        return (front == (rear + 1) % size);
    }

    bool isempty() {
        return front == -1;
    }

    void push(int val) {
        if (isfull()) {
            cout << "\nQueue is full.\n";
            return;
        }

        if (isempty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % size;
        }

        arr[rear] = val;
        cout << "\nElement pushed in queue: " << val;
    }

    void pop() {
        if (isempty()) {
            cout << "\nQueue is empty.\n";
            return;
        }

        cout << "\nElement popped from queue: " << arr[front] << endl;

        if (front == rear) {
            // Only one element was present
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void frontelement() {
        if (isempty()) {
            cout << "\nQueue is empty.\n";
        } else {
            cout << "\nFront element is: " << arr[front] << endl;
        }
    }

    void display() {
        if (isempty()) {
            cout << "\nQueue is empty.\n";
            return;
        }

        cout << "\nQueue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % size;
        }
        cout << endl;
    }

    ~CircularQueue() {
        delete[] arr;
        cout << "\nDeleted circular queue memory.\n";
    }
};

int main() {
    cout << "\nImplementing circular queue:\n";
    vector<int> v = {45, 23, 76, 98, 1, 3};
    CircularQueue cq(6);

    for (int i = 0; i < v.size(); i++) {
        cq.push(v[i]);
    }

    cq.display();

    cq.pop();
    cq.frontelement();
    cq.pop();
    cq.frontelement();
    cq.display();

    cq.push(99); // should reuse space
    cq.display();

    return 0;
}

-----------------------------------------------------------------------------------------------------------
                                                 vector
#include <iostream>
using namespace std;

class Vector {
    int* ptr;
    int size;
    int capacity;

public:
    // Default constructor
    Vector() {
        ptr = nullptr;
        size = 0;
        capacity = 0;
    }

    // Parameterized constructor
    Vector(int cap) {
        size = 0;
        capacity = cap;
        ptr = new int[capacity];
    }

    // Destructor
    ~Vector() {
        delete[] ptr;
    }

    // Push an element to the end
    void push(int data) {
        if (size == capacity) {
            int newCap = (capacity == 0) ? 1 : 2 * capacity;
            int* newPtr = new int[newCap];

            for (int i = 0; i < size; i++) {
                newPtr[i] = ptr[i];
            }

            delete[] ptr;
            ptr = newPtr;
            capacity = newCap;

            cout << "Vector capacity increased to: " << capacity << endl;
        }

        ptr[size] = data;
        size++;
        cout << "Pushed: " << data << endl;
    }

    // Pop the last element
    void pop() {
        if (size > 0) {
            cout << "Popped: " << ptr[size - 1] << endl;
            size--;
        } else {
            cout << "Vector is empty!\n";
        }
    }

    // Resize the capacity to match the current size
    void resize() {
        int* newPtr = new int[size];
        for (int i = 0; i < size; i++) {
            newPtr[i] = ptr[i];
        }
        delete[] ptr;
        ptr = newPtr;
        capacity = size;
        cout << "Vector resized to capacity: " << capacity << endl;
    }

    // Get current size
    int getsize() {
        return size;
    }

    // Get current capacity
    int getcapacity() {
        return capacity;
    }

    // Access by index
    int operator[](int index) {
        if (index >= 0 && index < size) {
            return ptr[index];
        } else {
            cout << "Index out of bounds!" << endl;
            return -1;
        }
    }

    // Display size and capacity
    void sizencap() {
        cout << "Size: " << size << ", Capacity: " << capacity << endl;
    }
};

int main() {
    Vector v(2);

    v.push(78);
    v.push(8);
    v.push(7);
    v.push(43);
    v.push(76);
    v.push(16);
    v.pop();
    v.resize();

    cout << "\nIterating vector:\n";
    for (int i = 0; i < v.getsize(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}
------------------------------------------------------------------------------------------
                                                   hashmap

#include <iostream>
using namespace std;

// Node to store key-value pair
class Node {
public:
    int key;
    int value;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        next = nullptr;
    }
};

class HashMap {
    Node** buckets;
    int size;

public:
    // Constructor
    HashMap(int s) {
        size = s;
        buckets = new Node*[size];
        for (int i = 0; i < size; i++) {
            buckets[i] = nullptr;
        }
    }

    // Hash function
    int hashFunc(int key) {
        return key % size;
    }

    // Insert key-value pair
    void insert(int key, int value) {
        int idx = hashFunc(key);
        Node* head = buckets[idx];

        // Check if key already exists, update value
        Node* temp = head;
        while (temp) {
            if (temp->key == key) {
                temp->value = value;
                cout << "Updated key " << key << " with value " << value << " at index " << idx << endl;
                return;
            }
            temp = temp->next;
        }

        // Insert at head
        Node* newNode = new Node(key, value);
        newNode->next = head;
        buckets[idx] = newNode;
        cout << "Inserted key " << key << " with value " << value << " at index " << idx << endl;
    }

    // Search value by key
    bool search(int key) {
        int idx = hashFunc(key);
        Node* temp = buckets[idx];
        while (temp) {
            if (temp->key == key) {
                cout << "Found key " << key << " with value " << temp->value << " at index " << idx << endl;
                return true;
            }
            temp = temp->next;
        }
        cout << "Key " << key << " not found" << endl;
        return false;
    }

    // Remove key-value pair
    void remove(int key) {
        int idx = hashFunc(key);
        Node* temp = buckets[idx];
        Node* prev = nullptr;

        while (temp) {
            if (temp->key == key) {
                if (prev) {
                    prev->next = temp->next;
                } else {
                    buckets[idx] = temp->next;
                }
                delete temp;
                cout << "Removed key " << key << " from index " << idx << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }

        cout << "Key " << key << " not found, cannot delete" << endl;
    }

    // Print map
    void printMap() {
        cout << "\nHashMap Contents:\n";
        for (int i = 0; i < size; i++) {
            cout << "Index " << i << ": ";
            Node* temp = buckets[i];
            while (temp) {
                cout << "[" << temp->key << " -> " << temp->value << "] -> ";
                temp = temp->next;
            }
            cout << "NULL" << endl;
        }
    }

    // Destructor
    ~HashMap() {
        for (int i = 0; i < size; i++) {
            Node* temp = buckets[i];
            while (temp) {
                Node* del = temp;
                temp = temp->next;
                delete del;
            }
        }
        delete[] buckets;
    }
};

// ----------------------------
// ✅ Main
// ----------------------------
int main() {
    HashMap map(10);

    map.insert(1, 100);
    map.insert(11, 200); // collision
    map.insert(21, 300); // collision
    map.insert(2, 400);
    map.insert(1, 500);  // update key 1

    map.printMap();

    map.search(11);
    map.search(99);

    map.remove(11);
    map.remove(99);

    map.printMap();

    return 0;
}


