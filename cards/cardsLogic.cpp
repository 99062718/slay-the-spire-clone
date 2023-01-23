#include "cards.h"
#include "cardsLogic.h"
#include <array>
#include <random>
#include <functional>
#include <iostream>

std::string cardTypeNames[7] = {"attack", "heal", "block", "fragile", "strength", "weak", "revive"};
std::default_random_engine hitChanceGen;
std::uniform_int_distribution<> hitChanceDistrubution(1, 100);
auto hitChance = std::bind(hitChanceDistrubution, hitChanceGen);

std::array<int, 2> getAOIsize(int AOIeffect, int id, std::array<int, 2> teamSize){
    switch (AOIeffect){
        case 0:
            return teamSize;
            break;
        case 1:
            return {id, teamSize[1]};
            break;
        case 2:
            return {id, id};
            break;
        default:
            throw std::invalid_argument("AOIeffect of " + std::to_string(AOIeffect) + " is not possible");
    }
}

std::array<int, 2> getTargetTeam(int id, bool target){
    if (id >= 10) target = !target;
    
    return {(target == 0) ? 0 : 10, (target == 0) ? 10 : 20};
}

void activateCard(int userId, card& currentCard, cardEffect& currentEffect, int teamId, std::array<int, 2> loopSize, battle& currentBattle){
    if (currentEffect.chanceToHit >= hitChance()){
        std::array<int, 2> AOIsize = getAOIsize(currentEffect.AOIeffect, teamId, loopSize);
        int loopNum = AOIsize[0];

        do{
            if (currentBattle.combatants[loopNum] != nullptr){
                if (currentEffect.displayMode == 1 || currentEffect.displayMode == 2){
                    switch (currentEffect.type){
                        // should have card effects that get played regardless of if entity is alive or not.
                        case 6:
                            currentBattle.combatants[loopNum]->heal(currentBattle.combatants[loopNum]->getMaxHealth() * (currentEffect.value / 100));
                            break;
                        default:
                            throw std::invalid_argument("cardEffect type of " + std::to_string(currentEffect.type) + " is not possible");
                            break;
                    }
                }
                
                if (currentBattle.combatants[loopNum]->getHealth() != 0 || currentEffect.displayMode == 2){
                    switch (currentEffect.type){
                        case 0: 
                            currentBattle.combatants[loopNum]->takeDamage(currentEffect.value);
                            break;
                        case 1:
                            currentBattle.combatants[loopNum]->heal(currentEffect.value);
                            break;
                        case 2:
                            currentBattle.combatants[loopNum]->upBlock(currentEffect.value);
                            break;
                        case 3:
                            currentBattle.combatants[loopNum]->downBlock(currentEffect.value);
                            break;
                        case 4:
                            currentBattle.combatants[loopNum]->upStrength(currentEffect.value);
                            break;
                        case 5:
                            currentBattle.combatants[loopNum]->downStrength(currentEffect.value);
                            break;
                        default:
                            throw std::invalid_argument("cardEffect type of " + std::to_string(currentEffect.type) + " is not possible");
                            break;
                    }
                }
            }
            loopNum++;
        } while (loopNum < AOIsize[1]);
    } else {
        std::cout << currentCard.name << "'s " << cardTypeNames[currentEffect.type] << " has failed!" << std::endl;
    }
}