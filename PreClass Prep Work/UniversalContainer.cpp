#include <iostream>
#include <string>

template <typename T>
class Storage{
    T data;

    public:
    void setData(T initialValue){
        data = initialValue;
    }

    T retrieve() {
        return data;
    }
};


int main(){

    Storage<int> numStore;
    Storage<std::string> stringStore;
    numStore.setData(100);
    stringStore.setData("My Secret");

    std::cout << numStore.retrieve() << std::endl;
    std::cout << stringStore.retrieve() << std::endl;
    
    return 0;
}