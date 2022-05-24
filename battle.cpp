#include "entities/enemy.h"
#include <vector>

class battle{
public:
    std::vector<monsterTemplate> ch_enemies;

    battle(std::vector<monsterTemplate> enemies):
        ch_enemies(enemies){};
};