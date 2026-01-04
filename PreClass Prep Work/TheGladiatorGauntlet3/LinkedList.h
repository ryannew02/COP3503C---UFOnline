#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "Fighter.h"
#include "Rogue.h"
#include "Mage.h"
#include "Knight.h"
using namespace std;

struct FighterNode {
    Fighter* unit;
    FighterNode* next;

    FighterNode(Fighter* value);
};

class LinkedList {
    public:
    FighterNode* head;
    int roster_size;

    LinkedList();
    void append(Fighter* unit);
    void deleteFighter(Fighter* unit);
    void displayStats();
    Fighter* selectFighter(string name);
    void loadRoster(string filename);
    void saveRoster(string filename);
    ~LinkedList();

};