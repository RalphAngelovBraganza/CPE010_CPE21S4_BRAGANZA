#include <iostream>
#include <string>
#include "theBalancedStack.h"

int main() {

    std::string input;
    std::cout << "-------SYMBOL BALANCER-------\n";

    std::cout << "Enter an expression: ";
    std::getline(std::cin, input);


    // Results Using Array Stack
    std::cout << "\nArray Stack: ";

    if (checkArray(input))
        std::cout << "VALID\n";
    else
        std::cout << "INVALID\n";


    // Results Using Linked List Stack
    std::cout << "Linked List Stack: ";

    if (checkList(input))
        std::cout << "VALID\n";
    else
        std::cout << "INVALID\n";


    return 0;
}

