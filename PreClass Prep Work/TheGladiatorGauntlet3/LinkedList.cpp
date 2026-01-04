#include "LinkedList.h"

    FighterNode::FighterNode(Fighter* value){
        unit = value;
        next = nullptr;
    }

    LinkedList::LinkedList() {
        head = nullptr;
        roster_size = 0;
    }

    void LinkedList::append(Fighter* unit) {
        roster_size++;
        FighterNode* newFighterNode = new FighterNode(unit);
        if(head == nullptr) {
            head = newFighterNode;
        }
        else {
            FighterNode* temp = head;

            while(temp->next != nullptr) {
                temp = temp -> next; 
            }

            temp -> next = newFighterNode;
        }
    }

    void LinkedList::deleteFighter(Fighter* unit) {
        FighterNode* firstFighterNode;
        FighterNode* secondFighterNode;
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
    void LinkedList::displayStats() {
        FighterNode* temp = head;
        while(temp != nullptr){
            cout << "Class: " << temp -> unit -> name << endl;
            cout << "Health: " << temp -> unit -> health << endl;
            cout << "Attack: " << temp -> unit -> attack << endl;
            cout << "Critical: " << temp -> unit -> critical << endl;
            cout << "Ability uses Remaining: " << temp -> unit -> abilityRemaining << endl << endl;
            temp = temp -> next;
        }
    }
    
    Fighter* LinkedList::selectFighter(string name){
        FighterNode* temp = head;
        while(temp != nullptr){
            if(name == temp->unit->name){
                return temp->unit;
            }
            temp = temp -> next;
        }
        return nullptr;
    }
    void LinkedList::loadRoster(string filename){
        ifstream inputFile(filename);
        if (!inputFile.is_open()){
            cout << "No save found...backing up from default template." << filename << endl;
            Fighter* newUnit;
            newUnit = new Rogue("Rogue", 10, 10, 10);
            append(newUnit);
            newUnit = new Knight("Knight", 10, 10, 10);
            append(newUnit);
            newUnit = new Mage("Mage", 10, 10, 10);
            append(newUnit);
            return;
        }
        string name;
        int h, a, c;
        Fighter* newUnit;
        while(inputFile >> name >> h >> a >> c){
            newUnit = nullptr;
            if(name == "Rogue"){
                newUnit = new Rogue(name, h, a, c);
            }
            else if(name == "Knight"){
                newUnit = new Knight(name, h, a, c);
            }
            else if(name == "Mage"){
                newUnit = new Mage(name, h, a, c);
            }
            if(newUnit != nullptr){
                append(newUnit);
                cout << name << " loaded successfully from file " << filename << endl;
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

    void LinkedList::saveRoster(string filename){
        ofstream outputFile(filename);
        FighterNode* temp;
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

    LinkedList::~LinkedList(){
        FighterNode* current = head;
        while(current != nullptr) {
            FighterNode* temp = current;
            current = temp -> next;
            delete temp -> unit;
            delete temp;
        }        
    }