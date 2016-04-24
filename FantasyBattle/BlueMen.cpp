/************************************************************
** Program Filename: BlueMen.cpp
** Author: Nicholas Brown
** Date: 11/06/2015
** Description: BlueMen implementation file
** Input: A string for the name.
** Output: The results of the attack and defense rolls.
************************************************************/

#include <cstdlib>  /* for rand */
#include <iostream>

#include "BlueMen.hpp"


/************************************************************
** Function: BlueMen
** Description: BlueMen constructor
** Parameters: A string for the name.
** Pre-Conditions: None.
** Post-Conditions: The default armor and strength are set
**					to 0, and name is set to "BlueMen".
************************************************************/
BlueMen::BlueMen(string name) : Creature(name)
{
	/* set data members */
	this->armor = 3;
	this->strength = 12;
	this->name = name;
	this->iAmBlue = true;
	this->type = "Blue Men";
}


/************************************************************
** Function: attack
** Description: The BlueMen's attack roll(s).
** Parameters: None.
** Pre-Conditions: A BlueMen is in battle.
** Post-Conditions: The result of the attack roll(s).
************************************************************/
int BlueMen::attack()
{
	int attackScore = 0;

	/* roll a single 10 sided die 2 times */
	for (int counter = 0; counter < 2; counter++)
	{
		/* total up the rolls */
		attackScore += rand() % 10 + 1;
	}

	/* if one of the Blue Men is KO'd, half the attackScore */
	if (this->cut)
	{
		return attackScore / 2;
	}
	else
		return attackScore;
}


/************************************************************
** Function: defend
** Description: The BlueMen's defense roll(s).
** Parameters: None.
** Pre-Conditions: A BlueMen is in battle.
** Post-Conditions: The result of the defense roll(s).
************************************************************/
int BlueMen::defend()
{
	int defenseScore = 0;

	/* roll a single 6 sided die 3 times */
	for (int counter = 0; counter < 3; counter++)
	{
		/* total up the rolls */
		defenseScore += rand() % 6 + 1;
	}

	/* if one of the Blue Men is KO'd, half the defenseScore */
	if (this->cut)
		return defenseScore / 2;
	else
		return defenseScore;
}

