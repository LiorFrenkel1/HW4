
#include "Monster.h"

void Monster::event(MatamStory& game) {
    game.currentPlayer->encounter(this->calculateCombatPower(),
                                  this->calculateLoot(), this->calculateDamage());
}
