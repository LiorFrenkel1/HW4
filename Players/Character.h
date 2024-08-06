#pragma once

#include <string>
#include "Player.h"

using std::string;

class Player;

class Character {

public:
    Character() = default;

    virtual string potionsMerchantEvent(Player& player) = 0;
    virtual string getDescription() = 0;
};

class Responsible : public Character{
public:
    string potionsMerchantEvent(Player& player) override;
    string getDescription() override;
};

class RiskTaker : public Character{
public:
    string potionsMerchantEvent(Player& player) override;
    string getDescription() override;
};