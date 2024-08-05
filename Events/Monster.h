
#pragma once
#include "Event.h"

class Monster : public Event{
public:
    /**
     * Starts an encounter of the current player with a monster (or a pack)
     * @param game
     */
    void event(MatamStory& game) override;

    /**
     * returns the combat power of a monster or a pack
     */
    virtual int calculateCombatPower() const = 0;
    /**
    * returns the loot of a monster or a pack
    */
    virtual int calculateLoot() const = 0;
    /**
    * returns the damage of a monster or a pack
    */
    virtual int calculateDamage() const = 0;

    virtual ~Monster();
};

