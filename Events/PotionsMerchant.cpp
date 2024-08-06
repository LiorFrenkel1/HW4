
#include "PotionsMerchant.h"

string PotionsMerchant::event(MatamStory& game) {
    game.currentPlayer->potionMerchantEvent();
}

string PotionsMerchant::getDescription() const {
    return "PotionsMerchant";
}
