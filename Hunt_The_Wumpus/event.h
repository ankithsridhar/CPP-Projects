#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>
#include "player.h"

using namespace std;

class Event{
    protected:
    public:
    //virtual 
        Event();
        virtual void encounter(Player&) = 0;
        virtual void percept() = 0;
        virtual char outputLetter() = 0;

};

#endif