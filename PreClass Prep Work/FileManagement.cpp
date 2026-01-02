#include <iostream>
#include <string>
#include <fstream>
using namespace std;


void loadRoster(string filename){
    ifstream inputFile(filename);

    if (!inputFile.is_open()){
        cout << "Error: Could not open file " << filename << endl;
        return;
    }
    string name;
    int h, a, c;
    while(inputFile >> name >> h >> a >> c){
        cout << name << h << a << c << endl;
    }
    inputFile.close();
    }

int main(){
    string name;
    name = "roster.txt";
    loadRoster(name);
    return 0;
}