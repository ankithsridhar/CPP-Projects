#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;





class Card {
private:
    int rank; // Should be in the range 0-12.
    int suit; // Should be in the range 0-3.
public:

    Card(){
        this->suit = -1;
        this->rank = -1;
    }

    Card(int r, int s){
        this->rank = r; 
        this->suit = s;
    }

	int getRank(){
		return rank;
	}

	int getSuit(){
		return suit;
	}

	void setRank(int r){
  		rank = r;
	}

	void setSuit(int s){
  		suit = s;
	}

    string map_rank(){
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

    string map_suit() {
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


	int stringConvert(string temp){
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
    void print_card() {
        cout << "Card: " << map_rank() << map_suit() << endl;
    }
};

class Deck {
 private:
 Card cards[52]; //A full deck of cards
 int n_cards; // Number of cards remaining in the deck.
 
public:
// must have constructors, destructor, accessors, and mutators
	Deck(){
		this->n_cards = 52;
		for (int i = 0; i < this->n_cards; ++i)
		{
			this->cards[i].setRank(i%13);
			this->cards[i].setSuit(i/13);
		}
	}

	int getDeckCards(){
		return n_cards;
	}

	void shuffleDeck(){
		int temp = 0;
		int randomIndex = 0;
		srand(time(NULL));
		for(int i = 0; i < n_cards; i++){
			int card1 = rand() % 52;
			int card2 = rand() % 52;
			Card temp = cards[card1];
			cards[card1] = cards[card2];
			cards[card2] = temp;
		}

	}

	Card& remove_card(){
		this->n_cards --;
		return this->cards[this->n_cards];
	}
};

class Hand {
private:
	Card* cards; // An array of cards in hand
	int n_cards; // Number of cards in the hand.
public:
 // must have constructors, destructor, accessors, and mutators
	Hand(){
		this->n_cards = 0;
		this->cards = NULL;
	}

	int getn_cards(){
		return n_cards;
	}

	Card* getCards() {
		return cards;
	}

	int inHand(int temp) {
	//for loop for player number of cards 
	int counter = 0;
	for (int i=0; i<n_cards; i++){
		if (temp == cards[i].getRank()) {
			//RETURN TRUE
			counter ++;
		}
		// else {
		// 	//RETURN FALSE
		// 	counter;

		// 	//you dont have that card. go again
		// 	//repeat player turn.
		// }
	}
	return counter;
	}

	Card deleteCard(string temp){
		//allocate a new array of Card objects with the size + 1
		Card* new_arr = new Card [this->n_cards - 1];
		bool cardFound = false;

		//copy all objects from the old array (cards) into the new array
		int counter= 0;

		Card t;

		for (int i = 0; i < this->n_cards; ++i)
		{
			if ((cardFound) or (this->cards[i].getRank() != cards[i].stringConvert(temp))) {
				new_arr[counter] = this->cards[i]; // AOO of Card 
				counter++;
			} else {
				t = this->cards[i];
				cardFound = true;
			}
		}

		//free the cards array (old array)
		if (this->cards != NULL){
			delete [] this->cards;
		}
		//set cards array to the new array
		this->cards = new_arr;

		this->n_cards--;

		return t;

	}

	Card deleteBook(int rank){
		//allocate a new array of Card objects with the size + 1
		Card* new_arr = new Card [this->n_cards -1];
		bool cardFound = false;

		//copy all objects from the old array (cards) into the new array
		int counter= 0;

		Card t;

		for (int i = 0; i < this->n_cards; ++i)
		{
			if ((cardFound) or (this->cards[i].getRank() != rank)) {
				new_arr[counter] = this->cards[i]; // AOO of Card 
				counter++;
			} else {
				t = this->cards[i];
				cardFound = true;
			}
		}

		//free the cards array (old array)
		if (this->cards != NULL){
			delete [] this->cards;
		}
		//set cards array to the new array
		this->cards = new_arr;

		this->n_cards--;

		return t;

	}


	~Hand() {
		if (this->cards != NULL){
			delete [] this->cards;
			this->cards = NULL;
		}
	}

	void addCard(Card& c){
		//allocate a new array of Card objects with the size + 1
		Card* new_arr = new Card [this->n_cards + 1];

		//copy all objects from the old array (cards) into the new array
		for (int i = 0; i < this->n_cards; ++i)
		{
			new_arr[i] = this->cards[i]; // AOO of Card 
		}

		//add the new Card object c into index n_cards
		new_arr[this->n_cards] = c;

		//free the cards array (old array)
		if (this->cards != NULL)
			delete [] this->cards;

		//set cards array to the new array
		this->cards = new_arr;

		//increment the n_cards
		this->n_cards++;
	}


};

class Player {
 private:
 Hand hand;
 int* books; // Array with ranks for which the player has books.
 int n_books;
 public:
 // must have constructors, destructor, accessors, and mutators
	Player(){
		this->books = new int[13];
		n_books = 0;
	}
	Hand& getHand(){
  		return hand;
	}

	int getNumBooks(){
		return n_books;
	}

	void setNumBooks(int n){
		this->n_books = n;
	}

	int getNumCards(){
		return hand.getn_cards();
	}

	void goFish(Card &go) {
		this->hand.addCard(go);
	}
	// Card removeRank(int temp){
	// 	return hand.retCard(temp);
	// }

	void addBook(int j){
		int* new_arr = new int [this->n_books + 1];

		//copy all objects from the old array (cards) into the new array
		for (int i = 0; i < this->n_books; ++i)
		{
			new_arr[i] = this->books[i]; // AOO of Card 
		}

		//add the new Card object c into index n_cards
		new_arr[this->n_books] = j;

		//free the cards array (old array)
		if (this->books != NULL)
			delete [] this->books;

		//set cards array to the new array
		this->books = new_arr;

		//increment the n_cards
		this->n_books++;

	}


	void checkForBooks(){
		//looping though the hand
		for (int i = 0; i < 13; i++)
		{
			if(hand.inHand(i) == 4){
				hand.deleteBook(i);
				hand.deleteBook(i);
				hand.deleteBook(i);
				hand.deleteBook(i);
				addBook(i);
			}
		}
		
		//if there is 4 of a kind of one suit
		//then, add 1 to the book counter
		//delete the 4 of a kind from the players/ computers hand


	}

	void print_books(){
		for (int i = 0; i < n_books; i++)
		{
			cout << books [i] + 2 << ", ";
		}

		cout << endl;
	}


	void place_a_card(Card& c){
		this->hand.addCard(c);
	}
};

class Game {
private:
	Deck d;
	Player players[2];
public:
 // must have constructors, destructor, accessors, and mutators
	void deal_card(){

		for (int i = 0; i < 14; ++i)
		{
			Card c = this->d.remove_card();

			
			this->players[i%2].place_a_card(c);
		}
	
	}

	void dealCards(){
		for(int i = 0; i<7; i++) {
			players[0].place_a_card(d.remove_card());
			players[1].place_a_card(d.remove_card());
		}
	}


int inHand(string temp, int j) {
	//for loop for player number of cards 
	int counter = 0;
	for (int i=0; i<players[j].getNumCards(); i++){
		if (players[j].getHand().getCards()[i].stringConvert(temp) == players[j].getHand().getCards()[i].getRank()) {
			//RETURN TRUE
			counter ++;
		
		}
		// else {
		// 	//RETURN FALSE
		// 	counter;

		// 	//you dont have that card. go again
		// 	//repeat player turn.
		// }
	}
	return counter;
}


void printGame(int debug){
	cout << "Your hand: ";

	int playCard = players[1].getHand().getn_cards();

	for(int i = 0; i < playCard; i++){
		cout << "(" << players[1].getHand().getCards()[i].map_rank() << ") ";
	}
	cout << "Books: ";
	players[1].print_books();
	

	if (debug==1){
		cout << "CPU HAND: ";
		int compCard = players[0].getHand().getn_cards();
		for(int i = 0; i < compCard; i++){
			cout << "(" << players[0].getHand().getCards()[i].map_rank() << ") ";
		} 
		cout << "Books: ";
		players[0].print_books();
	}

	cout << "Cards remaining in deck: " << d.getDeckCards() << endl;
}

void compTurn(int debug) {
	if(players[0].getHand().getn_cards() < 1){
    	cout << "You draw a card.";
		Card temp = d.remove_card();
		players[0].goFish(temp);
    	printGame(debug);
  	}

	cout << "Computer's turn..." << endl;

	int randnum = rand()% players[0].getNumCards();
	string compCard = players[0].getHand().getCards()[randnum].map_rank();
	cout << endl<< "The computer asks you a " << compCard << endl;

	if(inHand(compCard, 1) > 0){

		int counter = inHand(compCard, 1);
		for(int i=0;i<counter; i++){
			Card c = players[1].getHand().deleteCard(compCard);
			players[0].getHand().addCard(c);
			players[0].checkForBooks();
		}
			
		//players[0].removeRank(stringConvert(temp));
	} else {
		cout << "Go fish. Draw from the deck." << endl << endl;
		Card temp = d.remove_card();
		players[0].goFish(temp);
		players[0].checkForBooks();
	}


}

void playTurn(int debug){
	printGame(debug);
	string temp;
do{
	if(players[1].getHand().getn_cards() < 1){
    	cout << "You draw a card.";
		Card temp = d.remove_card();
		players[1].goFish(temp);
    	printGame(debug);
  	}
	cout << endl<< "What do you want to ask the computer?: ";
	cin >> temp;


	if (inHand(temp, 1) > 0) {

		//ask the card to the computer
		if(inHand(temp, 0) > 0){
			cout<<inHand(temp,0) << endl;
			int counter = inHand(temp, 0);
			for(int i=0;i<counter; i++){
				Card c = players[0].getHand().deleteCard(temp);
				players[1].getHand().addCard(c);
				players[1].checkForBooks();
			}
				printGame(debug);
			//players[0].removeRank(stringConvert(temp));
		} else {
			cout << "Go fish. Draw from the deck." << endl << endl;
			Card temp = d.remove_card();
			players[1].goFish(temp);
			players[1].checkForBooks();
		}
		//check the computers hand for the card asked
		//if the card asked is in the computers hand, add it to the players hand
		//subtract it from the computers hand
		//if the card in the computers hand is a book, add to the book array, go again
		//go again

		//if the card is not in the computers hand
		//go fish
		//draw a card from the deck
		//add a card to your deck
		//remove 1 card from the total cards
		//if the card drew is the card you asked, go again
		//if the card drew makes a book, add to the book array, go again	
	} else{
		cout<< "You dont have this card, Input a rank you have." << endl;

	}
} while (inHand(temp, 1) == 0);


}


bool gameOver(){
	if (players[0].getNumBooks() + players[1].getNumBooks() == 13) {
		return true;
	} else {
		return false;
	}
}

void playGame(){

	int debug;
	cout << "Do you want to run debug mode? (1-yes, 2-no): ";
	cin >> debug;


	d.shuffleDeck();
	deal_card();

	while (!gameOver())
	{
		playTurn(debug);
		compTurn(debug);
	}

	if(players[0].getNumBooks() > players[1].getNumBooks()){
	cout << "The CPU won the game! Thanks for playing." << endl;
	} else {
	cout << "You won the game! Thanks for playing" << endl;
	}

}
};


int main(){
	int playAgain;

	do{
		Game g;
		g.playGame();

		cout << "Do you want to play again? (1-yes, 2-no): ";
		cin >> playAgain;
	} while (playAgain == 1);

	cout << "Thanks for playing." << endl;

    return 0;
}


