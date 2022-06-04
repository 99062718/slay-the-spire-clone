#pragma once
#include "entity.h"
#include "../cards/cards.h"
#include <vector>

class ally : public entity{
public:
    ally(std::string type, int health, std::vector<card> cards, int mana, int block, int strength)
        : entity(type, health, cards, mana, block, "ally", strength){}
};

struct allyData{
    std::string type;
    int health;
    int mana;
    std::vector<card> startingDeck;
    int block = 0;
    int strength = 0;
};