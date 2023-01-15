#pragma once
#include "../cards/cards.h"
#include <string>
#include <vector>

struct entityData{
    std::string type;
    std::string desc;
    int health;
    int mana;
    std::vector<card> cards;
    int block = 0;
    int strength = 0;
};

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

    std::vector<std::string> giveCardNames();

    virtual void ai(std::string entityList[], int listSize) = 0;
};

class enemy : public entity{
public:
    enemy(entityData& data, int entityId);

    void ai(std::string entityList[], int listSize) override;
};

class ally : public entity{
public:
    ally(entityData& data, int entityId);

    void ai(std::string entityList[], int listSize) override;
};