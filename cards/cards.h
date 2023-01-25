#pragma once
#include <string>
#include <vector>

/*
Card effects corrosponding to their number:
    0: attack,
    1: heal,
    2: block,
    3: fragile,
    4: strength,
    5: weak,
    6: revive

AOI effect modes corrosponding to their number:
    0: all,
    1: row,
    2: single

Display modes corrosponding to their number:
    0: only show alive,
    1: only show dead,
    2: show all
*/

extern std::string cardTypeNames[7];

struct cardEffect{
    int AOIeffect;
    int type;
    int value = 0;
    int chanceToHit = 100;
    bool target = true;
    int displayMode = 0;
};

struct card{ // add mana cost
    std::string name;
    std::string rarity;
    std::vector<cardEffect> effects;
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