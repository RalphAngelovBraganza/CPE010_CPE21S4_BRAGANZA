#ifndef THEBALANCEDSTACK_H
#define THEBALANCEDSTACK_H

#include <iostream>
#include <string>


/* 

Array Stack Implementation

*/

char stackArr[100];
int top = -1;

// Push data into array stack
void pushArr(char data) {
    if (top == 99)
        return;
    stackArr[++top] = data;
}

// Remove top element
char popArr() {
    if (top == -1)
        return '\0';
    return stackArr[top--];
}

// Check if array stack is empty
bool emptyArr() {
    return top == -1;
}

// Reset array stack
void resetArr() {
    top = -1;
}

// Balanced symbol checking using array stack
bool checkArray(std::string input) {
    resetArr();
    for (int i = 0; i < input.length(); i++) {
        char symbol = input[i];
        // If opening symbols, push into stack
        if (symbol == '(' || symbol == '{' || symbol == '[') {
            pushArr(symbol);
        }
        // If closing symbols, check the stack
        else if (symbol == ')' || symbol == '}' || symbol == ']') {
            if (emptyArr())
                return false;
            char open = popArr();
            if ((symbol == ')' && open != '(') ||
                (symbol == '}' && open != '{') ||
                (symbol == ']' && open != '[')) {
                return false;
            }
        }
    }
    return emptyArr();
}

/*

Linked List Stack Implementation

*/

struct Node {
    char data;
    Node* next;
};

Node* head = nullptr;

// Push into linked list stack
void pushLL(char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

// Remove top node
char popLL() {
    if (head == nullptr)
        return '\0';
    Node* temp = head;
    char value = temp->data;
    head = head->next;
    delete temp;
    return value;
}

// Check if linked list stack is empty
bool emptyLL() {
    return head == nullptr;
}

// Clear linked list stack
void resetLL() {
    while (!emptyLL()) {
        popLL();
    }
}

// Balanced symbol checking using linked list
bool checkList(std::string input) {
    resetLL();
    for (int i = 0; i < input.length(); i++) {
        char symbol = input[i];
        // Opening symbols
        if (symbol == '(' || symbol == '{' || symbol == '[') {
            pushLL(symbol);
        }
        // Closing symbols
        else if (symbol == ')' || symbol == '}' || symbol == ']') {
            if (emptyLL())
                return false;
            char open = popLL();
            if ((symbol == ')' && open != '(') ||
                (symbol == '}' && open != '{') ||
                (symbol == ']' && open != '[')) {
                return false;
            }
        }
    }


    return emptyLL();
}


#endif

