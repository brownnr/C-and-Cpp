/*********************************************************************
** Author: Nicholas Brown
** Date: July 6, 2015
** Description: Assignment 3c - Min/Max puzzle, in which the player 
**				tries to confuse the program of which
**				integer is higher and lower, and how
**				many integers they're going to throw
**				at it.
*********************************************************************/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	int min,		//Here's my variables...
	    max,
	    counter,
	    newInt;

	cout << "Enter number of integers." << endl;	//Give me the number of integers
	cin >> counter;					//you're going to use.
	cout << "Enter integers." << endl;		//give me the integers.
	cin >> newInt;					//I take the first number
	min = max = newInt;				//and set it to both min and max

	//Now that I have a min and max.....I loop through each entered number and check them
	for (counter; counter > 1; counter--)			
	{       cin >> newInt;  		//I take each number,
		if (newInt < min)		//if they're smaller than the current min
			min = newInt;	        //they become the new min.
                else if (newInt > max)	        //larger than the current max
			max = newInt;		//then they become the new max.
	}

	cout << "min: " << min << endl;	        //Your smallest number was....
	cout << "max: " << max << endl;		//your largest was......

	return 0;	    //did it work?
}
