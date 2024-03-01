#include "card.h"
#include <iostream>
#include <string>

using namespace std;

/*********************************************************************
** Function: card
** Description: this function initializes rank and suit to -1
** Parameters: none
** Pre-Conditions: this function takes in private vairables
** Post-Conditions: this functon initializes them 
*********************************************************************/ 

    Card::Card(){
        this->suit = -1;
        this->rank = -1;
    }

    /*********************************************************************
** Function:card
** Description: this function sers rank and suit
** Parameters: int r, int s
** Pre-Conditions: this function takes in the integers r and s to return rank and suti
** Post-Conditions: sets rank and suti
*********************************************************************/ 

    Card::Card(int r, int s){
        this->rank = r; 
        this->suit = s;
    }

/*********************************************************************
** Function: get rank 
** Description: this function gets the rank of the functon
** Parameters: none
** Pre-Conditions: private access
** Post-Conditions: returns rank
*********************************************************************/ 
	int Card::getRank(){
		return rank;
	}
/*********************************************************************
** Function: get suit 
** Description: this suit gets the suit of the functon
** Parameters: none
** Pre-Conditions: private access
** Post-Conditions: returns suit
*********************************************************************/ 
	int Card::getSuit(){
		return suit;
	}
/*********************************************************************
** Function: set rank 
** Description: this rank sets the rank of the functon
** Parameters: none
** Pre-Conditions: private access
** Post-Conditions: sets suit
*********************************************************************/ 
	void Card::setRank(int r){
  		rank = r;
	}

/*********************************************************************
** Function: set suit 
** Description: this suit sets the suit of the functon
** Parameters: none
** Pre-Conditions: private access
** Post-Conditions: sets suit
*********************************************************************/ 

	void Card::setSuit(int s){
  		suit = s;
	}
/*********************************************************************
** Function:map rank
** Description: this function maps the rank of the function
** Parameters: none
** Pre-Conditions: it takes in the rank
** Post-Conditions: returns the ranks as string
*********************************************************************/ 
    string Card::map_rank(){
        if(this->rank == 12) {
            return "A";
        } else if(this->rank == 9) {
            return "J";
        } else if(this->rank == 10) {
            return "Q";
        } else if(this->rank == 11) {
            return "K";
        } else {
            return to_string(this->rank+2);
        }
        
    }
/*********************************************************************
** Function: map suit
** Description: maps the suit
** Parameters: none
** Pre-Conditions: this function maps the suit 
** Post-Conditions: returns suit ones a sstring
*********************************************************************/ 
    string Card::map_suit() {
        if(this->suit == 0) {
            return " of hearts";
        } else if(this->suit == 1) {
            return " of spades";
        } else if(this->suit == 2){
            return " of clubs";
        } else {
            return " of diamonds";
        }
    }

    /*********************************************************************
** Function: string convernt
** Description: converts string to rank
** Parameters: temp
** Pre-Conditions: takes in temp from game
** Post-Conditions: retrusn the int variables computers can read
JUSt: longer than 15 due to the returns of each type
*********************************************************************/ 

    int Card::stringConvert(string temp){
	if (temp == "2"){
		return 0;
	} else if (temp == "3"){
		return 1;
	} else if (temp == "4"){
		return 2;
	}else if (temp == "5"){
		return 3;
	}else if (temp == "6"){
		return 4;
	}else if (temp == "7"){
		return 5;
	}else if (temp == "8"){
		return 6;
	}else if (temp == "9"){
		return 7;
	}else if (temp == "10"){
		return 8;
	}else if (temp == "J"){
		return 9;
	}else if (temp == "Q"){
		return 10;
	}else if (temp == "K"){
		return 11;
	}else if (temp == "A"){
		return 12;
	}
}