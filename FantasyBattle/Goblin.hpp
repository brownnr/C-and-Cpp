#ifndef GOBLIN_HPP
#define GOBLIN_HPP


/********************************************************
** Program Filename: Goblin.hpp
** Author: Nicholas Brown
** Date: 11/22/2015
** Description: Goblin class header file.
** Input: A string for the name.
** Output: Integers from attack and defense rolls.
********************************************************/

#include "Creature.hpp"


class Goblin : public Creature
{
public:
	Goblin(string name);
	int attack();
	int defend();
	void heal() { strength = 8; };

};


#endif
