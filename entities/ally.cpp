#include "entities.h"
#include "../cards/cardsLogic.h"
#include "../general/userInteraction.h"
#include <iostream>
#include <array>


ally::ally(entityData& data, int entityId)
    : entity(data, entityId){}

void ally::ai(std::string entityList[], int listSize){
    std::vector<std::string> cardNames = giveCardNames();
        
    std::cout << ch_type << "'s turn" << std::endl;

    int chosenCard = playerChoiceVector(cardNames);


    for (cardEffect currentEffect : ch_cards[chosenCard].effects){ //currently loops through entire 5 sized list even if it only has 1 effect
        std::array<int, 2> loopSize = getTargetTeam(ch_entityId, currentEffect.target);

        int chosenEntity = playerChoiceArray(entityList, loopSize[0], loopSize[1]);
    }
}