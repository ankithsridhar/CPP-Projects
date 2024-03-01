#include "player.h"
#include <iostream>

/*********************************************************************
** Function:player
** Description: this function sets the books array
** Parameters: none
** Pre-Conditions: this function takes in the books array
** Post-Conditions: sets the book array to 13
*********************************************************************/ 
	Player::Player(){
		this->books = new int[13];
		n_books = 0;
	}

	/*********************************************************************
** Function:get hand
** Description: function gets hand
** Parameters: none
** Pre-Conditions: private
** Post-Conditions: returns hand
*********************************************************************/ 
	Hand& Player::getHand(){
  		return hand;
	}


/*********************************************************************
** Function: getnumbooks
** Description: this function gets number of books
** Parameters: none
** Pre-Conditions: private var
** Post-Conditions:  gets the number of books
*********************************************************************/ 
	int Player::getNumBooks(){
		return n_books;
	}


/*********************************************************************
** Function:set numbooks
** Description: sets the number of books
** Parameters: int n
** Pre-Conditions: takes in the integer
** Post-Conditions: sets number of books to n
*********************************************************************/ 
	void Player::setNumBooks(int n){
		this->n_books = n;
	}
/*********************************************************************
** Function: getnumcards
** Description: this gets the number of cards
** Parameters: none
** Pre-Conditions: private vriable
** Post-Conditions: returns num cards from hand class
*********************************************************************/ 
	int Player::getNumCards(){
		return hand.getn_cards();
	}
/*********************************************************************
** Function: go fish
** Description: go fishes 
** Parameters: this function has card &go
** Pre-Conditions: takes in the card from deck to fish
** Post-Conditions: returns the card
*********************************************************************/ 
	void Player::goFish(Card &go) {
		this->hand.addCard(go);
	}
	// Card removeRank(int temp){
	// 	return hand.retCard(temp);
	// }
/*********************************************************************
** Function: add book
** Description: this function adds book
** Parameters: int j
** Pre-Conditions: takes in j as players
** Post-Conditions: adds book to the player
*********************************************************************/ 
	void Player::addBook(int j){
		int* new_arr = new int [this->n_books + 1];

		//copy all objects from the old array (cards) into the new array
		for (int i = 0; i < this->n_books; ++i)
		{
			new_arr[i] = this->books[i]; // AOO of Card 
		}

		//add the new Card object c into index n_cards
		new_arr[this->n_books] = j;

		//free the cards array (old array)
		if (this->books != NULL)
			delete [] this->books;

		//set cards array to the new array
		this->books = new_arr;

		//increment the n_cards
		this->n_books++;

	}
/*********************************************************************
** Function:ckecks players hand for books
** Description: this function checks the hand for books
** Parameters: none
** Pre-Conditions: takes in player hand
** Post-Conditions: delets books if found
*********************************************************************/ 

	void Player::checkForBooks(){
		//looping though the hand
		for (int i = 0; i < 13; i++)
		{
			if(hand.inHand(i) == 4){
				hand.deleteBook(i);
				hand.deleteBook(i);
				hand.deleteBook(i);
				hand.deleteBook(i);
				addBook(i);
			}
		}
		
		//if there is 4 of a kind of one suit
		//then, add 1 to the book counter
		//delete the 4 of a kind from the players/ computers hand


	}
/*********************************************************************
** Function: print books
** Description: prints books to terminal
** Parameters: none
** Pre-Conditions: takes in books
** Post-Conditions: prins out the books when found
*********************************************************************/ 
	void Player::print_books(){
		for (int i = 0; i < n_books; i++)
		{
			cout << books [i] + 2 << ", ";
		}

		cout << endl;
	}

/*********************************************************************
** Function: place a card
** Description: places a card in the players hand
** Parameters:card&c
** Pre-Conditions : takes a card
** Post-Conditions: puts a card in players hand
*********************************************************************/ 
	void Player::place_a_card(Card& c){
		this->hand.addCard(c);
	}