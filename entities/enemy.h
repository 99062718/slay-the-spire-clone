#pragma once
#include "../cards/cards.h"
#include "entity.h"
#include <vector>

class enemy : public entity{
public:
    enemy(std::string type, int health, std::vector<card> cards, int mana, int block, int strength)
        : entity(type, health, cards, mana, block, "enemy", strength){}
};

struct monsterTemplate{
    std::string name;
    std::string desc;
    int health;
    int mana;
    std::vector<card> enemyCards;
    int block = 0;
    int strength = 0;
};

monsterTemplate allMonsters[1] = {
    {"Skeleton", "The skeleton appears", 20, 3, {common[1]}}
};
