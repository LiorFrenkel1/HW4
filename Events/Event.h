
#pragma once

#include "../Players/Player.h"
#include "../MatamStory.h"
#include "../Utilities.h"

class Event {
public:
    /**
     * Activates an event upon a player
     * @param game
     */
    virtual std::string event(MatamStory& game) = 0;

    virtual std::string getDescription() const = 0;
};
