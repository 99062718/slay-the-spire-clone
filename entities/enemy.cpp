#include "entityData.h"
#include "../general/battle.h"
#include <iostream>

enemy::enemy(entityData& data, int entityId)
    : entity(data, entityId){}

void enemy::ai(battle& battleInstance, int listSize){std::cout << "goodbye goodbye" << std::endl;} // maybe some kind of lookup system that does ai based on entities type?
