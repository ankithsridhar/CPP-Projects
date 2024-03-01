/*
 * Program: wumpus.cpp
 * Author: Ankith Sridhar
 * Date: 5/10/2022
 * Description: This program allows people to play hunt the wumpus
 * Input: program inouts users coine to move and shoot arrow
 * Output: program outpus the game messages and wins or loses 
*/

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "game.h"

using namespace std;


/*********************************************************************
** Function: main
** Description: main function 
** Parameters: none
** Pre-Conditions: game class
** Post-Conditions: runs program 
*********************************************************************/ 
int main(){
	srand(time(NULL));
	Game g;
	int playAgain = 1;
//play again
	while (playAgain == 1) {
		g.playGame();
		cout << "Do you want to play again?: 1 yes 0 no: ";
		cin >> playAgain;
	}

	cout << "Thanks for playing." << endl;
}