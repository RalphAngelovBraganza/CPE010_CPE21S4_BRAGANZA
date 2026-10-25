#include <iostream> 
#include <cstdlib> 
#include <time.h> 
#include "searchingAlgo.h" 
 
const int max_size = 50; 
 
int main() { 
 
 
// Linear Search Array 
 
    int dataset[max_size]; 
    srand(time(0)); 
    for(int i = 0; i < max_size; i++){ 
        dataset[i]=rand(); 
        std::cout << dataset[i] << " "; 
    } 
    std::cout << std::endl; 
 
    int choice; 
    std::cout << "Indicate the number to search: "; 
    std::cin >> choice; 
 
    linearSearchArr(max_size, choice, dataset); 
 
 
 
// Linear Search Linked List 
 
    Node<char>* name1 = new_node('R'); 
    Node<char>* name2 = new_node('A'); 
    Node<char>* name3 = new_node('L'); 
    Node<char>* name4 = new_node('P'); 
    Node<char>* name5 = new_node('H'); 
 
    name1->next = name2; 
    name2->next = name3; 
    name3->next = name4; 
    name4->next = name5; 
 
    linearSearchLL(name1, 'R'); 
    linearSearchLL(name2, 'D'); //not in the search list 
 
 
 
// Binary Search Array 
 
    int dataset2[max_size]; 
    for(int i = 0; i < max_size; i++){ 
        dataset2[i] = i; 
        std::cout << dataset2[i] << " "; 
    } 
 
    binarySearchArr(11, dataset2, max_size); 
    binarySearchArr(11111, dataset2, max_size); 
     
 
// Binary Search Linked List 
 
    Node<char>* name6 = new_node('A'); 
    Node<char>* name7 = new_node('B'); 
    Node<char>* name8 = new_node('C'); 
    Node<char>* name9 = new_node('D'); 
    Node<char>* name10 = new_node('E'); 
 
    name6->next = name7; 
    name7->next = name8; 
    name8->next = name9; 
    name9->next = name10; 
 
    binarySearchLL(name6, 'P'); 
    binarySearchLL(name6, 'C'); 


// ILOB PROBLEM 1
    std::cout << "\n| Problem 1 |\n";

    int data1[] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};

    int arrayCount = linearSearchComparison(10, 18, data1);
    std::cout << "Array comparisons for 18: " << arrayCount << std::endl;

    Node<int>* node1 = new_node(15);
    Node<int>* node2 = new_node(18);
    Node<int>* node3 = new_node(2);
    Node<int>* node4 = new_node(19);
    Node<int>* node5 = new_node(18);
    Node<int>* node6 = new_node(0);
    Node<int>* node7 = new_node(8);
    Node<int>* node8 = new_node(14);
    Node<int>* node9 = new_node(19);
    Node<int>* node10 = new_node(14);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;

    int listCount = linearSearchLLComparison(node1, 18);
    std::cout << "Linked list comparisons for 18: " << listCount << std::endl;


// ILOB PROBLEM 2

    std::cout << "\n| Problem 2 |\n";

    int total18 = linearSearchCount(10, 18, data1);

    std::cout << "Number of 18s: "<< total18 << std::endl;


// ILOB PROBLEM 3

    std::cout << "\n| Problem 3 |\n";

    int data3[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};

    binarySearchSteps(data3, 0, 9, 8);


// ILOB PROBLEM 4

    std::cout << "\n| Problem 4 |\n";

    int data4[] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};

    int searchResult = biSearchRec(data4, 0, 9, 8);

    if(searchResult != -1){
        std::cout << "The data was found at index "<< searchResult << ".\n";
    }
    else {
        std::cout << "Search element was not found.\n";
    }

    
    return 0; 
 
}