
#pragma once
#include "Event.h"

class Monster : public Event{
public:
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

