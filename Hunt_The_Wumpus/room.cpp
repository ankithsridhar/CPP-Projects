#include "room.h"


using namespace std;

/*********************************************************************
 ** Function: room constructor
 ** Description: sets events as null
 ** Parameters: none
 *********************************************************************/
Room::Room(){
    event = NULL;
}

/*********************************************************************
 ** Function: settevent
 ** Description: sets events
 ** Parameters: event pointer
 *********************************************************************/
void Room::set_event(Event* e){
    event = e;
}

/*********************************************************************
 ** Function: get event
 ** Description: gets event
 ** Parameters: none , const function 
 *********************************************************************/
Event* Room::get_event() const{
    return event;
}

/*********************************************************************
 ** Function: room destructor
 ** Description: ddeletes event
 ** Parameters: none
 *********************************************************************/

Room::~Room(){
    if(event != NULL) {
        delete event;
    }
}

/*********************************************************************
 ** Function: event letter
 ** Description: returns nothing or event
 ** Parameters: const, so same
 *********************************************************************/

char Room::eventLetter() const{
    if(event == NULL) {
        return ' ';
    } else {
        return event->outputLetter();
    }
}