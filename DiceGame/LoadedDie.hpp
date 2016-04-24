/************************************************************
** Program Filename: LoadedDie.hpp
** Author: Nicholas Brown(in conjunction with unknown author).
** Date: 10/15/2015
** Description: LoadedDie header file(Die derived class).
** Input: None.
** Output: The value of the roll of a LoadedDie via the
**         rollDie function.
************************************************************/

#ifndef __LAB_A__LOADEDDIE__HPP
#define __LAB_A__LOADEDDIE__HPP

#include <stdlib.h> /*rand()*/
#include "Die.hpp"

class LoadedDie : public Die
{
public:
    LoadedDie(int);
    int rollDie();
};

#endif


