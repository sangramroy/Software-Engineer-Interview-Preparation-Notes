#include <iostream>
using namespace std;

// Utility function to print an array
void print(int a[], int size) {
    cout << "Array elements: ";
    for (int i = 0; i < size; i++)
        cout << a[i] << " ";
    cout << endl;
}

// Bubble Sort
void bubbleSort(int a[], int size) {
    cout << "Applying Bubble Sort..." << endl;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

// Insertion Sort
void insertionSort(int a[], int size) {
    cout << "Applying Insertion Sort..." << endl;
    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0 && a[j] < a[j - 1]; j--) {
            swap(a[j], a[j - 1]);
        }
    }
}

// Selection Sort
void selectionSort(int a[], int size) {
    cout << "Applying Selection Sort..." << endl;
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (a[j] < a[minIndex])
                minIndex = j;
        }
        if (minIndex != i)
            swap(a[i], a[minIndex]);
    }
}

// Merge function for Merge Sort
void merge(int a[], int s, int m, int e) {
    int n1 = m - s + 1;
    int n2 = e - m;
    int left[n1], right[n2];

    for (int i = 0; i < n1; i++) left[i] = a[s + i];
    for (int i = 0; i < n2; i++) right[i] = a[m + 1 + i];

    int i = 0, j = 0, k = s;
    while (i < n1 && j < n2) {
        if (left[i] < right[j])
            a[k++] = left[i++];
        else
            a[k++] = right[j++];
    }

    while (i < n1) a[k++] = left[i++];
    while (j < n2) a[k++] = right[j++];
}

// Merge Sort
void mergeSort(int a[], int s, int e) {
    if (s >=e ) return;
     
        int m = (s + e) / 2;
        mergeSort(a, s, m);
        mergeSort(a, m + 1, e);
        merge(a, s, m, e);
    
}

// Linear Search
void linearSearch(int a[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (a[i] == key) {
            cout << key << " found at index " << i << endl;
            return;
        }
    }
    cout << "Key not found." << endl;
}

// Binary Search (Recursive)
int binarySearch(int a[], int s, int e, int key) {
    if (s <= e) {
        int mid = (s + e) / 2;
        if (a[mid] == key)
            return mid;
        else if (a[mid] > key)
            return binarySearch(a, s, mid - 1, key);
        else
            return binarySearch(a, mid + 1, e, key);
    }
    return -1;
}

// Cycle Sort (For elements from 1 to N)
void cycleSort(int a[], int size) {
    cout << "Applying Cycle Sort..." << endl;
    int i = 0;
    while (i < size) {
        int correct = a[i] - 1;
        if (a[i] >= 1 && a[i] <= size && a[i] != a[correct])
            swap(a[i], a[correct]);
        else
            i++;
    }
}


int partition(int arr[],int s,int e)
{
    int pivot=arr[e];
    int cnt=s-1;
    for(int i=s;i<e;i++)
    {
        if(arr[i]<pivot)
        {
            cnt++;
            swap(arr[i],arr[cnt]);
            //cnt++;
            
        }
    }
    swap(arr[e],arr[cnt+1]);
    return cnt+1;
}
void quicksort(int arr[],int s,int e)
{
    if(s>=e) return; // if subarray has one element it should return
    int p=partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}


// Main function
int main() {
    int arr[] = {34, 82, 1, 98, 3, 9, 333, 87, 44, 99};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array:\n";
    print(arr, n);

    linearSearch(arr, n, 333);

    mergeSort(arr, 0, n - 1);
    cout << "\nArray after Merge Sort:\n";
    print(arr, n);

    int index = binarySearch(arr, 0, n - 1, 99);
    if (index != -1)
        cout << "99 found at index: " << index << endl;
    else
        cout << "99 not found." << endl;

    int arr1[] = {5, 7, 4, 6, 2, 3, 1};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    cycleSort(arr1, m);
    cout << "\nArray after Cycle Sort:\n";
    print(arr1, m);

    return 0;
}
