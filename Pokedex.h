#ifndef __POKEDEX_H__
#define __POKEDEX_H__
#include <vector>
#include <string>
#include "Pokemon.h"

class Pokedex
{
    std::vector<Pokemon> pokedex;
    bool repeat_pokemon {false};

public:
    Pokedex();
    ~Pokedex();
    void display() const;
    bool add_pokemon(std::string id, std::string name, std::string type1, std::string type2, std::string hp, std::string att, std::string def, std::string spatt, std::string spdef, std::string speed);
    void repeat_true() { repeat_pokemon = true; }
    void repeat_false() { repeat_pokemon = false; }
    bool object_exists();
    void clear_party() { pokedex.clear(); }

};

#endif // __POKEDEX_H__
