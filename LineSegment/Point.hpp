//Point class specification file
#ifndef POINT_HPP
#define POINT_HPP


//Point class declaration
class Point
{
private: //private class members
    double xCoord,
           yCoord;

public: //public class methods
    Point();                //default constructor
    Point(double, double);  //constructor with 2 arguments

    //setter and getter functions
    void setXCoord(double);
    void setYCoord(double);
    double getXCoord();
    double getYCoord();

    //calculates distance between Point calling method
    //and Point being passed as argument
    double distanceTo(const Point&);
		
};
#endif
