#pragma once
#include "../entities/entities.h"
#include <vector>
#include <array>


// maybe add these to battle class itself so they can also be changed on battle init
const int entityListSize = 20;
const int halfListSize = entityListSize/2;

class battle{
    std::array<int, 2> amountAlive = {0, 0};
public:
    entity* combatants[entityListSize];
    std::string entityNames[entityListSize];

    battle(std::vector<entityData> enemies, std::vector<entityData> allies);

    void upAlive(int id);
    void downAlive(int id);

    void initBattle();
    void initTurn(int id);

    bool battleLoop();
};