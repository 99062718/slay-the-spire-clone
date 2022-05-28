#pragma once
#include "cards.h"
#include "battle.h"
#include <string>
#include <array>

std::array<int, 2> getAOIsize(std::string AOIeffect, int id, int teamSize){
    return {(AOIeffect == "all") ? 0 : id, (AOIeffect == "single") ? id : teamSize};
}

void activateCard(int userId, card currentCard, char team, int teamId, int teamSize, battle& currentBattle){
    for (cardEffect currentEffect : currentCard.effects){
        std::array<int, 2> loopSize = getAOIsize(currentEffect.AOIeffect, teamId, teamSize);

        for (int loopNum = loopSize[0]; loopNum < loopSize[1]; loopNum++){
            if (currentEffect.type == "atk"){
                currentBattle.ch_combatants[team][loopNum]
            }
        }
    }
}