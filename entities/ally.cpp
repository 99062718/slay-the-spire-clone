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

        int chosenEntity = playerChoiceArray(battleInstance.entityNames, loopSize[0], loopSize[1]); //entities wont get correctly chosen if 1 is not on the list but 2 is. 2 will get shown as 1 and 1 will get affected instead of 2.

        chosenEntity += loopSize[0];

        activateCard(ch_entityId, ch_cards[chosenCard], currentEffect, chosenEntity, loopSize, battleInstance);
    }
}