
#pragma once
#include <vector>
#include <Monster.h>

class Pack : public Monster {
private:
    std::vector<Monster> monsters;
public:
    /**
     * Constructor for pack
     */
    Pack();

    /**
    * returns the combat power of a monster or a pack
    */
    unsigned int calculateCombatPower() override;
    /**
    * returns the loot of a monster or a pack
    */
    unsigned int calculateLoot() override;
    /**
    * returns the damage of a monster or a pack
    */
    unsigned int calculateDamage() override;
};

