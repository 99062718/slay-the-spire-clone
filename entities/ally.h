#pragma once
#include "entity.h"
#include "../general/userInteraction.h"
#include "../cards/cardsLogic.h"
#include <iostream>
#include <array>

class ally : public entity{
public:
    ally(entityData& data, int entityId)
        : entity(data, entityId){}

    void ai(std::string entityList[], int listSize) override {
        std::vector<std::string> cardNames = giveCardNames();
        
        std::cout << ch_type << "'s turn" << std::endl;

        int chosenCard = playerChoiceVector(cardNames);


        for (cardEffect currentEffect : ch_cards[chosenCard].effects){
            std::array<int, 2> loopSize = getTargetTeam(ch_entityId, currentEffect.target);

            int chosenEntity = playerChoiceArray(entityList, loopSize[0], loopSize[1]);
        }
    }
};