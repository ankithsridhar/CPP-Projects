/******************************************************
** Program: pokemon.cpp
** Author: Ankith Sridhar
** Date: 10/22/2022
** Description: This program takes pokemon in a file from the user in a specific format and searches through
it and outputs the information in either the terminal or the file. This program also allows the user to add pokemon to the file
** Input: The program inputs include the user's choice on how they want to search the file as well as their inputs on them adding 
a new pokemon.
** Output: The outputs of the file include the terminal output of their searched results or file output for their searched results.
Another output is the file / terminal output for the new pokemon
******************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "pokemon.h"

using namespace std;

/*********************************************************************
** Function:  getIntegerValue
** Description: This function is used to accept the user inputs and provides a check to validate the inputs and manage error Handling for the function
** Parameters: 
        messageString - MessageString is used to pass the User Message for User Inputs.
        minValue  - Minimum value of the user Input
        maxValue  - Maximum value of the user Input
        errorMessage - Displaying the error Message
** Pre-Conditions: clear the user input and accept the correct Value out of the incorrect inputs
** Post-Conditions: Throw the error messages
*********************************************************************/

int getIntegerValue(string messageString, int minValue, int maxValue, string errorMessage) {
    string errorHandle = "";
    int returnValue = 0;

    // Clear the input stream to accept the correct message
    cin.clear();

    while (true) { 


        cout << messageString;
        cin >> returnValue;
        getline (cin, errorHandle);

        // Check all the charaters in the input String to ensure there are no invalid characters and only ensure integers are entered.
        for (int i= 0; i < errorHandle.length() ; i++){

            if ((errorHandle[i] == '-') || (errorHandle[i] == '.') || (errorHandle[i] == ',') || (errorHandle[i] == ' ') || (errorHandle[i] == '"') || (errorHandle[i] == '`')) {
                  returnValue = -1;
            }
        }

        // Check if the integer entered is withing the minValue and maxValue
        if ((returnValue >= minValue) && (returnValue <= maxValue)){
            return returnValue;
            break;
        }
        
        // If input does not satisfy the above conditions and clears and ignores the user input
        if (cin.fail()){
            cin.clear();
            cin.ignore(100000, '\n');
        }

        // Throws and errormessage if invalid inputs are entered.
        cout << errorMessage << endl;
    }
}

/*********************************************************************
** Function: create_pokemons(int num_pokemon)
** Description: This function will dynamically allocate an array of Pokemons (of the requested size)
** Parameters: The parameters are the number of pokemon that the user allocates
** Pre-Conditions: The pre conditions of the function is the file name that the user will put in, as this will create the array based on the file name
** Post-Conditions: The post conditions are that the array will be called in populate pokedex data based on the number of pokemon
*********************************************************************/ 

Pokemon* create_pokemons(int num_pokemon){
// This function will dynamically allocate an array of Pokemons (of the requested size):

    Pokemon* arr = new Pokemon[num_pokemon];
    return arr;
}

/*********************************************************************
** Function: create_moves(int num_pokemon)
** Description: This function creates a dynamic array for the number of moves so it can store it as strings
** Parameters: The parameters for this function is number of moves (num_pokemon is used as tempvar) 
** Pre-Conditions: the pre conditions for this function is that it taken in the number of moves from the file 
** Post-Conditions: the post conditions for this function is that it creates a dynamic array to be called in populate pokemon array 
*********************************************************************/ 

string* create_moves(int num_pokemon){
//This function will dynamically allocate an array of moves of a Pokemon (of the requested size):

    string* arr = new string[num_pokemon];
    return arr;
}

/*********************************************************************
** Function: populate_pokemon(Pokemon &d, ifstream &myFile)
** Description: This function reads the file and stores the pokemon struct in the 1d array
** Parameters: this function gets in the pokemon struct reference and the ifstream object
** Pre-Conditions: the preconditions for this function is to be filled by the populate pokedex data
** Post-Conditions: the post conditions for this function include being able to search through arrays by user input
*********************************************************************/ 

void populate_pokemon(Pokemon &d, ifstream &myFile){
//This function will fill a single Pokemon object with information that is read in from dex.txt.
    myFile >> d.dex_num >> d.name >> d.type >> d.num_moves;

// call create_moves
    d.moves = create_moves(d.num_moves);
    for(int i = 0; i < d.num_moves; i++){
        myFile >> d.moves[i];
    }

}

/*********************************************************************
** Function: populate_pokedex_data(Pokedex &d, ifstream &myFile)
** Description: This function will fill a Pokedex object with information that is read in from dex.txt. 
** Parameters: the paramerers for this function incude the struct pokedex, and the ifstream object myfile
** Pre-Conditions: the pre conditions for this function include the file name from the user
** Post-Conditions: the post conditions include populating the pokemon object with all the information from the file
*********************************************************************/ 

