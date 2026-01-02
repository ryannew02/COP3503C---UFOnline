#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Fighter{
    public:
    string name;
    int health;
    int attack;
    int critical;
    int abilityRemaining;

    Fighter(string n, int h, int a, int c){
        name = n;
        health = h;
        attack = a;
        critical = c;
        abilityRemaining = 1;
    }

    void displayStats(){
        cout << "Name: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Attack: " << attack << endl;
        cout << "Critical: " << critical << endl;
        cout << name << " ability uses remaining: " << abilityRemaining << endl;
    }

    virtual ~Fighter(){

    }

    virtual void useAbility() = 0;
};

class Rogue : public Fighter{
    public:

    Rogue(string n, int h, int a, int c) : Fighter(n, h, a, c) {
        critical *= 2;
    }

    void useAbility(){
        critical *= 2;
        attack *= 2;
    }
};

class Mage : public Fighter{
    public:

    Mage(string n, int h, int a, int c) : Fighter(n, h, a, c) {
        attack *= 2;
    }

    void useAbility(){
        attack *= 3;
    }
};

class Knight : public Fighter{
    public:

    Knight(string n, int h, int a, int c) : Fighter(n, h, a, c) {
        health *= 2;
    }

    void useAbility(){
        health /= 2;
        attack *= 2;
    }
};

template <typename T>
struct FighterNode {
    T unit;
    FighterNode<T>* next;

    FighterNode(T value){
        unit = value;
        next = nullptr;
    }
};

template <typename T>
class LinkedList {
    public:
    FighterNode<T>* head;
    int roster_size;

    LinkedList() {
        head = nullptr;
        roster_size = 0;
    }

    void append(T unit) {
        roster_size++;
        FighterNode<T>* newFighterNode = new FighterNode<T>(unit);
        if(head == nullptr) {
            head = newFighterNode;
        }
        else {
            FighterNode<T>* temp = head;

            while(temp->next != nullptr) {
                temp = temp -> next; 
            }

            temp -> next = newFighterNode;
        }
    }
    void deleteFighter(T unit) {
        FighterNode<T>* firstFighterNode;
        FighterNode<T>* secondFighterNode;
        if(head != nullptr && head->unit == unit){
            secondFighterNode = head;
            head = head->next;
            delete secondFighterNode->unit;
            delete secondFighterNode;
            roster_size--;
            return;
        }
        secondFighterNode = head;
        while(secondFighterNode->unit != unit){
            if(secondFighterNode->next != nullptr){
            firstFighterNode = secondFighterNode;
            secondFighterNode = secondFighterNode->next;
            }
            else{
                return;
            }
        }
        firstFighterNode->next = secondFighterNode->next;
        delete secondFighterNode->unit;
        delete secondFighterNode;
        roster_size--;

    }
    void displayStats() {
        FighterNode<T>* temp = head;
        while(temp != nullptr){
            cout << "Class: " << temp -> unit -> name << endl;
            cout << "Health: " << temp -> unit -> health << endl;
            cout << "Attack: " << temp -> unit -> attack << endl;
            cout << "Critical: " << temp -> unit -> critical << endl;
            cout << "Ability uses Remaining: " << temp -> unit -> abilityRemaining << endl << endl;
            temp = temp -> next;
        }
    }
    
    T selectFighter(string name){
        FighterNode<T>* temp = head;
        while(temp != nullptr){
            if(name == temp->unit->name){
                return temp->unit;
            }
            temp = temp -> next;
        }
        return nullptr;
    }
    void loadRoster(string filename){
        ifstream inputFile(filename);
        if (!inputFile.is_open()){
            cout << "Error: Could not load roster" << filename << endl;
            return;
        }
        string name;
        int h, a, c;
        Fighter* newUnit;
        while(inputFile >> name >> h >> a >> c){
            newUnit = nullptr;
            if(name == "Rogue"){
                newUnit = new Rogue(name, h, a, c);
                cout << name << " loaded successfully from file " << filename << endl;
            }
            else if(name == "Knight"){
                newUnit = new Knight(name, h, a, c);
                cout << name << " loaded successfully from file " << filename << endl;
            }
            else if(name == "Mage"){
                newUnit = new Mage(name, h, a, c);
                cout << name << " loaded successfully from file " << filename << endl;
            }
            if(newUnit != nullptr){
                append(newUnit);
            }
        }
        inputFile.close();
        if(head != nullptr){
        cout << "Roster loaded from " << filename << " successfully!" << endl;
        return;
        }
        else{
            cout << "No units exist in roster file " << filename << endl;
            return;
        }
    }

    void saveRoster(){
        ofstream outputFile("thirdroster.txt");
        FighterNode<T>* temp;
        string name;
        int h, a, c;
        temp = head;
        while(temp != nullptr){
            name = temp->unit->name;
            h = temp->unit->health;
            a = temp->unit->attack;
            c = temp->unit->critical;
            outputFile << name << " " << h << " " << a << " " << c << endl;
            temp = temp->next;
        }
        outputFile.close();
    }

    ~LinkedList(){
        FighterNode<T>* current = head;
        while(current != nullptr) {
            FighterNode<T>* temp = current;
            current = temp -> next;
            delete temp -> unit;
            delete temp;
        }        
    }
};

int main(){
  string name;
  name = "secondroster.txt";
  LinkedList<Fighter*>* fighterRoster = new LinkedList<Fighter*>;
  fighterRoster->loadRoster(name);
  fighterRoster->saveRoster();
  return 0;
}