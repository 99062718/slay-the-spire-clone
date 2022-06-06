#include "cards/cards.h"
#include "battle.h"
#include <iostream>

int main(){
    battle test({allMonsters[0]}, {{"test", "", 1, 1, {common[1]}, 0, 0}});

    std::cout << test.ch_combatants[0]->giveName() << std::endl;

    test.ch_combatants[25]->ai();

    return 0;
}
