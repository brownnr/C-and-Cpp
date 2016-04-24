/*********************************************************************
** Author: Nicholas Brown
** Date: June 28, 2015
** Description: Assignment 2b - Converts temperature from Celsius to
** 				Fahrenheit.
*********************************************************************/

#include <iostream>

/*********************************************************************
** Description: function to convert Celsius to Fahrenheit
*********************************************************************/
int main()
{
	//declare temperature variables
	double celsiusTemp, fahrenheitTemp;

	/*user prompt for Celsius temperature input, 
	  assign input to variable 'celsiusTemp'*/
	std::cout << "Please enter a Celsius temperature." << std::endl;
	std::cin >> celsiusTemp;

	//calculate Fahrenheit equivalent
	fahrenheitTemp = ((double) 9 / 5) * celsiusTemp + 32;
	
	//output result to user
	std::cout << "The equivalent Fahrenheit temperature is:" << std::endl;
	std::cout << fahrenheitTemp << std::endl;
		
	return 0; //it worked

}