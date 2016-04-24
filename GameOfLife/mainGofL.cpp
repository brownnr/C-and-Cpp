/*
** Program Filename:	mainGofL.cpp
** Author:				Nicholas Brown
** Date:				10/2/2015
** Description:			File which contains the main() function.
** Input:				User chooses which pattern and starting point of the patter
**						to play Conway's Game of Life
** Output:				Generations of the pattern are shown on the console.
*/

#include <iostream>	//for cin, cout, endl
#include <cstdlib>
#include <unistd.h>


#include "Shape.hpp"


using std::cout;
using std::cin;
using std::endl;

int main()
{

    // the size of the viewable window and number of generations
    const int windowHeight = 20,
	windowWidth = 40,
	generations = 75;

    unsigned int shapeType,
	yCenter,
    	xCenter,
	counter;


    // user choose's their pattern
    cout << "Choose your shape:" << endl <<
	"[1] Fixed Oscillator" << endl <<
	"[2] Glider" << endl <<
	"[3] Glider Gun\n" <<
    "...";
    cin >> shapeType;


    // test for valid entry
    if (shapeType < 1 || shapeType > 3)
    {
    	cout << "\nInvalid entry, try again.\n";
	cin >> shapeType;
    }

    // note about the viewing area size
    cout << "\nNote: The viewing area is 40x20, any choices outside of the\n" <<
            "      viewing area will be adjusted so that some portion of\n" <<
            "      the pattern stays visible inside of this area.\n";


    /* 
    ** Depending on pattern, the user is prompted for the start point.
    ** That start point is then offset to simulate that the viewing window is
    ** all that exists (i.e. an input of 0,0 will position the starting points
    ** in the upper left of the screen). The coordinates are also adjusted
    ** if the user tries to enter any outside of the viewing area.
    */
    if (shapeType == 1)
    {
    	cout << "\nChoose the position of the center point on the y axis: ";
	cin >> yCenter;
               
        if (yCenter > 44)
            yCenter = 44;

	cout << "Choose the position of the center point on the x axis: ";
	cin >> xCenter;
                
        if (xCenter > 24)
            xCenter = 24;

        yCenter += 79;
        xCenter += 39;
	
    }
    else if (shapeType == 2)
    {
	cout << "\nThis will be the center of the leading edge of the Glider.\n" <<
		"Choose starting position of the center point on the y axis: ";
	cin >> yCenter;

        if (yCenter > 47)
            yCenter = 47;

	cout << "Choose starting position of the center point on the x axis: ";
	cin >> xCenter;

        if (xCenter > 22)
            xCenter = 22;
		
        yCenter += 79;
        xCenter += 39;
		
    }
    else if (shapeType == 3)
    {
        cout << "\nThis will be the approximate upper left corner" <<
        	"of the Gun's area.\n" << "Choose starting position on the y axis: ";
        cin >> yCenter;
	
        if (yCenter > 37)
            yCenter = 37;

        cout << "Choose starting position on the x axis: ";
        cin >> xCenter;

        if (xCenter > 18)
            xCenter = 18;        
        
        yCenter += 80;
        xCenter += 39;
    }


    /* 
    ** User could be prompted, but this was used to require less 
    ** input by the user.
    */
    cout << "\nThe pattern will now iterate through 75 generations.\n" <<
	"Press ENTER to begin.";
    cin.ignore(100, '\n');
    cin.get();

    // Instantiates a shape
    Shape myShape(shapeType, xCenter, yCenter);

    // Clear the console of previous input/output
    system("clear");

    /* 
    ** Loop iterates through the pre-defined number of generations,
	** outputting the newest generation, pausing the screen, then 
	** clearing the screen and getting the next generation.
    */
    for (counter = 0; counter < generations; counter++)
    {
        // prints the latest generation to the console
        myShape.printShape();
            
        // pause the output to see generation
        usleep(100000);
	    
        // clears console after each output
        system("clear");
	
        // Applies the rules of the Game of Life to the Shape
        myShape.playByTheRules(myShape);
    }

    // clears console when done
    system("clear");

    cout << "Thank you for playing, press ENTER to quit.";
    
	// remove unread characters from input queue and get next key pressed
    cin.sync();
    cin.get();
	

    return 0;
}

