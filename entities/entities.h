#pragma once
#include "../cards/cards.h"
#include "entityData.h"
#include <string>
#include <vector>

class battle;
class entity{
protected:
    const std::string ch_type;
    std::vector<card> ch_cards;
    int ch_entityId, ch_maxHealth;
public:    
    int ch_health, ch_mana, ch_block, ch_strength;

    entity(entityData& data, int entityId);

    void upStat(int& stat, int value, int max = 99999);
    void downStat(int& stat, int value, int min = -99999);
    void takeDamage(int dmg, bool ignoreBlock = false);

    std::string giveName() const;
    int getMaxHealth() const;
    std::vector<std::string> giveCardNames() const;

    virtual void ai(battle& battleInstance, int listSize) = 0;
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