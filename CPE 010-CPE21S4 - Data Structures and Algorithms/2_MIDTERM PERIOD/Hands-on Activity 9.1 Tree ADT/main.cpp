#include <iostream>
#include "BST.h"

int main() {
    //create the root node:
    BinarySearchTree<char> tree('g');
    
    //  [g,C,L,a,E,i,N,d,J]
    tree.insert('g');
    tree.insert('C');
    tree.insert('L');
    tree.insert('a');
    tree.insert('E');
    tree.insert('i');
    tree.insert('N');
    tree.insert('d');
    tree.insert('J');

    std::cout<<"preOrder: ";
    tree.preOrder();
    std::cout<<std::endl;

    std::cout<<"inOrder: ";
    tree.inOrder();
    std::cout<<std::endl;

    std::cout<<"postOrder: ";
    tree.postOrder();
    std::cout<<std::endl;

    return 0;
}