void populate_pokedex_data(Pokedex &d, ifstream &myFile){
//This function will fill a Pokedex object with information that is read in from dex.txt. 

    cout << "What is your name? : ";
    cin >> d.trainer;
    cout << "Hello " << d.trainer << "!" << endl;
    myFile >> d.num_pokemon;
    d.dex = create_pokemons(d.num_pokemon);

//call populate_pokemon to fill the pokedex array
    for (int i = 0; i < d.num_pokemon; i++) {
        populate_pokemon(d.dex[i], myFile);
    }
}

/*********************************************************************
** Function: delete_info(Pokedex &d)
** Description: This function deletes memory dynamically allocated
** Parameters: this function takes in the pokedex struct 
** Pre-Conditions: the preconditions of this function include both the moves and pokemon dynamic array
** Post-Conditions: the post conditions include freeing up the memory allocated in the heap
*********************************************************************/ 


//You need to implement a function that will delete all the memory that was dynamically allocated.
void delete_info(Pokedex &d){
    //deletes the moves

    for (int i = 0; i < d.num_pokemon; i++){
        delete[] d.dex[i].moves;  
        d.dex[i].moves = NULL;  
    }

    //deletes all the pokemon
    delete[] d.dex;
    d.dex = NULL;
}

/*********************************************************************
** Function: fileOutput (Pokedex &d, int i)
** Description: This function outputs the information on the file
** Parameters: this function takes in the pokedex struct and the int i from the for loop
** Pre-Conditions: the pre condtions for this function is if the user chooses to output on the file
** Post-Conditions: the post condition is the file outputs , and if it exists it appends to the file 
*********************************************************************/ 

void fileOutput (Pokedex &d, int i) {

    // outputs the file by creating an ofstream
    ofstream o;
    string ofile;
    string typestore = ".txt";

    cout << "Please enter your file name: ";
    cin >> ofile;
    ofile += typestore;

    // append to a file
    o.open(ofile.c_str(), ios::app);

    //file outputs
    o << endl;
    o << "Dex Number: " << d.dex[i].dex_num << endl;
    o << "Pokemon Name: " << d.dex[i].name << endl;
    o << "Pokemon Type: " << d.dex[i].type << endl;
    o << "Number of moves: " << d.dex[i].num_moves << endl;
    for (int j = 0; j < d.dex[i].num_moves; j++){
        o << "Move " << j + 1 << ": " << d.dex[i].moves[j] << endl;
    }
    o.close();

}

/*********************************************************************
** Function: fileOrTerm(Pokedex &d, int i)
** Description: this function asks user if they want to output on terminal or the file
** Parameters: this function takes in the pokedex struct and the i from the for loop
** Pre-Conditions: the pre condition of this function is the computer finds a match of the term they searched for
** Post-Conditions: the post conditions are the output on the terminal or the file 
*********************************************************************/ 

void fileOrTerm(Pokedex &d, int i) {

// asks user if they want to output on terminal or the file
    int outputChoice;
    outputChoice = getIntegerValue("Would you like to print the information on a file or on the terminal? (Press 1 for terminal and press 2 for file)", 1, 2, "Please enter either 1 or 2.");
    
    //if they terminal, then cout if not call the file output function
    if (outputChoice == 1) {
        cout << "Dex Number: " << d.dex[i].dex_num << endl;
        cout << "Pokemon Name: " << d.dex[i].name << endl;
        cout << "Pokemon Type: " << d.dex[i].type << endl;
        cout << "Number of moves: " << d.dex[i].num_moves << endl;
        for (int j = 0; j < d.dex[i].num_moves; j++){
            cout << "Move " << j + 1 << ": " << d.dex[i].moves[j] << endl;
        }
    } else {
        fileOutput (d, i);
    }
}

/*********************************************************************
** Function: searchDex(Pokedex &d)
** Description: This function searches pokemon by dex number
** Parameters: This function takes in the pokedex object by reference
** Pre-Conditions: the pre conditions of this function include the user choosing to search by dex
** Post-Conditions: the post conditions of this function include the output option for the results using terminal or file
*********************************************************************/ 

void searchDex(Pokedex &d) {
    //searches pokemon by dex number
    int dexNum;
    bool pokemon = false;
    cout << "Enter the dex number that you would like to search for: ";
    cin >> dexNum;

    //forloop that iterates through number of pokemon, if found call the file or term function
    for (int i = 0; i < d.num_pokemon; i++){
        if (dexNum == d.dex[i].dex_num) {
            fileOrTerm(d, i);
            pokemon = true;
        }
    }

    //bool that throws error
    if (pokemon == false) {
        cout << endl << "Your dex number wasn't found." << endl << endl;
    }

}

