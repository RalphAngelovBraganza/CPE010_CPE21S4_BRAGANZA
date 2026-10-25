#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <iostream>


template <typename T>
class BinaryTree{
    private:
        T key;

        //pointers for left and right chld
        BinaryTree<T>* leftChild;
        BinaryTree<T>* rightChild;

    public:
        //constructor
        BinaryTree(T rootObj);
        //insert a child on the left node
        void insertChildLeft(T newNode);
        void insertChildRight(T newNode);

        BinaryTree<T>* getLeftChild();
        BinaryTree<T>* getRightChild();

        T getRootVal();
        void setRootVal(T newNode);
};

//constructor
template <typename T>
BinaryTree<T>::BinaryTree(T rootObj){
    key = rootObj;
    leftChild = nullptr;
    rightChild = nullptr;
};

//insert child
template <typename T>
void BinaryTree<T>::insertChildLeft(T newNode){
    if(leftChild == nullptr){
        leftChild = new BinaryTree<T>(newNode);
    } else {
        BinaryTree<T>* newnode = new BinaryTree<T>(newNode);
        newnode->leftChild = leftChild;
        leftChild = newnode;
    }
}

template<typename T>
void BinaryTree<T>::insertChildRight(T newNode){
    if(rightChild == nullptr){
        rightChild = new BinaryTree<T>(newNode);
    } else{
        BinaryTree<T>* newnode = new BinaryTree<T>(newNode);
        newnode->rightChild = rightChild;
        rightChild = newnode;
    }
}

template <typename T>
BinaryTree<T> *BinaryTree<T>::getLeftChild(){
    return leftChild;
};

template <typename T>
BinaryTree<T> *BinaryTree<T>::getRightChild(){
    return rightChild;
};

template <typename T>
T BinaryTree<T>::getRootVal(){
    return key;
};

template <typename T>
void BinaryTree<T>::setRootVal(T newNode){
    key = newNode;
};


#endif


    