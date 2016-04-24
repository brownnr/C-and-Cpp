#ifndef LINEUPQUEUE_HPP
#define LINEUPQUEUE_HPP

/*********************************************************
** Program Filename: LineupQueue.hpp
** Author: Nicholas Brown
** Date: 11/22/2015
** Description: LineupQueue class header file.
** Input: Creature from main.
** Output: The front Creature for the battles, and the 
**			contents of the Winner's Lineup is printed.
*********************************************************/

#include <cstdlib>		/* for NULL */


#include "Creature.hpp"	/* Creature class */
class Creature;			/* forward declaration of class */


class LineupQueue
{
private:
	struct Queuenode
	{
		Creature *beast;
		Queuenode *next;
		Queuenode *prev;
		Queuenode(Creature *beastIn, Queuenode *prevIn = NULL, Queuenode *nextIn = NULL)
		{
			beast = beastIn;
			prev = prevIn;
			next = nextIn;
		};
	};
	Queuenode *head;
	Queuenode *tail;

public:
	LineupQueue() { head = tail = NULL; };
	~LineupQueue();
	void add(Creature *beastIn);
	Creature* getFront();
	void removeFront();
	void moveBack();
	void printWinners();

};



#endif 

