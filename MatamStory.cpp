
#include "MatamStory.h"
#include <stdexcept>
#include "Utilities.h"
#include "Balrog.h"
#include "Slime.h"
#include "Snail.h"
#include "SolarEclipse.h"
#include "PotionsMerchant.h"
#include "Job.h"

MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream) :
        events(std::vector<std::shared_ptr<Event>>()),
        players(std::vector<std::shared_ptr<Player>>()), eventIndex(0) {
    //Read events
    string eventName;
    while (!eventsStream) {
        eventName = "";
        eventsStream >> eventName;
        if (eventName == "Balrog") {
            Balrog Bla;
            SolarEclipse s;
            this->events.push_back(std::make_shared<Balrog>());
        } else if (eventName == "Slime") {
            this->events.push_back(std::make_shared<Slime>());
        } else if (eventName == "Snail") {
            this->events.push_back(std::make_shared<Snail>());
        } else if (eventName == "SolarEclipse") {
            this->events.push_back(std::make_shared<SolarEclipse>());
        } else if (eventName == "PotionsMerchant") {
            this->events.push_back(std::make_shared<PotionsMerchant>());
        } else {
            throw std::runtime_error("Invalid Events File");
        }
    }
    if (this->events.size() < 2) {
        throw std::runtime_error("Invalid Events File");
    }
    //Read players
    string playerName, playerJob, playerCharacter;
    while (!playersStream) {
        playerName = "";
        playerJob = "";
        playerCharacter = "";
        playersStream >> playerName;
        playersStream >> playerJob;
        playersStream >> playerCharacter;
        if (playerCharacter == "Responsible") {
            Responsible car;
            if (playerJob == "Warrior") {
                this->players.push_back(std::make_shared<Warrior>(playerName, car));
            } else if (playerJob == "Magician") {
                this->players.push_back(std::make_shared<Magician>(playerName, car));
            } else if (playerJob == "Archer") {
                this->players.push_back(std::make_shared<Archer>(playerName, car));
            } else {
                throw std::runtime_error("Invalid Players File");
            }
        } else if (playerCharacter == "RiskTaker") {
            RiskTaker car;
            if (playerJob == "Warrior") {
                this->players.push_back(std::make_shared<Warrior>(playerName, car));
            } else if (playerJob == "Magician") {
                this->players.push_back(std::make_shared<Magician>(playerName, car));
            } else if (playerJob == "Archer") {
                this->players.push_back(std::make_shared<Archer>(playerName, car));
            } else {
                throw std::runtime_error("Invalid Players File");
            }
        } else {
            throw std::runtime_error("Invalid Players File");
        }
    }
    if (this->players.size() < 2 || this->players.size() > 6) {
        throw std::runtime_error("Invalid Players File");
    }
    currentPlayer = this->players[0];
}

void MatamStory::playTurn(Player& player, int index) {
    printTurnDetails(index, player, *this->events[this->eventIndex]);
    if (this->eventIndex == this->events.size()) {
        this->eventIndex = 0;
    }
    *this->events[this->eventIndex]->event(*this);
    this->eventIndex++;
}

void MatamStory::playRound() {

    printRoundStart();

    for (int i = 0; i < this->players.size(); i++) {
        this->currentPlayer = this->players[0];
        playTurn(*this->currentPlayer, i);
    }

    printRoundEnd();

    printLeaderBoardMessage();

    /*===== TODO: Print leaderboard entry for each player using "printLeaderBoardEntry" =====*/

    /*=======================================================================================*/

    printBarrier();
}

bool MatamStory::isGameOver() const {
    /*===== TODO: Implement the game over condition =====*/
    return false; // Replace this line
    /*===================================================*/
}

void MatamStory::play() {
    printStartMessage();
    /*===== TODO: Print start message entry for each player using "printStartPlayerEntry" =====*/

    /*=========================================================================================*/
    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();
    /*===== TODO: Print either a "winner" message or "no winner" message =====*/

    /*========================================================================*/
}
