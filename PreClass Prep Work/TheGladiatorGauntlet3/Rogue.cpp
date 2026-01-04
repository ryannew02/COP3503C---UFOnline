#include "Rogue.h"

Rogue::Rogue(string n, int h, int a, int c) : Fighter(n, h, a, c) {
}

void Rogue::useAbility(){
    critical *= 2;
    attack *= 2;
}