
#pragma once
#include "Monster.h"

class Snail : public Monster {
private:
    unsigned int combatPower;
    unsigned int loot;
    unsigned int damage;
public:
    Snail(unsigned int combatPower = 5, unsigned int loot = 2, unsigned int
    damage = 10);

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
