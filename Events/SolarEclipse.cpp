
#include "SolarEclipse.h"

string SolarEclipse::event(Player& player) {
    return player.solarEclipse();
}

string SolarEclipse::getDescription() const {
    return "SolarEclipse";
}
