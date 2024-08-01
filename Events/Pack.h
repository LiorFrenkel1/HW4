
#pragma once
#include <vector>
#include <Monster.h>

class Pack : public Monster {
private:
    std::vector<Monster> monsters;
public:
    /**
     * Constructor for pack
     * @param first The first monster added to pack (the order doesn't matter)
     */
    Pack(Monster& first);

    /**
     * Adds a monster to pack
     * @param monster
     */
    void addToPack(Monster& monster);

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

