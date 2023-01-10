#pragma once
#include "entity.h"
#include "../general/userInteraction.h"
#include <iostream>

class ally : public entity{
public:
    ally(entityData& data, int entityId)
        : entity(data, entityId){}

    void ai(std::string entityList[], int listSize) override {
        int startPoint = 0;

        std::vector<std::string> cardNames = giveCardNames();
        
        std::cout << ch_type << "'s turn" << std::endl;

        int chosenCard = playerChoiceVector(cardNames);

        int chosenEntity = playerChoiceArray(entityList, listSize, startPoint);
    }
};