#include "entities.h"
#include <iostream>

enemy::enemy(entityData& data, int entityId)
    : entity(data, entityId){}

void enemy::ai(std::string entityList[], int listSize){std::cout << "goodbye goodbye" << std::endl;}
