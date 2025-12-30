#include <iostream>
#include <string>

struct Character{
    std::string name;
    int level;
    int health;
    int score;
    int* staffPower;
    Character(std::string n = "John Doe", int l = 0, int h = 100, int s = 0, int power = 25){
        name = n;
        level = l;
        health = h;
        score = s;
        staffPower = new int;
        *staffPower = power;
    }
    Character(const Character& other){
        name = other.name;
        level = other.level;
        health = other.health;
        score = other.score;
        staffPower = new int;
        *staffPower = *other.staffPower;
        std::cout << "Copy Constructor called!" << std::endl;
    }
    virtual ~Character(){
        std::cout << "destructor called for " << name << std::endl;
        delete staffPower;
    }

    void takeDamage(){
        health -= 20;
    }
};

struct Wizard : public Character {
    int mana;

    Wizard(std::string n, int l, int h, int s, int power, int m = 1)
        :Character(n,l,h,s,power)
    {
        mana = m;
    }

};

int main(){
    Character* players[2];
    players[0] = new Character("Ryan", 1, 25, 0, 2);
    players[1] = new Character(*players[0]);
    Wizard* merlin;
    merlin = new Wizard("Merlin", 1, 25, 0, 2, 1);
    std::cout << players[0] -> name << std::endl;
    players[0] -> score = 500;
    std::cout << players[0] -> score << std::endl;
    std::cout << players[1] -> name << std::endl;
    players[1] -> score = 50;
    std::cout << players[1] -> score << std::endl;
    *(players[1] -> staffPower) = 10;
    std::cout << players[0] -> name << *(players[0] -> staffPower) << std::endl << players[1] -> name << *(players[1] -> staffPower) << std::endl;
    std::cout << merlin -> name << merlin -> mana << std::endl;
    delete players[0];
    delete players[1];
    delete merlin;    
    return 0;
}