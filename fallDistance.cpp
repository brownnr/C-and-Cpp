/*******************************************************
 * Author: Nicholas Brown
 * Date: July 17, 2015
 * Description: This fallDistance function takes one 
 *              integer parameter, the seconds, and 
 *              returns the meters fallen in that time.
********************************************************/

#include <cmath> //to use pow()

double fallDistance(double seconds)
{
	double metersFallen; //local variable used to hold calculated
			     //distance fallen.

	//set variable to meters fallen, using the seconds parameter
	metersFallen = (0.5) * 9.8 * pow(seconds, 2);

	//return calculation to main function
	return metersFallen;
}
