/************************************************************
** Program Filename: Goblin.cpp
** Author: Nicholas Brown
** Date: 11/06/2015
** Description: Goblin implementation file
** Input: A string for the name.
** Output: The results of the attack and defense rolls.
************************************************************/


#include <cstdlib>  /* for rand */
#include <iostream>
#include "Goblin.hpp"


/************************************************************
** Function: Goblin
** Description: Goblin constructor
** Parameters: A string for the name.
** Pre-Conditions: None.
** Post-Conditions: The default armor and strength are set
**					to 0, and name is set to "Goblin".
************************************************************/
Goblin::Goblin(string name) : Creature(name)
{
	/* set data members */
	this->armor = 3;
	this->strength = 8;
	this->name = name;
	this->type = "Goblin";
}


/************************************************************
** Function: attack
** Description: The Goblin's attack roll(s).
** Parameters: None.
** Pre-Conditions: A Goblin is in battle.
** Post-Conditions: The result of the attack roll(s).
************************************************************/
int Goblin::attack()
{
	int attackScore = 0;

	/* roll a single 6 sided die 2 times */
	for (int counter = 0; counter < 2; counter++)
	{
		/* total up the rolls */
		attackScore += rand() % 6 + 1;
	}

	return attackScore;
}


/************************************************************
** Function: defend
** Description: The Goblin's defense roll(s).
** Parameters: None.
** Pre-Conditions: A Goblin is in battle.
** Post-Conditions: The result of the defense roll(s).
************************************************************/
int Goblin::defend()
{
	/* one 6 sided die */
	return rand() % 6 + 1;

}

