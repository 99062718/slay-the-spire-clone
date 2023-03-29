#pragma once
#include "../cards/cards.h"
#include "entityData.h"
#include <string>
#include <vector>

class battle;
class entity{
protected: // add speed, level, xp?
    const std::string ch_type;
    std::vector<const card*> ch_cards, ch_hand;
    int ch_entityId, ch_maxHealth;
    int ch_currentInDeck = 0;
public:    
    int ch_health, ch_startingMana, ch_block, ch_strength;

    entity(entityData& data, int entityId);

    void upStat(int& stat, int value, int max = 99999);
    void downStat(int& stat, int value, int min = -99999);
    void takeDamage(int dmg, bool ignoreBlock = false);

    std::string giveName() const;
    int getMaxHealth() const;
    std::vector<std::string> giveCardNames(std::vector<const card*> &cardList) const;

    virtual void ai(battle& battleInstance, int listSize) = 0;

    void addToHand(int amount);
};

class enemy : public entity{
public:
    enemy(entityData& data, int entityId);

    void ai(battle& battleInstance, int listSize) override;
};

class ally : public entity{
public:
    ally(entityData& data, int entityId);

    void ai(battle& battleInstance, int listSize) override;
};