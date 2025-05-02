#include <iostream>
using namespace std;

// ==========================================================
// Node Class for all Linked List Operations
// ==========================================================
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int val) : data(val), next(nullptr) {}

    // ======================================================
    // Insert at tail
    static void insert(Node*& head, int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }

    // Insert at head
    static void insertAtHead(Node*& head, int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // ======================================================
    // Delete a node by value
    static void deleteNode(Node*& head, int val) {
        if (!head) return;
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != val) temp = temp->next;
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
        }
    }

    // ======================================================
    // Length of Linked List
    static int length(Node* head) {
        int count = 0;
        while (head) {
            count++;
            head = head->next;
        }
        return count;
    }

    // Find Middle Node
    static Node* findMiddle(Node* head) {
        Node* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // ======================================================
    // Reverse Linked List
    static Node* reverse(Node* head) {
        Node* prev = nullptr, *curr = head, *next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    // Reverse in k-groups
    static Node* reverseKGroup(Node* head, int k) {
        if (!head) return nullptr;

        Node* temp = head;
        for (int i = 0; i < k; i++) {
            if (!temp) return head;
            temp = temp->next;
        }

        Node* prev = reverseKGroup(temp, k);
        while (k--) {
            Node* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }

    // ======================================================
    // Detect Loop
    static bool detectLoop(Node* head) {
        Node* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }

    // Find Start of Loop
    static Node* findLoopStart(Node* head) {
        Node* slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }

    // ======================================================
    // Merge Sort
    static Node* merge(Node* left, Node* right) {
        Node dummy(0);
        Node* temp = &dummy;
        while (left && right) {
            if (left->data < right->data) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }
        temp->next = left ? left : right;
        return dummy.next;
    }

    static Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;
        Node* slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* mid = slow->next;
        slow->next = nullptr;
        Node* left = mergeSort(head);
        Node* right = mergeSort(mid);
        return merge(left, right);
    }

    // ======================================================
    // Sort 0s, 1s, and 2s
    static void sortZeroOneTwo(Node*& head) {
        int count[3] = {0};
        Node* temp = head;
        while (temp) {
            count[temp->data]++;
            temp = temp->next;
        }
        temp = head;
        for (int i = 0; i < 3; i++)
            while (count[i]--) {
                temp->data = i;
                temp = temp->next;
            }
    }

    // ======================================================
    // Find Intersection of Two Lists
    static Node* getIntersection(Node* head1, Node* head2) {
        int len1 = length(head1), len2 = length(head2);
        while (len1 > len2) { head1 = head1->next; len1--; }
        while (len2 > len1) { head2 = head2->next; len2--; }
        while (head1 && head2) {
            if (head1 == head2) return head1;
            head1 = head1->next;
            head2 = head2->next;
        }
        return nullptr;
    }

    // ======================================================
    // Add Two Numbers
    static Node* addTwoLists(Node* l1, Node* l2) {
        Node* dummy = new Node(0);
        Node* temp = dummy;
        int carry = 0;
        while (l1 || l2 || carry) {
            int sum = carry;
            if (l1) { sum += l1->data; l1 = l1->next; }
            if (l2) { sum += l2->data; l2 = l2->next; }
            carry = sum / 10;
            temp->next = new Node(sum % 10);
            temp = temp->next;
        }
        return dummy->next;
    }

    // ======================================================
    // Print List
    static void printList(Node* head) {
        while (head) {
            cout << head->data << " -> ";
            head = head->next;
        }
        cout << "NULL\n";
    }

    // ======================================================
    // Odd-Even Node Rearrangement
    static void oddEvenList(Node*& head) {
        if (!head || !head->next) return;
        Node* odd = head;
        Node* even = head->next;
        Node* evenStart = even;

        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenStart;
    }

    // ======================================================
    // Reorder List: L0→Ln→L1→Ln-1→...
    static void reorderList(Node*& head) {
        if (!head || !head->next) return;
        // Find mid
        Node* slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Reverse second half
        Node* second = reverse(slow->next);
        slow->next = nullptr;
        Node* first = head;

        // Merge two halves
        while (second) {
            Node* tmp1 = first->next;
            Node* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }

    // ======================================================
    // Swap kth node from beginning with kth from end
    static void swapKth(Node*& head, int k) {
        int len = length(head);
        if (k > len) return;

        Node* x = head;
        for (int i = 1; i < k; i++) x = x->next;

        Node* y = head;
        for (int i = 1; i < len - k + 1; i++) y = y->next;

        swap(x->data, y->data);
    }
};

// ==========================================================
// Main Driver Function
// ==========================================================
int main() {
    Node* head = nullptr;

    // Insert values
    for (int val : {1, 2, 3, 4, 5}) Node::insert(head, val);
    cout << "Initial List: "; Node::printList(head);

    // Delete a node
    Node::deleteNode(head, 3);
    cout << "After Deletion: "; Node::printList(head);

    // Length
    cout << "Length: " << Node::length(head) << endl;

    // Middle Node
    Node* mid = Node::findMiddle(head);
    cout << "Middle: " << (mid ? mid->data : -1) << endl;

    // Reverse
    head = Node::reverse(head);
    cout << "Reversed: "; Node::printList(head);

    // Sort
    head = Node::mergeSort(head);
    cout << "Sorted: "; Node::printList(head);

    // Odd-Even Rearrangement
    Node::oddEvenList(head);
    cout << "Odd-Even Rearranged: "; Node::printList(head);

    // Reorder L0→Ln→L1→Ln-1...
    Node::reorderList(head);
    cout << "Reordered: "; Node::printList(head);

    // Reverse in k-groups
    head = Node::reverseKGroup(head, 2);
    cout << "Reversed in K-Group (k=2): "; Node::printList(head);

    // Swap kth nodes
    Node::swapKth(head, 2);
    cout << "Swap 2nd node from start & end: "; Node::printList(head);

    return 0;
}
