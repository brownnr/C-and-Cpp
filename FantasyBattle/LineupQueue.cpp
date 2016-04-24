/*********************************************************
** Program Filename: LineupQueue.hpp
** Author: Nicholas Brown
** Date: 11/22/2015
** Description: LineupQueue class header file.
** Input: Creature from main.
** Output: The front Creature for the battles, and the
**			contents of the Winner's Lineup is printed.
*********************************************************/

#include <iostream>

#include "LineupQueue.hpp"

using std::cout;
using std::endl;

/************************************************************
** Function: add
** Description: Adds a Creature to the lineup.
** Parameters: One pointer to a creature.
** Pre-Conditions: A LineupQueue object has been initialized.
** Post-Conditions: A Creature is added to the lineup and the
**					pointers are adjusted.
************************************************************/
void LineupQueue::add(Creature *beastIn)
{
	/* if head is empty, make it a new node */
	if (head == NULL)
	{
		head = new Queuenode(beastIn, tail);
		//tail = head;
	}

	/* otherwise, find the end and add one there */
	else
	{
		Queuenode *ptr = head;

		while (ptr->next != NULL)
			ptr = ptr->next;

		ptr->next = new Queuenode(beastIn, ptr);
		tail = ptr->next; 
		tail->prev = ptr;
	}
}


/************************************************************
** Function: getFront
** Description: Returns a pointer to the Creature next up in
**				the lineup.
** Parameters: None.
** Pre-Conditions: A LineupQueue object has been initialized.
** Post-Conditions: A Creature is returned.
************************************************************/
Creature* LineupQueue::getFront()
{
	if (head == NULL)
		return NULL;
	else
		return head->beast;
}


/************************************************************
** Function: ~LineupQueue
** Description: LineupQueue Destructor.
** Parameters: None.
** Pre-Conditions: A LineupQueue object has been initialized.
** Post-Conditions: A LineupQueue object is destroyed.
************************************************************/
LineupQueue::~LineupQueue()
{
	/* traverse down the Stack deleting and
	reassigning head as I go */
	while (head != NULL)
	{
		Queuenode *trash = head;
		head = head->next;
		delete trash;
		trash = NULL;
	}

	delete head;
	head = tail = NULL;
}


/************************************************************
** Function: removeFront
** Description: Removes a Creature from the lineup.
** Parameters: None.
** Pre-Conditions: A LineupQueue object has been initialized.
** Post-Conditions: A Creature is removed from the lineup.
************************************************************/
void LineupQueue::removeFront()
{
	Queuenode *currNode = head;

	/* adjust pointers */
	if (head->next != NULL)
	{
		head = head->next;
		head->prev = NULL;
		delete currNode;
		currNode = NULL;
	}
	else
	{
		delete head;
		head = NULL;
	}
}


/************************************************************
** Function: moveBack
** Description: Moves Creature from front of lineup to the 
**				back.
** Parameters: None.
** Pre-Conditions: A LineupQueue object has been initialized.
** Post-Conditions: The front Creature is now at the back.
************************************************************/
void LineupQueue::moveBack()
{
	Queuenode *temp = head;

	if (head->next != NULL)
	{
		/* second Creature is up */
		head = head->next;
		head->prev = NULL;

		/* adjust tail and old head's pointers */
		temp->prev = tail;
		tail->next = temp;
		tail = temp;
		tail->next = NULL;
	}
}


/************************************************************
** Function: printWinners
** Description: Prints the contents of the winner's lineup.
** Parameters: None.
** Pre-Conditions: A LineupQueue object has been initialized.
** Post-Conditions: What's left of the lineup is displayed
**					and deleted from the lineup.
************************************************************/
void LineupQueue::printWinners()
{
	Queuenode *ptr = head;

	/* while there is a head */
	while (head != NULL)
	{
		/* print the front Creature's name */
		cout << head->beast->getName() << endl;

		/* adjust head to next Creature and delete old node */
		ptr = head->next;
		delete head;
		head = ptr;
	}

	/* delete last node */
	delete head;
	head = tail = NULL;
}
