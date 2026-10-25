#include <iostream>
#include "binaryTree.h"

int main(){

    BinaryTree<char>* root = new BinaryTree<char>('A');
    root->insertChildLeft('B');
    root->insertChildRight('C');

    root->getLeftChild()->insertChildLeft('D');
    root->getRightChild()->insertChildRight('E');
    root->getRightChild()->getRightChild()->insertChildRight('F');

    std::cout << "The root: " << root->getRootVal() << std::endl;
    std::cout << "The left child of root A is: " << root->getLeftChild()->getRootVal() << std::endl;
    std::cout << "The left child of the left child root A is: " << root->getLeftChild()->getLeftChild()->getRootVal() << std::endl;
    std::cout << "The right child of root A is: " << root->getRightChild()->getRootVal() << std::endl;
    std::cout << "The right child of the right child root A is: " << root->getRightChild()->getRightChild()->getRootVal() << std::endl;
    std::cout << "The right child of E is: " << root->getRightChild()->getRightChild()->getRightChild()->getRootVal() << std::endl;

    root->getRightChild()->setRootVal('V');
    std::cout << "The NEW right child of root A is: " << root->getRightChild()->getRootVal() << std::endl;

    //Test here
    root->getLeftChild()->setRootVal('Y');
    std::cout << "The NEW left child of root A is: " << root->getLeftChild()->getRootVal() << std::endl;

    return 0;
}

