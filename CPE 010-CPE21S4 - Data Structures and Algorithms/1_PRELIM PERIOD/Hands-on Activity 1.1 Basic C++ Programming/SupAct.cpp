#include <iostream>
#include <limits>

int main() {

    int swapNum1, swapNum2, temp;

    std::cout << "\n| Number Swapper ˚˖𓍢ִ໋❀ |\n" << std::endl;
    std::cout << "Enter the first number: ";

    while (!(std::cin >> swapNum1)) {
        std::cout << "Invalid input! Please enter a valid number: ";
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }

        std::cout << "Enter the second number: ";
    
    while (!(std::cin >> swapNum2)) {
        std::cout << "Invalid input! Please enter a valid number: ";
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
    }

    std::cout << "\nBefore swapping: " << std::endl;
    std::cout << "First number: " << swapNum1 << std::endl;
    std::cout << "Second number: " << swapNum2 << std::endl;

    // Swapping the numbers
    temp = swapNum1;
    swapNum1 = swapNum2;
    swapNum2 = temp;

    std::cout << "\nAfter swapping: " << std::endl;
    std::cout << "First number: " << swapNum1 << std::endl;
    std::cout << "Second number: " << swapNum2 << std::endl;

    return 0;
}

