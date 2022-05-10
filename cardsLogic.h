#pragma once
#include "cards.h"
#include <string>
#include <array>

std::array<int, 2> getAOIsize(std::string AOIeffect, int id, int teamSize){
    if (AOIeffect == "single"){
        return {id, id};
    } else if (AOIeffect == "all"){
        return {1, teamSize};
    } else{
        return {id, teamSize};
    }
}

void activateCard(card currentCard, std::string team, int teamId, int teamSize){
    for (int currentEffect = 0; currentEffect < std::size(currentCard.effects); currentEffect++){
        getAOIsize(currentCard.effects[currentEffect].AOIeffect, teamId, teamSize);
    }
}