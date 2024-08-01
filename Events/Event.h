
#pragma once

#include "../Players/Player.h"
#include "../MatamStory.h"

class Event {
public:

    virtual void event(MatamStory) = 0;

    string getDescription() const;
};
