/*************************************************************
**  Program Filename: Die.cpp
**  Author: Nicholas Brown(in conjuction with unknown author)
**  Date: 10/15/2015
**  Description: Die implementation file.
**  Input: Number of sides for the die from the user via the
**         main() function. 
**  Output: The value of the roll of a regular die via the 
**          rollDie function, also returns the number of 
**          sides through getSides.
************************************************************/

#include "Die.hpp"
#include <iostream>

/************************************************
**  Function: Die
**  Description: This constructor sets the number
**               of sides to an amount specified
**               by the user in the main function.
************************************************/
Die::Die(int sidesIn)
{
    this->sides = sidesIn;
}


/************************************************
**  Function: rollDie
**  Description: Rolls the dice and returns the
**               number rolled.
************************************************/
int Die::rollDie()
{
    return rand() % sides + 1;
}


/************************************************
**  Function: getSides
**  Description: Returns the number of sides.
************************************************/
int Die::getSides()
{
    return sides;
}


/************************************************
**  Function: setSides
**  Description: Sets the number of sides.
************************************************/
void Die::setSides(int sides)
{
    this->sides = sides;
}

