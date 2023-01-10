#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_

#include <fstream>
#include <queue>
#include <deque>
#include <memory>
#include <stack>
#include "cards/Card.h"
#include "players/Player.h"
#include "players/Healer.h"
#include "players/Warrior.h"
#include "cards/Gremlin.h"
#include "cards/Witch.h"
#include "cards/Dragon.h"
#include "cards/Mana.h"
#include "cards/Barfight.h"
#include "cards/Well.h"
#include "cards/Treasure.h"
#include "cards/Merchant.h"
#include "players/Ninja.h"

using namespace std;

class Mtmchkin {
    //todo check if aad fields is allowed.
    queue<unique_ptr<Card>> m_cards;
    deque<unique_ptr<Player>> m_players;
    deque<unique_ptr<Player>> m_losers;
    deque<unique_ptr<Player>> m_winners;
    int m_roundCount;

public:

    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    explicit Mtmchkin(const std::string &fileName);

    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();

    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;

    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;

    /*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;
};

bool nameIsLegal(string &name);

unique_ptr<Card> createCardByName(string &name);

unique_ptr<Player> createPlayer(string &playerName, string &playerClass);

void insertPlayers(deque<unique_ptr<Player>>& players);

#endif /* MTMCHKIN_H_ */
