#ifndef CANNIDATE_H
#define CANNIDATE_H

#include <iostream>

// Function to display the array
void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
}

// Function to perform Insertion Sort
template <typename T>
void insertionSort2(T arr[], int maxSize)
{
    for (int k = 1; k < maxSize; k++){
        T temp = arr[k];
        int j = k - 1;

        for (; j >= 0 && temp <= arr[j]; j--){
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}

#endif