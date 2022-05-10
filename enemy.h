#pragma once
#include "cards.h"
#include <string>
#include <array>

class enemy{
    std::string ch_type;
    int ch_id;
    int ch_health;
    int ch_mana;
    std::array<card, 10> ch_enemyCards;
public:
    enemy(std::string type, int id, int health, int mana, std::array<card, 10> enemyCards)
        : ch_type(type), ch_id(id), ch_health(health), ch_mana(mana), ch_enemyCards(enemyCards){}
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
