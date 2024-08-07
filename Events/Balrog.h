
#pragma once
#include "Monster.h"

class Balrog : public Monster {
private:
    int combatPower;
    int loot;
    int damage;
public:
    Balrog(int combatPower = 15, int loot = 100, int damage = 9001);

    /**
     * Starts an encounter of the current player with a monster (or a pack)
     * @param game
     */
    std::string event(Player& player) override;

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

    std::string getDescription() const override;

    int groupSize() const override;

    void addCombatPower(int addPower);
};

