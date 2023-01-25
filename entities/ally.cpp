#include "entityData.h"
#include "../cards/cardsLogic.h"
#include "../general/userInteraction.h"
#include <iostream>
#include <array>


ally::ally(entityData& data, int entityId)
    : entity(data, entityId){}

void ally::ai(battle& battleInstance, int listSize){
    int currentMana = ch_startingMana;
    std::vector<std::string> cardNames = giveCardNames();
        
    std::cout << ch_type << "'s turn" << std::endl;
    
    while (true){
        int chosenCard = playerChoiceVector(cardNames);

        if (ch_cards[chosenCard].manaCost > currentMana){
            std::cout << ch_cards[chosenCard].name << " costs more mana than you have!" << std::endl;
            continue;
        }

        currentMana -= ch_cards[chosenCard].manaCost;

        for (cardEffect currentEffect : ch_cards[chosenCard].effects){
            std::array<int, 2> loopSize = getTargetTeam(ch_entityId, currentEffect.target);

            int chosenEntity = entityChoiceList(battleInstance, loopSize[0], loopSize[1], currentEffect.displayMode); // need to make sure battle stops here if no entities are printed.

            activateCard(ch_entityId, ch_cards[chosenCard], currentEffect, chosenEntity, loopSize, battleInstance);
        }
    }
}