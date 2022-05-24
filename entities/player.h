#pragma once
#include "entity.h"
#include "cards/cards.h"
#include <vector>

class player : public entity{
    std::vector<card> ch_playerCards;
public:
    player(std::string type, int health, int mana, std::vector<card> playerCards, int block, int strength)
        : entity(type, health, mana, block, "player", strength), ch_playerCards(playerCards){}
};

struct playerData{
    std::string type;
    int health;
    int mana;
    std::vector<card> startingDeck;
    int block = 0;
    int strength = 0;
};