//LineSegment class specification file
#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP

#include "Point.hpp" //for Point class


//LineSegment class declaration
class LineSegment
{
private: //private class members
    Point point1,
	  point2;

public: //public class methods
    LineSegment(Point, Point); //constructor with 2 Point arguments
    
    //setter and getter functions
    void setEnd1(Point);
    void setEnd2(Point);
    Point getEnd1();
    Point getEnd2();

    //calculates length of LineSegment
    double length();

    //calculates slope of LineSegment
    double slope();

};
#endif
