
#include "Monster.h"

std::string Monster::event(Player& player) {
    return player.encounter(this->calculateCombatPower(),
                                  this->calculateLoot(), this->calculateDamage());
}
