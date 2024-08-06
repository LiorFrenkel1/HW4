
#include "PotionsMerchant.h"

string PotionsMerchant::event(Player& player) {
    return player.potionMerchantEvent();
}

string PotionsMerchant::getDescription() const {
    return "PotionsMerchant";
}
