/*********************************************************************
** Author: Nicholas Brown
** Date: July 6, 2015
** Description: Assignment 3b - Range Sum-mer, in which the range of  
**				the two integers entered by the user
**				is added up and revealed to the user!
*********************************************************************/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int firstNumber,		//declare the variables
	    secondNumber,
	    runningTotal;

	cout << "Please enter two integers." << endl;	//prompt
	cin >> firstNumber;			        //set input to variables
	cin >> secondNumber;

	//if the first number is the higher...
	if (firstNumber > secondNumber)
        {   //the firstNumber variable counts down to secondNumber variable
	    for (firstNumber; firstNumber >= secondNumber; firstNumber--)
	    {   runningTotal += firstNumber;
            }
        }
        else
        {
            //the secondNumber variable counts down to firstNumber variable
	    for (secondNumber; secondNumber >= firstNumber; secondNumber--)
	    {   runningTotal += secondNumber;
	    }
        }

	//display the sum of the range
	cout << "The sum of the values in that range is:" << endl;
	cout << runningTotal << endl;


	return 0;		//success!
}
