#ifndef GAME_H
#define GAME_H

#include "room.h"
#include "player.h"


#include <vector>
#include <string>

using namespace std;

// struct Player{
// 	int xCord;
// 	int yCord;
// 	int ogXcord;
// 	int ogYcord;
// 	bool playerAlive;
// };

//child class
class Game{
	private:
		vector <vector<Room> > rooms;
		bool debug;
		Player p;
		int vectorSize;
		bool wumpusDead;
		bool gold;
		int arrows;
		bool gameOver;
// public classes
	public:
		Game();
		void playGame();
        void makeGrid();
		void populateEvents();
		void fillRoom(Event*);
		void populatePlayer();
		int randomNumber();
		void printBoard();
		void movePlayer();
		void shootArrow(string);
		void printPercepts();
		void printEncounter();

};

#endif