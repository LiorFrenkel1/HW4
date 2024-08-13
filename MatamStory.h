
#pragma once

#include <iostream>
#include <fstream>

#include "Players/Player.h"
#include "Players/Character.h"
#include "Job.h"
#include "Events/Event.h"
#include "Events/Monster.h"
#include "Events/Balrog.h"
#include "Events/Snail.h"
#include "Events/Slime.h"
#include "Events/Pack.h"
#include "Events/SolarEclipse.h"
#include "Events/PotionsMerchant.h"
#include <vector>
#include <memory>
#include <stdexcept>
#include "Utilities.h"

class Player;
class Character;
class Warrior;
class Magician;
class Archer;
class Event;
class Monster;
class Balrog;
class Snail;
class Slime;
class Pack;
class SolarEclipse;
class PotionsMerchant;

class MatamStory{
private:
    std::vector<std::shared_ptr<Event>> events;
    std::vector<std::shared_ptr<Player>> players;
    long unsigned int eventIndex;
    int turnIndex;
    /**
     * Playes a single turn for a player
     *
     * @param player - the player to play the turn for
     *
     * @return - void
    */
    void playTurn();

    /**
     * Plays a single round of the game
     *
     * @return - void
    */
    void playRound();

    /**
     * Checks if the game is over
     *
     * @return - true if the game is over, false otherwise
    */
    bool isGameOver() const;

    /**
     * Checks if every player is dead
     *
     * @return - true if all the players dead, false otherwise
     */
    bool isEveryOneDead() const;

    /**
     * Gets a player by his index in the leaderboard
     *
     * @return The player in the index in the leaderboard
     */
    Player& getLeaderBoardPlayerByIndex(int index);

    /**
     * Gets the player that is in the top of the leaderboard
     * @param players
     * @return The index of the best player
     */
    static int getLeaderBoardBestPlayerIndex(std::vector<std::shared_ptr<Player>>& players);

    std::shared_ptr<Pack> readPack(std::istream& eventsStream);

public:
    std::shared_ptr<Player> currentPlayer;

    /**
     * Constructor of MatamStory class
     *
     * @param eventsStream - events input stream (file)
     * @param playersStream - players input stream (file)
     *
     * @return - MatamStory object with the given events and players
     *
    */
    MatamStory(std::istream& eventsStream, std::istream& playersStream);

    /**
     * Plays the entire game
     *
     * @return - void
    */
    void play();
};
