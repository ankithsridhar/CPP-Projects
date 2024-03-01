#ifndef HAND_H
#define HAND_H 

#include "card.h"

class Hand
{
private:
	Card* cards; //array of cards
	int n_cards; //size of the array cards

public:
	Hand();
	int getn_cards();
	Card* getCards();
	int inHand(int );
	Card deleteCard(string );
	Card deleteBook(int );
	~Hand();
	void addCard(Card&);
	
};
#endif