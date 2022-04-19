#include <string>

class enemy{
    std::string ch_type;
    int ch_id;
    int ch_health;
    int ch_mana;
public:
    enemy(std::string type, int id, int health, int mana)
        : ch_type(type), ch_id(id), ch_health(health), ch_mana(mana){}
};