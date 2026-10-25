#include<iostream>

//Create a function that will take two numbers and display the sum
int sumOfTwoNum(int fNum, int sNum);

//Create a function that will return whether variable A is greater than variable B
int isGreater(int varA, int varB);

//Create a function that will take two Boolean values and display the result of all logical operations then return true if it was a success.
bool logicOps(bool xVal, bool yVal);

int main(){

    std::cout << "The sum of two numbers is: "<< sumOfTwoNum(6,7) << std::endl;

    if(isGreater(6,9) == 1){
        std::cout << "\nvariable A is greater than variable B" << std::endl;
    }else{
        std::cout << "\nvariable A is not greater than variable B" << std::endl;
    }

    if(logicOps(true,true)){
        std::cout << "\nSuccess!" << std::endl;
    }

    return 0;
}

int sumOfTwoNum(int fNum, int sNum){
    int sum = fNum + sNum;
    return sum;
}

int isGreater(int varA, int varB){
    int answer = varA > varB;
    if(answer == 1){
        return 1;
    }else{
        return 0;
    }
}

bool logicOps(bool xVal, bool yVal){
    std::cout << "\nLogical Operations:" << std::endl;
    std::cout << "xVal AND yVal = " << (xVal && yVal) << std::endl;
    std::cout << "xVal OR yVal = " << (xVal || yVal) << std::endl;
    std::cout << "NOT xVal = " << (!xVal) << std::endl;
    std::cout << "NOT yVal = " << (!yVal) << std::endl;
    std::cout << "xVal XOR yVal = " << (xVal != yVal) << std::endl;

    return true;
}
