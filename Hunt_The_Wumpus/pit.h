#ifndef PIT_H
#define PIT_H

#include "event.h"
#include <string>

using namespace std;

//child class
class Pit : public Event{
	public:	
		Pit();
		void encounter(Player&);
		void percept();
		char outputLetter();
};

#endif