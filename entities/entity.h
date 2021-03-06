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
private:
    const std::string ch_type;
    std::vector<card> ch_cards;
    int ch_health, ch_maxHealth, ch_mana, ch_block, ch_strength;
    char ch_entityId;
public:    
    entity(entityData& data, char entityId)
        : ch_type(data.type), ch_cards(data.cards), ch_health(data.health), ch_mana(data.mana), ch_block(data.block), ch_strength(data.strength), ch_entityId(entityId){ch_maxHealth = ch_health;}

    void upBlock(int block){ch_block += block;}
    void downBlock(int block){ch_block = ((ch_block - block) < 0) ? 0 : ch_block - block;}

    void takeDamage(int dmg, bool ignoreBlock = false){
        if (ignoreBlock){
            ch_health -= dmg;
        } else {
            int totalDamage = dmg - ch_block;
            downBlock(dmg);
            ch_health -= (totalDamage < 1) ? 0 : totalDamage;
        }
    }

    void heal(int toHeal){ch_health = ((ch_health + toHeal) > ch_maxHealth) ? ch_maxHealth : ch_health + toHeal;}

    void upStrength(int strength){ch_strength += strength;}
    void downStrength(int strength){ch_strength -= strength;}

    std::string giveName() const {
        return ch_type;
    }

    virtual void ai() = 0;
};