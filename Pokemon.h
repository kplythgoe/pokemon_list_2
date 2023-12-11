#ifndef __POKEMON_H__
#define __POKEMON_H__
#include <string>

class Pokemon
{
    std::string id;
    std::string name;
    std::string type1;
    std::string type2;
    std::string hp;
    std::string att;
    std::string def;
    std::string spatt;
    std::string spdef;
    std::string speed;
public:
//    Pokemon();
    Pokemon(std::string id, std::string name, std::string type1, std::string type2, std::string hp, std::string att, std::string def, std::string spatt, std::string spdef, std::string speed);
    
    Pokemon(const Pokemon &source);
    ~Pokemon();
    
    void display() const;

    std::string get_name() const { 

        return name; 
    }

};

#endif // __POKEMON_H__
