#pragma once
#include <string>

/*
Card effects corrosponding to their number:
    0: attack,
    1: heal
*/

struct cardEffect{
    std::string AOIeffect;
    char type;
    int value = 0;
    bool target = false;
};

struct card{
    std::string name;
    std::string rarity;
    cardEffect effects[5];
    float chanceToHit = 1.0;
};

const card common[3] = {
    {"Sword slash", "common", {{"single", 0, 5}}},
    {"Jump kick", "common", {{"single", 0, 2}}},
    {"Chin punch", "common", {{"single", 0, 3}}}
};

const card uncommon[1] = {

};

const card legendary[1] = {

};

const card boss[1] = {

};

const card lunar[1] = {

};