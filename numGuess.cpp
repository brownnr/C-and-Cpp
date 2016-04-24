/*********************************************************************
** Author: Nicholas Brown
** Date: July 6, 2015
** Description: Assignment 3a - Guessing Game, in which the player 
**								tries to guess the number entered.
*********************************************************************/

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
	int targetNumber,                                 //declare the variables
		playerGuess,
		numberOfGuesses;
	string tries = " tries.";

	const string HIGH = "Too high - try again.",     //declare the constants
		LOW = "Too low - try again.";

	//Prompt player 1 for the target number to be guessed.
	cout << "Enter an integer for the player to guess." << endl;
	cin >> targetNumber;

	//First prompt to guess, doesn't change so it is outside of the loop.
	cout << "Enter your guess." << endl;
	cin >> playerGuess;	

	//start counter at 1, the minimum number of tries.
	//it increases, inside the loop, only if the guess is incorrect.
	numberOfGuesses = 1;		

	while (playerGuess != targetNumber)		//while the guess is not equal the target		
	{						//check if it's high or low.
		if (playerGuess > targetNumber)		//if the guess is too high
			cout << HIGH << endl;		//display "Too high" message.
		else					//if the guess is too low	
			cout << LOW << endl;		//display the "Too low" message.
					
		cin >> playerGuess;			//assign the new guess to variable and
		numberOfGuesses ++;			//increases the running total of guesses
	}

	//You deserve correct grammar if you're smart enough to get it on the first guess
	if (numberOfGuesses == 1)
		tries = " try.";	

	//display the total number of guesses it took.
	cout << "You guessed it in " << numberOfGuesses << tries << endl;


	return 0;		//I ran successfully!
}
