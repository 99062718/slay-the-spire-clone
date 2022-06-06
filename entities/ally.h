#pragma once
#include "entity.h"
#include <iostream>

class ally : public entity{
public:
    ally(entityData data)
        : entity(data, "ally"){}

    void ai(){std::cout << "hello hello" << std::endl;}
};