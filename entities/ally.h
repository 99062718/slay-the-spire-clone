#pragma once
#include "entity.h"

class ally : public entity{
public:
    ally(entityData data)
        : entity(data, "ally"){}
};