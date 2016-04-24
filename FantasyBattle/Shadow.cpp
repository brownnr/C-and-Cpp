/************************************************************
** Program Filename: Shadow.cpp
** Author: Nicholas Brown
** Date: 11/22/2015
** Description: Shadow implementation file
** Input: A string for the name.
** Output: The results of the attack and defense rolls.
************************************************************/


#include <cstdlib>  /* for rand */
#include <iostream> /* for cout, endl */

#include "Shadow.hpp"

using std::cout;
using std::cin;
using std::endl;


/************************************************************
** Function: ReptilePeople
** Description: ReptilePeople constructor
** Parameters: A string for the name.
** Pre-Conditions: None.
** Post-Conditions: The default armor and strength are set
**					to 0, and name is set to "ReptilePeople".
************************************************************/
Shadow::Shadow(string name) : Creature(name)
{
	/* set data members */
	this->armor = 0;
	this->strength = 12;
	this->name = name;
	this->type = "Shadow";
}


/************************************************************
** Function: attack
** Description: The Shadow's attack roll(s).
** Parameters: None.
** Pre-Conditions: A Shadow is in battle.
** Post-Conditions: The result of the attack roll(s).
************************************************************/
int Shadow::attack()
{
	int attackScore = 0;

	/* roll a single 10 sided die 2 times */
	for (int counter = 0; counter < 2; counter++)
	{
		/* total up the rolls */
		attackScore += rand() % 10 + 1;
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
** Description: The Shadow's defense roll(s).
** Parameters: None.
** Pre-Conditions: A Shadow is in battle.
** Post-Conditions: The result of the defense roll(s).
************************************************************/
int Shadow::defend()
{
	int chance = rand() % 2 + 1;

	switch (chance)
	{
	/* did not get hit, so gets a defense roll */
	case 1: 
		/* one 6 sided die */
		return rand() % 6 + 1;
		break;

	/* was hit with only overcoat to protect him
	**	does not get defense roll */
	case 2:
		return 0;
	}
	
}

