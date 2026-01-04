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
  string name;
  name = "save.txt";
  LinkedList* fighterRoster = new LinkedList;
  fighterRoster->loadRoster(name);
  fighterRoster->saveRoster(name);
  return 0;
}