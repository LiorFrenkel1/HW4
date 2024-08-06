#include "Player.h"
#include "Utilities.h"
#include <stdexcept>
//-----------------------------------C'tor--------------------------------------------------------
Player::Player(string name, Character& characterToPlayer) : name(name), level(1), force(5),
currentHP(100),maxHP(100), coins(10), job() ,character(characterToPlayer){
}

//------------------------------------Getters------------------------------------------------------
string Player::getName() const {
    return this->name;
}

int Player::getCoins() const {
    return this->coins;
}

int Player::getForce() const {
    return this->force;
}

int Player::getHealthPoints() const {
    return this->currentHP;
}

int Player::getLevel() const {
    return this->level;
}

/**
 * format: <Name>, <Job> with <Character> character (level <Level>, force <Force>)
 * @return string of description
 */
string Player::getDescription() const {
    string description;
    description += name + ", " + job + " with " + character.getDescription() + " character ";
    description += "(level " + std::to_string(level) + ", force " + std::to_string(force) + ")";
    return description;
}

//------------------------------------Added functions----------------------------------------------

string Player::encounter(int combatPower, int loot, int damage) {
    int playerCombatPower = this->level + this->force;
    if (playerCombatPower > combatPower) {
        level++;
        coins += loot;
        return getEncounterWonMessage(*this, loot);
    } else {
        currentHP -= damage;
        if (currentHP < 0) {
            currentHP = 0;
        }
        return getEncounterLostMessage(*this, damage);
    }
}

void Player::buyPotion() {
    const int potionPrice = 5;
    const int potionHP = 10;
    coins -= potionPrice;
    currentHP = currentHP + potionHP;
    if (currentHP > maxHP) {
        currentHP = maxHP;
    }
}

bool Player::isFullHP() const {
        return currentHP == maxHP;
}

string Player::potionMerchantEvent() {
    this->character.potionsMerchantEvent(*this);
}

string Player::solarEclipse() {
    if (force > 0) {
        force--;
        return getSolarEclipseMessage(*this, -1);
    }
    return getSolarEclipseMessage(*this, 0);
}

