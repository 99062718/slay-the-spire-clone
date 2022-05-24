#pragma once
#include "cards/cards.h"
#include "entity.h"
#include <array>

class enemy : public entity{
    std::array<card, 10> ch_enemyCards;
public:
    enemy(std::string type, int health, int mana, std::array<card, 10> enemyCards, int block, int strength)
        : entity(type, health, mana, block, "enemy", strength), ch_enemyCards(enemyCards){}
};

struct monsterTemplate{
    std::string name;
    std::string desc;
    int health;
    int mana;
    std::array<card, 10> enemyCards;
    int block = 0;
    int strength = 0;
};

monsterTemplate allMonsters[1] = {
    {"Skeleton", "The skeleton appears", 20, 3, {common[1]}}
};