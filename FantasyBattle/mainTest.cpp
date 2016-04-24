/************************************************************
** Program Filename: mainTest.cpp
** Author: Nicholas Brown
** Date: 11/22/2015
** Description: Main client code file.
** Input: User will input number and name of each Creature
**			for both players' lineups.
** Output: User will receive the results of the battles and 
**			the winning team.
************************************************************/

#include <iostream>         /* for cout, cin, endl */
#include <string>

#include "Creature.hpp"         /* Creature Class */
#include "Goblin.hpp"			/* Goblin Class */
#include "Barbarian.hpp"		/* Barbarian Class */
#include "ReptilePeople.hpp"	/* Reptile People Class */
#include "BlueMen.hpp"			/* Blue Men Class */
#include "Shadow.hpp"			/* The Shadow Class */

using std::cout;
using std::cin;
using std::endl;
using std::string;


int main()
{
	int players,
		type;
	string cName;
	Creature *in = NULL,
		*winner = NULL;
	LineupQueue p1Lineup,
		p2Lineup;
	LoserStack *losers = NULL;


	cout << "Enter the number of Creatures each player will have: \n";
	cin >> players;

	/* do for both players */
	for (int loop = 1; loop <= 2; loop++)
	{
		cout << "Choose the Creature and a name for each creature "
			<< "for Player " << loop << endl;

		/* do for the number of Creatures */
		for (int counter = 0; counter < players; counter++)
		{
			cout << "\n  1. Goblin\n";
			cout << "  2. Barbarian\n";
			cout << "  3. Reptile People\n";
			cout << "  4. Blue Men\n";
			cout << "  5. The Shadow\n";
			cin >> type;

			cout << "What will their name be? " << endl;
			cin >> cName;

			/* make new Creature */
			switch (type)
			{
			case 1:
				in = new Goblin(cName);
				break;
			case 2:
				in = new Barbarian(cName);
				break;
			case 3:
				in = new ReptilePeople(cName);
				break;
			case 4:
				in = new BlueMen(cName);
				break;
			case 5:
				in = new Shadow(cName);
			}

			/* add Creature to lineup */
			if (loop == 1)
				p1Lineup.add(in);
			else
				p2Lineup.add(in);
		}
	}

	/* get the losers */
	losers = in->doBattle(&p1Lineup, &p2Lineup);

	/* if player one's lineup is empty, he lost */
	if (p1Lineup.getFront() == NULL)
	{
		cout << "\nPlayer 2's team has won." << endl;
		cout << "Here are the rankings, from first to last: " << endl;
		p2Lineup.moveBack();
		/* print what's left of the winning lineup */
		p2Lineup.printWinners();
	}
	/* otherwise player two lost */
	else
	{
		cout << "\nPlayer 1's team has won." << endl;
		cout << "Here are the rankings, from first to last: " << endl;
		p1Lineup.moveBack();
		/* print what's left of the winning lineup */
		p1Lineup.printWinners();
	}

	/* print the losers */
	losers->printLosers();

	return 0;
}
