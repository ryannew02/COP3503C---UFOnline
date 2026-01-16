#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;


int main(){

    vector<int>  userInts;
    vector<string> userStrings;
    vector<string> userInputs;
    string userString1;
    string userString2;
    string userInput;
    int userInt;
    string tableHeader;
    string tableColumn1;
    string tableColumn2;

    cout << "Enter a title for the data:" << endl;
    getline(cin, tableHeader);
    cout << "You entered: " << tableHeader << endl;

    cout << "Enter the column 1 header:" << endl;
    getline(cin, tableColumn1);
    cout << "You entered: " << tableColumn1 << endl;

    cout << "Enter the column 2 header:" << endl;
    getline(cin, tableColumn2);
    cout << "You entered: " << tableColumn2 << endl;

    //Enter data loop
    while(true){
        cout << "Enter a data point (-1 to stop input):" << endl;
        getline(cin, userInput);
        stringstream ssUserInput(userInput);
        if(userInput == "-1"){
            break;
        }
        while(getline(ssUserInput, userString1, ',')){
            userInputs.push_back(userString1);
        }
        if(userInputs.size() <2){
            cout << "Error: No comma in string." << endl;
            userInputs.clear();
            continue;
        }
        else if(userInputs.size() > 2){
            cout << "Error: Too many commas in input." << endl;
            userInputs.clear();
            continue;
        }
        else{
            try{
                userInt = stoi(userInputs[1]);
                userStrings.push_back(userInputs[0]);
                cout << "Data string: " << userInputs[0] << endl;
                userInts.push_back(userInt);
                cout << "Data integer: " << userInt << endl;
                userInputs.clear();
                continue;
            }
            catch(...){
                cout << "Error: Comma not followed by an integer." << endl;
                userInputs.clear();
                continue;
            }
        }
    }
    //Print Table
    cout << endl << right << setw(33) << tableHeader << endl;
    cout << left << setw(20) << tableColumn1;
    cout << "|";
    cout <<  right << setw(23) << tableColumn2 << endl;
    cout << "--------------------------------------------" << endl;
    for(unsigned int i = 0; i < userStrings.size(); i++){
        cout << left << setw(20) << userStrings[i];
        cout << "|";
        cout <<  right << setw(23) << userInts[i] << endl;
        }

    //Print Histogram
    for(unsigned int i = 0; i < userStrings.size(); i++){
        cout << endl << right << setw(20) << userStrings[i];
        cout << " ";
        for(int j = 0; j < userInts[i]; j++){
            cout << "*";
        }
        }
        cout << endl;
    return 0;
}