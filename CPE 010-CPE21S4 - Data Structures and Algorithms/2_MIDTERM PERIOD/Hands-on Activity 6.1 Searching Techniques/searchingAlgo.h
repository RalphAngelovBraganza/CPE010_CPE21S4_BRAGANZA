#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

/* 
    LINEAR SEARCH ALGORITHM
    N -> Boundary of the list
    Item -> Searching number
    Data -> Linear array
    Step 1: I:= 0
    Step 2: Repeat while I <= n
    Exit
    Else print "searching is unsuccessful"
    Exit
*/

template <typename T>
class Node {
    public:
        T data;
        Node *next;
};

template <typename T>
Node<T> *new_node(T newData){ 
    Node<T> *newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}


// Linear Search Array 
template <typename T>
void linearSearchArr(int maxSize, T dataFind, T data[]){
    int i = 0;
    while(i <= maxSize){
        if(dataFind == data[i]){
            std::cout << "Searching is successful\n";
            return;
        }
        i++;
    }
    std::cout << "the search is unsuccessful\n";

}


// Linear Search Linked List

template <typename T>
void linearSearchLL(Node<T> *node, T dataFind) {
    while(node != nullptr){

        if(node->data == dataFind){
            std::cout << "the search was successful.\n";
            return;
        }
        node = node->next;
    }
    std::cout << "the search was unsuccessful\n";
}


// Binary Search Array

template <typename T>
void binarySearchArr(T dataFind, T data[], int maxSize){
    int low = 0, up = maxSize-1, middle;
    while(low <= up){
        middle = (int)((low+up)/2);
        if(dataFind == data[middle]){
            std::cout << "\nSearching is successful\n";
            return;
        }
        else if(dataFind > data[middle]){
            low = middle + 1;
        }else {
            up = middle - 1;
        }
    }
    std::cout << "Search element was not found.\n";
}

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){

    Node<T>* slow = start;
    Node<T>* fast = start;

    while(fast != last && fast->next != last){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


// Binary Search Linked List

template <typename T>
void binarySearchLL(Node<T>* start, T dataFind){
    
    Node<T>* last = nullptr;

    while (start != last) {
        Node<T>* middle = getMiddle(start, last);

        if(middle->data == dataFind){
            std::cout << "The data was found.\n";
            return;
        }
        else if(middle->data > dataFind){
            last = middle;
        }
        else {
            start = middle->next;
        }
    }
    std::cout << "Search element was not found.\n";
}


// ILOB Problem 1: Count the number of comparisons 

template <typename T>
int linearSearchComparison(int maxSize, T dataFind, T data[]){
    int i = 0;
    int comparisons = 0;
    while(i < maxSize){
        comparisons++;
        if(dataFind == data[i]){
            return comparisons;
        }
        i++;
    }
    return comparisons;
}


template <typename T>
int linearSearchLLComparison(Node<T> *node, T dataFind){
    int comparisons = 0;
    while(node != nullptr){
        comparisons++;
        if(node->data == dataFind){
            return comparisons;
        }
        node = node->next;
    }
    return comparisons;
}



// ILOB Problem 2: Count repeating instances of the search key
template <typename T>
int linearSearchCount(int maxSize, T dataFind, T data[]){
    int i = 0;
    int count = 0;
    while(i < maxSize){
        if(data[i] == dataFind){
            count++;
        }
        i++;
    }
    return count;
}


// ILOB Problem 3: Show each step of Binary Search
template <typename T>
void binarySearchSteps(T data[], int low, int up, T dataFind){
    int middle;
    int step = 1;

    while(low <= up){
        middle = (int)((low + up) / 2);

        std::cout << "Step " << step << ": ";
        std::cout << "Low = " << low;
        std::cout << ", Middle = " << middle;
        std::cout << ", Up = " << up;
        std::cout << ", Value = " << data[middle] << std::endl;

        if(dataFind == data[middle]){
            std::cout << "Key " << dataFind << " was found at index " << middle << ".\n";
            return;
        }
        else if(dataFind > data[middle]){
            low = middle + 1;
        }
        else {
            up = middle - 1;
        }

        step++;
    }

    std::cout << "Search element was not found.\n";
}


// ILOB Problem 4: Recursive Binary Search
template <typename T>
int biSearchRec(T data[], int low, int up, T dataFind){
    if(low > up){
        return -1;
    }
    int middle = (int)((low + up) / 2);
    if(dataFind == data[middle]){
        return middle;
    }
    else if(dataFind > data[middle]){
        return biSearchRec(data, middle + 1, up, dataFind);
    }
    else {
        return biSearchRec(data,low,middle - 1,dataFind);
    }
}


#endif