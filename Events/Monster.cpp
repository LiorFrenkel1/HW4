
#include "Monster.h"

std::string Monster::event(MatamStory& game) {
    return game.currentPlayer->encounter(this->calculateCombatPower(),
                                  this->calculateLoot(), this->calculateDamage());
}
