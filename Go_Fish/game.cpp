#include "game.h"	
#include <iostream>


/*********************************************************************
** Function:deal card
** Description: this function deals carss to players
** Parameters: none
** Pre-Conditions: takes in cards from deck 
** Post-Conditions:deals 7 cards to each player
*********************************************************************/ 
 // must have constructors, destructor, accessors, and mutators
	void Game::deal_card(){

		for (int i = 0; i < 14; ++i)
		{
			Card c = this->d.remove_card();

			//return cards
			this->players[i%2].place_a_card(c);
		}
	
	}
/*********************************************************************
** Function:inhand
** Description: this function checks a counter of whats in hand
** Parameters: string temp, int j
** Pre-Conditions: tankes in user input and player number
** Post-Conditions:counter if cards in player and cmputer hand
*********************************************************************/ 

	int Game::inHand(string temp, int j) {
		//for loop for player number of cards 
		int counter = 0;
		for (int i=0; i<players[j].getNumCards(); i++){
			if (players[j].getHand().getCards()[i].stringConvert(temp) == players[j].getHand().getCards()[i].getRank()) {
				//RETURN TRUE
				counter ++;
			
			}
			// 	//RETURN FALSE
			// 	counter;

			// 	//you dont have that card. go again
			// 	//repeat player turn.
			// }
		}
		return counter;
	}

/*********************************************************************
** Function: pirnt game 
** Description: this function prints the game to the screen 
** Parameters: int debug
** Pre-Conditions: takes in if the user wants debug mode or not
** Post-Conditions: couts game in terminal
*********************************************************************/ 
	void Game::printGame(int debug){
		cout << "Your hand: ";

		int playCard = players[1].getHand().getn_cards();

		for(int i = 0; i < playCard; i++){
			cout << "(" << players[1].getHand().getCards()[i].map_rank() << ") ";
		}
		cout << "Books: ";
		players[1].print_books();
		//show computer hand

		if (debug==1){
			cout << "CPU HAND: ";
			int compCard = players[0].getHand().getn_cards();
			for(int i = 0; i < compCard; i++){
				cout << "(" << players[0].getHand().getCards()[i].map_rank() << ") ";
			} 
			cout << "Books: ";
			players[0].print_books();
		}

		cout << "Cards remaining in deck: " << d.getDeckCards() << endl;
	}

	/*********************************************************************
** Function: comp turn 
** Description: this function takes in the computer turn 
** Parameters: int debug
** Pre-Conditions: debugs the file
** Post-Conditions: plays the comp turn 
*********************************************************************/ 

	void Game::compTurn(int debug) {
		if (gameOver()){
			return;
		}
		if(players[0].getHand().getn_cards() < 1){
			cout << "You draw a card.";
			Card temp = d.remove_card();
			players[0].goFish(temp);
			printGame(debug);
		}

		cout << "Computer's turn..." << endl;

		int randnum = rand()% players[0].getNumCards();
		string compCard = players[0].getHand().getCards()[randnum].map_rank();
		cout << endl<< "The computer asks you a " << compCard << endl;

		if(inHand(compCard, 1) > 0){

			int counter = inHand(compCard, 1);
			for(int i=0;i<counter; i++){
				Card c = players[1].getHand().deleteCard(compCard);
				players[0].getHand().addCard(c);
				players[0].checkForBooks();
			}
				
			//players[0].removeRank(stringConvert(temp));
		} else {
			cout << "Go fish. Draw from the deck." << endl << endl;
			Card temp = d.remove_card();
			players[0].goFish(temp);
			players[0].checkForBooks();
		}


	}

/*********************************************************************
** Function: player trun 
** Description: does the player turn 
** Parameters: int debug
** Pre-Conditions: takes in debug mode from player
** Post-Conditions: does the player turn 
*********************************************************************/ 
	void Game::playTurn(int debug){
		printGame(debug);
		string temp;

	if (gameOver()){
		return;
	}
	do{
		
		if(players[1].getHand().getn_cards() < 1){
			cout << "You draw a card.";
			Card temp = d.remove_card();
			players[1].goFish(temp);
			printGame(debug);
		}
		cout << endl<< "What do you want to ask the computer?: ";
		cin >> temp;


		if (inHand(temp, 1) > 0) {

			//ask the card to the computer
			if(inHand(temp, 0) > 0){
				cout<<inHand(temp,0) << endl;
				int counter = inHand(temp, 0);
				for(int i=0;i<counter; i++){
					Card c = players[0].getHand().deleteCard(temp);
					players[1].getHand().addCard(c);
					players[1].checkForBooks();
				}
					printGame(debug);
			//check the computers hand for the card asked
			//if the card asked is in the computers hand, add it to the players hand
			//subtract it from the computers hand
			//if the card in the computers hand is a book, add to the book array, go again
			//go again
			} else {
				cout << "Go fish. Draw from the deck." << endl << endl;
				Card temp = d.remove_card();
				players[1].goFish(temp);
				players[1].checkForBooks();
			}

			//if the card is not in the computers hand
			//go fish
			//draw a card from the deck
			//add a card to your deck
			//remove 1 card from the total cards
			//if the card drew is the card you asked, go again
			//if the card drew makes a book, add to the book array, go again	
		} else{
			cout<< "You dont have this card, Input a rank you have." << endl;

		}
	} while (inHand(temp, 1) == 0);


	}

/*********************************************************************
** Function:game over
** Description: boolean to check if the games over
** Parameters: none
** Pre-Conditions: check if game is over
** Post-Conditions: return t of f
*********************************************************************/ 
	bool Game::gameOver(){
		if (players[0].getNumBooks() + players[1].getNumBooks() == 13) {
			return true;
		} else {
			return false;
		}
	}
/*********************************************************************
** Function:play game
** Description: this function plays the game
** Parameters: none
** Pre-Conditions: main calling
** Post-Conditions: plays the whole game
*********************************************************************/ 
	void Game::playGame(){

		int debug;
		cout << "Do you want to run debug mode? (1-yes, 2-no): ";
		cin >> debug;


		d.shuffleDeck();
		deal_card();
//game over 
		while (!gameOver())
		{
			playTurn(debug);
			compTurn(debug);
		}
//final check 
		if(players[0].getNumBooks() > players[1].getNumBooks()){
		cout << "The CPU won the game! Thanks for playing." << endl;
		} else {
		cout << "You won the game! Thanks for playing" << endl;
		}

	}
