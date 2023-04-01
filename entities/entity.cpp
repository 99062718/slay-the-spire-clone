#include "entities.h"
#include "../general/battle.h"

entity::entity(entityData& data, int entityId)
    : ch_type(data.type), ch_cards(data.cards), ch_health(data.health), ch_startingMana(data.startingMana), ch_block(data.block), ch_strength(data.strength), ch_drawDefault(ch_drawDefault), ch_entityId(entityId){
        ch_maxHealth = ch_health;
        ch_drawAmount = ch_drawDefault;
    }

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

std::vector<std::string> entity::giveCardNames(std::vector<const card*> &cardList) const{
    std::vector<std::string> cardNames;
    cardNames.reserve(cardList.size());
        
    for(int x = 0; x < cardList.size(); x++){
        cardNames.emplace_back((*cardList[x]).name + " - cost: " + std::to_string((*cardList[x]).manaCost));
    }

    return cardNames;
}

void entity::addToHand(int amount){
    ch_hand.reserve(amount);

    for (int x = 0; x < amount; x++) {
        ch_hand.emplace_back(ch_cards[ch_currentInDeck]);
        ch_currentInDeck = (ch_currentInDeck == ch_cards.size()) ? 0 : ch_currentInDeck++;
    }
}

void entity::resetHand(){
    ch_hand = std::vector<const card*>();
    addToHand(ch_drawAmount);
}