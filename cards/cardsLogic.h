#pragma once
#include "cards.h"
#include "battle.h"
#include <array>
#include <random>
#include <functional>

std::default_random_engine hitChanceGen;
std::uniform_int_distribution hitChanceDistrubution(1, 100);
auto hitChance = std::bind(hitChanceDistrubution, hitChanceGen);

std::array<char, 2> getAOIsize(char AOIeffect, char id, std::array<char, 2> teamSize){
    return {(AOIeffect == 0) ? teamSize[0] : id + teamSize[0], (AOIeffect == 2) ? id + teamSize[0] : teamSize[1]};
}

std::array<char, 2> getTargetTeam(char id, bool target){
    if (id >= 25) target = !target;
    
    return {(target == 0) ? 0 : 25, (target == 0) ? 25 : 50};
}

void activateCard(char userId, card& currentCard, char teamId, battle& currentBattle){
    if (currentCard.chanceToHit >= hitChance()){
        for (cardEffect currentEffect : currentCard.effects){
            std::array<char, 2> teamSize = getTargetTeam(userId, currentEffect.target);
            std::array<char, 2> loopSize = getAOIsize(currentEffect.AOIeffect, teamId, teamSize);

            for (char loopNum = loopSize[0]; loopNum < loopSize[1]; loopNum++){
                switch (currentEffect.type){
                    case 0: 
                        currentBattle.ch_combatants[loopNum]->takeDamage(currentEffect.value);
                        break;
                    case 1:
                        currentBattle.ch_combatants[loopNum]->heal(currentEffect.value);
                        break;
                }
            }
        }
    }
}