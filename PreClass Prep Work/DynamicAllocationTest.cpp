#include <iostream>

int main(){
    int size;
    std::cout << "How many soilders do you want?";
    std::cin >> size;

    int* students = new int[size];
    for(int i = 0;i < size;i++){
        students[i] = 100;
    }
    std::cout << "Army of " << size << " created!" << std::endl;
    delete[] students;
    return 0;
}