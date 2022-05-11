#pragma once
#include "entity.h"
#include "cards/cards.h"
#include <vector>

class player : public entity{
    std::vector<card> ch_playerCards;
public:
    player(std::string type, int health, int mana, std::vector<card> playerCards, int block = 0)
        : entity(type, health, mana, block, "player"), ch_playerCards(playerCards){}
};

card startingDeck[1] = {
    // insert some starting decks here. Should 
}