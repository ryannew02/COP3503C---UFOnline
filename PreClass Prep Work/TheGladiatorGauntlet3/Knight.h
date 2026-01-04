#pragma once
#include <string>
#include <iostream>
#include "Fighter.h"
using namespace std;

class Knight : public Fighter{
    public:

    Knight(string n, int h, int a, int c);

    void useAbility();
};