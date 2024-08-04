#pragma once

#include <string>
#include "Player.h"

using std::string;

class Player;

class Character {

public:
    Character() = default;

    virtual void potionsMerchantEvent(Player& player) = 0;
    virtual string getDescription() = 0;
};

class Responsible : public Character{
public:
    void potionsMerchantEvent(Player& player) override;
    string getDescription() override;
};

class RiskTaker : public Character{
public:
    void potionsMerchantEvent(Player& player) override;
    string getDescription() override;
};