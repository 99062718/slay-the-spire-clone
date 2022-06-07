#pragma once
#include <string>

struct cardEffect{
    std::string AOIeffect;
    std::string type;
    int value = 0;
    bool target = 0;
};

struct card{
    std::string name;
    std::string rarity;
    cardEffect effects[5];
};

card common[3] = {
    {"Sword slash", "common", {{"single", "atk", 5}}},
    {"Jump kick", "common", {{"single", "atk", 2}}},
    {"Chin punch", "common", {{"single", "atk", 3}}}
};

card uncommon[1] = {

};

card legendary[1] = {

};

card boss[1] = {

};

card lunar[1] = {

};