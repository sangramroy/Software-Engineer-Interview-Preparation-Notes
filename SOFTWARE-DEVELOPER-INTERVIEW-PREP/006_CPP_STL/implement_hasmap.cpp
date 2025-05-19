
```cpp
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
```

/*---

## ✅ Dry Run Summary

```cpp
insert(1, 100); → hashFunc(1) = 1 → [1->100]
insert(11, 200); → 1 → [11->200] → [1->100]
insert(21, 300); → 1 → [21->300] → [11->200] → [1->100]
insert(2, 400); → 2 → [2->400]
insert(1, 500); → update existing key 1 → [1->500]

search(11); → found
remove(11); → delete node from chain
```

---

*/
