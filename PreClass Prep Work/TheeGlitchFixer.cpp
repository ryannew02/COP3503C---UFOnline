#include <iostream>
#include <string>



int fixGlitch(int* array,int size){
        int i = 0;
        while(i < size){
            if(*(array + i) % 2 == 0){
                *(array + i) = *(array + i) * 2; 
            }
            else{
                *(array + i) += 1;
            }
            i++;
        }
        for(int i = 0;i < size;i++){
            std::cout << *(array + i) << std::endl; 
        }
        return 0;
    }



int main(){
    std::cout << "Hello, World! System booting..." << std::endl;
    std::string user_name;
    user_name = "Agent Smith";
    std::cout << "Good morning, " << user_name << std::endl;
    int raw_numbers[5] = {5, 12, 7, 20, 3};
    fixGlitch(raw_numbers, 5);
}