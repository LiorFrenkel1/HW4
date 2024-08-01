
#pragma once
#include "Monster.h"

class Slime : public Monster {
private:
    unsigned int combatPower;
    unsigned int loot;
    unsigned int damage;
public:
    Slime(unsigned int combatPower = 12, unsigned int loot = 5, unsigned int
    damage = 25);

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
