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
    std::string ch_type;
    std::vector<card> ch_cards;
    int ch_health;
    int ch_maxHealth;
    int ch_mana;
    int ch_block;
    std::string ch_team;
    int ch_strength;
public:    
    entity(entityData data, std::string team)
        : ch_type(data.type), ch_health(data.health), ch_cards(data.cards), ch_mana(data.mana), ch_block(data.block), ch_strength(data.strength), ch_team(team){ch_maxHealth = ch_health;}

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

    std::string giveName(){
        return ch_type;
    }
};