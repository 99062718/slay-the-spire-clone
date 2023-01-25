#include "battle.h"
#include <iostream>

battle::battle(std::vector<entityData> enemies, std::vector<entityData> allies)
    : combatants(){
    for (int loopNum = 0; loopNum < allies.size(); loopNum++){
        entityData currentAlly = allies[loopNum];
        combatants[loopNum] = new ally(currentAlly, loopNum);
        entityNames[loopNum] = currentAlly.type;
        amountAlive[0]++;
    }

    for (int loopNum = 0; loopNum < enemies.size(); loopNum++){
        entityData currentEnemy = enemies[loopNum];
        combatants[loopNum + halfListSize] = new enemy(currentEnemy, loopNum + halfListSize);
        entityNames[loopNum + halfListSize] = currentEnemy.type;
        amountAlive[1]++;
    }
}

void battle::upAlive(int id){amountAlive[(id >= halfListSize) ? 1 : 0]++;}
void battle::downAlive(int id){amountAlive[(id >= halfListSize) ? 1 : 0]--;}

void battle::initBattle(){
    bool result = battleLoop();

    if (result){
        // should have xp gained and stuff here
        std::cout << "You have won!";
        return;
    }
    std::cout << "You have lost!";
    exit(1);
}

void battle::initTurn(int id){
    if (combatants[id] != nullptr && combatants[id]->ch_health > 0) combatants[id]->ai(*this, entityListSize);
}

bool battle::battleLoop(){
    int idTurn = 0;
    while (true){ // maybe sort by entity speed?
        initTurn(idTurn);

        idTurn += halfListSize;

        initTurn(idTurn);

        idTurn -= (idTurn == entityListSize - 1) ? entityListSize - 1 : halfListSize - 1;

        if (amountAlive[0] == 0 || amountAlive[1] == 0) return (amountAlive[0] == 0) ? false : true;
    }
}