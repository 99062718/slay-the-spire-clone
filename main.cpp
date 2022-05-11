#include "enemy.h"
#include "cards.h"
#include <iostream>

int main(){
    enemy monster(allMonsters[0].name, allMonsters[0].health, allMonsters[0].mana, allMonsters[0].enemyCards, 5);

    monster.takeDamage(4);

    return 0;
}
