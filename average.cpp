/*********************************************************************
** Author: Nicholas Brown
** Date: June 28, 2015
** Description: Assignment 2a - Finds average of 5 numbers from user.
*********************************************************************/

#include <iostream>

/*********************************************************************
** Description: Function to find average of 
** 5 numbers input from user
*********************************************************************/
int main()
{
	//declare 5 variables for user input
	double number1, number2, number3, number4,
		number5, average;
	
	//output directions to user
	std::cout << "Please enter five numbers." << std::endl;
	
	//assign user input to 5 variables
	std::cin >> number1;
	std::cin >> number2;
	std::cin >> number3;
	std::cin >> number4;
	std::cin >> number5;

	/*variable "average" gets the calculated average of the user's 5
	  numbers*/
	average = (number1 + number2 + number3 + number4 + number5) / 5;

	//output average to user
	std::cout << "The average of those numbers is:" << std::endl;
	std::cout << average << std::endl;

	return 0; //it worked!

}