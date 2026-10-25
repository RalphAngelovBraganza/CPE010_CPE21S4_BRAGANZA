#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

#include <iostream>

template <typename T>
class DoubleList{
    public:
        T data;
        DoubleList<T>* next;
        DoubleList<T>* prev;
};

//Creating a node function
template <typename T>
DoubleList<T>* createNode(T newData){
    //dynamic memory allocation for a new node
    DoubleList<T>* newNode = new DoubleList<T>;

    newNode->data = newData;

    //point it to the previous and next node
    newNode->prev = nullptr;
    newNode->next = nullptr;

    return newNode;
}

template<typename T>
void dllTraverse(DoubleList<T>* currentNode){
    //Check if the list is empty
    if(currentNode == nullptr){
        std::cout << "The list is Empty";
        return;
    }

    DoubleList<T>* tail = nullptr;

    //Forward traverse
    while(currentNode != nullptr){
        std::cout << currentNode->data << " ";
        tail = currentNode;
        currentNode = currentNode->next;
    }
    std::cout << std::endl;

    //Reverse Traverse
    std::cout << "\nREVERSE" << std::endl;
    while(tail != nullptr){
        std::cout << tail->data << " ";
        tail = tail->prev;
    }
    std::cout << std::endl;
}

// Inserting a node to the head
template <typename T>
void dllInsertHead(T newData, DoubleList<T>** currentNode){

    //Create a new node
    DoubleList<T>* newNode = createNode(newData);

    //Check if the list is empty
    if(*currentNode == nullptr){
        *currentNode = newNode;
        return;
    }

    //Point the newNode to the currentNode (head)
    newNode->next = *currentNode;

    //Point the currentNode(head) back to the newNode
    (*currentNode)->prev = newNode;

    //Update the head pointer
    *currentNode = newNode;
}

//Inserting at the End
template <typename T>
void dllInsertEnd(T newData, DoubleList<T>* currenthead){

    //Create a new node
    DoubleList<T>* newNode = createNode(newData);

    //Check if the list is empty
    if(currenthead == nullptr){
        return;
    }

    //Traverse until we reach the last node
    while(currenthead->next != nullptr){
        currenthead = currenthead->next;
    }

    //Connect the new node back to the last node
    newNode->prev = currenthead;

    //Connect the last node to the new node
    currenthead->next = newNode;
}

//General Insert (Insertion at any part of the list)
template <typename T>
void dllGeneralInsert(T newData, DoubleList<T>* previousNode){

    //Check if it is the head node (previous node is null)
    if(previousNode == nullptr){
        //If null, print "Previous node cannot be null."
        std::cout << "Previous node cannot be null." << std::endl;
        return;
    }

    //Allocate a new node
    DoubleList<T>* newNode = createNode(newData);

    //Store data in the new node
    newNode->data = newData;

    //Point new node to the node previous node was pointing to
    newNode->next = previousNode->next;
    newNode->prev = previousNode;

    //If there is a node after previousNode,
    //connect it back to the new node
    if(previousNode->next != nullptr){
        previousNode->next->prev = newNode;
    }

    //Point previous node to the new node
    previousNode->next = newNode;
}

//Deletion of a node
template <typename T>
void dllDeleteNode(DoubleList<T>** head, DoubleList<T>* deleteNode){

    //Check if the list or node is empty
    if(*head == nullptr || deleteNode == nullptr){
        return;
    }

    //If deleting the head node
    if(*head == deleteNode){
        *head = deleteNode->next;
    }

    //Find previous node of the node to be deleted.
    if(deleteNode->prev != nullptr){
        //Change the next of previous node.
        deleteNode->prev->next = deleteNode->next;
    }

    //Update the previous pointer of the next node
    if(deleteNode->next != nullptr){
        deleteNode->next->prev = deleteNode->prev;
    }

    //Free memory for the node to be deleted.
    delete deleteNode;
}

#endif