#include "gold.h"
#include <iostream>

using namespace std;

Gold::Gold() {
}

/*********************************************************************
 ** Function: encounter
 ** Description: encounters gold
 ** Parameters: player struct
 *********************************************************************/

void Gold::encounter(Player& p) {
    cout << "You have collected the gold!" << endl;
    p.hasGold = true;
}

/*********************************************************************
 ** Function: percept
 ** Description: percepts gold
 ** Parameters: none
 *********************************************************************/

void Gold::percept(){
    cout << "You see a glimmer nearby." << endl;
}

/*********************************************************************
 ** Function: outputletter
 ** Description: returns char
 ** Parameters: none
 *********************************************************************/

char Gold::outputLetter(){
    return 'g';
}