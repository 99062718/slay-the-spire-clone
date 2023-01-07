#pragma once
#include "entity.h"
#include <iostream>

class enemy : public entity{
public:
    enemy(entityData& data, int entityId)
        : entity(data, entityId){}

    void ai() override {std::cout << "goodbye goodbye" << std::endl;}
};

const entityData allMonsters[1] = {
    {"Skeleton", "The skeleton appears", 20, 3, {common[1]}}
};
