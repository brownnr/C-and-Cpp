//LineSegment class function implementation file

#include "LineSegment.hpp" //LineSegment class header

/******************************************************
*  constructor that sets the Points to the arguments  *
* 	                                              *
******************************************************/
LineSegment::LineSegment(Point firstPoint, Point secondPoint)
{
    setEnd1(firstPoint);
    setEnd2(secondPoint);
}



/*****************************************************
*	        getter and setter functions          *
*	                                             *
*****************************************************/
void LineSegment::setEnd1(Point firstPoint)
{
    point1 = firstPoint;
}

void LineSegment::setEnd2(Point secondPoint)
{
    point2 = secondPoint;
}

Point LineSegment::getEnd1()
{
    return point1;
}

Point LineSegment::getEnd2()
{
    return point2;
}



/*****************************************************
*	                length                       *
*    This function uses the Point class distanceTo   *
*    method to find the length of the line segment   *
*    between the two Point members                   *
*****************************************************/
double LineSegment::length()
{
    return point1.distanceTo(point2);
}

/*****************************************************
*                       slope                        *
*     This function determines the slope of the      *
*     LineSegment.                                   *
*****************************************************/
double LineSegment::slope()
{
	//slope = (y2 - y1) / (x2 - x1)
	return (point1.getYCoord() - point2.getYCoord()) /
		(point1.getXCoord() - point2.getXCoord());
}
