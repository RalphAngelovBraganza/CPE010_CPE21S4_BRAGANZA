#include <iostream>
#include <stack>

int main() {

    // Create an object - creating the stack object
    std::stack<char> stack1;

    // isEmpty - checking if the stack is empty
    std::cout << "Is the stack empty? " << stack1.empty() << std::endl;

    // Push - Adding elements to the stack
    stack1.push('R');
    std::cout << "Top element: " << stack1.top() << std::endl;
    stack1.push('A');
    std::cout << "Top element: " << stack1.top() << std::endl;
    stack1.push('L');
    std::cout << "Top element: " << stack1.top() << std::endl;
    stack1.push('P');
    std::cout << "Top element: " << stack1.top() << std::endl;
    stack1.push('H');
    std::cout << "Top element: " << stack1.top() << std::endl;

    // Check stack
    std::cout << "\nIs the stack empty? " << stack1.empty() << std::endl;
    std::cout << "Stack size: " << stack1.size() << std::endl;
    std::cout << "Top element: " << stack1.top() << std::endl;

    // Pop
    std::cout << "\nPopping top element..." << std::endl;
    stack1.pop();
    std::cout << "New top element: " << stack1.top() << std::endl;
    std::cout << "Stack size after pop: " << stack1.size() << std::endl;

    // Swap
    std::stack<char> stack2;
    stack2.push('C');
    stack2.push('P');
    stack2.push('E');

    stack1.swap(stack2);

    std::cout << "\nAfter swapping:" << std::endl;
    std::cout << "Stack 1 top element: " << stack1.top() << std::endl;
    std::cout << "Stack 2 top element: " << stack2.top() << std::endl;

    // Emplace
    stack1.emplace('A');
    std::cout << "\nAfter emplacing 'A' onto stack 1, top element: " << stack1.top() << std::endl;

    return 0;
}


