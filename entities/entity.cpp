#include "entities.h"
#include "../general/battle.h"

entity::entity(entityData& data, int entityId)
    : ch_type(data.type), ch_cards(data.cards), ch_health(data.health), ch_mana(data.mana), ch_block(data.block), ch_strength(data.strength), ch_entityId(entityId){ch_maxHealth = ch_health;}

void entity::upBlock(int block){ch_block += block;}
void entity::downBlock(int block){ch_block = ((ch_block - block) < 0) ? 0 : ch_block - block;}

void entity::takeDamage(int dmg, bool ignoreBlock){
    if (ignoreBlock){
        ch_health -= dmg;
    } else {
        int totalDamage = dmg - ch_block;
        downBlock(dmg);
        ch_health -= (totalDamage < 1) ? 0 : totalDamage;
    }
}

void entity::heal(int toHeal){ch_health = ((ch_health + toHeal) > ch_maxHealth) ? ch_maxHealth : ch_health + toHeal;}

void entity::upStrength(int strength){ch_strength += strength;}
void entity::downStrength(int strength){ch_strength -= strength;}

std::string entity::giveName() const {return ch_type;}
int entity::getHealth() const {return ch_health;}
int entity::getMaxHealth() const {return ch_maxHealth;}

std::vector<std::string> entity::giveCardNames() const{
    std::vector<std::string> cardNames;
        
    for(int x = 0; x < ch_cards.size(); x++){
        cardNames.push_back(ch_cards[x].name);
    }

    return cardNames;
}
