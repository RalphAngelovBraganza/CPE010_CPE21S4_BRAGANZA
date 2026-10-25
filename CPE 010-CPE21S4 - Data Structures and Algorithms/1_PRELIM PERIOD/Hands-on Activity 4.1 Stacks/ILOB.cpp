#include <iostream>

// Global Variables
#define maxSize 10
// const int maxSize = 10;

int stackArr[maxSize];
int top = -1, newData;

// Function Prototypes
// Top, Push, Pop, isEmpty, isFull
bool isEmpty();
bool isFull();
void Top();              // The T is capital
void displayAll();       // Goal is to display the stack following the LIFO principle

// Transformer operators
void push();
void pop();

int main() {
    int choice;

    while (true) {
        std::cout << "\n===================================================\n";
        std::cout << "Stack Operations\n";
        std::cout << "===================================================\n";
        std::cout << "[1] Push\n";
        std::cout << "[2] Pop\n";
        std::cout << "[3] IsEmpty\n";
        std::cout << "[4] IsFull\n";
        std::cout << "[5] Top\n";
        std::cout << "[6] Display All\n";
        std::cout << "====================================================\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {

            case 1:
                push();
                break;

            case 2:
                pop();
                break;

            case 3:
                std::cout << "Is the stack empty? " << isEmpty() << std::endl;
                break;

            case 4:
                std::cout << "Is the stack full? " << isFull() << std::endl;
                break;

            case 5:
                Top();
                break;

            case 6:
                displayAll();
                break;

            default:
                std::cout << "Invalid Choice!" << std::endl;
                break;
        }
    }

    return 0;
}

// Function Definitions

bool isEmpty() {
    return (top == -1);
}

bool isFull() {
    return (top == maxSize - 1);
}

void Top() {

    // Error checking
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        return;
    }

    // Print the top element
    std::cout << "The top element is: " << stackArr[top] << std::endl;
}

void push() {

    // Error Checking
    if (isFull()) {
        std::cout << "Stack Overflow!" << std::endl;
        return;
    }

    // Ask the user what they want to insert
    std::cout << "Enter a number to push: ";
    std::cin >> newData;

    // Store the data in the stack
    stackArr[++top] = newData;
}

void pop() {

    // Error Checking
    if (isEmpty()) {
        std::cout << "Stack Underflow!" << std::endl;
        return;
    }

    // Display the item to be popped
    std::cout << "Popped element: " << stackArr[top] << std::endl;

    // Remove the element from the stack
    top--;
}

void displayAll() {

    // Error Checking
    if (isEmpty()) {
        std::cout << "Stack is empty!" << std::endl;
        return;
    }

    // Display the stack following the LIFO principle
    std::cout << "\nStack Contents (Top to Bottom)\n";

    for (int i = top; i >= 0; i--) {
        std::cout << stackArr[i] << std::endl;
    }
}

