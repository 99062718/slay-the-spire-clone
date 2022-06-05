#pragma once
#include "../cards/cards.h"
#include "entity.h"
#include <vector>

class enemy : public entity{
public:
    enemy(entityData data)
        : entity(data, "enemy"){}
};

entityData allMonsters[1] = {
    {"Skeleton", "The skeleton appears", 20, 3, {common[1]}}
};
