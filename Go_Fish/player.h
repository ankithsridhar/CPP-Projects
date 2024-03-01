#ifndef PLAYER_H
#define PLAYER_H 

#include "hand.h"
#include "card.h"

class Player
{
private:
	Hand hand;
	int* books;
	int n_books;
	
public:
	Player();
	Hand& getHand();
	int getNumBooks();
	void setNumBooks(int);
	int getNumCards();
	void goFish(Card&);
	void addBook(int j);
	void checkForBooks();
	void print_books();
	void place_a_card(Card&);
	
};
#endif