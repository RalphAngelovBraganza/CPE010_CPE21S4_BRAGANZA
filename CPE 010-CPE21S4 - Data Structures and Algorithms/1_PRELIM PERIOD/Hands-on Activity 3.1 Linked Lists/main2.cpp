#include <iostream>
#include <utility>
#include "singly_ll.h"

int main() {
    // Step 1: Declare pointers
    SinglyList<char> *head = nullptr;
    SinglyList<char> *second = nullptr;
    SinglyList<char> *third = nullptr;
    SinglyList<char> *fourth = nullptr;
    SinglyList<char> *fifth = nullptr;
    SinglyList<char> *last = nullptr;

    // Step 2: Allocate memory for nodes
    head = new SinglyList<char>;
    second = new SinglyList<char>;
    third = new SinglyList<char>;
    fourth = new SinglyList<char>;
    fifth = new SinglyList<char>;
    last = new SinglyList<char>;

    // Step 3: Assign data and link nodes
    head->data = 'C';
    head->next = second;

    second->data = 'P';
    second->next = third;

    third->data = 'E';
    third->next = fourth;

    fourth->data = '0';
    fourth->next = fifth;

    fifth->data = '1';
    fifth->next = last;

    // Step 4: Assign data to the last node and terminate the list
    last->data = '0';
    last->next = nullptr;

    std::cout << "Original List:" << std::endl;
    ListTraversal(head);

    // Insert 'G' at the head of the list
    sllInsertHead('G', &head);
    // Insert 'E' after the node containing 'P'
    sllGeneralInsert('E', third);
    // Delete the node containing 'C'
    sllDeleteNode('C', &head);
    // Delete the node containing 'P'
    sllDeleteNode('P', &head);

    std::cout << "New List:" << std::endl;
    ListTraversal(head);




    // Optional: Clean up dynamically allocated memory
    delete head;
    delete second;
    delete third;
    delete fourth;
    delete fifth;
    delete last;

    return 0;
}
