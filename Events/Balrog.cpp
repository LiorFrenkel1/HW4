
#include "Balrog.h"

Balrog::Balrog(int combatPower, int loot, int damage) :
        combatPower(combatPower), loot(loot), damage(damage) {}

int Balrog::calculateCombatPower() const {
    return this->combatPower;
}

int Balrog::calculateLoot() const {
    return this->loot;
}

int Balrog::calculateDamage() const {
    return this->damage;
}

std::string Balrog::getDescription() const {
    return "Balrog (power " + std::to_string(this->calculateCombatPower()) + ", loot "
    + std::to_string(this->calculateLoot()) + ", damage " +
    std::to_string(this->calculateDamage()) + ")";
}

int Balrog::groupSize() const {
    return 1;
}
