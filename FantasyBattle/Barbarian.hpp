#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP


/********************************************************
** Program Filename: Barbarian.hpp
** Author: Nicholas Brown
** Date: 11/22/2015
** Description: Barbarian class header file.
** Input: A string for the name.
** Output: Integers from attack and defense rolls.
********************************************************/

#include "Creature.hpp"


class Barbarian : public Creature
{
public:
	Barbarian(string name);
	int attack();
	int defend();
	void heal() { strength = 12; };
};


#endif

