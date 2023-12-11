#include "Pokemon.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cctype>

Pokemon::Pokemon(std::string id, std::string name, std::string type1, std::string type2, std::string hp, std::string att, std::string def, std::string spatt, std::string spdef, std::string speed)
    :id(id), name(name), type1(type1), type2(type2), hp(hp), att(att), def(def), spatt(spatt), spdef(spdef), speed(speed){

        }

//Pokemon::Pokemon() {
//    std::cout << "Calling default constructor" << std::endl;
//}

Pokemon::Pokemon(const Pokemon &source) 
    : Pokemon{source.id, source.name, source.type1, source.type2, source.hp, source.att, source.def, source.spatt, source.spdef, source.speed} {

}

Pokemon::~Pokemon()
{

}

void Pokemon::display() const {
    std::cout << std::setw(5) << std::left << id
                   << std::setw(15)  << name
                   << std::setw(10)  << type1
                   << std::setw(10)  << type2
                   << std::setw(7)  << std::right << hp
                   << std::setw(7)  << att
                   << std::setw(7)  << def
                   << std::setw(10)  << spatt
                   << std::setw(10)  << spdef
                   << std::setw(10)  << speed << std::endl;
}