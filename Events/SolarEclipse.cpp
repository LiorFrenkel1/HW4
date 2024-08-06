
#include "SolarEclipse.h"

string SolarEclipse::event(MatamStory& game) {
    game.currentPlayer->solarEclipse();
}

string SolarEclipse::getDescription() const {
    return "SolarEclipse";
}
