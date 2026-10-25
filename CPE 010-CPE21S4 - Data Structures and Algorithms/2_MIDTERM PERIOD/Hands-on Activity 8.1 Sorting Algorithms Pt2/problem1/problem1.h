#ifndef PROBLEM1_H
#define PROBLEM1_H
#include <iostream>

void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
}

// Insertion Sort
void insertionSort(int arr[], int low, int high)
{
    for (int i = low + 1; i <= high; i++){
        int temp = arr[i];
        int j = i - 1;

        while (j >= low && arr[j] > temp){
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = temp;
    }
}

// Partition
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++){
        if (arr[j] <= pivot){
            i++;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

// Quick Sort using Insertion Sort for sublists
void quickSort(int arr[], int low, int high)
{
    if (low < high){
        int pivot = partition(arr, low, high);

        // Use Insertion Sort for the left sublist
        insertionSort(arr, low, pivot - 1);

        // Use Insertion Sort for the right sublist
        insertionSort(arr, pivot + 1, high);
    }
}

#endif