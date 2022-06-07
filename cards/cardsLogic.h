#pragma once
#include "cards.h"
#include "battle.h"
#include <string>
#include <array>

std::array<int, 2> getAOIsize(std::string AOIeffect, int id, std::array<int, 2> teamSize){
    return {(AOIeffect == "all") ? teamSize[0] : id, (AOIeffect == "single") ? id : teamSize[1]};
}

std::array<int, 2> getTargetTeam(std::string team, bool target){
    if (team == "enemy"){
        target = !(target);
    }
    
    return {(target == 0) ? 0 : 25, (target == 0) ? 25 : 50};
}

void activateCard(int userId, card currentCard, std::string team, int teamId, battle& currentBattle){
    for (cardEffect currentEffect : currentCard.effects){
        std::array<int, 2> teamSize = getTargetTeam(currentBattle.ch_combatants[userId]->ch_team, currentEffect.target);
        std::array<int, 2> loopSize = getAOIsize(currentEffect.AOIeffect, teamId, teamSize);

        for (int loopNum = loopSize[0]; loopNum < loopSize[1]; loopNum++){
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