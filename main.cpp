#include "general/battle.h"
#include "entities/entityData.h"
#include <iostream>

int main(){
    battle test({allMonsters[0], allMonsters[1]}, {{"test", "", 1, 1, {common[1]}, 0, 0}});

    return 0;
}
