#ifndef WUMPUS_H
#define WUMPUS_H

#include "event.h"
#include <string>

using namespace std;

//child class
class Wumpus : public Event{
	protected:
	public:	
		Wumpus();
		void encounter(Player&);
		void percept();
		char outputLetter();
};

#endif