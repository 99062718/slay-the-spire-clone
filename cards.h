#pragma once
#include <string>

struct card{
    std::string type;
    std::string name;
    std::string rarity;
    int dmg = 0;
};

card common[3] = {
    {"atk", "Sword slash", "common", 5},
    {"atk", "Jump kick", "common", 2},
    {"atk", "Chin punch", "common", 3}
};

card uncommon[1] = {

};

card legendary[1] = {

};

card boss[1] = {

};

card lunar[1] = {

};