#include <iostream>
#include "queueLL.h"
#include <queue>

int main() {
    qNode<int>* front = nullptr;
    qNode<int>* back = nullptr;

    std::cout << "Enqueueing:" << std::endl;
    enqueue(1, &front, &back);
    std::cout << "front: " << front->data << " back: " << back->data << std::endl; 

    enqueue(2, &front, &back);
    enqueue(3, &front, &back);
    std::cout << "front: " << front->data << " back: " << back->data << std::endl; 
    
    std::cout << "Queue:" << std::endl;
    display(front);
    std::cout << std::endl;
    std::cout << "Dequeueing:" << std::endl;
    dequeue(&front, &back);
    std::cout << "front: " << front->data << " back: " << back->data << std::endl; 

    dequeue(&front, &back);
    std::cout << "front: " << front->data << " back: " << back->data << std::endl; 

    dequeue(&front, &back);
    dequeue(&front, &back); // Queue is empty

    return 0;
}
