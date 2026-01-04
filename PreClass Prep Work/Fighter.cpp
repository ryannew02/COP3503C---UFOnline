#include "Fighter.h"

Fighter::Fighter(string n, int h, int a, int c) {
    name = n;
    health = h;
    attack = a;
    critical = c;
    abilityRemaining = 1;
}

void Fighter::displayStats() {
    cout <<"Name: " << name << endl;
    cout << "Health Attack Critical" << endl;
    cout << health << attack << critical << endl;
    cout << "Ability uses remaining " << abilityRemaining << endl;
}

Fighter::~Fighter() {}
