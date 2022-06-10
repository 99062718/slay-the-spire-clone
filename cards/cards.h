#pragma once
#include <string>

/*
Card effects corrosponding to their number:
    0: attack,
    1: heal

AOI effect modes corrosponding to their number:
    0: all,
    1: row,
    2: single
*/

struct cardEffect{
    char AOIeffect;
    char type;
    int value = 0;
    bool target = false;
};

struct card{
    std::string name;
    std::string rarity;
    cardEffect effects[5];
    char chanceToHit = 100;
};

const card common[3] = {
    {"Sword slash", "common", {{2, 0, 5}}},
    {"Jump kick", "common", {{2, 0, 2}}},
    {"Chin punch", "common", {{2, 0, 3}}}
};

const card uncommon[1] = {

};

const card legendary[1] = {

};

const card boss[1] = {

};

const card lunar[1] = {

};