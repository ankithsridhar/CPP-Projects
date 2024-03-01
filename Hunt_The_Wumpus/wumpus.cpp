#include "wumpus.h"
#include <iostream>

using namespace std;

/*********************************************************************
 ** Function: wumpus
 ** Description: wumpus constructor
 ** Parameters: none
 *********************************************************************/
Wumpus::Wumpus() {
}

/*********************************************************************
 ** Function: encounter
 ** Description: encounters the wumpus
 ** Parameters: playerp
 *********************************************************************/
void Wumpus::encounter(Player& p) {
    cout << "The wumpus has eaten you and you died! Game over." << endl;
    p.playerAlive = false;
}

/*********************************************************************
 ** Function: percept
 ** Description: percepts wumpus
 ** Parameters: none
 *********************************************************************/
void Wumpus::percept(){
    cout << "You smell a terrible stench." << endl;
}

/*********************************************************************
 ** Function: outputletter
 ** Description: returns letter
 ** Parameters: none
 *********************************************************************/
char Wumpus::outputLetter(){
    return 'w';
}