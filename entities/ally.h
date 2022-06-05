#pragma once
#include "entity.h"
#include "../cards/cards.h"
#include <vector>

class ally : public entity{
public:
    ally(entityData data)
        : entity(data, "ally"){}
};