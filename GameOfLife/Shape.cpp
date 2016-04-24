/*
** Program Filename:	Shape.cpp
** Author:				Nicholas Brown
** Date:				10/2/2015
** Description:			Implementation file for the Shape Class
** Input:				Several of the functions require the starting position
**						and pattern chosen.
** Output:				The generations of the patterns are printed to the console.
*/

#include "Shape.hpp"
#include <iostream>


/* 
** Function: Constructor
** Description: Initializes the Shape to all dead cells, then calls
**				the appropriate function based on the user's choice.
** Parameters: None.
** Pre-Conditions: None.
** Post-Conditions: An array of all dead cells, representing the 
**					Game of Life "world."
*/

Shape::Shape (int shapeType, int x, int y)
{
	// run initiate function 
	initiate();


	//run appropriate make Shape function
	switch (shapeType)
	{
	case 1:
		makeOscillator(x, y);
		break;

	case 2:
		makeGlider(x, y);
		break;

	case 3:
		makeGliderGun(x, y);
		break;

	}
}


/* 
** Function: initiate
** Description: This is a PRIVATE Shape method. It Initializes the array,
**				pattern, to all dead, because there will be less live cells 
**				than dead.
** Parameters: None.
** Pre-Conditions: The height and width should be set, these are static
**					constants in the header.
** Post-Conditions: Member 'pattern' has all dead cells, representing the
**					first Game of Life "world's" generation from which to 
**					build the first Shape's generation.
*/

void Shape::initiate ()
{
	// initiates all cells to dead
	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			pattern[w][h] = dead;
		}
	}

}


/* 
** Function: makeOscillator
** Description: Creates the first generation of the fixed Oscillator shape.
** Parameters: Two integers representing the x and y coordinates of the center
**				of the Oscillator.
** Pre-Conditions: The member 'pattern' has been first initialized with 
**				all dead cells.
** Post-Conditions: The first generation of the Oscillator is born.  
				The member 'pattern' can then be printed to the console
**				via the printShape function.
*/

void Shape::makeOscillator (int x, int y)
{

	/* 
	** Sets the first generation of the oscillator
	** pattern based on the user's center point.
	**
	** I broke it into 3 loops, one for all the sections
	** that the y offset was only +-1, another for +-6 & +-1,
	** and yet another where the y offset was only +-6.
	*/

	for (int xOffset = 2; xOffset <= 4; xOffset++)
	{
		pattern[y + 1][x + xOffset] = alive;
		pattern[y - 1][x + xOffset] = alive;
		pattern[y + 1][x - xOffset] = alive;
		pattern[y - 1][x - xOffset] = alive;
	}

	for (int yOffset = 2; yOffset <= 4; yOffset++)
	{
		pattern[y + yOffset][x + 1] = alive;
		pattern[y + yOffset][x + 6] = alive;
		pattern[y + yOffset][x - 1] = alive;
		pattern[y + yOffset][x - 6] = alive;
		pattern[y - yOffset][x + 1] = alive;
		pattern[y - yOffset][x + 6] = alive;
		pattern[y - yOffset][x - 1] = alive;
		pattern[y - yOffset][x - 6] = alive;
	}

	for (int xOffset = 2; xOffset <= 4; xOffset++)
	{
		pattern[y + 6][x + xOffset] = alive;
		pattern[y - 6][x + xOffset] = alive;
		pattern[y + 6][x - xOffset] = alive;
		pattern[y - 6][x - xOffset] = alive;
	}

}


/* 
** Function: makeGlider
** Description: Creates the first generation of the Glider shape.
** Parameters: Two integers representing the x and y coordinates of the center
**				of the Glider's leading edge.
** Pre-Conditions: The member 'pattern' has been first initialized with all dead cells.
** Post-Conditions: The first generation of the Glider is born.  The member
**					'pattern' can then be printed to the console via the 
**					printShape function.
*/

