
#include "Slime.h"

Slime::Slime(int combatPower, int loot, int damage) :
        combatPower(combatPower), loot(loot), damage(damage){}

int Slime::calculateCombatPower() const {
    return this->combatPower;
}

int Slime::calculateLoot() const {
    return this->loot;
}

int Slime::calculateDamage() const {
    return this->damage;
};
