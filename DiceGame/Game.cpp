/************************************************************
** Program Filename: Game.cpp
** Author: Nicholas Brown
** Date: 10/14/2015
** Description: The Game class implementation file.
** Input: The types of dice for each player and the number
**        of rounds they will play via the main() function.
** Output: A string of which player won and the final score.
************************************************************/

#include <vector>   /*std::vector*/
#include "Game.hpp"


/************************************************************
** Function: Game
** Description: Default Constructor.
** Parameters: None.
** Pre-Conditions: None.
** Post-Conditions: A Game object and both player's dice are
**					initialized with a starting score of 0.
************************************************************/

Game::Game() 
{
    p1Total = 0;
    p2Total = 0;
}


/************************************************************
** Function: getP1Total
** Description: Returns the first player's total score.
** Parameters: None.
** Pre-Conditions: None.
** Post-Conditions: Returns the total score of player 1
************************************************************/

int Game::getP1Total()
{
    return p1Total;
}


/************************************************************
** Function: getP2Total
** Description: Returns the second player's scores.
** Parameters: None.
** Pre-Conditions: None.
** Post-Conditions: Returns the total score of player 2
************************************************************/

int Game::getP2Total()
{
    return p2Total;
}


/************************************************************
** Function: getP1Scores
** Description: Returns the first player's scores.
** Parameters: None.
** Pre-Conditions: None.
** Post-Conditions: Returns the vector of scores for player 1
************************************************************/

std::vector <int> Game::getP1Scores()
{
    return p1Score;
}


/************************************************************
** Function: getP2Scores
** Description: Returns the second player's scores.
** Parameters: None.
** Pre-Conditions: None.
** Post-Conditions: Returns the vector of scores for player 2
************************************************************/

std::vector <int> Game::getP2Scores()
{
    return p2Score;
}


/************************************************************
** Function: playTheGame
** Description: Rolls each player's die, adjusting their total
**				scores and adding the current roll to their
**				vector.
** Parameters: Two pointers of type Die.
** Pre-Conditions: A Game, the 2 players' dice and the number
**                 of rounds have all been initiated.
** Post-Conditions: The player's score vectors are filled.
************************************************************/

void Game::playWar(Die *p1Die, Die *p2Die)
{
    int p1Round = p1Die->rollDie();
    int p2Round = p2Die->rollDie();

    /* add individual scores to vectors */
    p1Score.push_back(p1Round);
    p2Score.push_back(p2Round);
              
	/* total scores */
    if (p1Round > p2Round)
    {
            p1Total++;
    }
    else if (p1Round < p2Round)
    {
            p2Total++;
    }
    
}

