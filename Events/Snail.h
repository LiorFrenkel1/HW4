
#pragma once
#include "Monster.h"

class Snail : public Monster {
private:
    int combatPower;
    int loot;
    int damage;
public:
    Snail(int combatPower = 5, int loot = 2, int damage = 10);

    /**
* returns the combat power of a monster or a pack
*/
    int calculateCombatPower() const override;
    /**
    * returns the loot of a monster or a pack
    */
    int calculateLoot() const override;
    /**
    * returns the damage of a monster or a pack
    */
    int calculateDamage() const override;
};
