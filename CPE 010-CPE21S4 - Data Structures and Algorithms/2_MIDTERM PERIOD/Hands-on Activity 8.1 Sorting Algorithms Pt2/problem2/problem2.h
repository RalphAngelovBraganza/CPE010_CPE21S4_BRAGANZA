#ifndef PROBLEM2_H
#define PROBLEM2_H
#include <iostream>

void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
}

/*

A.3. Quick Sort
quicksort(A, low, high)
begin
Declare array A[N] to be sorted
low = 1st element; high = last element; pivot
if(low < high)
begin
pivot = partition (A,low,high);
quicksort(A,low,pivot-1)
quicksort(A,pivot+1,high)
End
end

*/

// Quick Sort (CREDITS TO PROGRAMIZ)

// function to swap elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// function to rearrange array (find the partition point)
int partition(int array[], int low, int high)
{
    
    // select the rightmost element as pivot
    int pivot = array[high];
  
    // pointer for greater element
    int i = (low - 1);

    // traverse each element of the array
    // compare them with the pivot
    for (int j = low; j < high; j++){
        if (array[j] <= pivot){
        
            // if element smaller than pivot is found
            // swap it with the greater element pointed by i
            i++;
      
            // swap element at i with element at j
            swap(&array[i], &array[j]);
        }
    }
  
    // swap pivot with the greater element at i
    swap(&array[i + 1], &array[high]);
  
    // return the partition point
    return (i + 1);
}

void quickSort(int array[], int low, int high)
{
    if (low < high){
      
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        int pi = partition(array, low, high);

        // recursive call on the left of pivot
        quickSort(array, low, pi - 1);

        // recursive call on the right of pivot
        quickSort(array, pi + 1, high);
    }
}

#endif

