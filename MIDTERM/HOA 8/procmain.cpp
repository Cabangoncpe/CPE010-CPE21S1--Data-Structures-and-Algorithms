#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sortingalgo.h"

const int size = 100;

void copyArray(int source[], int destination[], int size);
void displayArr(int array[], int size);

int main(){

    int original[size];
    int shellArray[size];
    int mergeArray[size];
    int quickArray[size];

    srand(time(0));

    for (int i = 0; i < size; i++)
    {
        original[i] = rand() % 1000 + 1;
    }
    copyArray(original, shellArray, size);
    copyArray(original, mergeArray, size);
    copyArray(original, quickArray, size);

    std::cout << "Original Unsorted Array:" << std::endl;
    displayArr(original, size);

    shellSort(shellArray, size);

    mergeSort(mergeArray, 0, size - 1);

    quickSort(quickArray, 0, size - 1);

    std::cout << std::endl;
    std::cout << "Shell Sort:" << std::endl;
    displayArr(shellArray, size);

    std::cout << std::endl;
    std::cout << "Merge Sort:" << std::endl;
    displayArr(mergeArray, size);

    std::cout << std::endl;
    std::cout << "Quick Sort:" << std::endl;
    displayArr(quickArray, size);

    return 0;
}
void copyArray(int source[], int destination[], int size)
{
    for (int i = 0; i < size; i++)
    {
        destination[i] = source[i];
    }
}

void displayArr (int array[], int size){
    for(int i = 0; i < size; i++){
        std::cout << array[i] << " "; 
    }
    std::cout << std::endl;
}
