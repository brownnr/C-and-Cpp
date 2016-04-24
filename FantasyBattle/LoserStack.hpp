#ifndef LOSERSTACK_HPP
#define LOSERSTACK_HPP

/*********************************************************
** Program Filename: LoserStack.hpp
** Author: Nicholas Brown
** Date: 11/22/2015
** Description: LoserStack class header file.
** Input: Creature from main.
** Output: The contents of the Loser's Pile is printed.
*********************************************************/

#include <cstdlib>		/* for NULL */


#include "Creature.hpp"	/* Creature class */
class Creature;			/* forward declaration of class */


class LoserStack
{
private:
	struct Stacknode
	{
		Creature *loser;
		Stacknode *next;
		Stacknode(Creature *loserIn, Stacknode *nextIn = NULL)
		{
			loser = loserIn;
			next = nextIn;
		};
	};
	Stacknode *head;

public:
	LoserStack() { head = NULL; };
	~LoserStack();
	void add(Creature *loser);
	void printLosers();

};



#endif 

