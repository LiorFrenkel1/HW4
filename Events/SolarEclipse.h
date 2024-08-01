
#pragma once

#include "Event.h"

class SolarEclipse : public Event {
    /**
     * Activates the solar eclipse event upon a player
     * @param game
     */
    void event(MatamStory& game) override;
};

