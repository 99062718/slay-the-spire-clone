#pragma once
#include "entities/enemy.h"
#include "entities/ally.h"
#include "entities/entity.h"
#include <vector>

class battle{
public:
    entity* ch_combatants[50];

    battle(std::vector<monsterTemplate> enemies, std::vector<allyData> allies){
        for (int loopNum = 0; loopNum < allies.size(); loopNum++){
            allyData currentAlly = allies[loopNum];
            ch_combatants[loopNum] = new ally(currentAlly.type, currentAlly.health, currentAlly.startingDeck, currentAlly.mana, currentAlly.block, currentAlly.strength);
        }

        for (int loopNum = 0; loopNum < enemies.size(); loopNum++){
            monsterTemplate currentEnemy = enemies[loopNum];
            ch_combatants[loopNum + 25] = new enemy(currentEnemy.name, currentEnemy.health, currentEnemy.enemyCards, currentEnemy.mana, currentEnemy.block, currentEnemy.strength);
        }
    };
};