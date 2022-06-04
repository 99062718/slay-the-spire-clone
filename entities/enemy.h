#pragma once
#include "../cards/cards.h"
#include "entity.h"
#include <vector>

class enemy : public entity{
public:
    enemy(monsterTemplate data)
        : entity(data.type, data.health, data.cards, data.mana, data.block, "enemy", data.strength){}
};

struct monsterTemplate{
    std::string type;
    std::string desc;
    int health;
    int mana;
    std::vector<card> cards;
    int block = 0;
    int strength = 0;
};

monsterTemplate allMonsters[1] = {
    {"Skeleton", "The skeleton appears", 20, 3, {common[1]}}
};
