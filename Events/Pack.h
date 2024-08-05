
#pragma once
#include <vector>
#include <Monster.h>

class Pack : public Monster {
private:
    std::vector<Monster*> monsters;
public:
    /**
     * Constructor for pack, creates an empty pack
     */
    Pack();

    /**
     * Adds a monster to pack
     * @param monster
     */
    void addToPack(Monster& monster);

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

