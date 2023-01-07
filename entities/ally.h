#pragma once
#include "entity.h"
#include "../general/userInteraction.h"
#include <iostream>

class ally : public entity{
public:
    ally(entityData& data, int entityId)
        : entity(data, entityId){}

    void ai() override {
        std::vector<std::string> cardNames = giveCardNames();
        
        std::cout << ch_type << "'s turn" << std::endl;

        int chosen = playerChoice(cardNames);
    }
};