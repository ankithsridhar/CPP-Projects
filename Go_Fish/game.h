#ifndef GAME_H
#define GAME_H 

#include "deck.h"
#include "player.h"

class Game
{
private:
	Deck d;
	Player players[2];

public:
	void deal_card();
	int inHand(string, int);
	void printGame(int );
	void compTurn(int );
	void playTurn(int );
	bool gameOver();
	void playGame();
	
};
#endif