#pragma once
#include "entities/enemy.h"
#include "entities/ally.h"
#include "entities/entity.h"
#include <vector>

class battle{
public:
    entity* ch_combatants[50];

    battle(std::vector<entityData> enemies, std::vector<entityData> allies)
        : ch_combatants(){
        for (int loopNum = 0; loopNum < allies.size(); loopNum++){
            entityData currentAlly = allies[loopNum];
            ch_combatants[loopNum] = new ally(currentAlly, loopNum);
        }

        for (int loopNum = 0; loopNum < enemies.size(); loopNum++){
            entityData currentEnemy = enemies[loopNum];
            ch_combatants[loopNum + 25] = new enemy(currentEnemy, loopNum + 25);
        }
    }

    ~battle(){
        for (entity* currentEntity : ch_combatants){
            delete currentEntity;
        }
    }

    void initTurn(char id){
        if (ch_combatants[id] != nullptr) ch_combatants[id]->ai();
    }

    void battleLoop(){
        bool ongoing = 1;
        char idTurn = 0;
        while (ongoing){
            initTurn(idTurn);

            idTurn += 25;

            initTurn(idTurn);

            idTurn -= (idTurn == 49) ? 49 : 24;
        }
    }
};