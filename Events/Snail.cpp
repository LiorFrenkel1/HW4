
#include "Snail.h"

Snail::Snail(int combatPower, int loot, int damage) :
        combatPower(combatPower), loot(loot), damage(damage){}

int Snail::calculateCombatPower() const {
    return this->combatPower;
}

int Snail::calculateLoot() const {
    return this->loot;
}

int Snail::calculateDamage() const {
    return this->damage;
};
