#pragma once
#include "cards.h"
#include "../general/battle.h"
#include <array>
#include <random>
#include <functional>
#include <iostream>

std::default_random_engine hitChanceGen;
std::uniform_int_distribution hitChanceDistrubution(1, 100);
auto hitChance = std::bind(hitChanceDistrubution, hitChanceGen);

std::array<int, 2> getAOIsize(int AOIeffect, int id, std::array<int, 2> teamSize){
    return {(AOIeffect == 0) ? teamSize[0] : id + teamSize[0], (AOIeffect == 2) ? id + teamSize[0] : teamSize[1]};
}

std::array<int, 2> getTargetTeam(int id, bool target){
    if (id >= 10) target = !target;
    
    return {(target == 0) ? 0 : 10, (target == 0) ? 10 : 20};
}

void activateCard(int userId, card& currentCard, int currentEffect, int teamId, battle& currentBattle){
    if (currentCard.effects[currentEffect].chanceToHit >= hitChance()){
        std::array<int, 2> teamSize = getTargetTeam(userId, currentCard.effects[currentEffect].target);
        std::array<int, 2> loopSize = getAOIsize(currentCard.effects[currentEffect].AOIeffect, teamId, teamSize);

        for (int loopNum = loopSize[0]; loopNum < loopSize[1]; loopNum++){
            switch (currentCard.effects[currentEffect].type){
                case 0: 
                    currentBattle.combatants[loopNum]->takeDamage(currentCard.effects[currentEffect].value);
                    break;
                case 1:
                    currentBattle.combatants[loopNum]->heal(currentCard.effects[currentEffect].value);
                    break;
            }
        }
    } else {
        std::cout << currentCard.name << "'s " << cardTypeNames[currentCard.effects[currentEffect].type] << " has failed!" << std::endl;
    }
}