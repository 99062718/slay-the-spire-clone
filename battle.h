#pragma once
#include "entities/enemy.h"
#include "entities/ally.h"
#include "entities/entity.h"
#include <vector>

class battle{
public:
    entity* ch_combatants[50];

    battle(std::vector<monsterTemplate> enemies, std::vector<allyData> allies)
        : ch_combatants(){
        for (int loopNum = 0; loopNum < allies.size(); loopNum++){
            allyData currentAlly = allies[loopNum];
            ch_combatants[loopNum] = new ally(currentAlly);
        }

        for (int loopNum = 0; loopNum < enemies.size(); loopNum++){
            monsterTemplate currentEnemy = enemies[loopNum];
            ch_combatants[loopNum + 25] = new enemy(currentEnemy);
        }
    }

    ~battle(){
        for (entity* currentEntity : ch_combatants){
            delete currentEntity;
        }
    }
};