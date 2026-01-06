#include "LinkedList.h"

    FighterNode::FighterNode(Fighter* value){
        unit = value;
        next = nullptr;
    }

    LinkedList::LinkedList(bool affiliation) {
        head = nullptr;
        roster_size = 0;
        is_ally = affiliation;
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
            cout << endl << "Class: " << temp -> unit -> name << endl;
            cout << "Health: " << temp -> unit -> health << endl;
            cout << "Attack: " << temp -> unit -> attack << endl;
            cout << "Critical: " << temp -> unit -> critical << endl;
            cout << "Ability uses Remaining: " << temp -> unit -> abilityRemaining << endl;
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
        string name;
        int h, a, c;
        Fighter* newUnit;
        if(is_ally){
        //Load ally roster...
        ifstream fighterFile(filename);
        if (!fighterFile.is_open()){
            cout << "No save found...backing up from default template " << filename << endl;
            Fighter* newUnit;
            newUnit = new Rogue("Rogue", 10, 10, 10);
            append(newUnit);
            newUnit = new Knight("Knight", 10, 10, 10);
            append(newUnit);
            newUnit = new Mage("Mage", 10, 10, 10);
            append(newUnit);
        }
        else{
            while(fighterFile >> name >> h >> a >> c){
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
        fighterFile.close();
        if(head != nullptr){
        cout << "Roster loaded from " << filename << " successfully!" << endl;
        }
        }
        }
        else{   
        //Load enemy roster...
        ifstream enemyFile(filename);
        if (!enemyFile.is_open()){
            cout << "No save found...backing up from default template " << filename << endl;
            Fighter* newUnit;
            newUnit = new Monster("Monster", 10, 10, 10);
            append(newUnit);
            newUnit = new Monster("Monster", 20, 20, 20);
            append(newUnit);
            newUnit = new Monster("Monster", 30, 30, 30);
            append(newUnit);
        }
        else{
            while(enemyFile >> name >> h >> a >> c){
                newUnit = nullptr;
                if(name == "Monster"){
                    newUnit = new Rogue(name, h, a, c);
                }
                if(newUnit != nullptr){
                    append(newUnit);
                    cout << name << " loaded successfully from file " << filename << endl;
                }
            }
            enemyFile.close();
            if(head != nullptr){
            cout << "Roster loaded from " << filename << " successfully!" << endl;
            }
        }
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

    void LinkedList::loadRosterBinary(string filename){
        ifstream inputFile(filename, ios::binary);

        if(!inputFile.is_open()) {
            cout << "Error opening binary file (or file doesn't exist)!" << endl;
            return;
        }

        int nameLength;
        int h, a, c;

        while(inputFile.read((char*)&nameLength, sizeof(nameLength))) {
            char* nameBuffer = new char[nameLength +1];
            inputFile.read(nameBuffer, nameLength);
            nameBuffer[nameLength] = '\0';
            string name = nameBuffer;
            delete[] nameBuffer;

            inputFile.read((char*)&h, sizeof(int));
            inputFile.read((char*)&a, sizeof(int));
            inputFile.read((char*)&c, sizeof(int));

        Fighter* newUnit = nullptr;
        if(name == "Rogue") newUnit = new Rogue(name, h, a, c);
        else if(name == "Knight") newUnit = new Knight(name, h, a, c);
        else if(name == "Mage") newUnit = new Mage(name, h, a, c);

        if (newUnit != nullptr) {
            append(newUnit);
            cout << "Loaded Binary: " << name << endl;
        }
    }
    inputFile.close();
    }