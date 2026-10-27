#include <iostream>
#include "supp.h"

void displayArr(int array[], int size);

int main() {
    int arr[] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};
    int size = sizeof(arr) / sizeof(arr[0]);

    std::cout << "Original Array:" << std::endl;
    displayArr(arr, size);

    // Sorting left and right sub-lists with Shell Sort after partition
    hybridQuickSort(arr, 0, size - 1);

    std::cout << std::endl;
    std::cout << "Sorted Array (Hybrid Quick-Shell Sort):" << std::endl;
    displayArr(arr, size);

    return 0;
}

void displayArr(int array[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}