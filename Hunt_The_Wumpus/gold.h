#ifndef GOLD_H
#define GOLD_H

#include "event.h"
#include <string>

using namespace std;

//child class
class Gold : public Event{
	protected:
	public:	
		Gold();
		void encounter(Player&);
		void percept();
		char outputLetter();
};

#endif