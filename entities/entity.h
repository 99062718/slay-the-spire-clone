#pragma once
#include <string>

class entity{
protected:
    std::string ch_type;
    int ch_health;
    int ch_maxHealth;
    int ch_mana;
    int ch_block;
    std::string ch_team;
    int ch_strength = 0;
public:
    entity(std::string type, int health, int mana, int block, std::string team)
        : ch_type(type), ch_health(health), ch_mana(mana), ch_block(block), ch_team(team){ch_maxHealth = ch_health;}

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
};