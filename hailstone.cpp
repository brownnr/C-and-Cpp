/*********************************************************
 * Author: Nicholas Brown
 * Date: July 17, 2015
 * Description: This hailstone function takes one positive 
 *              integer, and if it's even, divides it by 
 *              two to get the next integer in the sequence, 
 *              but if it is odd, then multiplies it by 
 *              three and adds one to get the next integer 
 *              in the sequence.
 *              Then returns the the number of steps it 
 *              takes to reach 1.
*********************************************************/

int hailstone(int startInt)
{
    int counter = 0,		//declare and initialize the counter
        newInt = startInt;	//to preserve the parameter value

    //while the integer is not equal to 1...
    for (counter = 0; newInt != 1; counter++)
    {
        if (newInt % 2 == 0)		//if it's even,
	    newInt = newInt / 2;	//divide by 2.
	else				//if it's odd,
	    newInt = (newInt * 3) + 1;	//multiply by 3, add 1
    }

    return counter;		//return number of steps
}
