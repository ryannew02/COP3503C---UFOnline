#include "GameLoop.h"

void reset(LinkedList* fighterRoster, LinkedList* enemyRoster){
    while(fighterRoster->head != nullptr){
        Fighter* unit;
        unit = fighterRoster->head->unit;
        fighterRoster->deleteFighter(unit);
    }
    while(enemyRoster->head != nullptr){
        Fighter* unit;
        unit = enemyRoster->head->unit;
        enemyRoster->deleteFighter(unit);
    }
    Fighter* unit;
    unit = new Rogue("Rogue", 10, 10, 10);
    fighterRoster->append(unit);
    unit = new Knight("Knight", 10, 10, 10);
    fighterRoster->append(unit);
    unit = new Mage("Mage", 10, 10, 10);
    fighterRoster->append(unit);
    unit = new Monster("Monster", 10, 10, 10);
    enemyRoster->append(unit);
    unit = new Monster("Monster", 10, 10, 10);
    enemyRoster->append(unit);
    unit = new Monster("Monster", 10, 10, 10);
    enemyRoster->append(unit);
}

void game(LinkedList* fighterRoster, LinkedList* enemyRoster){
    //initialize control variable
    bool game_running;
    game_running = true;
    string active_player_selector;
    string usingAbility;
    active_player_selector = "Rogue";
    Fighter* active_player;
    Fighter* active_enemy;
    while(true){
        //exit game loop
        if(!game_running){
            string command;
            cout << "Would you like to continue: Yes/No";
            cin >> command;
            if(command == "Yes"){
                game_running = true;
                continue;
            }
            else{
                break;
            }
        }
        // collect and validate input
        cout << "Choose your active player: Rogue/Mage/Knight" << endl;
        cout << "You can always Save or Restart: Save/Restart" << endl;
        cin >> active_player_selector;
        if(active_player_selector == "Save"){
            game_running = false;
            continue;
        }
        if(active_player_selector == "Restart"){
            reset(fighterRoster, enemyRoster);
            continue;
        }
        //Uses name string to find and select the current unit on the fighter roster
        active_player = fighterRoster->selectFighter(active_player_selector);
        if(active_player == nullptr){
            cout << "Invalid input! Select an active player on your Roster." << endl;
            continue;
        }
        cout << "Your chosen gladiator" << endl;
        active_player->displayStats();

        cout << endl << "Would you like to use your ability before the fight: Yes/No" << endl;
        cin >> usingAbility;
        if(usingAbility == "Yes"){
            if(active_player->abilityRemaining > 0){
            active_player->useAbility();
            cout << endl << "Your chosen gladiator grows stronger" << endl;
            active_player->displayStats();
            }
            else{
                cout << "You cannot you are drained of power..." << endl;
            }
        }

        //enemy is always the head of the enemy roster
        active_enemy = enemyRoster->head->unit;
        // display current fight
        cout << endl << "The current enemy" << endl;
        active_enemy->displayStats();

        active_enemy->health -= active_player -> attack;
        active_player->health -= active_enemy -> attack;
        cout << endl << "----- The battle rages on -----" << endl;
        cout << active_enemy -> name << " does " << active_enemy->attack << " damage to " << active_player->name << endl << active_player->name << " has " << active_player->health << " remaining" << endl;
        cout << active_player -> name << " does " << active_player->attack << " damage to " << active_enemy->name << endl << active_enemy->name << " has " << active_enemy->health << " remaining" << endl;
        if(active_enemy->health < 1){
            enemyRoster->deleteFighter(active_enemy);
            active_enemy = nullptr;
        }
        if(active_player->health < 1){
            fighterRoster->deleteFighter(active_player);
            active_player = nullptr;
        }
        if(fighterRoster->head == nullptr){
            cout << "Your team has been eliminated! Game Over..." << endl;
            cout << "The enemies remain: " << endl;
            enemyRoster->displayStats();
            reset(fighterRoster, enemyRoster);
            game_running = false;
            continue;
        }
        if(enemyRoster->head == nullptr){
            cout << "The enemies have been eliminated! You Win!" << endl;
            cout << "The victors that remain: " << endl;
            fighterRoster->displayStats();
            reset(fighterRoster, enemyRoster);
            game_running = false;
            continue;
        }    
    }
}