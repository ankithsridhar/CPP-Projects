#include "game.h"
#include "room.h"
#include "pit.h"
#include "gold.h"
#include "wumpus.h"
#include "bats.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <stdexcept>

/*
user input for grid size
user input for debug/ non debug
make a grid - 2d vector of rooms
populate it with events
print out the cave
*/

/*********************************************************************
 ** Function: game
 ** Description: constructs game class
 ** Parameters: none
 *********************************************************************/

Game::Game() {
    p.playerAlive = true;
    gameOver = false;
    p.hasGold = false;
    arrows = 3;
}

/*********************************************************************
 ** Function: randomnumber
 ** Description: returns random number form vector size
 ** Parameters: none
 *********************************************************************/
int Game::randomNumber(){
    int rando = rand() % vectorSize;
    return rando;
}

/*********************************************************************
 ** Function: shootarrow
 ** Description: shoots an arrow
 ** Parameters: usermove
 *********************************************************************/
void Game::shootArrow(string userMove) {
    cout << "arrow shot!" << endl;
    --arrows;
    try {
        // ip for arrow
        if (userMove == " w") {
            for (int i = 1; i <= 3; i++){
                if(rooms.at(p.xCord).at(p.yCord - i).eventLetter() == 'w') {
                    wumpusDead = true;
                }
            }

            //right arrow
        } else if (userMove == " a") {
            for (int i = 1; i <= 3; i++){
                if(rooms.at(p.xCord - i).at(p.yCord).eventLetter() == 'w') {
                    wumpusDead = true;
                }
            }
        // down arrow
        } else if (userMove == " s") {
            for (int i = 1; i <= 3; i++){
                if(rooms.at(p.xCord).at(p.yCord + i).eventLetter() == 'w') {
                    wumpusDead = true;
                }
            }
        // right arrow
        } else if (userMove == " d") {
            for (int i = 1; i <= 3; i++) {
                if(rooms.at(p.xCord+i).at(p.yCord).eventLetter() == 'w') {
                    wumpusDead = true;
                }
            }
            
        } 
    } 
    //catch error
    catch(out_of_range& e){
        cout << "Arrow hit a wall" << endl;
    }
// sets wumpus dead
    if (wumpusDead == true) {
        cout << "Wumpus died!" << endl;
    }
}

/*********************************************************************
 ** Function: move player
 ** Description: moves the player
 ** Parameters: none
 *********************************************************************/
void Game::movePlayer(){
    string userMove;
    cout << "Where do you want to move the player? Press space followed by wasd to shoot an arrow (wasd): ";
    getline(cin,userMove);
// moves up
    if (userMove == "w") {
        if (p.yCord == 0) {
            cout << "Out of bounds." << endl;
        } else {
            p.yCord --;
        }

        // moves right 
    } else if (userMove == "a") {
        if(p.xCord == 0) {
            cout << "Out of bounds." << endl;
        } else {
            p.xCord --;
        }
        // move down
    } else if (userMove == "s") {
        if (p.yCord == vectorSize - 1 ){
            cout << "Out of bounds." << endl;
        } else {
            p.yCord ++;
        }
        //move right
    } else if (userMove == "d") {
        if (p.xCord == vectorSize - 1){
            cout << "Out of bounds." << endl;
        } else {
            p.xCord ++;
        }
    } else {
        shootArrow(userMove);
    }
//print board
    printBoard();

}

/*********************************************************************
 ** Function: print encounter
 ** Description: prints encounter
 ** Parameters: none
 *********************************************************************/

void Game::printEncounter(){
    if ((rooms[p.xCord][p.yCord].get_event() != NULL)) {
        rooms[p.xCord][p.yCord].get_event()->encounter(p);
    }
    //player alive
    if (p.playerAlive != true) {
            gameOver = true;
    }
    //final gold or wumpus check
    if ((p.hasGold == true) && (p.ogXcord == p.xCord) && (p.ogYcord == p.yCord) && (wumpusDead == true)){ 
            gameOver = true;
    }
}


/*********************************************************************
 ** Function: printpercepts
 ** Description: prints the percepts
 ** Parameters: none
 *********************************************************************/
