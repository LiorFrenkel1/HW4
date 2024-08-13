
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

string Slime::getDescription() const {
    return "Slime (power " + std::to_string(this->calculateCombatPower()) + ", loot "
           + std::to_string(this->calculateLoot()) + ", damage " +
           std::to_string(this->calculateDamage()) + ")";
}

int Slime::groupSize() const {
    return 1;
}

void Slime::addCombatPower(int addPower) {}
