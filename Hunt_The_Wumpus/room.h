#ifndef ROOM_H
#define ROOM_H

#include "event.h"
#include <string>

using namespace std;

class Room {
    private:
        Event* event;

    public:
        Room();
        ~Room();
        void set_event(Event*);
        Event* get_event() const;
        char eventLetter() const;
};

#endif