void Game::printPercepts(){

    if (p.xCord > 0){
        // left room
        if ((rooms[p.xCord-1][p.yCord].get_event() != NULL)) {
            rooms[p.xCord-1][p.yCord].get_event()->percept();
        }
    }

    if (p.xCord < vectorSize - 1){
        //right room
        if ((rooms[p.xCord+1][p.yCord].get_event() != NULL)) {
            rooms[p.xCord+1][p.yCord].get_event()->percept();
        }
    }
    if (p.yCord > 0){
        //down room
        if ((rooms[p.xCord][p.yCord-1].get_event() != NULL)) {
            rooms[p.xCord][p.yCord-1].get_event()->percept();
        }  
    }
    if (p.yCord < vectorSize - 1){
        //up room
        if ((rooms[p.xCord][p.yCord+1].get_event() != NULL)) {
            rooms[p.xCord][p.yCord+1].get_event()->percept();
        } 
    }
     // cout << " i am here 5 " << endl;
}


/*********************************************************************
 ** Function: print board
 ** Description: prints the board
 ** Parameters: none
 *********************************************************************/
void Game::printBoard() {
    
    for (int i = 0; i < vectorSize; i++) {
        for (int j = 0; j < vectorSize; j++) {
            if (j == p.xCord && i == p.yCord){
                cout << "[*]";
            } else if (debug == true){
                cout << "[" << rooms[j][i].eventLetter() << "]";
            } else {
                cout << "[ ]";
            }
        }  
        cout << endl;
    }
    cout << "Arrows: " << arrows << endl;
    printEncounter();
    if (p.playerAlive == true) {
        printPercepts();
    }
}

/*********************************************************************
 ** Function: populate player
 ** Description: populates the player
 ** Parameters: none
 *********************************************************************/

void Game::populatePlayer(){
    int row = randomNumber();
    int col = randomNumber();
    while (rooms[row][col].get_event() != NULL) {
        row = randomNumber();
        col = randomNumber();
    }
    p.xCord = row;
    p.yCord = col;
    p.ogXcord = p.xCord;
    p.ogYcord = p.yCord;
}

/*********************************************************************
 ** Function: fill room
 ** Description: fills the room
 ** Parameters: Event*e
 *********************************************************************/
void Game::fillRoom(Event* e) {
    int row = randomNumber();
    int col = randomNumber();
    while (rooms[row][col].get_event() != NULL) {
        row = randomNumber();
        col = randomNumber();
    }
    rooms[row][col].set_event(e);
    populatePlayer();
}

/*********************************************************************
 ** Function: poppulateevents
 ** Description: populates the events
 ** Parameters: none
 *********************************************************************/
void Game::populateEvents(){
    fillRoom(new Bats);
    fillRoom(new Bats);
    fillRoom(new Pit);
    fillRoom(new Pit);
    fillRoom(new Gold);
    fillRoom(new Wumpus);
}


/*********************************************************************
 ** Function: makegrid
 ** Description: makes the grid
 ** Parameters: none
 *********************************************************************/

void Game::makeGrid(){

    //sets size
    cout << "Set the size you want your game board to be: ";
    cin >> vectorSize;
//asks debug
    cout << "Do you want debug? (press 1 for yes and 0 for no): ";
    cin >> debug;
    cin.ignore();

    //vector creation
    for(int i = 0; i < vectorSize; i++){
        vector<Room> row;
        rooms.push_back(row);
        for(int j = 0; j < vectorSize; j++){
            Room tempRoom;
            rooms[i].push_back(tempRoom);
        }
    }
//populate events

    populateEvents();
    printBoard();
    while (!gameOver){
        movePlayer();
        if (p.playerAlive != true) {
            gameOver = true;
        }
        if ((p.hasGold == true) && (p.ogXcord == p.xCord) && (p.ogYcord == p.yCord) && (wumpusDead == true)){
            gameOver = true;

        }

    }
//reset stuff
    rooms.clear();
    p.playerAlive = true;
    arrows = 3;
    wumpusDead = false;
    p.hasGold = false;
    

}

/*********************************************************************
 ** Function: playgame
 ** Description: plays game
 ** Parameters: none
 *********************************************************************/
void Game::playGame(){
    makeGrid();
}

