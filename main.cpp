#include "general/battle.h"
#include "entities/entityData.h"
#include <iostream>

int main(){
    battle test({allMonsters[0]}, {{"test", "", 10, 1, {&common[1]}, 0, 0, 3}});
    test.initBattle();

    return 0;
}