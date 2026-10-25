#ifndef SINGLY_LL_H
#define SINGLY_LL_H

#include <iostream>

template <typename T>
class SinglyList{
public:
    T data;
    SinglyList<T>* next;
};

// Traverse the list
template <typename T>
void ListTraversal(SinglyList<T>* node){

    if(node == nullptr){
        std::cout << "The list is empty" << std::endl;
        return;
    }

    // WHILE n IS NOT EQUAL TO null:
    while(node != nullptr){

        // PRINT data to n
        std::cout << node->data;

        // GO TO THE NEXT NODE:
        node = node->next;
    }

    // PRINT THE NEXT LINE
    std::cout << std::endl;
}

// Insert at the Head
template <typename T>
void sllInsertHead(T newData, SinglyList<T>** currentHead){

    // 1. Allocate memory for the new node
    SinglyList<T>* newNode = new SinglyList<T>;

    // 2. Put our data into the new node
    newNode->data = newData;

    // 3. Set next of the new node to point to the previous head
    newNode->next = *currentHead;

    // 4. Reset head to point to the new node
    *currentHead = newNode;
}

// General Insert (Insertion at any part of the list)
template <typename T>
void sllGeneralInsert(T newData, SinglyList<T>* prevNode){

    // 1. Check if it is the head node
    if(prevNode == nullptr){

        // 2. If null, print "Previous node cannot be null."
        std::cout << "Previous node cannot be null." << std::endl;
        return;
    }

    // 3. Allocate a new node
    SinglyList<T>* newNode = new SinglyList<T>;

    // 4. Store data in the new node
    newNode->data = newData;

    // 5. Point new node to the node previous node was pointing to
    newNode->next = prevNode->next;

    // 6. Point previous node to the new node
    prevNode->next = newNode;
}

// Insert at the End
template <typename T>
void sllInsertEnd(T newData, SinglyList<T>** head){

    // 1. Allocate new node
    SinglyList<T>* newNode = new SinglyList<T>;

    // Store data in new node
    newNode->data = newData;

    // Point the new node to null
    newNode->next = nullptr;

    // Check if the list is empty
    if(*head == nullptr){
        *head = newNode;
        return;
    }

    // Dereference to the current node
    SinglyList<T>* currentNode = *head;

    // Traverse the list until the last node
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }

    // Point the next of the current node to the new node
    currentNode->next = newNode;
}

// Delete a Node
template <typename T>
void sllDeleteNode(T findData, SinglyList<T>** head){

    // Check if the list is empty
    if(*head == nullptr){
        return;
    }

    SinglyList<T>* currNode = *head;
    SinglyList<T>* prevNode = nullptr;

    // Search for the node
    while(currNode != nullptr && currNode->data != findData){
        prevNode = currNode;
        currNode = currNode->next;
    }

    // Data was not found
    if(currNode == nullptr){
        return;
    }

    // If deleting the head node
    if(prevNode == nullptr){
        *head = currNode->next;
    }
    else{
        prevNode->next = currNode->next;
    }

    // Free memory
    delete currNode;
}

// Delete the Entire List
template <typename T>
void sllDeleteList(SinglyList<T>** head){

    SinglyList<T>* current = *head;

    while(current != nullptr){
        SinglyList<T>* temp = current;
        current = current->next;
        delete temp;
    }

    *head = nullptr;
}

#endif  