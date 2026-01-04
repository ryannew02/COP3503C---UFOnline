#pragma once
#include <string>
#include <iostream>
#include "Fighter.h"
using namespace std;

class Mage : public Fighter{
    public:

    Mage(string n, int h, int a, int c);

    void useAbility();
};