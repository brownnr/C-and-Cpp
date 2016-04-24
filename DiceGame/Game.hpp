/**************************************************************
** Program Filename: Game.hpp
** Author: Nicholas Brown
** Date: 10/14/2015
** Description: Game class header file.
** Input: The type of dice for each player and number of rounds
**        they will play.
** Output: The playTheGame function returns a string stating
**         the winner and the final score.
**************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include <vector>   /*std::vector*/
#include "Die.hpp"  /*Die class*/
#include "LoadedDie.hpp"

class Game
{
private:
	int p1Total,
        p2Total;
    std::vector <int> p1Score;
    std::vector <int> p2Score;

public:
    Game();
    int getP1Total();
    int getP2Total();
    std::vector <int> getP1Scores();
    std::vector <int> getP2Scores();
    void playWar(Die *p1, Die *p2);
};

#endif

