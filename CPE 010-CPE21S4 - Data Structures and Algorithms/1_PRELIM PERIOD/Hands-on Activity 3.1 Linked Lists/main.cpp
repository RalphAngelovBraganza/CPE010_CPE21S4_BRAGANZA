#include <iostream>
#include "double_ll.h"

int main(){
    //create a list 'C P E'
    DoubleList<char>* head = createNode('C');
    DoubleList<char>* second = createNode('P');
    DoubleList<char>* third = createNode('E');

    // Connecting the nodes:

    //Connect the head node to the next node:
    head->next = second;
    second->prev = head;

    //Connect the second node to the third node:
    second->next = third;
    third->prev = second;

    //Traversal
    std::cout << "Testing the dllTraverse List" << std::endl;
    dllTraverse(head);

    //Insert at the head
    std::cout << "Testing the dllInsertHead" << std::endl;
    dllInsertHead('X', &head);
    dllTraverse(head);

    //Insert at the end
    std::cout << "Testing the dllInsertEnd" << std::endl;
    dllInsertEnd('0', head);
    dllTraverse(head);

    //General insert
    std::cout << "Testing the dllGeneralInsert" << std::endl;
    dllGeneralInsert('Y', second);
    dllTraverse(head);

    //Delete a node
    std::cout << "Testing the dllDeleteNode" << std::endl;
    dllDeleteNode(&head, second);
    dllTraverse(head);

    return 0;
}