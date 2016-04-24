/************************************************************
** Program Filename: Barbarian.cpp
** Author: Nicholas Brown
** Date: 11/06/2015
** Description: Barbarian implementation file
** Input: A string for the name.
** Output: The results of the attack and defense rolls.
************************************************************/

#include <cstdlib>  /* for rand */
#include <iostream>
#include "Barbarian.hpp"


/************************************************************
** Function: Barbarian
** Description: Barbarian constructor
** Parameters: A string for the name.
** Pre-Conditions: None.
** Post-Conditions: The default armor and strength are set
**					to 0, and name is set to "Barbarian".
************************************************************/
Barbarian::Barbarian(string name) : Creature(name)
{
	/* set data members */
	this->armor = 0;
	this->strength = 12;
	this->name = name;
	this->type = "Barbarian";
}


/************************************************************
** Function: attack
** Description: The Barbarian's attack roll(s).
** Parameters: None.
** Pre-Conditions: A Barbarian is in battle.
** Post-Conditions: The result of the attack roll(s).
************************************************************/
int Barbarian::attack()
{
	int attackScore = 0;

	/* roll a single 6 sided die 2 times */
	for (int counter = 0; counter < 2; counter++)
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
** Description: The Barbarian's defense roll(s).
** Parameters: None.
** Pre-Conditions: A Barbarian is in battle.
** Post-Conditions: The result of the defense roll(s).
************************************************************/
int Barbarian::defend()
{
	int defenseScore = 0;

	/* roll a single 6 sided die 2 times */
	for (int counter = 0; counter < 2; counter++)
	{
		/* total up the rolls */
		defenseScore += rand() % 6 + 1;
	}

	return defenseScore;
}

