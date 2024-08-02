#pragma once

#include <string>

using std::string;

class Character {

public:
    Character() = default;

    virtual void potionsMerchantEvent() = 0;
    virtual string getDescription() = 0;
};

class Responsible : Character{
public:
    void potionsMerchantEvent() override;
    string getDescription() override;
};

class RiskTaker : Character{
public:
    void potionsMerchantEvent() override;
    string getDescription() override;
};