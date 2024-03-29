#ifndef DECK_H
#define DECK_H
#include "card.h"

class Deck
{
private:
	Card storage[52];
	int top;
public:
	Deck();
	void refreshDeck();
	Card deal();
	void shuffle();
	int cardsLeft();
	void showDeck();
};
#endif