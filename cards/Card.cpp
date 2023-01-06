#include "Card.h"

Card::Card() {
}

Card::~Card() {
}

void Card::printInfo(ostream &os) {
    printCardDetails(os,getName());
}

ostream &operator<<(ostream &os, Card &card) {
    card.printInfo(os);
    printEndOfCardDetails(os);
}

