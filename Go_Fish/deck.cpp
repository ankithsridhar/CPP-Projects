#include "deck.h"
#include <iostream>

using namespace std;

/*********************************************************************
** Function:deck 
** Description: constructor for deck class
** Parameters: none
** Pre-Conditions: this function takes in the number of cards
** Post-Conditions: initialzes the number of cards to rank and suit
*********************************************************************/ 


// must have constructors, destructor, accessors, and mutators
	Deck::Deck(){
		this->n_cards = 52;

		//setting sut
		for (int i = 0; i < this->n_cards; ++i)
		{
			this->cards[i].setRank(i%13);
			this->cards[i].setSuit(i/13);
		}
	}

	/*********************************************************************
** Function:get deck cards
** Description: this function gets the deck cards and returns it
** Parameters: none
** Pre-Conditions: this function takes in the private n cards
** Post-Conditions: returns the n cards
*********************************************************************/ 

	int Deck::getDeckCards(){
		return n_cards;
	}


/*********************************************************************
** Function: shuffle deck
** Description: this function shuffles the deck 
** Parameters: none
** Pre-Conditions: takes in cards
** Post-Conditions: shuffles them for the game to happen 
*********************************************************************/ 
	void Deck::shuffleDeck(){
		int temp = 0;
		int randomIndex = 0;
		srand(time(NULL));
		for(int i = 0; i < n_cards; i++){
			int card1 = rand() % 52;
			int card2 = rand() % 52;
			Card temp = cards[card1];
			cards[card1] = cards[card2];
			cards[card2] = temp;
		}

	}
	
	/*********************************************************************
** Function:remove card
** Description: removes card in the array
** Parameters: none
** Pre-Conditions: removes the number of cards
** Post-Conditions:  this function returns the number of cards in the cards array
*********************************************************************/ 
	Card& Deck::remove_card(){
		Card& card = this->cards[this->n_cards];
		this->n_cards --;
		return card;
	}
