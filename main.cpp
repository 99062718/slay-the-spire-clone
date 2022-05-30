#include "entities/enemy.h"
#include "entities/entity.h"
#include "cards/cards.h"
#include "battle.h"
#include <iostream>
#include <boost/variant/get.hpp>

int main(){
    battle amogus({allMonsters[0]}, {{"mongus", 1, 1, {}, 0, 0}});

    std::cout << boost::get<entity>(amogus.ch_combatants[0]).giveName() << std::endl;

    return 0;
}
