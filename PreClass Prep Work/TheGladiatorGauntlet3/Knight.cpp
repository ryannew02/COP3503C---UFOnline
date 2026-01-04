#include "Knight.h"

Knight::Knight(string n, int h, int a, int c) : Fighter(n, h, a, c) {
}

void Knight::useAbility(){
    health /= 2;
    attack *= 2;
}