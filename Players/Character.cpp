#include "Character.h"
//--------------------------------------Responsible-------------------------------------------
string Responsible::getDescription() {
    return "Responsible";
}

void Responsible::potionsMerchantEvent(Player& player) {
    while (player.getCoins() >= 5 && !player.isFullHP()) {
        player.buyPotion();
    }
}

//---------------------------------------RiskTaker-------------------------------------------------
string RiskTaker::getDescription() {
    return "RiskTaker";
}

void RiskTaker::potionsMerchantEvent(Player &player) {
    if (player.getCoins() >= 5 && player.getHealthPoints() < 50) {
        player.buyPotion();
    }
}
