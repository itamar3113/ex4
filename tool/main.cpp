//
// Created by itama on 03/01/2023.
//

#include "../Mtmchkin.h"

int main() {
    const int MAX_NUMBER_OF_ROUNDS = 100;
    try {
        Mtmchkin mtmchkin("deck.txt");
        while(!mtmchkin.isGameOver() && mtmchkin.getNumberOfRounds() < MAX_NUMBER_OF_ROUNDS)
        {
            mtmchkin.playRound();
        }
    }
    catch (const DeckFileErrors & e)
    {
        std::cout << e.what();
        return 0;
    }

}