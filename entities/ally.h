#pragma once
#include "entity.h"
#include "cards/cards.h"
#include <vector>

class ally : public entity{
    std::vector<card> ch_allyCards;
public:
    ally(std::string type, int health, int mana, std::vector<card> allyCards, int block, int strength)
        : entity(type, health, mana, block, "ally", strength), ch_allyCards(allyCards){}
};

struct allyData{
    std::string type;
    int health;
    int mana;
    std::vector<card> startingDeck;
    int block = 0;
    int strength = 0;
};