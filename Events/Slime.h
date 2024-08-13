
#pragma once
#include "Monster.h"

class Slime : public Monster {
private:
    int combatPower;
    int loot;
    int damage;
public:
    Slime(int combatPower = 12, int loot = 5, int damage = 25);

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

    string getDescription() const override;

    int groupSize() const override;

    void addCombatPower(int addPower) override;
};
