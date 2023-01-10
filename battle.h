#pragma once
#include "entities/enemy.h"
#include "entities/ally.h"
#include "entities/entity.h"
#include <vector>

const int entityListSize = 20;
const int halfListSize = entityListSize/2;

class battle{
public:
    entity* combatants[entityListSize];
    std::string entityNames[entityListSize];

    battle(std::vector<entityData> enemies, std::vector<entityData> allies)
        : combatants(){
        for (int loopNum = 0; loopNum < allies.size(); loopNum++){
            entityData currentAlly = allies[loopNum];
            combatants[loopNum] = new ally(currentAlly, loopNum);
            entityNames[loopNum] = currentAlly.type;
        }

        for (int loopNum = 0; loopNum < enemies.size(); loopNum++){
            entityData currentEnemy = enemies[loopNum];
            combatants[loopNum + halfListSize] = new enemy(currentEnemy, loopNum + halfListSize);
            entityNames[loopNum + halfListSize] = currentEnemy.type;
        }

        battleLoop();
    }

    ~battle(){
        for (entity* currentEntity : combatants){
            delete currentEntity;
        }
    }

    void initTurn(int id){
        if (combatants[id] != nullptr) combatants[id]->ai(entityNames, entityListSize);
    }

    void battleLoop(){
        bool ongoing = true;
        int idTurn = 0;
        while (ongoing){
            initTurn(idTurn);

            idTurn += halfListSize;

            initTurn(idTurn);

            idTurn -= (idTurn == entityListSize - 1) ? entityListSize - 1 : halfListSize - 1;
        }
    }
};