#ifndef DECK_H
#define DECK_H 

#include "card.h"

class Deck
{
private:
	Card cards[52];
	int n_cards;
public:
	Deck();
	int getDeckCards();
	void shuffleDeck();
	Card& remove_card();
	
};
#endif