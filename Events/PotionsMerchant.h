
#pragma once

#include "Event.h"

class PotionsMerchant : public Event {
    /**
    * Activates the potions merchant event upon a player
    * @param game
    */
    std::string event(MatamStory& game) override;

    string getDescription() const override;
};

