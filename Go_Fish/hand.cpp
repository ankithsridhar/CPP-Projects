#include "hand.h"

/*********************************************************************
** Function: hand
** Description: hand constuctor
** Parameters: none
** Pre-Conditions: take in the private variables in class
** Post-Conditions: sets the cards to null
*********************************************************************/ 


	Hand::Hand(){
		this->n_cards = 0;
		this->cards = NULL;
	}

	/*********************************************************************
** Function:getncards
** Description: this function gets cards from player
** Parameters: none
** Pre-Conditions: private variable ncards
** Post-Conditions: returns the private vairable
*********************************************************************/ 

	int Hand::getn_cards(){
		return n_cards;
	}

	/*********************************************************************
** Function: get cards
** Description: returns card array
** Parameters: none
** Pre-Conditions: this function takes in card array thats private
** Post-Conditions: returns card array
*********************************************************************/ 

	Card* Hand::getCards() {
		return cards;
	}

/*********************************************************************
** Function:in hand
** Description: counts variables in hand
** Parameters: int temp
** Pre-Conditions: takes in temo from other class
** Post-Conditions: returns counter variable
*********************************************************************/ 

	int Hand::inHand(int temp) {
	//for loop for player number of cards 
	int counter = 0;
	for (int i=0; i<n_cards; i++){
		if (temp == cards[i].getRank()) {
			//RETURN TRUE
			counter ++;
		}
		// else {
		// 	//RETURN FALSE
		// 	counter;

		// 	//you dont have that card. go again
		// 	//repeat player turn.
		// }
	}
	return counter;
	}

	/*********************************************************************
** Function:delete card
** Description: this fuction deletes cards from the array
** Parameters: string temp
** Pre-Conditions: this function takes in temp var from game
** Post-Conditions: this function deletes card from hand
*********************************************************************/ 

	Card Hand::deleteCard(string temp){
		//allocate a new array of Card objects with the size + 1
		Card* new_arr = new Card [this->n_cards - 1];
		bool cardFound = false;

		//copy all objects from the old array (cards) into the new array
		int counter= 0;

		Card t;

		for (int i = 0; i < this->n_cards; ++i)
		{
			if ((cardFound) or (this->cards[i].getRank() != cards[i].stringConvert(temp))) {
				new_arr[counter] = this->cards[i]; // AOO of Card 
				counter++;
			} else {
				t = this->cards[i];
				cardFound = true;
			}
		}

		//free the cards array (old array)
		if (this->cards != NULL){
			delete [] this->cards;
		}
		//set cards array to the new array
		this->cards = new_arr;

		this->n_cards--;

		return t;

	}

	/*********************************************************************
** Function:delete book
** Description: this function deletes the book from players hand
** Parameters: int rank
** Pre-Conditions: takes in the payer rank from game
** Post-Conditions: deletes book from hamd
*********************************************************************/ 

	Card Hand::deleteBook(int rank){
		//allocate a new array of Card objects with the size + 1
		Card* new_arr = new Card [this->n_cards -1];
		bool cardFound = false;

		//copy all objects from the old array (cards) into the new array
		int counter= 0;

		Card t;

		for (int i = 0; i < this->n_cards; ++i)
		{
			if ((cardFound) or (this->cards[i].getRank() != rank)) {
				new_arr[counter] = this->cards[i]; // AOO of Card 
				counter++;
			} else {
				t = this->cards[i];
				cardFound = true;
			}
		}

		//free the cards array (old array)
		if (this->cards != NULL){
			delete [] this->cards;
		}
		//set cards array to the new array
		this->cards = new_arr;

		this->n_cards--;

		return t;

	}

	/*********************************************************************
** Function:~hand
** Description: destructor for hand
** Parameters: none
** Pre-Conditions: the cards array
** Post-Conditions: deletes the array
*********************************************************************/ 


	Hand::~Hand() {
		if (this->cards != NULL){
			delete [] this->cards;
			this->cards = NULL;
		}
	}

	/*********************************************************************
** Function: add card
** Description: adds card to player hand
** Parameters: card&C
** Pre-Conditions: takes in the card object c
** Post-Conditions: adds the card to other player hand
*********************************************************************/ 

	void Hand::addCard(Card& c){
		//allocate a new array of Card objects with the size + 1
		Card* new_arr = new Card [this->n_cards + 1];

		//copy all objects from the old array (cards) into the new array
		for (int i = 0; i < this->n_cards; ++i)
		{
			new_arr[i] = this->cards[i]; // AOO of Card 
		}

		//add the new Card object c into index n_cards
		new_arr[this->n_cards] = c;

		//free the cards array (old array)
		if (this->cards != NULL)
			delete [] this->cards;

		//set cards array to the new array
		this->cards = new_arr;

		//increment the n_cards
		this->n_cards++;
	}