/*********************************************************************
** Function: searchName(Pokedex &d)
** Description: This function searches pokemon by name
** Parameters: This function takes in the pokedex object by reference
** Pre-Conditions: the pre conditions of this function include the user choosing to search by name
** Post-Conditions: the post conditions of this function include the output option for the results using terminal or file
*********************************************************************/ 

void searchName(Pokedex &d) {

//searches pokemon by name
    string dexName;
    bool pokemon = false;
    cout << "Enter the pokemon name that you would like to search for: ";
    cin >> dexName;
    for (int i = 0; i < d.num_pokemon; i++){
        if (dexName == d.dex[i].name) {
            fileOrTerm(d, i);
            pokemon = true;
        }
    }
    if (pokemon == false) {
        cout << endl << "Your pokemon name wasn't found." << endl << endl;
    }

}

/*********************************************************************
** Function: searchType(Pokedex &d)
** Description: This function searches pokemon by type
** Parameters: This function takes in the pokedex object by reference
** Pre-Conditions: the pre conditions of this function include the user choosing to search by type
** Post-Conditions: the post conditions of this function include the output option for the results using terminal or file
*********************************************************************/ 

void searchType(Pokedex &d) {
//searches pokemon by type
    string dexType;
    bool pokemon = false;
    cout << "Enter the pokemon type that you would like to search for (Capitalize the first letter): ";
    cin >> dexType;
    for (int i = 0; i < d.num_pokemon; i++){
        if (dexType == d.dex[i].type) {
            fileOrTerm(d, i);
            pokemon = true;
        } 
    }
    if (pokemon == false) {
        cout << endl << "Your pokemon name wasn't found." << endl << endl;
    }


}

/*********************************************************************
** Function: addPokemon(Pokedex &d)
** Description: This function adds pokemon if the user chooses to do so 
** Parameters: This function takes in the pokedex object by reference
** Pre-Conditions: the pre conditions of this function include the user choosing to add new pokemon
** Post-Conditions: the post conditions of this function include the output option for the results using terminal or file

**Justification - this function is over 15 lines because of the cout statements, where it asks to user to individually enter things
also, i cannot call the delete function here as it does a shallow copy of the addresses. This is why its a little longer
*********************************************************************/ 

void addPokemon(Pokedex &d) {
    //adds pokemon with copying array and adding 1 element
    Pokemon* tempvar;
    tempvar = create_pokemons(d.num_pokemon + 1);
    for (int i = 0; i < d.num_pokemon; i++) {
        tempvar[i] = d.dex[i];
    }

    //cout statements to prompt, and store user inputs into array
    cout << "Please enter your dex number: ";
    cin >> tempvar[d.num_pokemon].dex_num;
    cout << "Please enter your pokemon name: ";
    cin >> tempvar[d.num_pokemon].name;
    cout << "Please enter your pokemon type: ";
    cin >> tempvar[d.num_pokemon].type;
    cout << "Please enter the number of moves: ";
    cin >> tempvar[d.num_pokemon].num_moves;
    tempvar[d.num_pokemon].moves =  create_moves(tempvar[d.num_pokemon].num_moves);
    for (int i = 0; i < tempvar[d.num_pokemon].num_moves; i++){
        cout << "Please enter move " << i + 1 << ": ";
        cin >> tempvar[d.num_pokemon].moves[i];
    }
    
    //delete the array to avoid leaks
    delete[] d.dex;
    d.dex = NULL;
    d.dex = tempvar;
    fileOrTerm(d, d.num_pokemon);
    d.num_pokemon = d.num_pokemon + 1;

}


/*********************************************************************
** Function: printStuff(Pokedex &d)
** Description: This function prints out the basic input that the user is supposed to see initially
** Parameters: This function takes in the pokedex object by reference
** Pre-Conditions: the preconditions of this function include the main function calling to print out the initial outputs
** Post-Conditions: the post conditions of this function are the calls to search by functions
*********************************************************************/ 

void printStuff(Pokedex &d) {
    //initial print out function asking the user to put in an option
    int userOption;

    //do while to keep repeating program if they dont quit and keep presenting options 
    do {
        cout << endl << "Choose an option from 1-5 about how you would like to search through your file." << endl;
        cout << "[1] Search by pokemon dex number" << endl;
        cout << "[2] Search by pokemon name" << endl;
        cout << "[3] Search by pokemon type" << endl;
        cout << "[4] Add new pokemon" << endl;
        cout << "[5] Quit program" << endl;
        cout << "Enter option here, from 1 to 5: ";
        cin >> userOption;

    // funtion calls to search dex respectively
        if (userOption == 1) {
            searchDex(d);
        } else if (userOption == 2) {
            searchName(d);
        }else if (userOption == 3) {
            searchType(d);
        }else if (userOption == 4) {
            addPokemon(d);
        }
    } while (userOption != 5);
}
