
#pragma once

#include "Pack.h"
#include <vector>

Pack::Pack() : monsters(std::vector<Monster*>()) {}

void Pack::addToPack(Monster& monster) {
    this->monsters.push_back(&monster);
}

int Pack::calculateCombatPower() const {
    int sum = 0;
    for (Monster* m : this->monsters) {
        sum += m->calculateCombatPower();
    }
    return sum;
}

int Pack::calculateLoot() const {
    int sum = 0;
    for (Monster* m : this->monsters) {
        sum += m->calculateLoot();
    }
    return sum;
}

int Pack::calculateDamage() const {
    int sum = 0;
    for (Monster* m : this->monsters) {
        sum += m->calculateDamage();
    }
    return sum;
}
