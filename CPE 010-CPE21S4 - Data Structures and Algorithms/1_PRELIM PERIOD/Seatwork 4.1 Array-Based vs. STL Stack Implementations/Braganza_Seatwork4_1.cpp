#include <iostream>
#include <stack>


int main() {

    // Push
    // Pop
    // isEmpty
    // isFull
    // Top
    

    // Create an object:
    std::stack<char> stack1;
    
    std::cout << "Is the stack empty? " << stack1.empty() << std::endl; // Check if the stack is empty
    stack1.push('R'); // Push an element onto the stack
        std::cout << "Top element: " << stack1.top() << std::endl; // Get the top element of the stack
    stack1.push('A'); // Push an element onto the stack
        std::cout << "Top element: " << stack1.top() << std::endl; // Get the top element of the stack
    stack1.push('L'); // Push an element onto the stack
        std::cout << "Top element: " << stack1.top() << std::endl; // Get the top element of the stack
    stack1.push('P'); // Push an element onto the stack
        std::cout << "Top element: " << stack1.top() << std::endl; // Get the top element of the stack
    stack1.push('H'); // Push an element onto the stack
        std::cout << "Top element: " << stack1.top() << std::endl; // Get the top element of the stack
    
    // C
    std::cout << "Is the stack empty? " << stack1.empty() << std::endl; // Check if the stack is empty
    std::cout << "Stack size: " << stack1.size() << std::endl; // Get the size of the stack
    std::cout << "Top element: " << stack1.top() << std::endl; // Get the top element of the stackS

    //swap
    std::stack<char> stack2;
    stack2.push('X');
    stack2.push('Y');
    stack2.push('Z');

    // Swap the contents of the two stacks
    stack1.swap(stack2);

    std::cout << "After swapping:" << std::endl;
    std::cout << "Stack 1 top element: " << stack1.top() << std::endl; 
    std::cout << "Stack 2 top element: " << stack2.top() << std::endl;

    //Emplace
    stack1.emplace('A'); // Emplace an element onto the stack
    std::cout << "After emplacing 'A' onto stack 1, top element: " << stack1.top() << std::endl;
    

    return 0;
}