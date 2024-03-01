#ifndef CARD_H
#define CARD_H 
#include <string>


using namespace std;

class Card
{
private:
	int suit; //0-3
	int rank; //0-12
	
public:
	Card();
	Card(int, int);
	int getRank();
	int getSuit();
	void setRank(int);
	void setSuit(int);
	string map_rank();
	string map_suit();
	int stringConvert(string);
};
#endif