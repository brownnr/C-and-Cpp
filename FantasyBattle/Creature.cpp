/************************************************************
** Program Filename: Creature.cpp
** Author: Nicholas Brown
** Date: 11/05/2015
** Description: Creature implementation file
** Input: The chosen creatures for the battle from the user
**			and main.
** Output: The winner and stats of the battle.
************************************************************/

#include <ctime>		/* for time */
#include <cstdlib>      /* for srand */
#include <iostream>		/* for cout, cin, endl */
#include <iomanip>		/* for setw, left */

#include "Creature.hpp"	/* for Creature */

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;


/************************************************************
** Function: Creature
** Description: Creature constructor
** Parameters: A string for the name.
** Pre-Conditions: None.
** Post-Conditions: The default armor and strength are set
**					to 0, and name is set to "".
************************************************************/
Creature::Creature(string name)
{
	/* set data members */
	this->armor = 0;
	this->strength = 0;
	this->name = name;
	this->cut = false;
	this->iAmBlue = false;
}


/************************************************************
** Function: doBattle
** Description: Handles the battles between the two creatures.
** Parameters: Two LineupQueues.
** Pre-Conditions: Two lineups have been instantiated with at
**					least 1 creature in each.
** Post-Conditions: One of the lineups is empty(defeated) and
**					a stack of losers is returned.
************************************************************/
LoserStack* Creature::doBattle(LineupQueue *one, LineupQueue *two)
{
	LoserStack *losers = new LoserStack;

	Creature *p1 = one->getFront(),
		*p2 = two->getFront();

	/* attacker.....1 = Creature one attacks
					2 = Creature two attacks*/
	int attacker = 1,
		attackPoints = 0,
		defensePoints = 0;

	bool cut = false,
		blue = false,
		once = false;

	/* set seed for attack and defense rolls */
	srand(time(NULL));
		

	/* while there are still 2 creatures and they both have strength */
	while ((p1 != NULL && p1->strength > 0) && (p2 != NULL && p2->strength > 0))
	{
		/* Creature one attacks */
		if (attacker == 1)
		{
			defensePoints = p2->defend();

			/* check if Creature 2 is the shadow, and if he was not hit*/
			if (p2->name == "The Shadow" && defensePoints > 0)
				attackPoints = 0;
			else
				attackPoints = p1->attack();

			/* check if 1 is a goblin and if he rolled a 12 */
			if (p1->name == "Goblin")
			{
				if (attackPoints == 12)
				{
					/* is the goblin fighting the blue men group? */
					if (p2->iAmBlue == true)
						p2->cut = true;

					else if (p2->iAmBlue == false)
					{
						/* if a Goblin rolls a 12, cut the achilles */
						if (p2->cut == false && once == false)
						{
							once = true;
							p2->cut = true;
						}
					}
				}
			}

			/* apply damage to the defender */
			applyDamage(p1, attackPoints, p2, defensePoints);

			/* Creature two is out */
			if (p2->strength <= 0)
			{
				/* display which creatures battled and who won */
				cout << "Player One's " << p1->getType() << ", "
					<< p1->getName() << ", has won against\n"
					<< "  Player Two's " << p2->getType() << ", "
					<< p2->getName() << endl;
					
				/* add p2 to loser pile and remove from lineup*/
				losers->add(p2);
				two->removeFront();
				/* move the winner to the back and reset strength */
				one->moveBack();
				p1->heal();

				/* get the next two Creatures to battle */
				p1 = one->getFront();
				p2 = two->getFront();
			}
								
			/* switch attackers */
			attacker = 2;
		}

		/* Creature two attacks */
		else if (attacker == 2)
		{
			defensePoints = p1->defend();

			/* check if Creature 1 is the shadow, and he was not hit*/
			if (p1->name == "The Shadow" && defensePoints > 0)
				attackPoints = 0;
			else
				attackPoints = p2->attack();

			/* check if 2 is a goblin and if he rolled a 12 */
			if (p2->name == "Goblin")
			{
				if (attackPoints == 12)
				{
					/* is the goblin fighting the blue men group? */
					if (p2->iAmBlue == true)
						p1->cut = true;

					else if (p1->iAmBlue == false)
					{
						/* if a Goblin rolls a 12, cut the achilles */
						if (attackPoints == 12 && once == false)
						{
							once = true;
							p1->cut = true;
						}
					}
				}
			}

			/* apply damage to the defender */
			applyDamage(p2, attackPoints, p1, defensePoints);
				
			/* Creature one is out */
			if (p1->strength <= 0)
			{
				/* display which creatures battled and who won */
				cout << "Player Two's " << p2->getType() << ", "
					<< p2->getName() << ", has won against\n"
					<< "  Player One's " << p1->getType() << ", "
					<< p1->getName() << endl;

				/* add p1 to loser pile and remove from lineup*/
				losers->add(p1);
				one->removeFront();
				/* move the winner to the back and reset strength */
				two->moveBack();
				p2->heal();

				/* get the next two Creatures to battle */
				p1 = one->getFront();
				p2 = two->getFront();
			}
				
			/* switch attackers */
			attacker = 1;
		}
	}

	return losers;
}


/************************************************************
** Function: applyDamage
** Description: Applies damage to the defender's strength.
** Parameters: 2 Creature pointers and two integers.
** Pre-Conditions: 2 Creatures are in battle.
** Post-Conditions: Strength is altered based on damage
**					assessed.
************************************************************/
void Creature::applyDamage(Creature *attacker, int attackP, Creature *defender, int defendP)
{
	int damage = attackP - defendP;

	/* so there is not negative damage as this
	**	would result in an INCREASE of strength */
	if (damage > defender->armor)
	{
		/* damage is only that which is above the
		** strength of the armor */
		damage -= defender->armor;
	}
	else
		damage = 0;
	
	defender->strength -= damage;
}


/************************************************************
** Function: getName
** Description: Returns the Creature's name.
** Parameters: None.
** Pre-Conditions: A Creature exists.
** Post-Conditions: The name of the Creature is returned.
************************************************************/
string Creature::getName()
{
	return this->name;
}


/************************************************************
** Function: getType
** Description: Returns the Creature's type.
** Parameters: None.
** Pre-Conditions: A Creature exists.
** Post-Conditions: The type of the Creature is returned.
************************************************************/
string Creature::getType()
{
	return this->type;
}
