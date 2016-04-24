/*********************************************************
 * Author: Nicholas Brown
 * Date: July 17, 2015
 * Description: This smallSort function takes three 
 *              integers by reference, and sorts them 
 *              from smallest to largest.
*********************************************************/

void smallSort(int& num1, int& num2, int& num3)
{
	int min,  //declare 3 temporary integers used for
		mid,  //rearranging order of paramater variables
		max;  //without losing original values

		
		if (num1 < num2)		//if 1st number is lower than 2nd
		{
			//and 3rd is less than or equal to 1st
			if (num3 <= num1)	
			{
				min = num3;
				mid = num1;
				max = num2;
			}
			//or 3rd is greater than or equal to 2nd
			else if (num3 >= num2)
			{
				min = num1;
				mid = num2;
				max = num3;
			}
		}
		else if (num2 < num1)	//or if 1st is higher than 2nd
		{
			//and 3rd is less than or equal to 2nd
			if (num3 <= num2)
			{
				min = num3;
				mid = num2;
				max = num1;
			}
			//or 3rd is greater than or equal to 1st
			else if (num3 >= num2)
			{
				min = num2;
				mid = num3;
				max = num1;
			}
		}
		else if (num1 == num2)	//or if 1st and 2nd are equal
		{
			//and 3rd is less than 2nd
			if (num3 < num2)
			{
				min = num3;
				mid = num1;
				max = num2;
			}
			//else they're all equal
			else
			{
				return;
			}
		}

    num1 = min;  //reassign numbers to original variables for main function
    num2 = mid;
    num3 = max;

}
