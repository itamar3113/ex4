//
// Created by itama on 03/01/2023.
//

#include "Mtmchkin.h"

int main() {
    string s = "War";
    Healer h("healer");
    Warrior w("warrior");
    Ninja n("ninja");
    Gremlin g;
    Witch witch;
    Dragon dragon;
    Mana mana;
    Barfight barfight;
    Well well;
    Treasure treasure;
    Merchant merchant;
    string a = "Yotam ninja";
    string b = a.substr(0, a.find(' '));
    string c = a.substr(a.find(' ') + 1);
    std::queue<std::unique_ptr<Card>> ints;
    ints.push(std::unique_ptr<Card>(new Well()));
    ints.push(std::unique_ptr<Card>(new Barfight()));
    ints.push(std::unique_ptr<Card>(new Merchant()));
    ints.push(std::move(ints.front()));
    ints.pop();
    try {
        Mtmchkin mtmchkin("C:\\TDM-GCC-64\\ex4\\dragon.txt");
        while(!mtmchkin.isGameOver() && mtmchkin.getNumberOfRounds() < 100)
        {
            mtmchkin.playRound();

        }
    }
    catch (const DeckFileNotFound& e)
    {
        std::cout << e.what();
        return 0;
    }
    catch (const DeckFileInvalidSize& e)
    {
        std::cout << e.what();
        return 0;
    }

}