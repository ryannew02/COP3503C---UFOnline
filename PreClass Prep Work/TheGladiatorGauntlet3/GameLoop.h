#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "Fighter.h"
#include "Rogue.h"
#include "Mage.h"
#include "Knight.h"
#include "LinkedList.h"
using namespace std;

void game(LinkedList* fighterRoster, LinkedList* enemyRoster);
void reset(LinkedList* fighterRoster, LinkedList* enemyRoster);