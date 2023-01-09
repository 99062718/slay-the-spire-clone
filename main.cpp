#include "cards/cards.h"
#include "battle.h"
#include <iostream>

int main(){
    battle test({allMonsters[0]}, {{"test", "", 1, 1, {common[1]}, 0, 0}});

    return 0;
}
