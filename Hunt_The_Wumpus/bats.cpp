#include "bats.h"
#include <iostream>

using namespace std;

/*********************************************************************
 ** Function: Bats
 ** Description: empty constructor
 ** Parameters: none
 *********************************************************************/
Bats::Bats() {
}

/*********************************************************************
 ** Function: encounter
 ** Description: encounter bats
 ** Parameters: player p
 *********************************************************************/
void Bats::encounter(Player& p) {
    cout << "You have entered the bats room and have been teleported to a random location!" << endl;
    p.teleport = true;
}

/*********************************************************************
 ** Function: percept
 ** Description: percepts bats
 ** Parameters: none
 *********************************************************************/
void Bats::percept(){
    cout << "You hear wings flapping." << endl;
}

/*********************************************************************
 ** Function: outputletter
 ** Description: returns outputletter
 ** Parameters: none
 *********************************************************************/
char Bats::outputLetter(){
    return 'b';
}