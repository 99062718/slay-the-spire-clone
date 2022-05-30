#pragma once
#include "entities/enemy.h"
#include "entities/ally.h"
#include <boost/variant/variant.hpp>
#include <array>
#include <vector>
#include <variant>

class battle{
public:
    std::array<boost::variant<ally, enemy>, 50> ch_combatants;

    battle(std::vector<monsterTemplate> enemies, std::vector<allyData> allies){
        for (int loopNum = 0; loopNum < allies.size(); loopNum++){
            allyData currentAlly = allies[loopNum];
            ch_combatants[loopNum] = ally(currentAlly.type, currentAlly.health, currentAlly.mana, currentAlly.startingDeck, currentAlly.block, currentAlly.strength);
        }

        for (int loopNum = 0; loopNum < enemies.size(); loopNum++){
            monsterTemplate currentEnemy = enemies[loopNum];
            ch_combatants[loopNum + 25] = enemy(currentEnemy.name, currentEnemy.health, currentEnemy.mana, currentEnemy.enemyCards, currentEnemy.block, currentEnemy.strength);
        }
    };
};