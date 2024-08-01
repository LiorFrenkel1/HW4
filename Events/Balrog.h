
#pragma once
#include "Monster.h"

class Balrog : public Monster {
private:
    unsigned int combatPower;
    unsigned int loot;
    unsigned int damage;
public:
    Balrog(unsigned int combatPower = 15, unsigned int loot = 100, unsigned int
    damage = 9001);

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

