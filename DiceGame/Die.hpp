/*****************************************************
** Program Filename: Die.hpp
** Author: Nicholas Brown(in conjuction with unknown)
** Date: 10/15/2015
** Description: Die header file and program base class
** Input: The private member is set by the base
**        and derived class constructors, as well as
**        the setSides function.
** Output: The value of the roll of a regular die via
**         the rollDie function, also the number of
**         through the getSides function.
*****************************************************/


#ifndef DIE__HPP
#define DIE__HPP

#include <stdlib.h> /*rand()*/

class Die
{
protected:
    int sides;

public:
    Die(int);
    int getSides();
    void setSides(int);
    int rollDie();
};

#endif

