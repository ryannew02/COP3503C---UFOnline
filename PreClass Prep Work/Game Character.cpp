#include <iostream>
#include <string>

class Character{
        std::string name;
        int health;
        int score;
    public:
        Character(std::string n, int h, int s){
            name = n;
            health = h;
            score = s;
        }
        void takeDamage(){
            health -= 20;
            std::cout << "Hit Taken!" << std::endl;
        }
        void printStats(){
            std::cout << name << ":" << health << ":" << score << std::endl;        
        }
        void heal(){
            health += 10;
            std::cout << "Heal used!" << std::endl;
        }
    };

// void takeDamage(Character& player){
//     player.health -= 20;
//     std::cout << "Hit Taken!" << std::endl;
// }

// void printStats(Character& player){
//     std::cout << player.name << ":" << player.health << ":" << player.score << std::endl;
// }

int main(){
    Character player_one("Ryan", 50, 0);
    player_one.printStats();
    player_one.takeDamage();
    player_one.printStats();
    player_one.heal();
    player_one.printStats();
    
    
    return 0;
}