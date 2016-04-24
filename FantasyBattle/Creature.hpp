#ifndef CREATURE_HPP
#define CREATURE_HPP

/********************************************************
** Program Filename: Creature.hpp
** Author: Nicholas Brown
** Date: 11/22/2015
** Description: Creature class header file.
** Input: A string for the name.
** Output: Integers from attack and defense rolls.
********************************************************/

#include <string>			/* for string */


#include "LineupQueue.hpp"	/* for LineupQueue */
class LineupQueue;			/* forward declaration of class */

#include "LoserStack.hpp"	/* for LoserStack */
class LoserStack;			/* forward declaration of class */



using std::string;


class Creature
{
protected:
	int armor;
	int strength;
	string name;
	string type;
	bool cut;
	bool iAmBlue;

public:
	Creature(string name);
	LoserStack* doBattle(LineupQueue *, LineupQueue *);
	void applyDamage(Creature *, int, Creature *, int);
	string getName();
	string getType();
	virtual int attack() = 0;
	virtual int defend() = 0;
	virtual void heal() = 0;
	
};


#endif

