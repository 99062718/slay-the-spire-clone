#pragma once
#include "cards.h"
#include "battle.h"
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
    if (id >= 25) target = !target;
    
    return {(target == 0) ? 0 : 10, (target == 0) ? 10 : 20};
}

void activateCard(int userId, card& currentCard, int teamId, battle& currentBattle){
    if (currentCard.chanceToHit >= hitChance()){
        for (cardEffect currentEffect : currentCard.effects){
            std::array<int, 2> teamSize = getTargetTeam(userId, currentEffect.target);
            std::array<int, 2> loopSize = getAOIsize(currentEffect.AOIeffect, teamId, teamSize);

            for (int loopNum = loopSize[0]; loopNum < loopSize[1]; loopNum++){
                switch (currentEffect.type){
                    case 0: 
                        currentBattle.combatants[loopNum]->takeDamage(currentEffect.value);
                        break;
                    case 1:
                        currentBattle.combatants[loopNum]->heal(currentEffect.value);
                        break;
                }
            }
        }
    } else {
        std::cout << currentCard.name << " has missed!" << std::endl;
    }
}