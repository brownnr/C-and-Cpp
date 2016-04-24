#ifndef REPTILE_HPP
#define REPTILE_HPP


/********************************************************
** Program Filename: ReptilePeople.hpp
** Author: Nicholas Brown
** Date: 11/22/2015
** Description: ReptilePeople class header file.
** Input: A string for the name.
** Output: Integers from attack and defense rolls.
********************************************************/

#include "Creature.hpp"


class ReptilePeople : public Creature
{
public:
	ReptilePeople(string name);
	int attack();
	int defend();
	void heal() { strength = 18; };

};


#endif
