
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
    virtual unsigned int calculateCombatPower() = 0;
    /**
    * returns the loot of a monster or a pack
    */
    virtual unsigned int calculateLoot() = 0;
    /**
    * returns the damage of a monster or a pack
    */
    virtual unsigned int calculateDamage() = 0;

};

