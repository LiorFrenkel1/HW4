#include "Character.h"
//--------------------------------------Responsible-------------------------------------------
string Responsible::getDescription() {
    return "Responsible";
}

string Responsible::potionsMerchantEvent(Player& player) {
    int potionsBought = 0;
    while (player.getCoins() >= 5 && !player.isFullHP()) {
        player.buyPotion();
        potionsBought++;
    }
    return getPotionsPurchaseMessage(player, potionsBought);
}

//---------------------------------------RiskTaker-------------------------------------------------
string RiskTaker::getDescription() {
    return "RiskTaking";
}

string RiskTaker::potionsMerchantEvent(Player &player) {
    int potionsBought = 0;
    if (player.getCoins() >= 5 && player.getHealthPoints() < 50) {
        player.buyPotion();
    }
    return getPotionsPurchaseMessage(player, potionsBought);
}
