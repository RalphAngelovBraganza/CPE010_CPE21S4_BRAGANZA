#include <iostream>
#include "singly_ll.h"

int main(){
    
    //create nodes:
    SinglyList<char>* head = nullptr;
    SinglyList<char>* second = nullptr;
    SinglyList<char>* third = nullptr;
    SinglyList<char>* fourth = nullptr;

    //allocate memory to the head
    head = new SinglyList<char>;
    second = new SinglyList<char>;
    third = new SinglyList<char>;
    fourth = new SinglyList<char>;

    //added the data to the node
    head->data = 'R';
    second->data = 'A';
    third->data = 'P';
    fourth->data = 'H';

    //assign the next to the node
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = nullptr;

    std::cout << "Testing the ListTraversal Fucntion: \n";
    ListTraversal(head);

    std::cout << "Testing the Insert at Head Fucntion: \n";
    sllInsertHead('I', &head);
    ListTraversal(head);

    std::cout << "Testing the Insert any location Function: \n";
    sllGeneralInsert('X', head->next->next);
    ListTraversal(head);

    std::cout << "Testing the Insert at end Function: \n";
    sllInsertEnd('U', &head);
    ListTraversal(head);

    std::cout << "Testing the delete a nodeFunction: \n";
    sllDeleteNode('X', &head);
    ListTraversal(head);
    sllDeleteNode('Q', &head);
    ListTraversal(head);
    sllDeleteNode('U', &head);
    ListTraversal(head);

    std::cout<<"Deleteing the whole list: \n";
    sllDeleteList(&head);
    ListTraversal(head);

    return 0;
}
