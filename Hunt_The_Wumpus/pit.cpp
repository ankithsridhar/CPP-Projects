#include "pit.h"
#include <iostream>

using namespace std;

/*********************************************************************
 ** Function: pit 
 ** Description: pitconstructor
 ** Parameters: none
 *********************************************************************/
Pit::Pit() {
}

/*********************************************************************
 ** Function: encounter
 ** Description: encounter put
 ** Parameters: player p
 *********************************************************************/
void Pit::encounter(Player& p) {
    cout << "You fell down the pit! You lose!" << endl;
    p.playerAlive = false;
}

/*********************************************************************
 ** Function: percept
 ** Description: percepts bat
 ** Parameters: none
 *********************************************************************/
void Pit::percept(){
    cout << "You feel a breeze." << endl;
}


/*********************************************************************
 ** Function: outputletter
 ** Description: outputs b
 ** Parameters: none
 *********************************************************************/
char Pit::outputLetter(){
    return 'p';
}