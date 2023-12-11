#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <sstream>
#include <typeinfo>
#include <cctype>
#include "Pokedex.h"

using namespace std;

void add_pokemon(Pokedex &pokedex, std::string id, std::string name, std::string type, std::string type2, std::string hp, std::string att, std::string def, std::string spatt, std::string spdef, std::string speed);
void add_pokemon(Pokedex &pokedex, std::string id, std::string name, std::string type1, std::string type2, std::string hp, std::string att, std::string def, std::string spatt, std::string spdef, std::string speed) {
    if (!pokedex.add_pokemon(id,name,type1,type2, hp, att, def, spatt, spdef, speed)) 
        std::cout << name << " already exists" <<  std::endl;
}
void create_party();
void menu_output();
bool mini_menu();

int main() {
    
    fstream file ("pokemon.csv", ios::in);
        if(!file.is_open()){
            cout<<"Could not open the file\n";
        }
    srand((unsigned) time(0));
    int ranNum;
    vector<string> row;
    string line, word;
    int choice{0}, num_pokemon{0};
    vector<int> picks{};
    while(getline(file, line)) {
        num_pokemon++;
    }
    
    
    
    do {
        menu_output();
        cout << "Please select a choice by number: ";
        while(!(cin >> choice)) {
            cout << "\nPlease enter a number from the choices available: ";
            cin >> choice;
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
        switch(choice) {
            case 1:
            {
                file.clear();
                file.seekg(0, ios::beg);
                Pokedex all_pokemon;
                while(getline(file, line)) {
                    row.clear();
                    stringstream str(line);
                    while(getline(str, word, ',')) {
                        row.push_back(word);
                    }
                    add_pokemon(all_pokemon, row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9]);
                }
                all_pokemon.display();  
                cout << "You have " << num_pokemon << " Pokemon.\n" << endl;
                
                if (!mini_menu()) {
                    cout << "\nGoodbye!" << endl;
                    return 0;
                }
                    
                break;
            }
            case 2:
            {
                file.clear();
                file.seekg(0, ios::beg);
                cout << "\nWould you like to include possible duplicates in your party?\n" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cout << "\nPlease select a choice by number: ";
                while(!(cin >> choice)) {
                    cout << "\nPlease enter a number from the choices available: ";
                    cin >> choice;
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }
                cout << "\nChoosing party of 6 at random\n";
                cout << "\nPossible duplicates: ";
                choice == 1 ? cout << "YES" : cout << "NO";
                picks.clear();
                for (int i {0} ; i < 6 ; i++) {
                    ranNum = (rand() % num_pokemon) + 1;
                    if (choice == 2) {
                        while (count(picks.begin(), picks.end(), ranNum)) {
                                ranNum = (rand() % num_pokemon) + 1;
                        }
                    }
                    picks.push_back(ranNum);
                }
                Pokedex party;
                party.repeat_true();
                while(getline(file, line)) {
                    row.clear();
                    stringstream str(line);
                    while(getline(str, word, ',')) {
                        row.push_back(word);
                    }
                    for(auto pick : picks) {
                        if(pick == stoi(row[0])) {
                            add_pokemon(party, row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9]);
                        }
                    }
                }
                party.repeat_false();
                party.display();
 
                if (!mini_menu()) {
                    cout << "\nGoodbye!" << endl;
                    return 0;
                }
                    
                break;
            }
            case 3:
            {
                file.clear();
                file.seekg(0, ios::beg);
                cout << "\nWould you like to include possible duplicates in your party?\n" << endl;
                cout << "1. Yes" << endl;
                cout << "2. No" << endl;
                cout << "\nPlease select a choice by number: ";
                while(!(cin >> choice)) {
                    cout << "\nPlease enter a number from the choices available: ";
                    cin >> choice;
                    cin.clear(); 
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                }
                cout << "\nChoose 6 Pokemon by their Pokemon ID" << endl;
                cout << "\nPossible duplicates: ";
                choice == 1 ? cout << "YES" : cout << "NO";
                cout << endl << endl;
                picks.clear();
                for(int i {1} ; i <= 6 ; i++) {
                    int pick;
                    cout << "Choice " << i << ": ";
                    while(!(cin >> pick)) {
                        cout << "\nPlease enter a number from the choices available\n" << endl;
                        cout << "Choice " << i << ": ";
                        cin >> pick;
                        cin.clear(); 
                        cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    }
                    while (choice == 2 && count(picks.begin(), picks.end(), pick)) {
                        cout << "\nYou selected not to allow repeat Pokemon. Would you like to change this? (Y/N): ";
                        char change;
                        cin >> change;
                        change = toupper(change);
                        while (change != 'Y' && change != 'N') {
                            cout << "Invalid choice: please choose Y for yes and N for no: ";
                            cin >> change;
                            change = toupper(change);
                            cout << endl;
                        }
                        if(change == 'Y') {
                            choice = 1;
                            cout << "\nPossible duplicates: ";
                            choice == 1 ? cout << "YES" : cout << "NO";
                            cout << endl << endl;
                        }
                        else {
                            cout << "\nPossible duplicates: ";
                            choice == 1 ? cout << "YES" : cout << "NO";
                            cout << endl << endl;
                            cout << "Choice " << i << ": ";
                            cin >> pick;
                        }
                    }
                    picks.push_back(pick);
                }
                
                Pokedex party;
                party.repeat_true();
                num_pokemon = 0;
                while(getline(file, line)) {
                    num_pokemon++;
                        row.clear();
                        stringstream str(line);
                        while(getline(str, word, ',')) {
                            row.push_back(word);
                        }
                        for(auto pick : picks) {
                            if(pick == stoi(row[0])) {
                                add_pokemon(party, row[0], row[1], row[2], row[3], row[4], row[5], row[6], row[7], row[8], row[9]);
                            }
                        }
                }
                party.repeat_false();
                party.display();

                if (!mini_menu()) {
                    cout << "\nGoodbye!" << endl;
                    return 0;
                }
                    
                break;
            }
            case 4:
            {
                cout << "\nGoodbye!" << endl;
                break;
            }
            default:
            {
                cout << "\nInvalid choice: ";
                break;
            }
        }
    } while (choice != 4);

    return 0;
}

bool mini_menu() {
    cout << "1. Main Menu" <<endl;
    cout << "2. Exit\n" << endl;
    cout << "Please select a choice by number: ";
    int choice;
    while(!(cin >> choice)) {
        cout << "\nPlease enter a number from the choices available: ";
        cin >> choice;
        cin.clear(); 
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    if ( choice == 1)
        return 1;
    else 
        return 0;
}

void menu_output() {
    system("cls");
    cout << "Welcome to the Pokemon simulator. In the Pokemon simulator, you can look at a list of all the Pokemon from Gen 1 and get a randomly selected party of 6 Pokemon from Gen 1.\n" << endl;
    cout << "Please choose by number from the options provided\n" << endl;
    cout<<"1. Display all Pokemon from Gen 1" << endl;
    cout<<"2. Party Selector - Get a randomly chosen party of 6 Pokemon at random" << endl;
    cout<<"3. Choose your own party of Pokemon" << endl;
    cout<<"4. Quit\n" << endl;
}

