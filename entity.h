#pragma once
#include <string>

class entity{
protected:
    std::string ch_type;
    int ch_health;
    int ch_maxHealth;
    int ch_mana;
    int ch_block;
public:
    entity(std::string type, int health, int mana, int block = 0)
        : ch_type(type), ch_health(health), ch_mana(mana), ch_block(block){ch_maxHealth = ch_health;}

    void takeDamage(int dmg, bool ignoreBlock = false){
        if (ignoreBlock){
            ch_health -= dmg;
        } else {
            int totalDamage = dmg - ch_block;
            ch_health -= (totalDamage < 1) ? 0 : totalDamage;
        }
    }

    void heal(int toHeal){
        ch_health = ((ch_health + toHeal) > ch_maxHealth) ? ch_maxHealth : ch_health + toHeal;
    }
};