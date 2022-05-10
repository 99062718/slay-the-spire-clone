#pragma once
#include "cards.h"
#include <string>
#include <array>

std::array<int, 2> getAOIsize(std::string AOIeffect, int id, int teamSize){
    if (AOIeffect == "single"){
        return {id, id};
    } else if (AOIeffect == "all"){
        return {0, teamSize};
    } else{
        return {id, teamSize};
    }
}

void activateCard(card currentCard, std::string team, int teamId, int teamSize){
    for (cardEffect currentEffect : currentCard.effects){
        std::array<int, 2> loopSize = getAOIsize(currentEffect.AOIeffect, teamId, teamSize);

        for (int loopNum = loopSize[0]; loopNum < loopSize[1]; loopNum++){
            if (currentEffect.type == "atk"){
                // no enemy interaction logic yet
            }
        }
    }
}