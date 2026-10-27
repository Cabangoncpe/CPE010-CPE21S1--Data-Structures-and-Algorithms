#ifndef SORTINGALGO_H
#define SORTINGALGO_H

#include <iostream> 
#include <utility>

template <typename T>
void shellSort(T arr[], int arrSize) {
    int n = arrSize;

    // Start with a large gap, then reduce it step by step
    for (int gap = n / 2; gap > 0; gap /= 2) {

        // Perform a "gapped" insertion sort for this gap size
        for (int i = gap; i < n; i++) {
            
            // Current element to be placed correctly
            T temp = arr[i];  
            int j = i;

            // Shift elements that are greater than temp to make space
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            // Place temp in its correct location
            arr[j] = temp;
        }
    }
}

template <typename T>
int partition(T arr[], int low, int high) {
  
    // choose the pivot
    T pivot = arr[high];
  
    // undex of smaller element and indicates 
    // the right position of pivot found so far
    int i = low - 1;

    // Traverse arr[low..high] and move all smaller
    // elements on left side. Elements from low to 
    // i are smaller after every iteration
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    
    // move pivot after smaller elements and
    // return its position
    std::swap(arr[i + 1], arr[high]);  
    return i + 1;
}

// the QuickSort function implementation
template <typename T>
void quickSort(T arr[], int low, int high) {
  
    if (low < high) {
      
        // pi is the partition return index of pivot
        int pi = partition(arr, low, high);

        // recursion calls for smaller elements
        // and greater or equals elements
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merges two subarrays of arr[].
// First subarray is arr[left..mid]
// Second subarray is arr[mid+1..right]
template <typename T>
void merge(T arr[], int left, int mid, int right){
                    
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp vectors
    T* L = new T[n1];
    T* R = new T[n2];

    // Copy data to temp vectors L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0;
    int k = left;

    // Merge the temp vectors back 
    // into arr[left..right]
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], 
    // if there are any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], 
    // if there are any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
template <typename T>
void mergeSort(T arr[], int left, int right){
    
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

#endif