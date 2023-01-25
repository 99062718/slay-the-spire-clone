#pragma once
#include "../cards/cards.h"

struct entityData{ // some kind of xp on defeat?
    std::string type;
    std::string desc;
    int health;
    int startingMana;
    std::vector<card> cards;
    int block = 0;
    int strength = 0;
};

const entityData allMonsters[2] = {
    {"Skeleton", "The skeleton appears", 20, 3, {common[1]}},
    {"The unfortunate one", "It was dead on arrival", 0, 0, {}}
};