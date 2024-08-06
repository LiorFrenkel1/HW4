
#include "SolarEclipse.h"

string SolarEclipse::event(MatamStory& game) {
    return game.currentPlayer->solarEclipse();
}

string SolarEclipse::getDescription() const {
    return "SolarEclipse";
}
