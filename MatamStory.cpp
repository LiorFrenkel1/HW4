
#include <iostream>
#include <fstream>

#include "MatamStory.h"
#include <stdexcept>
#include "Utilities.h"

MatamStory::MatamStory(std::ifstream& eventsStream, std::ifstream& playersStream) :
events(std::vector<std::shared_ptr<Event>>()),
players(std::vector<std::shared_ptr<Player>>()) {
    //Read events
    string eventName;
    if (!eventsStream.is_open())
    while (!eventsStream) {
        eventName = "";
        eventsStream >> eventName;
        if
        if (eventName == "balrog") {

        } else {
            throw std::
        }
    }

}

void MatamStory::playTurn(Player& player) {

    /**
     * Steps to implement (there may be more, depending on your design):
     * 1. Get the next event from the events list
     * 2. Print the turn details with "printTurnDetails"
     * 3. Play the event
     * 4. Print the turn outcome with "printTurnOutcome"
    */
}

void MatamStory::playRound() {

    printRoundStart();

    /*===== TODO: Play a turn for each player =====*/

    /*=============================================*/

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
