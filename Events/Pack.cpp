
#include "Pack.h"

Pack::Pack() : monsters(std::vector<std::shared_ptr<Monster>>()) {}

void Pack::addToPack(std::shared_ptr<Monster>& monster) {
    this->monsters.push_back(monster);
}

int Pack::calculateCombatPower() const {
    int sum = 0;
    for (const std::shared_ptr<Monster>& m: this->monsters) {
        sum += m->calculateCombatPower();
    }
    return sum;
}

int Pack::calculateLoot() const {
    int sum = 0;
    for (const std::shared_ptr<Monster>& m : this->monsters) {
        sum += m->calculateLoot();
    }
    return sum;
}

int Pack::calculateDamage() const {
    int sum = 0;
    for (const std::shared_ptr<Monster>& m : this->monsters) {
        sum += m->calculateDamage();
    }
    return sum;
}

