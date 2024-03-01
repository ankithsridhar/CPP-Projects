/******************************************************
** Program: asm31.zip
** Author: Ankith Sridhar
** Date: 11/9/2022
** Description: This program plays go fish with a computer. 
** Input: The user inputs what card it wants from the computer
** Output: The program outputs the cards that the user has/ wants and also CPU cards until one wins.
******************************************************/

#include <iostream>
#include "game.h"

using namespace std;


/*********************************************************************
** Function: main
** Description: main funct that creates a game object
** Parameters: none
** Pre-Conditions: need a game class
** Post-Conditions: working program 
*********************************************************************/ 
int main(){
	int playAgain;

	do{
		Game g;
		g.playGame();

		cout << "Do you want to play again? (1-yes, 2-no): ";
		cin >> playAgain;
	} while (playAgain == 1);

	cout << "Thanks for playing." << endl;

    return 0;
}

/*

void playTurn(int debug){
	printGame(debug);
	string temp;
do{
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
			//players[0].removeRank(stringConvert(temp));
		} else {
			cout << "Go fish. Draw from the deck." << endl << endl;
			Card temp = d.remove_card();
			players[1].goFish(temp);
			players[1].checkForBooks();
		}
		//check the computers hand for the card asked
		//if the card asked is in the computers hand, add it to the players hand
		//subtract it from the computers hand
		//if the card in the computers hand is a book, add to the book array, go again
		//go again


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

	cout << "Computer's turn..." << endl;
	
	int rank;
	for (int i = 0; i < players[1].numCards; i++)
	{
		if ()
	}
	
	if (there is a matching rank) {
		rank = the matching rank
	}
	else {
		rank = rand()% players[0].getNumCards();
	}

	string compCard = players[0].getHand().getCards()[rank].map_rank();
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


void playTurn(int debug){
	printGame(debug);
	string temp;
do{
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
			//players[0].removeRank(stringConvert(temp));
		} else {
			cout << "Go fish. Draw from the deck." << endl << endl;
			Card temp = d.remove_card();
			players[1].goFish(temp);
			players[1].checkForBooks();
		}
		//check the computers hand for the card asked
		//if the card asked is in the computers hand, add it to the players hand
		//subtract it from the computers hand
		//if the card in the computers hand is a book, add to the book array, go again
		//go again


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

*/