
#include "Monster.h"

std::string Monster::event(Player& player) {
    string str = player.encounter(this->calculateCombatPower(),
                                  this->calculateLoot(), this->calculateDamage());
    this->addCombatPower(2);
    return str;
}
