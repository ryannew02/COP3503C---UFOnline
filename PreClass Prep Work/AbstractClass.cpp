#include <iostream>
#include <string>

class Character{

    public:
        std::string name;
        int level;
        int strength;
        int health;
        int score;
        int* weaponPower;

        Character(
            std::string n,
            int l = 0,
            int st = 1, 
            int h = 10,
            int sc = 0,
            int wP = 0
        )
        {
            name = n;
            level = l;
            strength = st;
            health = h;
            score = sc;
            weaponPower = new int;
            *weaponPower = wP;
        }
        Character(const Character& other){
            name = other.name;
            level = other.level;
            strength = other.strength;
            health = other.health;
            score = other.score;
            weaponPower = new int;
            *weaponPower = *other.weaponPower;
            }

        virtual ~Character(){
            delete weaponPower;
            std::cout << "***Deconstructor called on " << name << "***" << std::endl;
        }

        virtual void attack() = 0;
};

class Wizard : public Character {
    public:

    int mana;

    Wizard(
            std::string n,
            int l = 0,
            int st = 1, 
            int h = 10,
            int sc = 0,
            int wP = 0,
            int m = 100
    ) : Character(n, l, st, h, sc, wP){
        mana = m;
    }

    void attack(){
        std::cout << "Fireball" << std::endl;
    }
};

class Warrior : public Character {
    public:

    int armourClass;

    Warrior(
            std::string n,
            int l = 0,
            int st = 1, 
            int h = 10,
            int sc = 0,
            int wP = 0,
            int aC = 12
    ) : Character(n, l, st, h, sc, wP){
        armourClass = aC;
    }

    void attack(){
        std::cout << "Cleave" << std::endl;
    }
};


int main() {
    Wizard* player1 = new Wizard("Marlin");
    Warrior* player2 = new Warrior("Smith");
    player1->attack();
    player2->attack();
    std::cout << player2 -> armourClass << std::endl;
    std::cout << player1 -> mana << std::endl;
    delete player1;
    delete player2;
    return 0;
}