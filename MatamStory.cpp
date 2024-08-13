
#include "MatamStory.h"


bool lettersOnly(string str);

MatamStory::MatamStory(std::istream& eventsStream, std::istream& playersStream) :
        events(std::vector<std::shared_ptr<Event>>()),
        players(std::vector<std::shared_ptr<Player>>()), eventIndex(0), turnIndex(1) {
    //Read events
    string eventName;
    while (eventsStream >> eventName) {
        if (eventName == "Balrog") {
            this->events.push_back(std::make_shared<Balrog>());
        } else if (eventName == "Slime") {
            this->events.push_back(std::make_shared<Slime>());
        } else if (eventName == "Snail") {
            this->events.push_back(std::make_shared<Snail>());
        } else if (eventName == "Pack") {
            try {
                this->events.push_back(readPack(eventsStream));
            } catch (...) {
                throw;
            }
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
    while (playersStream >> playerName && playersStream >> playerJob &&
    playersStream >> playerCharacter) {
        if(playerName.length() < 3 || playerName.length() > 15 || !lettersOnly(playerName)) {
            throw std::runtime_error("Invalid Players File");
        } else if (playerCharacter == "Responsible") {
            if (playerJob == "Warrior") {
                this->players.push_back(std::make_shared<Warrior>(playerName, std::make_shared<Responsible>()));
            } else if (playerJob == "Magician") {
                this->players.push_back(std::make_shared<Magician>(playerName, std::make_shared<Responsible>()));
            } else if (playerJob == "Archer") {
                this->players.push_back(std::make_shared<Archer>(playerName, std::make_shared<Responsible>()));
            } else {
                throw std::runtime_error("Invalid Players File");
            }
        } else if (playerCharacter == "RiskTaking") {
            if (playerJob == "Warrior") {
                this->players.push_back(std::make_shared<Warrior>(playerName, std::make_shared<RiskTaker>()));
            } else if (playerJob == "Magician") {
                this->players.push_back(std::make_shared<Magician>(playerName, std::make_shared<RiskTaker>()));
            } else if (playerJob == "Archer") {
                this->players.push_back(std::make_shared<Archer>(playerName, std::make_shared<RiskTaker>()));
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

std::shared_ptr<Pack> MatamStory::readPack(std::istream& eventsStream) {
    int amountOfMonsters;
    eventsStream >> amountOfMonsters;
    std::shared_ptr<Pack> newPack = std::make_shared<Pack>();
    string monsterName;
    for (int i = 0; i < amountOfMonsters; i++) {
        eventsStream >> monsterName;
        if (monsterName == "Balrog") {
            newPack->addToPack(std::make_shared<Balrog>());
        } else if (monsterName == "Slime") {
            newPack->addToPack(std::make_shared<Slime>());
        } else if (monsterName == "Snail") {
            newPack->addToPack(std::make_shared<Snail>());
        } else if (monsterName == "Pack") {
            try {
                newPack->addToPack(readPack(eventsStream));
            } catch (...) {
                throw;
            }
        } else {
            throw std::runtime_error("Invalid Events File");
        }
    }
    return newPack;
}

void MatamStory::playTurn() {
    if (this->currentPlayer->getHealthPoints() == 0) {
        return;
    }

    printTurnDetails(this->turnIndex, *this->currentPlayer, *this->events[this->eventIndex]);
    printTurnOutcome(this->events[this->eventIndex]->event(*this->currentPlayer));
    this->eventIndex++;

    if (this->eventIndex == this->events.size()) {
        this->eventIndex = 0;
    }
    this->turnIndex++;
}

void MatamStory::playRound() {

    printRoundStart();

    for (const std::shared_ptr<Player>& player : this->players) {
        this->currentPlayer = player;
        playTurn();
    }

    printRoundEnd();

    printLeaderBoardMessage();

    for (long unsigned int i = 0; i < this->players.size(); i++) {
        printLeaderBoardEntry(i + 1, getLeaderBoardPlayerByIndex(i));
    }

    printBarrier();
}

bool MatamStory::isGameOver() const {
    if (isEveryOneDead()) {
        return true;
    }
    for (const std::shared_ptr<Player>& player: this->players) {
        if (player->getLevel() == 10) {
            return true;
        }
    }
    return false;
}

bool MatamStory::isEveryOneDead() const {
    bool isAlive = false;
    for (const std::shared_ptr<Player>& player : this->players) {
        if (player->getHealthPoints() > 0) {
            isAlive = true;
        }
    }
    return !isAlive;
}

void MatamStory::play() {

    printStartMessage();

    for (long unsigned int i = 0; i < this->players.size(); i++) {
        printStartPlayerEntry(i + 1, *this->players[i]);
    }

    printBarrier();

    while (!isGameOver()) {
        playRound();
    }

    printGameOver();

    if (isEveryOneDead()) {
        printNoWinners();
    } else {
        printWinner(*this->players[getLeaderBoardBestPlayerIndex(this->players)]);
    }
}

Player& MatamStory::getLeaderBoardPlayerByIndex(int index) {
    std::vector<std::shared_ptr<Player>> temp(this->players);
    for (int i = 0; i < index; i++) {
        temp.erase(temp.begin() + getLeaderBoardBestPlayerIndex(temp));
    }
    return *temp[getLeaderBoardBestPlayerIndex(temp)];
}

int MatamStory::getLeaderBoardBestPlayerIndex(
        std::vector<std::shared_ptr<Player>>& playersVector) {
    if (playersVector.size() == 1) {
        return 0;
    }
    int currentIndex = 0, currentLevel = playersVector[0]->getLevel();
    int currentCoins = playersVector[0]->getCoins();
    string currentName = playersVector[0]->getName();
    for (long unsigned int i = 1; i < playersVector.size(); i++) {
        if (playersVector[i]->getLevel() > currentLevel) {
            currentIndex = i;
            currentLevel = playersVector[currentIndex]->getLevel();
            currentCoins = playersVector[currentIndex]->getCoins();
            currentName = playersVector[currentIndex]->getName();
        } else if (playersVector[i]->getLevel() == currentLevel) {
            if (playersVector[i]->getCoins() > currentCoins) {
                currentIndex = i;
                currentLevel = playersVector[currentIndex]->getLevel();
                currentCoins = playersVector[currentIndex]->getCoins();
                currentName = playersVector[currentIndex]->getName();
            } else if (playersVector[i]->getCoins() == currentCoins) {
                if (playersVector[i]->getName() < currentName) {
                    currentIndex = i;
                    currentLevel = playersVector[currentIndex]->getLevel();
                    currentCoins = playersVector[currentIndex]->getCoins();
                    currentName = playersVector[currentIndex]->getName();
                }
            }
        }
    }
    return currentIndex;
}

//-------------------------------------helper functions---------------------------------------

bool lettersOnly(string str) {
    for (char c : str) {
        if (!(('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z'))) {
            return false;
        }
    }
    return true;
}