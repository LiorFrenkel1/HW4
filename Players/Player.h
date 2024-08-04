
#pragma once

#include <string>
#include "Character.h"

using std::string;

class Player {
private:
    string name; //english letters, no spaces, max 15 chars.
    int level; // [1,10]
    int force;
    int currentHP; // <= maxHp
    int maxHP; // >0
    int coins;
    Character& character;

public:

    Player(string name, Character& characterToPlayer);
    /**
     * Gets the description of the player
     *
     * @return - description of the player
    */
    virtual string getDescription() const = 0;

    /**
     * Gets the name of the player
     *
     * @return - name of the player
    */
    string getName() const;

    /**
     * Gets the current level of the player
     *
     * @return - level of the player
    */
    int getLevel() const;

    /**
     * Gets the of force the player has
     *
     * @return - force points of the player
    */
    int getForce() const;

    /**
     * Gets the amount of health points the player currently has
     *
     * @return - health points of the player
    */
    int getHealthPoints() const;

    /**
     * Gets the amount of coins the player has
     *
     * @return - coins of the player
    */
    int getCoins() const;

    /**
     * fighting an abstract monster according to the values, if you win you get to loot
     * otherwise, loose HP in amount of combatPower
     * @param combatPower
     * @param loot
     */
    virtual void encounter(int combatPower, int loot);

    /**
     * Use money for one potion and get the HP, not more than the max HP
     */
    void buyPotion();

    /**
     * doing potionsMerchant event according to the character
     */
    void potionMerchantEvent();

    /**
     * doing solarEclipseEvent according to the job.
     */
    virtual void solarEclipse();
};
