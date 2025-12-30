#include <iostream>
#include <string>
using namespace std;

//Base Class
class Fighter{
    public:
    int health;
    int attack;
    int critical;

    Fighter(int h,int a,int c){
        health = h;
        attack = a;
        critical = c;
    }

    virtual ~Fighter(){

    }

    virtual void useAbility() = 0;

};

class Knight : public Fighter {
    public:
    int abilityRemaining;

    Knight(int h, int a, int c)
    :Fighter(h, a, c){
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
    int abilityRemaining;

    Sorcerer(int h, int a, int c)
    :Fighter(h, a, c){
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
    int abilityRemaining;

    Rogue(int h, int a, int c)
    :Fighter(h, a, c){
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

template <typename T>
struct FighterNode{
    T* character;
    FighterNode<T>* next;

    FighterNode(T unit){
        character = &unit;
        next = nullptr;
    }
};


template <typename T>
struct LinkedList{
    FighterNode<T>* head;

    LinkedList(){
        head = nullptr;
    }

    void append(T unit){
        FighterNode<T>* newUnit = new FighterNode<T>(unit);
        if(head = nullptr){
            head = newUnit;
        }
        else{
            FighterNode<T>* temp = head;
            while(temp != nullptr){
                temp = temp -> next;
            }
            head = newUnit;
        }
    }

    // void display(){
    //     FighterNode<T>* current;
    //     current = head;
    //     int i;
    //     i = 1;
    //     while(current != nullptr){
    //         cout << "Current Node" << i << current->character->health << ":" << current->character->attack << endl;
    //         current = current->next;
    //     }
    // }

//     ~LinkedList(){
//         FighterNode<T>* temp;
//         FighterNode<T>* current;
//         temp = head;
//         while(temp->next != nullptr){
//             current = temp->next;
//             delete temp;
//             temp = current;
//         delete temp;
//         }
//     }
};

int main(){
  
    LinkedList<Fighter*>* Fighter_Roster = new LinkedList<Fighter*>; 
    Fighter* Ryan = new Knight(10,10,10);
    Fighter* Elise = new Sorcerer(10,10,10);
    Fighter* Lily = new Rogue(10,10,10);
    Fighter_Roster->append(Ryan);
    Fighter_Roster->append(Elise);
    Fighter_Roster->append(Lily);
    //Fighter_Roster->display();
    // delete Fighter_Roster;
    return 0;
}