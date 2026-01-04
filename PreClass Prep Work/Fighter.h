#pragma once
#include <string>
#include <iostream>
using namespace std;

class Fighter {
    public:
    string name;
    int health, attack, critical, abilityRemaining;

    Fighter(string n, int h, int a, int c);

    void displayStats();

    virtual ~Fighter();

    virtual void useAbility() = 0;
};