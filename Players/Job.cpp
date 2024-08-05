#include "Job.h"

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

void CloseFighter::encounter(int combatPower, int loot, int damage) {
    Player::encounter(combatPower, loot, damage);
    int playerCombatPower = force + level;
    if(playerCombatPower > combatPower) {
        currentHP -= 10;
        if(currentHP < 0) {
            currentHP = 0;
        }
    }
}

//----------------------------------Warrior---------------------------------------------------------

Warrior::Warrior(std::string name, Character &characterToPlayer) :
CloseFighter(name, characterToPlayer){
    job = "Warrior";
}

//----------------------------------Archer----------------------------------------------------------

Archer::Archer(std::string name, Character &characterToPlayer) :
Player(name, characterToPlayer){
    job = "Archer";
}