
#pragma once

#include <vector>
#include <memory>
#include <Monster.h>

class Pack : public Monster {
private:
    std::vector<std::shared_ptr<Monster>> monsters;
public:
    /**
     * Constructor for pack, creates an empty pack
     */
    Pack();

    /**
     * Adds a monster to pack
     * @param monster
     */
    void addToPack(std::shared_ptr<Monster>& monster);

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
};

