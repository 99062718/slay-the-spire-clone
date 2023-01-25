#include "entities.h"
#include "../general/battle.h"

entity::entity(entityData& data, int entityId)
    : ch_type(data.type), ch_cards(data.cards), ch_health(data.health), ch_startingMana(data.startingMana), ch_block(data.block), ch_strength(data.strength), ch_entityId(entityId){ch_maxHealth = ch_health;}

void entity::upStat(int& stat, int value, int max){stat = ((stat - value) > max) ? max : stat + value;}
void entity::downStat(int& stat, int value, int min){stat = ((stat - value) < min) ? min : stat - value;}

void entity::takeDamage(int dmg, bool ignoreBlock){
    int totalDamage = dmg;
    if (!ignoreBlock){
        totalDamage = dmg - ch_block;
        downStat(ch_block, dmg, 0);
    }
    downStat(ch_health, totalDamage, 0);
}

std::string entity::giveName() const {return ch_type;}
int entity::getMaxHealth() const {return ch_maxHealth;}

std::vector<std::string> entity::giveCardNames() const{
    std::vector<std::string> cardNames;
        
    for(int x = 0; x < ch_cards.size(); x++){
        cardNames.push_back(ch_cards[x].name + " - cost: " + std::to_string(ch_cards[x].manaCost));
    }

    return cardNames;
}
