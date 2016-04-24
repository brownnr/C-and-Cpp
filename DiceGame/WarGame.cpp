/************************************************************
** Program Filename: WarGame.cpp
** Author: Nicholas Brown
** Date: 10/15/2015 
** Description: Main client code file.
** Input: User will input which type of Die each player will
**        play with, the number of sides of the dice, and
**        the number of rounds to play.
** Output: User will receive the results of each row, along
**         with the overall winner and score.
************************************************************/

#include <iostream>         /*std::cout, std::cin, std::endl*/
#include <iomanip>          /*std::setw(), set::left*/
#include <string>
#include <vector>           /*std::vector*/
#include "Game.hpp"         /*Game Class*/
#include "LoadedDie.hpp"    /*LoadedDie Class*/
#include "Die.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::left;
using std::vector;
using std::string;

/************************************************************
** Function: main()
** Description: main function which handles the user input
**              and output, object initialization and calls to
**              class methods.
** Parameters: None.
** Pre-Conditions: The appropriate header files have been
**                 #included.
** Post-Conditions: User will receive the results of each 
**                  round of the Game that is played, as well
**                  as the overall winner and score.
************************************************************/

int main()
{
    char dieChoice;
    int sides = 0,
        rounds = 0,
        p1Score = 0,
        p2Score = 0;
    string p1Choice,
           p2Choice;
    bool validChoice = true;
    Game war;
    Die *p1Die = new Die(sides),
        *p2Die = new LoadedDie(sides);
    vector<int> p1Vector;
    vector<int> p2Vector;
    
 
    
    /*set rand() seed*/
    srand(time(NULL));

    /*get sides from user*/
    cout << "How many sides will the player's dice have?" << endl;
    cin >> sides;
    
	
    /*get user-defined Die type for player 1*/
    cout << "What kind of die will Player 1 have?" << endl
         << "a: Regular Die         b: Loaded Die" << endl;
    cin >> dieChoice;
    
    /*assign appropriate Die object to player 1*/
    if (dieChoice == 'a')
    {
        p1Die = new Die(sides);
    }
            
    else if (dieChoice == 'b')
    {
        p1Die = new LoadedDie(sides);
    }

    
    /*get user-defined Die type for player 2*/
    cout << "What kind of die will Player 2 have?" << endl
         << "a: Regular Die         b: Loaded Die" << endl;
    cin >> dieChoice;
        
    /*assign appropriate Die object to player 1*/
    if (dieChoice == 'a')
    {
        p2Die = new Die(sides);
    }
            
    else if (dieChoice == 'b')
    {
        p2Die = new LoadedDie(sides);
    }
    

    /*get number of rounds from the user*/
    cout << "How many rounds will the players play?" << endl;
    cin >> rounds;

	/*loops through the number of rounds, playing war*/
    for (int counter = 0; counter < rounds; counter++)
    {
        war.playWar(p1Die, p2Die);
    }

    
	/*prints results of game*/
    cout << endl << std::setw(8) << std::left << "Round" <<
            std::setw(9) << std::left << "Player 1" << "Player 2" <<
            std::endl;

	/*gets vectors of scores*/
    p1Vector = war.getP1Scores();
    p2Vector = war.getP2Scores();

	/*prints the result of each round*/
    for (int counter = 0; counter < p1Vector.size(); counter++)
    {
        cout << std::setw(8) << std::left << counter + 1 <<
            std::setw(9) << std::left << p1Vector[counter] <<
            p2Vector[counter] << std::endl;
    }
        
    /*gets each player's total score*/
    p1Score = war.getP1Total();
    p2Score = war.getP2Total();

    std::cout << std::endl;

	/*displays overall winner*/
    if (p1Score > p2Score)
        cout << "Player 1 has won with a score of " << p1Score <<
            " to " << p2Score << ".";
    else if (p1Score < p2Score)
        cout << "Player 2 has won with a score of " << p2Score <<
            " to " << p1Score << ".";
    else
        cout << "Player 1 and Player 2 have tied with a score of " <<
            p1Score << " to " << p2Score << ".";       

    std::cout << std::endl;

	delete[] p1Die;
	delete[] p2Die;
	
    return 0;
}










