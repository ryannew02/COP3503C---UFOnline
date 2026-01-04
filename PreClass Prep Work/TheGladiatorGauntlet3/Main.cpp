#include <iostream>
#include <string>
#include <fstream>
#include "Fighter.h"
#include "Rogue.h"
#include "Mage.h"
#include "Knight.h"
#include "LinkedList.h"
using namespace std;

int main(){
  string fighter_save; 
  string enemy_save;
  fighter_save = "fighter_save.txt";
  enemy_save = "enemy_save.txt";
  LinkedList* fighterRoster = new LinkedList;
  fighterRoster->loadRoster(fighter_save, enemy_save);
  fighterRoster->saveRoster(fighter_save);
  fighterRoster->saveRoster(enemy_save);
  return 0;
}