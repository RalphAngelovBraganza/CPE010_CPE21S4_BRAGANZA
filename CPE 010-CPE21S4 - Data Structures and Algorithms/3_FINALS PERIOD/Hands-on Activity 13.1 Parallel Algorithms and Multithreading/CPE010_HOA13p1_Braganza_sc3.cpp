#include <iostream>
#include <vector>
#include <thread>

int globalSum = 69;

void add(int add){
    globalSum += add;
    std::cout<<globalSum<<std::endl;
}

int main(){

    std::thread T1(add, 21);
    std::thread T2(add, 14);
    std::thread T3(add, 67);

    std::cout<<globalSum<<std::endl;
    T1.join();
    std::cout<<globalSum<<std::endl;
    T2.join();
    std::cout<<globalSum<<std::endl;
    T3.join();
    std::cout<<globalSum<<std::endl;

return 0;

}
