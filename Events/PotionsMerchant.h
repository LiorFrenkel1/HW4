
#pragma once

#include "Event.h"

class PotionsMerchant : public Event {
    /**
    * Activates the potions merchant event upon a player
    * @param game
    */
    string event(Player& player) override;

    string getDescription() const override;
};

