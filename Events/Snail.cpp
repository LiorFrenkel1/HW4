
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

string Snail::getDescription() const {
    return "Snail (power " + std::to_string(this->calculateCombatPower()) + ", loot "
           + std::to_string(this->calculateLoot()) + ", damage " +
           std::to_string(this->calculateDamage()) + ")";
}

int Snail::groupSize() const {
    return 1;
};
