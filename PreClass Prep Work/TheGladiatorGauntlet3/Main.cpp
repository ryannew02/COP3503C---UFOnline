#include <iostream>
#include <string>
#include <fstream>
#include "Fighter.h"
#include "Rogue.h"
#include "Mage.h"
#include "Knight.h"
#include "LinkedList.h"
#include "GameLoop.h"
using namespace std;

int main(){
  //initialize filenames
  string fighter_save; 
  string enemy_save;
  string fighter_save_bin; 
  string enemy_save_bin;
  fighter_save = "fighter_save.txt";
  enemy_save = "enemy_save.txt";
  fighter_save_bin = "fighter_save.bin";
  enemy_save_bin = "enemy_save.bin";
  //allocate roster memory
  LinkedList* fighterRoster = new LinkedList(true);
  LinkedList* enemyRoster = new LinkedList(false);
  //load saved game state
  // fighterRoster->loadRoster(fighter_save);
  // enemyRoster->loadRoster(enemy_save);
  fighterRoster->loadRosterBinary(fighter_save_bin);
  enemyRoster->loadRosterBinary(enemy_save_bin);
  game(fighterRoster, enemyRoster);
  //Save game state
  // fighterRoster->saveRoster(fighter_save);
  // enemyRoster->saveRoster(enemy_save);
  fighterRoster->saveRosterBinary(fighter_save_bin);
  enemyRoster->saveRosterBinary(enemy_save_bin);
  //delete rosters
  delete fighterRoster;
  delete enemyRoster;
  return 0;
}