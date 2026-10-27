#ifndef SUPP_H
#define SUPP_H

#include <iostream> 
#include <utility>

template <typename T>
void shellSortSubarray(T arr[], int low, int high) {
    int n = high - low + 1;
    if (n <= 1) return;

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = low + gap; i <= high; i++) {
            T temp = arr[i];
            int j = i;

            while (j >= low + gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

template <typename T>
int partition(T arr[], int low, int high) {
    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]); 
    return i + 1;
}

// Hybrid Quick Sort using Shell Sort for sub-lists
template <typename T>
void hybridQuickSort(T arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        // Sort left sub-list using Shell Sort
        shellSortSubarray(arr, low, pi - 1);

        // Sort right sub-list using Shell Sort
        shellSortSubarray(arr, pi + 1, high);
    }
}
#endif