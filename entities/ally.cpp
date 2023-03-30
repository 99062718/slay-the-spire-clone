#include "entityData.h"
#include "../cards/cardsLogic.h"
#include "../general/userInteraction.h"
#include <iostream>
#include <array>


ally::ally(entityData& data, int entityId)
    : entity(data, entityId){}

void ally::ai(battle& battleInstance, int listSize){
    resetHand();
    int currentMana = ch_startingMana;
        
    std::cout << ch_type << "'s turn" << std::endl;
    
    while (true){
        if (battleInstance.amountAlive[1] == 0) return;

        std::vector<std::string> cardNames = giveCardNames(ch_hand);

        std::cout << "current mana : " << currentMana << std::endl;

        int chosenCard = playerChoiceVector(cardNames, "end turn", -1);

        if (chosenCard == -1) break;

        if ((*ch_hand[chosenCard]).manaCost > currentMana){
            std::cout << (*ch_hand[chosenCard]).name << " costs more mana than you have!" << std::endl;
            continue;
        }

        currentMana -= (*ch_hand[chosenCard]).manaCost;

        for (cardEffect currentEffect : (*ch_hand[chosenCard]).effects){
            if (battleInstance.amountAlive[1] == 0) return;

            std::array<int, 2> loopSize = getTargetTeam(ch_entityId, currentEffect.target);

            int chosenEntity = entityChoiceList(battleInstance, loopSize[0], loopSize[1], currentEffect.displayMode); 

            activateCard(ch_entityId, ch_hand[chosenCard], currentEffect, chosenEntity, loopSize, battleInstance);
        }
    }
}