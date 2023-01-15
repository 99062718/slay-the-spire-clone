#pragma once
#include "../entities/entities.h"
#include <vector>

const int entityListSize = 20;
const int halfListSize = entityListSize/2;

class battle{
public:
    entity* combatants[entityListSize];
    std::string entityNames[entityListSize];

    battle(std::vector<entityData> enemies, std::vector<entityData> allies);

    void initTurn(int id);

    void battleLoop();
};