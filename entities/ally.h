#pragma once
#include "entity.h"
#include "../cards/cards.h"
#include <vector>

class ally : public entity{
public:
    ally(allyData data)
        : entity(data.type, data.health, data.cards, data.mana, data.block, "ally", data.strength){}
};

struct allyData{
    std::string type;
    int health;
    int mana;
    std::vector<card> cards;
    int block = 0;
    int strength = 0;
};