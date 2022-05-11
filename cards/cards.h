#pragma once
#include <string>

struct cardEffect{
    std::string AOIeffect;
    std::string type;
    int value = 0;
};

struct card{
    std::string name;
    std::string rarity;
    cardEffect effects[5];
};

card common[] = {
    {"Sword slash", "common", {{"single", "atk", 5}}},
    {"Jump kick", "common", {{"single", "atk", 2}}},
    {"Chin punch", "common", {{"single", "atk", 3}}}
};

card uncommon[] = {

};

card legendary[] = {

};

card boss[] = {

};

card lunar[] = {

};