#pragma once
#include "entity.h"

class enemy : public entity{
public:
    enemy(entityData data)
        : entity(data, "enemy"){}

    void ai(){}
};

entityData allMonsters[1] = {
    {"Skeleton", "The skeleton appears", 20, 3, {common[1]}}
};
