#include <iostream>
#include <string>


template <typename T>

T getSum(T num1, T num2){
    return num1 + num2;
}


int main(){

    std::cout << getSum(1,2) << std::endl;
    std::cout << getSum(1.1,1.2) << std::endl;
    std::string text[2];
    text[0] = "Hello";
    text[1] = "World";
    std::cout << getSum(text[0], text[1]) << std::endl;
    return 0;
}