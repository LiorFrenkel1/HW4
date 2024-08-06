
#pragma once

#include "../Players/Player.h"

class Event {
public:
    /**
     * Activates an event upon a player
     * @param game
     */
    virtual std::string event(Player& player) = 0;

    virtual std::string getDescription() const = 0;
};
