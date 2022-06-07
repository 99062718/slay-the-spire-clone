#pragma once
#include "entity.h"
#include <iostream>

class enemy : public entity{
public:
    enemy(entityData data, char entityId)
        : entity(data, entityId){}

    void ai(){std::cout << "goodbye goodbye" << std::endl;}
};

entityData allMonsters[1] = {
    {"Skeleton", "The skeleton appears", 20, 3, {common[1]}}
};
