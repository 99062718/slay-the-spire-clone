#pragma once
#include <string>

/*
Card effects corrosponding to their number:
    0: attack
    1: heal
*/

struct cardEffect{
    std::string AOIeffect;
    char type;
    int value = 0;
    bool target = 0;
};

struct card{
    std::string name;
    std::string rarity;
    cardEffect effects[5];
};

card common[3] = {
    {"Sword slash", "common", {{"single", 0, 5}}},
    {"Jump kick", "common", {{"single", 0, 2}}},
    {"Chin punch", "common", {{"single", 0, 3}}}
};

card uncommon[1] = {

};

card legendary[1] = {

};

card boss[1] = {

};

card lunar[1] = {

};