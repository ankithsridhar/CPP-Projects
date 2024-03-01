#ifndef BATS_H
#define BATS_H

#include "event.h"
#include <string>

using namespace std;

//child class
class Bats : public Event{
	protected:
	public:	
	//bats stuff
		Bats();
		void encounter(Player&);
		void percept();
		char outputLetter();
};

#endif