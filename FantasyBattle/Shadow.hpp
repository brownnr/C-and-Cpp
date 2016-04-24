#ifndef SHADOW_HPP
#define SHADOW_HPP


/********************************************************
** Program Filename: Shadow.hpp
** Author: Nicholas Brown
** Date: 11/22/2015
** Description: Shadow class header file.
** Input: A string for the name.
** Output: Integers from attack and defense rolls.
********************************************************/

#include "Creature.hpp"


class Shadow : public Creature
{
public:
	Shadow(string name);
	int attack();
	int defend();
	void heal() { strength = 12; };

};


#endif
