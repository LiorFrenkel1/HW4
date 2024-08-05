
#pragma once

#include "Balrog.h"

Balrog::Balrog(int combatPower, int loot, int damage) :
        combatPower(combatPower), loot(loot), damage(damage){}

int Balrog::calculateCombatPower() const {
    return this->combatPower;
}

int Balrog::calculateLoot() const {
    return this->loot;
}

int Balrog::calculateDamage() const {
    return this->damage;
};
