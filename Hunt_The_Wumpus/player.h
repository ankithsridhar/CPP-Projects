#ifndef PLAYER_H
#define PLAYER_H


struct Player{
	int xCord;
	int yCord;
	int ogXcord;
	int ogYcord;
	bool playerAlive;
	bool hasGold;
	bool teleport;
};

#endif