void Shape::makeGlider (int x, int y)
{
	/* 
	** Sets the first generation of the glider
	** pattern based on user's center point.
	**
	** This particular glider is a little complicated,
	** in terms of the layout, I used a combination of
	** for loops, and regular assigning statements.
	*/

	for (int yOffset = 5; yOffset <= 7; yOffset++)
	{
		pattern[y + yOffset][x - 2] = alive;
		pattern[y - yOffset][x - 2] = alive;
	}

	for (int xOffset = -1; xOffset <= 0; xOffset++)
	{ 	
		pattern[y - 8][x + xOffset] = alive;
		pattern[y + 8][x + xOffset] = alive;
		pattern[y - 6][x + xOffset] = alive;
		pattern[y + 6][x + xOffset] = alive;
		pattern[y - 4][x + xOffset] = alive;
		pattern[y + 4][x + xOffset] = alive;
	}

	pattern[y - 3][x - 1] = alive;
	pattern[y + 3][x - 1] = alive;
	pattern[y - 7][x + 1] = alive;
	pattern[y + 7][x + 1] = alive;
	pattern[y - 5][x + 3] = alive;
	pattern[y + 5][x + 3] = alive;
	pattern[y - 4][x + 5] = alive;
	pattern[y + 4][x + 5] = alive;
	pattern[y - 1][x + 5] = alive;
	pattern[y + 1][x + 5] = alive;
	pattern[y - 2][x + 6] = alive;
	pattern[y + 2][x + 6] = alive;

	for (int yOffset = -2; yOffset <= -1; yOffset++)
	{
		pattern[y + yOffset][x + 7] = alive;
		pattern[y - yOffset][x + 7] = alive;
	}

	for (int yOffset = -5; yOffset <= -4; yOffset++)
	{
		pattern[y + yOffset][x + 1] = alive;
		pattern[y - yOffset][x + 1] = alive;
	}

	for (int yOffset = -2; yOffset <= -1; yOffset++)
	{
		pattern[y + yOffset][x + 1] = alive;
		pattern[y - yOffset][x + 1] = alive;
	}

	for (int xOffset = 2; xOffset <= 4; xOffset++)
	{
		pattern[y - 3][x + xOffset] = alive;
		pattern[y + 1][x + xOffset] = alive;
		pattern[y - 1][x + xOffset] = alive;
		pattern[y + 3][x + xOffset] = alive;
	}

	for (int xOffset = 4; xOffset <= 6; xOffset++)
	{
		pattern[y - 6][x + xOffset] = alive;
		pattern[y + 6][x + xOffset] = alive;
		pattern[y - 5][x + xOffset] = alive;
		pattern[y + 5][x + xOffset] = alive;
	}

	for (int xOffset = 7; xOffset <= 8; xOffset++)
	{
		pattern[y - 7][x + xOffset] = alive;
		pattern[y + 7][x + xOffset] = alive;
	}
	
}


/* 
** Function: makeGliderGun
** Description: Creates the first generation of the Gosper Glider Gun shape.
** Parameters: Two integers representing the x and y coordinates of the upper left
**				corner of the glider gun.
** Pre-Conditions: The member 'pattern' has been first initialized with all dead cells.
** Post-Conditions: The first generation of the Glider Gun is born.  The member
**					'pattern' can then be printed to the console via the
**					printShape function.
*/

void Shape::makeGliderGun (int x, int y)
{
	/* 
	** The shape required a combination of for loops and direct
	** assignment statements to initiate the first generation.
	*/
	pattern[y + 22][x + 2] = alive;
	pattern[y + 22][x + 6] = alive;
	pattern[y + 11][x + 4] = alive;
	pattern[y + 15][x + 4] = alive;
	pattern[y + 14][x + 6] = alive;
	pattern[y + 17][x + 6] = alive;
	pattern[y + 10][x + 7] = alive;
	pattern[y + 16][x + 7] = alive;
	pattern[y + 11][x + 8] = alive;
	pattern[y + 15][x + 8] = alive;

	for (int xOffset = 5; xOffset <= 6; xOffset++)
	{
		pattern[y][x + xOffset] = alive;
		pattern[y + 1][x + xOffset] = alive;
		pattern[y + 10][x + xOffset] = alive;
		pattern[y + 16][x + xOffset] = alive;
	}

	for (int xOffset = 3; xOffset <= 5; xOffset++)
	{
		pattern[y + 20][x + xOffset] = alive;
		pattern[y + 21][x + xOffset] = alive;
	}

	for (int xOffset = 1; xOffset <= 2; xOffset++)
	{
		pattern[y + 24][x + xOffset] = alive;
	}

	for (int xOffset = 6; xOffset <= 7; xOffset++)
	{
		pattern[y + 24][x + xOffset] = alive;
	}

	for (int xOffset = 3; xOffset <= 4; xOffset++)
	{
		pattern[y + 34][x + xOffset] = alive;
		pattern[y + 35][x + xOffset] = alive;
	}

	for (int yOffset = 12; yOffset <= 13; yOffset++)
	{
		pattern[y + yOffset][x + 3] = alive;
		pattern[y + yOffset][x + 9] = alive;
	}

}


