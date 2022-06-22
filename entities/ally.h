#pragma once
#include "entity.h"
#include <iostream>

class ally : public entity{
public:
    ally(entityData& data, char entityId)
        : entity(data, entityId){}

    void ai() override {std::cout << "hello hello" << std::endl;}
};