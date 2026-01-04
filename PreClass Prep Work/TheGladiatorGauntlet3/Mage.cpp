#include "Mage.h"

Mage::Mage(string n, int h, int a, int c) : Fighter(n, h, a, c) {
    attack *= 3;
}

void Mage::useAbility(){
    attack *= 2;
}