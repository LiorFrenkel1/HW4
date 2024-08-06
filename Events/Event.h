
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
    virtual void event(MatamStory& game) = 0;

    //TODO understand the demand of getDescription by the instructions
    string getDescription() const;
};
