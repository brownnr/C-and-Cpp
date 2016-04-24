#ifndef BLUE_HPP
#define BLUE_HPP


/********************************************************
** Program Filename: BlueMen.hpp
** Author: Nicholas Brown
** Date: 11/22/2015
** Description: BlueMen class header file.
** Input: A string for the name.
** Output: Integers from attack and defense rolls.
********************************************************/

#include "Creature.hpp"


class BlueMen : public Creature
{
public:
	BlueMen(string name);
	int attack();
	int defend();
	void heal() { strength = 12; };

};

#endif
