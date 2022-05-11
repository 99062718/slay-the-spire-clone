#pragma once
#include "cards.h"
#include "entity.h"
#include <string>
#include <array>

class enemy : entity{
    std::array<card, 10> ch_enemyCards;
public:
    enemy(std::string type, int health, int mana, std::array<card, 10> enemyCards)
        : entity(type, health, mana), ch_enemyCards(enemyCards){}
};

struct monsterTemplate{
    std::string name;
    std::string desc;
    int health;
    int mana;
    std::array<card, 10> ch_enemyCards;
};

monsterTemplate allMonsters[1] = {
    {"Skeleton", "The skeleton appears", 20, 3, {common[1]}}
};
