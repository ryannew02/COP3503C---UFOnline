#pragma once
#include <string>
#include <iostream>
#include "Fighter.h"
using namespace std;

class Rogue : public Fighter{
    public:
    Rogue(string n, int h, int a, int c);
    void useAbility();
};