/* 
** Function: playByTheRules
** Description: Applies the rules of Conway's Game of Life.
** Parameters: A Shape object.
** Pre-Conditions: The Shape has a first generation on which the rules can be applied.
**					and the public static const members height and width have been set.
** Post-Conditions: The next generation of the Shape is created. It then replaces
**					the current generation in the pattern array via the 
**					swap function, and is ready to be printed to the console 
**					via the printShape function.
*/

void Shape::playByTheRules (Shape myShape)
{
	/*
	** The nested loops use the Shape's member variables of
	** height and width in order to loop through all cells in 
	** the "world."
	*/
	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			int sum = 0;

			if (pattern[w][h] == alive)
			{
				if (pattern[w - 1][h - 1] == alive)
					sum++;

				if (pattern[w - 1][h] == alive)
					sum++;
				
				if (pattern[w - 1][h + 1] == alive)
					sum++;
		
				if (pattern[w][h - 1] == alive)
					sum++;

				if (pattern[w][h + 1] == alive)
					sum++;
				
				if (pattern[w + 1][h] == alive)
					sum++;

				if (pattern[w + 1][h - 1] == alive)
					sum++;

				if (pattern[w + 1][h + 1] == alive)
					sum++;

				if (sum == 2 || sum == 3)
				{
					pattern2[w][h] = alive;
				}
				else
				{
					pattern2[w][h] = dead;
				}

			} // closes first outer if statement
			else if (pattern[w][h] == dead)
			{
				if (pattern[w - 1][h - 1] == alive)
					sum++;

				if (pattern[w][h - 1] == alive)
					sum++;

				if (pattern[w + 1][h - 1] == alive)
					sum++;

				if (pattern[w - 1][h] == alive)
					sum++;

				if (pattern[w + 1][h] == alive)
					sum++;

				if (pattern[w - 1][h + 1] == alive)
					sum++;

				if (pattern[w][h + 1] == alive)
					sum++;

				if (pattern[w + 1][h + 1] == alive)
					sum++;

				if (sum == 3)
				{
					pattern2[w][h] = alive;
				}
				else
				{
					pattern2[w][h] = dead;
				}

			} // closes second outer if statement

		} // closes inner for loop statement

	} // closes outer for loop statement

	
	// swaps out the new generation for the old
	swapPatterns();

}


/* 
** Function: swapPatterns
** Description: This is a PRIVATE Shape method. It swaps the old generation
**				out for the new generation, to update the pattern and be
**				printed to the console via the printShape function
** Parameters: None.
** Pre-Conditions: The height and width should be set, these are static
**					constants in the header.
** Post-Conditions: Member 'pattern' has all dead cells, representing the
**					first Game of Life "world's" generation from which to
**					build the first Shape's generation.
*/

void Shape::swapPatterns()
{
	// swaps generations to get the next generation
	for (int h = 0; h < height; h++)
	{
		for (int w = 0; w < width; w++)
		{
			pattern[w][h] = pattern2[w][h];
		}

	}

}


/*
** Function: printShape
** Description: Print's the newest generation of the Shape to the console.
** Parameters: None.
** Pre-Conditions: A generation of the Shape has been initialized into the 
**					pattern array.
** Post-Conditions: The newest generation is printed to the console..
*/

void Shape::printShape()
{
	for (int counter2 = 40; counter2 < 60; counter2++)
	{
		for (int counter = 80; counter < 120; counter++)
		{
			std::cout << pattern[counter][counter2];
		}

		std::cout << std::endl;
	}


}

