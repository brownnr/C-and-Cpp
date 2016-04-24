/*********************************************************
** Program Filename: LoserStack.hpp
** Author: Nicholas Brown
** Date: 11/22/2015
** Description: LoserStack class header file.
** Input: Creature from main.
** Output: The contents of the Loser's Pile is printed.
*********************************************************/

#include <iostream>

#include "LoserStack.hpp"

using std::cout;
using std::endl;


/************************************************************
** Function: add
** Description: Adds a Creature to the Loser's pile.
** Parameters: One pointer to a Creature.
** Pre-Conditions: A LoserStack object has been initialized.
** Post-Conditions: A Creature is added to the Stack and 
**					pointers are adjusted.
************************************************************/
void LoserStack::add(Creature *loser)
{
	/* if head is empty, make it a new node */
	if (this->head == NULL)
	{
		this->head = new Stacknode(loser);
	}

	/* otherwise, find the end and add one there */
	else
	{
		Stacknode *ptr = this->head;

		while (ptr->next != NULL)
			ptr = ptr->next;

		ptr->next = new Stacknode(loser);
	}

}


/************************************************************
** Function: printLosers
** Description: Prints the contents of the Loser's pile.
** Parameters: None.
** Pre-Conditions: A LoserStack object has been initialized.
** Post-Conditions: The losers are printed to the console
**					and deleted from the stack.
************************************************************/
void LoserStack::printLosers()
{
	/* while there's a head */
	while (head != NULL)
	{
		Stacknode *last = head;
		Stacknode *end = NULL;

		/* traverse to the last Creature inserted*/
		while (last->next != NULL)
		{
			end = last;
			last = last->next;
		}

		/* if only the head is left print the Creature's
		   name and delete the node */
		if (head->next == NULL)
		{
			cout << head->loser->getName() << endl;

			delete head;
			head = NULL;

			return;
		}
		
		/* print the Creature's name and delete them */
		cout << last->loser->getName() << endl;
		end->next = NULL;

		delete last;
		last = NULL;
	}
}


/************************************************************
** Function: ~Stack
** Description: Stack Destructor.
** Parameters: None.
** Pre-Conditions: A Stack object has been initialized.
** Post-Conditions: A Stack object is destroyed.
************************************************************/
LoserStack::~LoserStack()
{
	/* traverse down the Stack deleting and
	reassigning head as I go */
	while (head != NULL)
	{
		Stacknode *garbage = head;
		head = head->next;
		delete garbage;
		garbage = NULL;
	}
}

