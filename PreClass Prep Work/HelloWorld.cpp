#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Person {
    int age;
    string name;
    bool alive;
    bool born_after_1990;

};
Person people[5]; 
string names[5];
int ages[5];

int main(){
    int y;
    cin >> y;
    cout << boolalpha;
names[0] = "Ryan";
names[1] = "David";
names[2] = "Andrew";
names[3] = "Mitchell";
names[4] = "Kevin";
ages[0] = 28;
ages[1] = 30;
ages[2] = 33;
ages[3] = 35;
ages[4] = 37;
for(int i = 0; i < y && i < 5; i++){
    people[i].name = names[i];
    people[i].age = ages[i];
    people[i].alive = people[i].age < 99;
    if(people[i].age <= 34) {
        people[i].born_after_1990 = 1;
    }
    else{
        people[i].born_after_1990 = 0;
    }
}
int x;
x = y;
while(x > 0){
    --x;
    cout 
    << left << setw(10) << people[x].name << ": " 
    << people[x].age << ": is alive " 
    << people[x].alive << ": is born after 1990 " 
    << people[x].born_after_1990 << endl;
}
}
