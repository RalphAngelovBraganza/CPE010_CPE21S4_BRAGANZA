#include <iostream>
#include "problem2.h"

const int SIZE = 15;

int main(){

    int arr[SIZE] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};

    std::cout << "Original Array:" << std::endl;
    displayArray(arr, SIZE);

    quickSort(arr, 0, SIZE - 1);

    std::cout << "\n\nQuick Sort:" << std::endl;
    displayArray(arr, SIZE);

    return 0;
}
