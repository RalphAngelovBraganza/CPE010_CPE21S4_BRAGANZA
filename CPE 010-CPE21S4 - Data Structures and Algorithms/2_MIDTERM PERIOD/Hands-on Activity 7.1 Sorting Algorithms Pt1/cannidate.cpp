#include <iostream>
#include <cstdlib>
#include <ctime>
#include "cannidate.h"

const int SIZE = 100;

int main()
{
    int arr[SIZE];

    srand(time(0));

    // Array of size 100 to hold random integers
    for (int i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 5 + 1; // to make sure there is no candidate with 0 votes, we will generate random numbers from 1 to 5
    }

    std::cout << "UNSORTED VOTES:\n";
    displayArray(arr, SIZE);

    // Sort the votes
    insertionSort2(arr, SIZE);

    std::cout << "\n\nSORTED VOTES:\n";
    displayArray(arr, SIZE);

    std::cout << "\n\nVOTE COUNT:\n";

    int winner = 1;
    int highestVotes = 0;

    for (int candidate = 1; candidate <= 5; candidate++)
    {
        int count = 0;

        for (int i = 0; i < SIZE; i++){
            if (arr[i] == candidate){
                count++;
            }
        }

        if (candidate == 1)
            std::cout << "Bo Dalton Capistrano: ";
        else if (candidate == 2)
            std::cout << "Cornelius Raymon Agustín: ";
        else if (candidate == 3)
            std::cout << "Deja Jayla Bañaga: ";
        else if (candidate == 4)
            std::cout << "Lalla Brielle Yabut: ";
        else if (candidate == 5)
            std::cout << "Franklin Relano Castro: ";

        std::cout << count << " votes\n";

        if (count > highestVotes){
            highestVotes = count;
            winner = candidate;
        }
    }

    std::cout << "\n THE WINNER: ";

    if (winner == 1)
        std::cout << "Bo Dalton Capistrano";
    else if (winner == 2)
        std::cout << "Cornelius Raymon Agustín";
    else if (winner == 3)
        std::cout << "Deja Jayla Bañaga";
    else if (winner == 4)
        std::cout << "Lalla Brielle Yabut";
    else if (winner == 5)
        std::cout << "Franklin Relano Castro";

    std::cout << " with " << highestVotes << " votes.\n";

    return 0;
}