/************************************************************
** Program Filename: ReptilePeople.cpp
** Author: Nicholas Brown
** Date: 11/06/2015
** Description: ReptilePeople implementation file
** Input: A string for the name.
** Output: The results of the attack and defense rolls.
************************************************************/


#include <cstdlib>  /* for rand */
#include <iostream>
#include "ReptilePeople.hpp"


/************************************************************
** Function: ReptilePeople
** Description: ReptilePeople constructor
** Parameters: A string for the name.
** Pre-Conditions: None.
** Post-Conditions: The default armor and strength are set
**					to 0, and name is set to "ReptilePeople".
************************************************************/
ReptilePeople::ReptilePeople(string name) : Creature(name)
{
	/* set data members */
	this->armor = 7;
	this->strength = 18;
	this->name = name;
	this->type = "Reptile People";
}


/************************************************************
** Function: attack
** Description: The ReptilePeople's attack roll(s).
** Parameters: None.
** Pre-Conditions: A ReptilePeople is in battle.
** Post-Conditions: The result of the attack roll(s).
************************************************************/
int ReptilePeople::attack()
{
	int attackScore = 0;

	/* roll a single 6 sided die 3 times */
	for (int counter = 0; counter < 3; counter++)
	{
		/* total up the rolls */
		attackScore += rand() % 6 + 1;
	}

	/* if the achilles is cut, half the attackScore */
	if (this->cut)
	{
		return attackScore / 2;
	}
	else
		return attackScore;
}


/************************************************************
** Function: defend
** Description: The ReptilePeople's defense roll(s).
** Parameters: None.
** Pre-Conditions: A ReptilePeople is in battle.
** Post-Conditions: The result of the defense roll(s).
************************************************************/
int ReptilePeople::defend()
{
	/* one 6 sided die */
	return rand() % 6 + 1;

}

