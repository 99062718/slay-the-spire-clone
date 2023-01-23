#include "entityData.h"
#include "../cards/cardsLogic.h"
#include "../general/userInteraction.h"
#include <iostream>
#include <array>


ally::ally(entityData& data, int entityId)
    : entity(data, entityId){}

void ally::ai(battle& battleInstance, int listSize){
    std::vector<std::string> cardNames = giveCardNames();
        
    std::cout << ch_type << "'s turn" << std::endl;

    int chosenCard = playerChoiceVector(cardNames);

    for (cardEffect currentEffect : ch_cards[chosenCard].effects){
        std::array<int, 2> loopSize = getTargetTeam(ch_entityId, currentEffect.target);

        int chosenEntity = entityChoiceList(battleInstance, loopSize[0], loopSize[1], currentEffect.displayMode);

        activateCard(ch_entityId, ch_cards[chosenCard], currentEffect, chosenEntity, loopSize, battleInstance);
    }
}