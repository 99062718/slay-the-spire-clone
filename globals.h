#pragma once
#include <vector>
#include <string>

struct card{
    std::string type;
    std::string name;
    std::string rarity;
    int dmg = 0;
};

extern std::vector<card> common;
extern std::vector<card> uncommon;
extern std::vector<card> legendary;
extern std::vector<card> boss;
extern std::vector<card> lunar;