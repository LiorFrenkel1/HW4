
#pragma once

#include "Event.h"

class PotionsMerchant : public Event {
    /**
    * Activates the potions merchant event upon a player
    * @param game
    */
    void event(MatamStory& game) override;
};

