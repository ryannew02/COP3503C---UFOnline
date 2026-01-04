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