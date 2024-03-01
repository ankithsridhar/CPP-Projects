#include <iostream>
#include <fstream>
#include <string>
#include "pokemon.h"

using namespace std;

/*********************************************************************
** Function: main()
** Description: This function runs the whole program
** Parameters: None
** Pre-Conditions: running the program
** Post-Conditions: outputting, quitting program
*********************************************************************/ 

int main () {
// declare ifstream and struct objects
    string fname;
    string typestore = ".txt";
    ifstream myFile; 
    Pokedex d;

//welcome the user 
    cout << "Welcome to the Pokedex!" << endl;
    cout << "Enter the name of the file you would like to search through (without the .txt): ";
    cin >> fname;
    fname = fname + typestore;

//open the file of the user
    myFile.open(fname.c_str());

//if file is found, run functions if not quit the program gracefully
    if (myFile.is_open()){ 
        populate_pokedex_data(d, myFile);
        printStuff(d);
        myFile.close();
    } else {
        cout << "Your file doesn't exist. The program will quit." << endl;
        return 1;
    }

// if user types in option 5
    cout << endl << "Thanks for playing! You have quit." << endl;

    delete_info(d); 

    return 0;
}