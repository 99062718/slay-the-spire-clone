#pragma once
#include "entities/enemy.h"
#include "entities/ally.h"
#include <vector>
#include <variant>

class battle{
public:
    std::vector<std::variant<std::vector<ally>, std::vector<enemy>>> ch_combatants;

    battle(std::vector<monsterTemplate> enemies, std::vector<allyData> allies){
        for (monsterTemplate currentEnemy : enemies){
            ch_combatants[1]->pushback(enemy(currentEnemy.name, currentEnemy.health, currentEnemy.mana, currentEnemy.enemyCards, currentEnemy.block, currentEnemy.strength));
        }
    };
};