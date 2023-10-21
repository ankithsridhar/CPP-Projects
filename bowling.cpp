/******************************************************
** Program: bowling.cpp
** Author: Ankith Sridhar
** Date: 10/09/2022
** Description: This program simulates the bowling game with random numbers and calculates the scoring for each frame as well as displaying the total frame.
** Input: The name of the user, the enter button to continue, and weather the user would like to play again or not
** Output: THe program outputs the bowling frame and updates the score and rolls with each enter button push.
******************************************************/


#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <ctime>
#include <string>
#define ROUND 10
#define ROLL  4
#define TOTALPINS 10

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
** Function: greeting()
** Description: This function is for the start of the game, where it greets the user and asks them for their name
** Parameters: This function has no parameters
** Pre-Conditions: This fuction is called in the main to be ran
** Post-Conditions: This function allows the user to input the name and welcomes the user
*********************************************************************/ 

void greeting() {
	//greet player and ask name
    string name;
    cout << endl << "Welcome to bowling!" << endl;
    cout << "What's your name? : ";
    cin >> name;
    cout << endl << "Hello " << name << "!" << endl;
}

/*********************************************************************
** Function: frame output()
** Description: This function does the actual outputting of the frame to the console. It takes the information
from the frame function and outputs it on the console
** Parameters: int pins[10][4], int i, int j, bool isStrike, bool isSpare, int totalScore
** Pre-Conditions: The preconditions of this function include the pins array, integers i and j, the true or false value if the 
roll is a strike or spare, and the total score of the rolls 
** Post-Conditions: The post conditions of this function include the final output of the code
*********************************************************************/ 

void frameOutput(int pins[10][4], int i, int j, bool isStrike, bool isSpare, int totalScore) {
	cout << endl << "Name     |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  10        | Total" << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "Player1  | ";
	// output first line
	for (i = 0; i < 10; i++) {
		if ((i == 9) and ((pins[9][0] == 10) or (pins[9][0] + pins[9][1] == 10))) {
			cout << setw(2) << pins [i][0] << setw(3) << pins [i] [1] << setw(2) << pins [i][2] << "|";
		} else {
			cout << setw(2) << pins [i][0] << setw(3) << pins [i] [1] << "|";
		}
	}
//total score output
	cout << " " << totalScore << endl;
	cout << "         | ";
	//output second line
	for (i = 0; i < 10; i++) {
		cout << setw(5) << pins [i][3] << "|";
	}
	cout << endl;
	cout << "-----------------------------------------------------------------------------------" << endl;

}

/*********************************************************************
** Function: bowls()
** Description: this function does the press enter to roll as well as telling the user how many pins they knocked down
** Parameters: intpinsRemaining
** Pre-Conditions: This function takes in the pins remaining and sets the rolled number equal to it
** Post-Conditions: THis function's post condition is to update the int pins remaining and keep telling the user how many pins they knocked down
*********************************************************************/ 

int bowls(int& intpinsRemaining) {
	//enter to roll here
	int rolledNumber;
	cout << "Press enter to roll." << endl;
	cin.get();

	//random number
	rolledNumber = rand() % (intpinsRemaining + 1);
	cout << "You knocked down " << rolledNumber << " pins." << endl;
	intpinsRemaining = rolledNumber ;
}

/*********************************************************************
** Function: recount()
** Description: this function recounts the scores for both strike and spare
** Parameters: i, pins array
** Pre-Conditions: This function takes in the i value from the array and the whole pins array
** Post-Conditions: THis function's post condition is to update the scoring if it is a strike or spare
*********************************************************************/ 

void recount(int i, int pins[10][4]){
// function for strike and spare calculation
	for (int j = 0; j <= i; j++ ){
		if (pins[j][0] == 10) { // STRKE
			pins[j][3] = pins[j][0] + pins [j+1][0] + pins [j+1][1];
		}
		if ((pins[j][0] + pins[j][1] == 10)) //SPARE
			pins[j][3] = pins[j-1][3] + pins[j][0] + pins[j][1] + pins [j+1][0];                      
	}
}

/*********************************************************************
** Function:frame()
** Description: This important fuction does the filling in values for the array and also does the scoring functionality for all 3 rolls
** Parameters: none
** Pre-Conditions: there are no preconditions- the array has to be initialized 
** Post-Conditions: this function modifies the array by adding values and calculating the score, and it sends
this information to the frame output function to be outputted

** justification: This function is longer than 15 lines because I wanted to include all 3 rolls in
one function to make it more easy to access. This allows the functions to get the scoring and the
rolls all from one function, which aids in the simplification process.
*********************************************************************/ 

void frame () {
	int pins[ROUND][ROLL] = {};  // 0 - roll 1, 1 - Roll 2, 2 - Roll 3 (if he gets spare), 3 - Total for Frame
	int pinsRemaining = TOTALPINS;
	int rolledNumber = 10;
	bool isSPARE = false;
	bool isSTRIKE = false;
	int totalScore = 0;

	for (int i = 0; i < 10; i++) {
		pinsRemaining = 10;
		cout << endl << "Frame " << i + 1 << "..." << endl;

		// ROLL 1
		//if it is a spare
		if((isSPARE) and (i>0)){
			bowls(rolledNumber);
			if (rolledNumber == 10)
				isSTRIKE = true;
			pins[i][0] = rolledNumber;
			pins[i-1][3] += rolledNumber;
			recount(i, pins);
			frameOutput(pins, i, 0, isSTRIKE, isSPARE, totalScore);
			isSPARE = false;
		}
		//else if it is normal
		else {
			bowls(rolledNumber);
			if (rolledNumber == 10)
				isSTRIKE = true;
			pins[i][0] = rolledNumber;
			recount(i, pins);
			frameOutput(pins, i, 0, isSTRIKE, isSPARE, totalScore);
		}


		// ROLL 2
		if (!isSTRIKE){
			rolledNumber = 10 - rolledNumber;
			bowls(rolledNumber);
			pins[i][1] = rolledNumber;

			if ((pins[i][0] + pins [i][1] ) == 10){
				isSPARE = true;
			}
			recount(i, pins);
			frameOutput(pins, i, 1, isSTRIKE, isSPARE, totalScore);
		}	


		// ROLL 3
		if ((i== 9) and (isSPARE or isSTRIKE)) {
			// ROLL 3
			rolledNumber = 10;
			bowls(rolledNumber);
			pins[i][2] = rolledNumber;
			recount(i, pins);
			frameOutput(pins, i,2, isSTRIKE, isSPARE, totalScore);
		}

		//Sumup the totals
		pins[i][3] = pins[i][0] + pins[i][1] + pins[i][2];
		if (i > 0){
			pins[i][3] += pins[i-1][3];
			totalScore = pins[i][3];
			recount(i, pins);
			frameOutput(pins, i,2, isSTRIKE, isSPARE, totalScore);
		}
	}
}


int main () {
	int playAgain = 2;
	int rolledNumber = 10;
	// do while to run once and then play again
	do
	{
		srand(time(NULL));
		greeting();
		frame();

		playAgain = getIntegerValue("Do you want to play again? (1- yes, 2-no): ", 1, 2, "Please enter either 1 or 2.");

	} while (playAgain == 1);


    return 0;
}