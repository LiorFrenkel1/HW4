
#pragma once

#include "Event.h"

class SolarEclipse : public Event {
    /**
     * Activates the solar eclipse event upon a player
     * @param game
     */
    std::string event(MatamStory& game) override;

    string getDescription() const override;
};

