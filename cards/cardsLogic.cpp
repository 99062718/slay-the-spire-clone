#include "cards.h"
#include "cardsLogic.h"
#include <array>
#include <random>
#include <functional>
#include <iostream>

std::string cardTypeNames[2] = {"attack", "heal"};
std::default_random_engine hitChanceGen;
std::uniform_int_distribution<> hitChanceDistrubution(1, 100);
auto hitChance = std::bind(hitChanceDistrubution, hitChanceGen);

std::array<int, 2> getAOIsize(int AOIeffect, int id, std::array<int, 2> teamSize){
    return {(AOIeffect == 0) ? teamSize[0] : id + teamSize[0], (AOIeffect == 2) ? id + teamSize[0] : teamSize[1]};
}

std::array<int, 2> getTargetTeam(int id, bool target){
    if (id >= 10) target = !target;
    
    return {(target == 0) ? 0 : 10, (target == 0) ? 10 : 20};
}

void activateCard(int userId, card& currentCard, cardEffect& currentEffect, int teamId, std::array<int, 2> loopSize, battle& currentBattle){
    if (currentEffect.chanceToHit >= hitChance()){
        std::array<int, 2> AOIsize = getAOIsize(currentEffect.AOIeffect, teamId, loopSize);

        for (int loopNum = AOIsize[0]; loopNum < AOIsize[1]; loopNum++){
            if (currentBattle.combatants[loopNum] != nullptr){
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
        std::cout << currentCard.name << "'s " << cardTypeNames[currentEffect.type] << " has failed!" << std::endl;
    }
}