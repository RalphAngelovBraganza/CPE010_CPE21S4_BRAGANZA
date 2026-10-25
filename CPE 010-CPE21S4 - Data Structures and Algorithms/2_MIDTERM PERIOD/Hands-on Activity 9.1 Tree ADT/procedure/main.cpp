#include <iostream>
#include "generalTree.h"

int main(){

    //Tree structure:
    //level 0
    GeneralTree<char>* root = new GeneralTree<char>('A');

    //level 1
    root->insertChild('B');
    root->insertChild('C');
    root->insertChild('D');
    root->insertChild('E');
    root->insertChild('F');
    root->insertChild('G');

    //level 2
    root->getChild(2)->insertChild('H');

    root->getChild(3)->insertChild('I');
    root->getChild(3)->insertChild('J');

    root->getChild(4)->insertChild('K');
    root->getChild(4)->insertChild('L');
    root->getChild(4)->insertChild('M');

    root->getChild(5)->insertChild('N');

    //level 3
    root->getChild(3)->getChild(1)->insertChild('P');
    root->getChild(3)->getChild(1)->insertChild('Q');

    //traverse the original tree
    std::cout << "Original Tree Traversals:" << std::endl;
    std::cout << "Preorder Order: ";
    root->preOrder();
    std::cout << "\nPostorder Order: ";
    root->postOrder();
    std::cout << "\nInorder Order: ";
    root->inOrder();

    std::cout << std::endl;

    //search the original tree
    std::cout << "\nSearch Results:" << std::endl;
    root->findData(1, 'F');
    root->findData(2, 'B');
    root->findData(3, 'Z'); //No output since Z is not in the tree

    //add O as the second child of G
    root->getChild(5)->insertChild('O');

    //traverse the tree after adding O
    std::cout << "\nTraversals After Adding O:" << std::endl;
    std::cout << "Preorder Order: ";
    root->preOrder();
    std::cout << "\nPostorder Order: ";
    root->postOrder();
    std::cout << "\nInorder Order: ";
    root->inOrder();

    std::cout << std::endl;

    //search for O using the three traversal choices
    std::cout << "\nSearch Results After Adding O:" << std::endl;

    root->findData(1, 'O');  // Pre-order search
    root->findData(2, 'O');  // In-order search
    root->findData(3, 'O');  // Post-order search

    return 0;
}
