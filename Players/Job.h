#pragma once
#include "Player.h"

/**
 * Father class for all the magical Players, needed for Solar eclipse event, in case of adding jobs.
 */
class MagicalCharacter : public Player {
public:
    MagicalCharacter(string name, std::shared_ptr<Character> characterToPlayer);
    string solarEclipse() override;
};

/**
 * Father class for all the close fighters, needed for loosing HP in winning battle, in case of
 * adding jobs.
 */
class CloseFighter : public Player {
public:
    CloseFighter(string name, std::shared_ptr<Character> characterToPlayer);
    string encounter(int combatPower, int loot, int damage) override;
};

class Magician : public MagicalCharacter {
public:
    Magician(string name, std::shared_ptr<Character> characterToPlayer);
};

class Warrior : public CloseFighter {
public:
    Warrior(string name, std::shared_ptr<Character> characterToPlayer);
};

class Archer : public Player {
public:
    Archer(string name, std::shared_ptr<Character> characterToPlayer);
};


