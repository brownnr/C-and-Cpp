//Point class function implementation file
#include <cmath> //for sqrt()
#include "Point.hpp" //Point class header



/*****************************************************
*                 default constructor                *
*             sets both coordinates to 0             *
******************************************************/
Point::Point() 
{
    setXCoord(0);
    setYCoord(0);
}

/*****************************************************
* constructor that sets coordinates to the arguments *
*                                                    *
*****************************************************/
Point::Point(double xIn, double yIn)
{
    setXCoord(xIn);
    setYCoord(yIn);
}



/*****************************************************
*             getter &  setter functions             *
*                                                    *
*****************************************************/
void Point::setXCoord(double x)
{
    xCoord = x;
}

void Point::setYCoord(double y)
{
    yCoord = y;
}

double Point::getXCoord()
{
    return xCoord;
}

double Point::getYCoord()
{
    return yCoord;
}



/*****************************************************
*	              distanceTo                     *
*   This function determines the length between the  *
*   Point executing the method and the Point passed  *
*   as an argument.                                  *
*****************************************************/
double Point::distanceTo(const Point &otherPoint)
{
    //square root of ((x1 - x2) * (x1 - x2)) + ((y1 - y2) * (y1 - y2))
    return sqrt((otherPoint.xCoord - xCoord) * (otherPoint.xCoord - xCoord)
	+ (otherPoint.yCoord - yCoord) * (otherPoint.yCoord - yCoord));
}

