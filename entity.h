#pragma once
#include <string>

class entity{
protected:
    std::string ch_type;
    int ch_health;
    int ch_mana;
public:
    entity(std::string type, int health, int mana)
        : ch_type(type), ch_health(health), ch_mana(mana){}
};