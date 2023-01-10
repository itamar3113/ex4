//
// Created by itama on 08/01/2023.
//


#include <limits>
#include "Mtmchkin.h"

const int MAX_TEAM_SIZE = 6;
const int MIN_TEAM_SIZE = 2;
const string NINJA = "Ninja";
const string WARRIOR = "Warrior";
const string HEALER = "Healer";

Mtmchkin::Mtmchkin(const std::string &fileName) : m_players(deque<unique_ptr<Player>>()),
                                                  m_cards(queue<unique_ptr<Card>>()),
                                                  m_losers(deque<unique_ptr<Player>>()),
                                                  m_winners(deque<unique_ptr<Player>>()),
                                                  m_roundCount(0) {
    ifstream readFile;
    //todo add exception
    readFile.open(fileName);
    string cardName;
    //todo better way to initiate the queue
    while (getline(readFile, cardName)) {
        try {
            m_cards.push(createCardByName(cardName));
            //todo add exception
        } catch (InvalidCardNameException &e) {
            cerr << e.what();
            printInvalidName();
        }
    }
    readFile.close();
    printStartGameMessage();
    insertPlayers(m_players);
}


void insertPlayers(deque<unique_ptr<Player>> &players) {
    printEnterTeamSizeMessage();
    int teamSize;
    bool validSize = false;
    while (!validSize) {
        cin >> teamSize;
        //todo add exception for non numbers
        if (cin.fail()) {
            // input is not an integer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            printInvalidTeamSize();
        } else {
            if (teamSize > MAX_TEAM_SIZE || teamSize < MIN_TEAM_SIZE) {
                printInvalidTeamSize();
            } else {
                validSize = true;
            }
        }
    }
    string playerName;
    string playerClass;
    for (int i = 0; i < teamSize; ++i) {
        printInsertPlayerMessage();
        cin >> playerName >> playerClass;
        try {
            players.push_back(createPlayer(playerName, playerClass));//
        } catch (InvalidPlayerNameException &e) {
            cerr << e.what();
            printInvalidName();
            i -= 1;
        }
        catch (InvalidClassException &e) {
            cerr << e.what();
            printInvalidClass();
            i -= 1;
        }
    }
}

void Mtmchkin::playRound() {
    printRoundStartMessage(getNumberOfRounds());
    deque<unique_ptr<Player>> tmpPlayers;
    while (!isGameOver()) {
        while (!m_players.empty()) {
            printTurnStartMessage(m_players.front()->getName());
            m_cards.front()->applyEncounter(*(m_players.front()));
            m_cards.push(std::move(m_cards.front()));
            m_cards.pop();
            if (m_players.front()->isKnockedOut()) {
                m_losers.push_front(std::move(m_players.front()));
            } else if (m_players.front()->getLevel() == 10) {
                m_winners.push_back(std::move(m_players.front()));
            } else {
                tmpPlayers.push_back(std::move(m_players.front()));
            }
            m_players.pop_front();
        }
        m_players.swap(tmpPlayers);
        m_roundCount += 1;
    }
    printGameEndMessage();
    printLeaderBoard();
}

bool Mtmchkin::isGameOver() const {
    return m_players.empty();
}

int Mtmchkin::getNumberOfRounds() const {
    return m_roundCount;
}

void Mtmchkin::printLeaderBoard() const {
    printLeaderBoardStartMessage();
    int rank = 0;
    for (const unique_ptr<Player> &playerPtr: m_winners) {
        rank += 1;
        printPlayerLeaderBoard(rank, *playerPtr);
    }
    for (const unique_ptr<Player> &playerPtr: m_players) {
        rank += 1;
        printPlayerLeaderBoard(rank, *playerPtr);
    }
    for (const unique_ptr<Player> &playerPtr: m_losers) {
        rank += 1;
        printPlayerLeaderBoard(rank, *playerPtr);
    }
}

unique_ptr<Card> createCardByName(string &name) {
    if (name == "BarFight") {
        return unique_ptr<Card>(new Barfight());
    }
    if (name == "Dragon") {
        return unique_ptr<Card>(new Dragon());
    }
    if (name == "Gremlin") {
        return unique_ptr<Card>(new Gremlin());
    }
    if (name == "Mana") {
        return unique_ptr<Card>(new Mana());
    }
    if (name == "Merchant") {
        return unique_ptr<Card>(new Merchant());
    }
    if (name == "Treasure") {
        return unique_ptr<Card>(new Treasure());
    }
    if (name == "Well") {
        return unique_ptr<Card>(new Well());
    }
    if (name == "Witch") {
        return unique_ptr<Card>(new Witch());
    }
    printInvalidName();
    //todo add exception
    throw InvalidCardNameException("name of card is illegal");
}

unique_ptr<Player> createPlayer(string &playerName, string &playerClass) {
    if (!nameIsLegal(playerName)) {
        throw InvalidPlayerNameException("name of player is illegal");
    }
    if (playerClass == NINJA) {
        return unique_ptr<Player>(new Ninja(playerName));
    }
    if (playerClass == WARRIOR) {
        return unique_ptr<Player>(new Warrior(playerName));
    }
    if (playerClass == HEALER) {
        return unique_ptr<Player>(new Healer(playerName));
    }
    throw InvalidClassException("class is illegal");
}

//todo where to declare function? should be static?
bool nameIsLegal(string &name) {
    if (name.length() > 15) {
        return false;
    }
    for (char const &c: name) {
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}