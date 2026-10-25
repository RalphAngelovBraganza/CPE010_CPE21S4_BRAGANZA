
#ifndef CPE010_HOA14p1_Braganza_sc1_1_H
#define CPE010_HOA14p1_Braganza_sc1_1_H
#include <iostream>
#include <utility>

// Function to perform Bubble Sort
template <typename T>
void bubbleSort(T arr[], int maxSize){

    for(int i = 0; i < maxSize; i++){
        for(int j = i + 1; j < maxSize; j++){
            if(arr[i]>arr[j]){
                std::swap(arr[j],arr[i]);
            }
        }
    }
}

#endif
