#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sorting.h"

const int SIZE = 100;

int main(){
    

    // Array of size 100 to hold random integers
    int arr[SIZE];
    srand(time(0));

    for (int i = 0; i < SIZE; i++){
        arr[i] = rand()%100;
    }
    
    //Display unsorted array
    // std::cout << "\nUNSORTED ARRAY:\n";
    // displayArray(arr, SIZE);

    // std::cout << "\n----------------------------------------------------------\n";


    // // Displaying Bubble Sort
    // std::cout << "\nBUBBLE SORT";
    // std::cout << "\n\nUnsorted Array:\n";
    // displayArray(arr, SIZE);
    // bubbleSort(arr, SIZE);
    // std::cout << "\n\nSorted Array Using Bubble Sort:\n";
    // displayArray(arr, SIZE);

    // std::cout << "\n----------------------------------------------------------\n";

    // Displaying Selection Sort
    // std::cout << "\nSELECTION SORT";
    // std::cout << "\n\nUnsorted Array:\n";
    // displayArray(arr, SIZE);
    // selectionSort(arr, SIZE);
    // std::cout << "\n\nSorted Array Using Selection Sort:\n";
    // displayArray(arr, SIZE);

    // std::cout << "\n----------------------------------------------------------\n";

    // Displaying Insertion Sort (while-loop)
    // std::cout << "\nINSERTION SORT (while-loop)";
    // std::cout << "\n\nUnsorted Array:\n";
    // displayArray(arr, SIZE);
    // insertionSort1(arr, SIZE);
    // std::cout << "\n\nSorted Array Using Insertion Sort (while-loop):\n";
    // displayArray(arr, SIZE);

    // std::cout << "\n----------------------------------------------------------\n";

    // Displaying Insertion Sort (for-loop)
    std::cout << "\nINSERTION SORT (for-loop)";
    std::cout << "\n\nUnsorted Array:\n";
    displayArray(arr, SIZE);
    insertionSort2(arr, SIZE);
    std::cout << "\n\nSorted Array Using Insertion Sort (for-loop):\n";
    displayArray(arr, SIZE);

    return 0;
}