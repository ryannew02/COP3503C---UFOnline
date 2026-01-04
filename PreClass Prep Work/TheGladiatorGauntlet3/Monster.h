#pragma once
#include <string>
#include <iostream>
#include "Fighter.h"

class Monster : public Fighter {
    public:
    Monster(string n, int h, int a, int c);
    void useAbility();
};