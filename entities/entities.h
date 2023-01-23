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
    int ch_health, ch_maxHealth, ch_mana, ch_block, ch_strength;
    int ch_entityId;
public:    
    entity(entityData& data, int entityId);

    void upBlock(int block);
    void downBlock(int block);

    void takeDamage(int dmg, bool ignoreBlock = false);

    void heal(int toHeal);

    void upStrength(int strength);
    void downStrength(int strength);

    std::string giveName() const;
    int getHealth() const;

    std::vector<std::string> giveCardNames();

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