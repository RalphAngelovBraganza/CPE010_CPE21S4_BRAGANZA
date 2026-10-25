#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mergesort.h"

const int SIZE = 100;

int main(){
    
    // Array of size 100 to hold random integers
    int arr[SIZE];
    srand(time(0));

    for (int i = 0; i < SIZE; i++){
        arr[i] = rand()%100;
    }

    std::cout << "Original Array:" << std::endl;
    displayArray(arr, SIZE);

    mergeSort(arr, 0, SIZE - 1);
    std::cout << "\n\nMerge Sort:" << std::endl;
    displayArray(arr, SIZE);


    return 0;
}

    