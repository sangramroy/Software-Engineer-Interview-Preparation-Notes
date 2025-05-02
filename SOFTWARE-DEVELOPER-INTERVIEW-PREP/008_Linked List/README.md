# Linked List Operations in C++

This repository contains a C++ implementation of a singly linked list along with various common operations. The code is organized within a `Node` class, providing a clean and modular way to work with linked lists.

## Features

This implementation includes the following linked list operations:

* **Insertion:**
    * `insert(head, val)`: Inserts a new node with the given `val` at the tail of the linked list.
    * `insertAtHead(head, val)`: Inserts a new node with the given `val` at the head of the linked list.
* **Deletion:**
    * `deleteNode(head, val)`: Deletes the first node with the given `val` from the linked list.
* **Traversal and Information:**
    * `length(head)`: Returns the number of nodes in the linked list.
    * `printList(head)`: Prints the elements of the linked list to the console.
    * `findMiddle(head)`: Finds and returns the middle node of the linked list.
* **Reversal:**
    * `reverse(head)`: Reverses the order of the nodes in the linked list.
    * `reverseKGroup(head, k)`: Reverses the linked list in groups of `k` nodes.
* **Loop Detection:**
    * `detectLoop(head)`: Detects if the linked list contains a cycle (loop).
    * `findLoopStart(head)`: If a loop exists, finds and returns the starting node of the loop.
* **Sorting:**
    * `merge(left, right)`: Helper function to merge two sorted linked lists.
    * `mergeSort(head)`: Sorts the linked list using the merge sort algorithm.
    * `sortZeroOneTwo(head)`: Sorts a linked list containing only 0s, 1s, and 2s efficiently.
* **Other Operations:**
    * `getIntersection(head1, head2)`: Finds and returns the intersection node of two linked lists.
    * `addTwoLists(l1, l2)`: Adds two numbers represented by linked lists.
    * `oddEvenList(head)`: Rearranges the linked list so that all odd positioned nodes appear before all even positioned nodes.
    * `reorderList(head)`: Reorders the linked list in the pattern L0→Ln→L1→Ln-1→....
    * `swapKth(head, k)`: Swaps the kth node from the beginning with the kth node from the end of the linked list.

