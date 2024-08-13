#include "Job.h"

//----------------------------------MagicalCharacter------------------------------------------------

MagicalCharacter::MagicalCharacter(std::string name, std::shared_ptr<Character> characterToPlayer) :
Player(name, characterToPlayer) {}

string MagicalCharacter::solarEclipse() {
    force++;
    return getSolarEclipseMessage(*this, 1);
}

//----------------------------------Magician--------------------------------------------------------

Magician::Magician(std::string name, std::shared_ptr<Character> characterToPlayer) :
MagicalCharacter(name, characterToPlayer){
    job = "Magician";
}

//----------------------------------CloseFighter----------------------------------------------------

CloseFighter::CloseFighter(std::string name, std::shared_ptr<Character> characterToPlayer) :
Player(name, characterToPlayer){}

string CloseFighter::encounter(int combatPower, int loot, int damage) {
    int playerCombatPower = this->level + this->force * 2;
    if (playerCombatPower > combatPower) {
        level++;
        coins += loot;
        currentHP -= 10;
        if (currentHP < 0) {
            currentHP = 0;
        }
        return getEncounterWonMessage(*this, loot);
    } else {
        currentHP -= damage;
        if (currentHP < 0) {
            currentHP = 0;
        }
        return getEncounterLostMessage(*this, damage);
    }
}

//----------------------------------Warrior---------------------------------------------------------

Warrior::Warrior(std::string name, std::shared_ptr<Character> characterToPlayer) :
CloseFighter(name, characterToPlayer){
    job = "Warrior";
    maxHP = 150;
    currentHP = 150;
}

//----------------------------------Archer----------------------------------------------------------

Archer::Archer(std::string name, std::shared_ptr<Character> characterToPlayer) :
Player(name, characterToPlayer){
    job = "Archer";
    coins = 20;
}