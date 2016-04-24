/*********************************************************************
** Author: Nicholas Brown
** Date: June 28, 2015
** Description: Assignment 2c - Finds fewest number of coins for cents
** 				from user.
*********************************************************************/

#include <iostream>

/*********************************************************************
** Description: Function to output fewest number of coins, by
** denomination, for input of cents
*********************************************************************/
int main()
{
	//declare variables
	int cents, 
		numofquarters, 
		numofdimes, 
		numofnickels, 
		numofpennies, 
		remainder;

	//assign user input to variable 'cents'
	std::cout << "Please enter an amount in cents less than a dollar." << std::endl;
	std::cin >> cents;

	//calculate number of quarters, assign new value to cents
	numofquarters = cents / 25;
	cents = cents % 25; //modulus operator is quick/easy way to use the
						//remainder of a calc.

	//calculate number of dimes, assign new value to cents
	numofdimes = cents / 10;
	cents = cents % 10;

	//calculate number of nickels, set cents to new value
	numofnickels = cents / 5;
	cents = cents % 5;

	//calculate number of pennies
	numofpennies = cents / 1;

	//output result
	std::cout << "Your change will be:" << std::endl;
	std::cout << "Q: " << numofquarters << std::endl;
	std::cout << "D: " << numofdimes << std::endl;
	std::cout << "N: " << numofnickels << std::endl;
	std::cout << "P: " << numofpennies << std::endl;

	std::cin.ignore();
	std::cin.get();

	return 0; //it worked!

}