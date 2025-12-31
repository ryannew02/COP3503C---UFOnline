#include <iostream>
#include <string>
using namespace std;

class Fighter{
    public:
    string name;
    int health;
    int attack;
    int critical;
    int abilityRemaining;

    Fighter(int h,int a,int c){
        name = "Fighter";
        health = h;
        attack = a;
        critical = c;
    }

    virtual ~Fighter(){

    }

    virtual void useAbility() = 0;

    void display(){
        cout << "Name: " << name << endl << 
        "Health: " << health << endl;
    }

};

class Knight : public Fighter {
    public:

    Knight(int h, int a, int c)
    :Fighter(h, a, c){
        name = "Knight";
        health *= 3;
        attack *= 2;
        critical = 0;
        abilityRemaining = 1;
    }
    
    void useAbility(){
        if(abilityRemaining > 0){
            attack *= 2;
            health /= 2;
            abilityRemaining -= 1;
        }
    }
};

class Sorcerer : public Fighter {
    public:

    Sorcerer(int h, int a, int c)
    :Fighter(h, a, c){
        name = "Sorcerer";
        health *= 1;
        attack *= 3;
        critical *= 1;
        abilityRemaining = 1;
    }

    void useAbility(){
        if(abilityRemaining > 0){
            attack *= 2;
            abilityRemaining -= 1;
        }
    }
};

class Rogue : public Fighter {
    public:

    Rogue(int h, int a, int c)
    :Fighter(h, a, c){
        name = "Rogue";
        health *= 1;
        attack *= 3;
        critical *= 3;
        abilityRemaining = 1;
    }

    void useAbility(){
        if(abilityRemaining > 0){
            critical *= 2;
            abilityRemaining -= 1;
        }
    }
};

class Monster : public Fighter {
    public:

    Monster(int h, int a, int c)
    :Fighter(h, a, c)
    {
        health = h;
        attack = a;
        critical = c;
    }

    void useAbility(){
        health = 0;
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
    Fighter* selectFighter(string name) {
        FighterNode<T>* temp = head;
        while(temp != nullptr){
            if(name == temp->unit->name){
                return temp->unit;
            }
            temp = temp -> next;
        }
        return nullptr;
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
    //create team roster
    LinkedList<Fighter*>* Fighter_Roster = new LinkedList<Fighter*>();
    Fighter* player1 = new Rogue(10,10,10);
    Fighter* player2 = new Sorcerer(10,10,10);
    Fighter* player3 = new Knight(10,10,10);
    Fighter_Roster -> append(player1);
    Fighter_Roster -> append(player2);
    Fighter_Roster -> append(player3);
    //create enemy roster
    LinkedList<Fighter*>* Enemy_Roster = new LinkedList<Fighter*>();
    Fighter* enemy1 = new Monster(10,10,10);
    Fighter* enemy2 = new Monster(20,20,20);
    Fighter* enemy3 = new Monster(30,30,30);
    Enemy_Roster -> append(enemy1);
    Enemy_Roster -> append(enemy2);
    Enemy_Roster -> append(enemy3);
    //initialize control variable
    string active_player_selector;
    string usingAbility;
    active_player_selector = "Rogue";
    Fighter* active_player;
    Fighter* active_enemy;
    while(true){
        // collect and validate input
        cout << "Choose your active player, Rogue, Sorcerer, Knight" << endl;
        cin >> active_player_selector;
        //Uses name string to find and select the current unit on the fighter roster
        active_player = Fighter_Roster->selectFighter(active_player_selector);
        if(active_player == nullptr){
            cout << "Invalid input! Select an active player on your Roster." << endl;
            continue;
        }
        cout << "Your chosen gladiator" << endl;
        active_player->display();

        cout << endl << "Would you like to use your ability before the fight? Yes?" << endl;
        cin >> usingAbility;
        if(usingAbility == "Yes"){
            if(active_player->abilityRemaining > 0){
            active_player->useAbility();
            cout << endl << "Your chosen gladiator grows stronger" << endl;
            active_player->display();
            }
            else{
                cout << "You cannot you are drained of power..." << endl;
            }
        }

        //enemy is always the head of the enemy roster
        active_enemy = Enemy_Roster->head->unit;
        // display current fight
        cout << endl << "The current enemy" << endl;
        active_enemy->display();

        active_enemy->health -= active_player -> attack;
        active_player->health -= active_enemy -> attack;
        cout << endl << "----- The battle rages on -----" << endl;
        cout << active_enemy -> name << " does " << active_enemy->attack << " damage to " << active_player->name << endl << active_player->name << " has " << active_player->health << " remaining" << endl;
        cout << active_player -> name << " does " << active_player->attack << " damage to " << active_enemy->name << endl << active_enemy->name << " has " << active_enemy->health << " remaining" << endl;
        if(active_enemy->health < 1){
            Enemy_Roster->deleteFighter(active_enemy);
            active_enemy = nullptr;
        }
        if(active_player->health < 1){
            Fighter_Roster->deleteFighter(active_player);
            active_player = nullptr;
        }
        if(Fighter_Roster->head == nullptr){
            cout << "Your team has been eliminated! Game Over..." << endl;
            cout << "The enemies remain: " << endl;
            Enemy_Roster->displayStats();
            break;
        }
        if(Enemy_Roster->head == nullptr){
            cout << "The enemies have been eliminated! You Win!" << endl;
            cout << "The victors that remain: " << endl;
            Fighter_Roster->displayStats();
            break;
        }    
    }

    delete Fighter_Roster;
    delete Enemy_Roster;
    return 0;
}