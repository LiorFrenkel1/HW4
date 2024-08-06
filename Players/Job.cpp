#include "Job.h"
#include "Utilities.h"

//----------------------------------MagicalCharacter------------------------------------------------

MagicalCharacter::MagicalCharacter(std::string name, Character &characterToPlayer) :
Player(name, characterToPlayer) {}

void MagicalCharacter::solarEclipse() {
    force++;

}

//----------------------------------Magician--------------------------------------------------------

Magician::Magician(std::string name, Character &characterToPlayer) :
MagicalCharacter(name, characterToPlayer){
    job = "Magician";
}

//----------------------------------CloseFighter----------------------------------------------------

CloseFighter::CloseFighter(std::string name, Character &characterToPlayer) :
Player(name, characterToPlayer){}

string CloseFighter::encounter(int combatPower, int loot, int damage) {
    int playerCombatPower = this->level + this->force * 2;
    if (playerCombatPower > combatPower) {
        level++;
        coins += loot;
        currentHP -= 10;
        return getEncounterWonMessage(*this, loot);
    } else {
        currentHP -= damage;
        return getEncounterLostMessage(*this, damage);
    }
    if (currentHP < 0) {
        currentHP = 0;
    }
}

//----------------------------------Warrior---------------------------------------------------------

Warrior::Warrior(std::string name, Character &characterToPlayer) :
CloseFighter(name, characterToPlayer){
    job = "Warrior";
    maxHP = 150;
}

//----------------------------------Archer----------------------------------------------------------

Archer::Archer(std::string name, Character &characterToPlayer) :
Player(name, characterToPlayer){
    job = "Archer";
    coins = 20;
}