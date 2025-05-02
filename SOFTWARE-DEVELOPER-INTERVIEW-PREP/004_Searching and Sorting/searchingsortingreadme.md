# Searching and Sorting Algorithms

This folder contains implementations of fundamental **searching** and **sorting** algorithms in C++. These are essential for understanding time complexity, optimization, and foundational logic used in interviews and competitive programming.

---

## 📚 Contents

1. [Searching Algorithms](#1-searching-algorithms)
   - Linear Search
   - Binary Search
2. [Sorting Algorithms](#2-sorting-algorithms)
   - Bubble Sort
   - Insertion Sort
   - Selection Sort
   - Merge Sort
   - Cycle Sort

---

## 1. 🔍 Searching Algorithms

### 🔸 Linear Search
- **Concept**: Sequentially checks each element until the key is found.
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
- **Best for**: Unsorted arrays or small datasets.
- **Usage**:
  ```cpp
  linearSearch(arr, size, key);
  ```

---

### 🔸 Binary Search
- **Concept**: Efficient search using divide and conquer on a sorted array.
- **Time Complexity**: O(log n)
- **Space Complexity**: O(1) (iterative)
- **Best for**: Sorted arrays.
- **Usage**:
  ```cpp
  int index = binarySearch(arr, 0, size - 1, key);
  if (index != -1) {
      cout << "Element found at index: " << index;
  }
  ```

---

## 2. 🔃 Sorting Algorithms

### 🔸 Bubble Sort
- **Concept**: Repeatedly compares and swaps adjacent elements if they are in the wrong order.
- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)
- **Stable**: Yes
- **Usage**:
  ```cpp
  bubbleSort(arr, size);
  ```

---

### 🔸 Insertion Sort
- **Concept**: Builds the sorted array one item at a time by shifting elements.
- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)
- **Stable**: Yes
- **Usage**:
  ```cpp
  insertionSort(arr, size);
  ```

---

### 🔸 Selection Sort
- **Concept**: Selects the minimum element and swaps with current position.
- **Time Complexity**: O(n²)
- **Space Complexity**: O(1)
- **Stable**: No
- **Usage**:
  ```cpp
  selectionSort(arr, size);
  ```

---

### 🔸 Merge Sort
- **Concept**: Divide-and-conquer algorithm that splits, sorts recursively, and merges arrays.
- **Time Complexity**: O(n log n)
- **Space Complexity**: O(n)
- **Stable**: Yes
- **Usage**:
  ```cpp
  mergeSort(arr, 0, size - 1);
  ```

---

### 🔸 Cycle Sort
- **Concept**: Places elements directly at their correct index assuming unique values from 1 to N.
- **Time Complexity**: O(n)
- **Space Complexity**: O(1)
- **Stable**: No
- **Usage**:
  ```cpp
  cycleSort(arr, size);
  ```


## ✅ Recommendations

| Algorithm       | Best Use Case                          | Time Complexity |
|----------------|-----------------------------------------|-----------------|
| Linear Search   | Unsorted arrays                        | O(n)            |
| Binary Search   | Sorted arrays                          | O(log n)        |
| Bubble Sort     | Learning basics                        | O(n²)           |
| Insertion Sort  | Nearly sorted or small datasets        | O(n²)           |
| Selection Sort  | Memory-constrained, small datasets     | O(n²)           |
| Merge Sort      | Large datasets with stable sorting     | O(n log n)      |
| Cycle Sort      | Unique elements in range 1 to N        | O(n)            |

---

## 🧠 Author Notes

This folder is part of the **Developer Prep** series focused on mastering data structures and algorithms using C++.  
Understanding these basic sorting and searching algorithms is critical for excelling in coding interviews and solving real-world optimization problems.

---
