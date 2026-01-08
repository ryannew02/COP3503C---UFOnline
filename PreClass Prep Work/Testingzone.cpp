    void LinkedList::loadRosterBinary(string filename){
        ifstream inputFile(filename, ios::binary);

        if(!inputFile.is_open()) {
            cout << "Error opening binary file (or file doesn't exist)!" << endl;
            return;
        }

        int nameLength;
        int h, a, c;

        while(inputFile.read((char*)&nameLength, sizeof(nameLength))) {
            char* nameBuffer = new char[nameLength +1];
            inputFile.read(nameBuffer, nameLength);
            nameBuffer[nameLength] = '\0';
            string name = nameBuffer;
            delete[] nameBuffer;

            inputFile.read((char*)&h, sizeof(int));
            inputFile.read((char*)&a, sizeof(int));
            inputFile.read((char*)&c, sizeof(int));

        Fighter* newUnit = nullptr;
        if(name == "Rogue") newUnit = new Rogue(name, h, a, c);
        else if(name == "Knight") newUnit = new Knight(name, h, a, c);
        else if(name == "Mage") newUnit = new Mage(name, h, a, c);

        if (newUnit != nullptr) {
            append(newUnit);
            cout << "Loaded Binary: " << name << endl;
        }
    }
    inputFile.close();
    }

    void LinkedList::loadRoster(string filename){
    string name;
    int h, a, c;
    Fighter* newUnit;
    if(is_ally){
    //Load ally roster...
    ifstream fighterFile(filename);
    if (!fighterFile.is_open()){
        cout << "No save found...backing up from default template " << filename << endl;
        Fighter* newUnit;
        newUnit = new Rogue("Rogue", 10, 10, 10);
        append(newUnit);
        newUnit = new Knight("Knight", 10, 10, 10);
        append(newUnit);
        newUnit = new Mage("Mage", 10, 10, 10);
        append(newUnit);
    }
    else{
        while(fighterFile >> name >> h >> a >> c){
        newUnit = nullptr;
        if(name == "Rogue"){
            newUnit = new Rogue(name, h, a, c);
        }
        else if(name == "Knight"){
            newUnit = new Knight(name, h, a, c);
        }
        else if(name == "Mage"){
            newUnit = new Mage(name, h, a, c);
        }
        if(newUnit != nullptr){
            append(newUnit);
            cout << name << " loaded successfully from file " << filename << endl;
        }
    }
    fighterFile.close();
    if(head != nullptr){
    cout << "Roster loaded from " << filename << " successfully!" << endl;
    }
    }
    }
    else{   
    //Load enemy roster...
    ifstream enemyFile(filename);
    if (!enemyFile.is_open()){
        cout << "No save found...backing up from default template " << filename << endl;
        Fighter* newUnit;
        newUnit = new Monster("Monster", 10, 10, 10);
        append(newUnit);
        newUnit = new Monster("Monster", 20, 20, 20);
        append(newUnit);
        newUnit = new Monster("Monster", 30, 30, 30);
        append(newUnit);
    }
    else{
        while(enemyFile >> name >> h >> a >> c){
            newUnit = nullptr;
            if(name == "Monster"){
                newUnit = new Monster(name, h, a, c);
            }
            if(newUnit != nullptr){
                append(newUnit);
                cout << name << " loaded successfully from file " << filename << endl;
            }
        }
        enemyFile.close();
        if(head != nullptr){
        cout << "Roster loaded from " << filename << " successfully!" << endl;
        }
    }
    }
}

    void LinkedList::saveRoster(string filename){
    ofstream outputFile(filename);
    FighterNode* temp;
    string name;
    int h, a, c;
    temp = head;
    while(temp != nullptr){
        name = temp->unit->name;
        h = temp->unit->health;
        a = temp->unit->attack;
        c = temp->unit->critical;
        outputFile << name << " " << h << " " << a << " " << c << endl;
        temp = temp->next;
    }
    outputFile.close();
    }

    void LinkedList::saveRosterBinary(string filename){
        ofstream outputFile(filename, ios::binary);

        if(!outputFile.is_open()){
            cout << "Error: Could not create binary file " << filename << endl;
            return;
        }

        FighterNode* temp = head;
        while(temp != nullptr){
            Fighter* f = temp->unit;
            int nameLength = f->name.size();

            outputFile.write((char*)&nameLength, sizeof(nameLength));

            outputFile.write(f->name.c_str(), nameLength);

            outputFile.write((char*)&f->health, sizeof(int));
            outputFile.write((char*)&f->attack, sizeof(int));
            outputFile.write((char*)&f->critical, sizeof(int));

            temp = temp->next;
        }
        
        outputFile.close();
        cout << "Successfully saved binary roster to " << filename << endl;
    }