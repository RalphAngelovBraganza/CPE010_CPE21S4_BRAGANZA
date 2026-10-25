#include <iostream>
#include <cstdlib>
#include <ctime>
#include "problem1.h"

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

    quickSort(arr, 0, SIZE - 1);

    std::cout << "\n\nQuick Sort with Insertion Sort:" << std::endl;
    displayArray(arr, SIZE);


    return 0;
}