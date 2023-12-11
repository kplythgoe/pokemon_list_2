#include <iostream>
#include <iomanip>
#include "Pokedex.h"

Pokedex::Pokedex() {

}

Pokedex::~Pokedex() {

}

void Pokedex::display() const {
    if (pokedex.size() == 0) {
        std::cout << "\nSorry, no Pokemon to display\n" << std::endl;
    } else {
        std::cout << "\n" << std::setfill('=') << std::setw(91) << "" << std::setfill(' ')  << "\n" << std::endl;
        std::cout << std::setw(5) << std::left << "Id";
        std::cout << std::setw(15) << std::left << "Name";
        std::cout << std::setw(10) << "Type 1";
        std::cout << std::setw(10) << "Type 2";
        std::cout << std::setw(7) << std::right << "HP";
        std::cout << std::setw(7) << "Att";
        std::cout << std::setw(7) << "Def";
        std::cout << std::setw(10) << "Sp.Att";
        std::cout << std::setw(10) << "Sp.Def";
        std::cout << std::setw(10) << "Speed" << std::endl;
        std::cout << std::setfill('-') << std::setw(91) << "" << std::setfill(' ')  << std::endl;
        
        for (const auto &pokemon: pokedex)
            pokemon.display();
        std::cout << "\n" << std::setfill('=') << std::setw(91) << "" << std::setfill(' ')  << "\n" << std::endl;
    }
}

bool Pokedex::add_pokemon(std::string id, std::string name, std::string type1, std::string type2, std::string hp, std::string att, std::string def, std::string spatt, std::string spdef, std::string speed) {
    for (Pokemon &pokemon : pokedex) {
        if (pokemon.get_name() == name && !repeat_pokemon) 
            return false;
    }
    Pokemon temp {id, name, type1, type2, hp, att, def, spatt, spdef, speed};
    pokedex.push_back(temp);
    return true;
}

bool Pokedex::object_exists() {
    if (pokedex.size() > 0)
        return true;
    else {
        return false;
    }
}