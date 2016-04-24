/*************************************************************
**  Program Filename: LoadedDie.cpp
**  Author: Nicholas Brown(in conjunction with unknown author
**  Date: 10/15/2015
**  Description: LoadedDie implementation file.
**  Input: None.
**  Output: The value of the roll of a LoadedDie via the 
**          rollDie function.
************************************************************/

#include "LoadedDie.hpp"
#include <iostream>

/************************************************
**  Function: LoadedDie
**  Description: This constructor sets the number
**               of sides to an amount specified
**               by the user.
************************************************/
LoadedDie::LoadedDie(int sidesIn) : Die(sidesIn)
{
    sides = sidesIn;
}

/************************************************
**  Function: rollDie
**  Description: Rolls the loaded dice and returns
**               the number rolled.
************************************************/
int LoadedDie::rollDie()
{
    int loadedDieVal = rand() % sides + 1; //rolls the dice like normal
    if (loadedDieVal == sides)
        return loadedDieVal;
	
    /*
     * this if condition was changed to produce
     * a more noticable loaded die appearance
     */
    if ((rand() % 10 + 1) >= 5) //adds 1 to roll 60% if the time
    {
        return loadedDieVal + 1;
    }
    else
    {
        return loadedDieVal;
    }

}


