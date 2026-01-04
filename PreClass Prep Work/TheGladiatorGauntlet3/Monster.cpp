#include "Monster.h"

    Monster::Monster(string n, int h, int a, int c)
    :Fighter(n, h, a, c)
    {
        name = n;
        health = h;
        attack = a;
        critical = c;
    }

    void Monster::useAbility(){
        health = 0;
    }
    void Monster::displayStats(){
        cout <<"Name: " << name << endl;
        cout << "Health - Attack - Critical" << endl;
        cout << health << " - "<< attack << " - " << critical << endl;
        }