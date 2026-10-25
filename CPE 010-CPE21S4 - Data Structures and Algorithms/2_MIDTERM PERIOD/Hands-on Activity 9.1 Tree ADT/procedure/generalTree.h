#ifndef GENERALTREE_H
#define GENERALTREE_H

#include <iostream>

template<typename T>
class GeneralTree{

    private:
    T key;
    //Linked list for storing the children
    struct ChildNode{
        GeneralTree<T>* child;
        ChildNode* next;
        ChildNode(GeneralTree<T>* newChild){
            child = newChild;
            next = nullptr;
        }
    };
    ChildNode* firstChild;
    //Search functions
    bool preOrderSearch(T search);
    bool inOrderSearch(T search);
    bool postOrderSearch(T search);

    public:
    //constructor
    GeneralTree(T value);
    //insertion
    void insertChild(T value);
    //get positions
    T getRootVal();
    GeneralTree<T>* getChild(int position);
    //traversal
    void preOrder();
    void postOrder();
    void inOrder();
    //search
    void findData(int choice, T search);
};

//constructor
template <typename T>
GeneralTree<T>::GeneralTree(T value){
    key = value;
    firstChild = nullptr;
}

//insert a child at the end of the linked list
template <typename T>
void GeneralTree<T>::insertChild(T value){
    GeneralTree<T>* newChild = new GeneralTree<T>(value);
    ChildNode* newNode = new ChildNode(newChild);
    //if there are no children yet
    if(firstChild == nullptr){
        firstChild = newNode;
    }
    //if there are already children
    else{
        ChildNode* current = firstChild;
        while(current->next != nullptr){
            current = current->next;
        }
        current->next = newNode;
    }
}

//get the value of the current node
template <typename T>
T GeneralTree<T>::getRootVal(){
    return key;
}

//get a child based on its position
//position starts at 0
template <typename T>
GeneralTree<T>* GeneralTree<T>::getChild(int position){
    ChildNode* current = firstChild;
    int count = 0;

    while(current != nullptr){
        if(count == position){
            return current->child;
        }
        current = current->next;
        count++;
    }
    return nullptr;
}

//preorder traversal
template <typename T>
void GeneralTree<T>::preOrder(){
    //print root first
    std::cout << key << " ";
    //then visit the children from left to right
    ChildNode* current = firstChild;
    while(current != nullptr){
        current->child->preOrder();
        current = current->next;
    }
}

//postorder traversal
template <typename T>
void GeneralTree<T>::postOrder(){
    //visit the children first
    ChildNode* current = firstChild;
    while(current != nullptr){
        current->child->postOrder();
        current = current->next;
    }
    //print root last
    std::cout << key << " ";
}

//inorder traversal
//Convention: first child, root, then remaining children
template <typename T>
void GeneralTree<T>::inOrder(){
    ChildNode* current = firstChild;
    //visit the first child's subtree
    if(current != nullptr){
        current->child->inOrder();
        current = current->next;
    }
    //print the current node
    std::cout << key << " ";
    //visit the remaining children
    while(current != nullptr){
        current->child->inOrder();
        current = current->next;
    }
}

//preorder search
template <typename T>
bool GeneralTree<T>::preOrderSearch(T search){
    //check the current node first
    if(key == search){
        return true;
    }
    //then search the children
    ChildNode* current = firstChild;
    while(current != nullptr){
        if(current->child->preOrderSearch(search)){
            return true;
        }
        current = current->next;
    }
    return false;
}

//inorder search
template <typename T>
bool GeneralTree<T>::inOrderSearch(T search){
    ChildNode* current = firstChild;
    //search the first child's subtree
    if(current != nullptr){
        if(current->child->inOrderSearch(search)){
            return true;
        }
        current = current->next;
    }
    //check the current node
    if(key == search){
        return true;
    }
    //search the remaining children
    while(current != nullptr){
        if(current->child->inOrderSearch(search)){
            return true;
        }
        current = current->next;
    }
    return false;
}

//postorder search
template <typename T>
bool GeneralTree<T>::postOrderSearch(T search){
    //search the children first
    ChildNode* current = firstChild;
    while(current != nullptr){
        if(current->child->postOrderSearch(search)){
            return true;
        }
        current = current->next;
    }
    //check the current node last
    if(key == search){
        return true;
    }
    return false;
}

//search based on the selected traversal
template <typename T>
void GeneralTree<T>::findData(int choice, T search){
    bool found = false;
    switch(choice){
        case 1:
            found = preOrderSearch(search);
            break;
        case 2:
            found = inOrderSearch(search);
            break;
        case 3:
            found = postOrderSearch(search);
            break;
        default:
            std::cout << "Invalid Choice!" << std::endl;
            return;
    }

    //display a message only if the value was found
    if(found){
        std::cout << search << " was found!" << std::endl;
    }
}

#endif

