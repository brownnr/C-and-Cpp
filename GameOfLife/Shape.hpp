/*
** Program Filename:	Shape.hpp
** Author:				Nicholas Brown
** Date:				9/28/2015
** Description:			Header file for the Shape Class
** Input:				The private methods swapPatterns and initiate are 
**						only called by other class methods, and the 
**						representations of live and dead cells, as well as
**						the height and width of the "world" are static consts.
** Output:				The generations of the patterns are printed to the console.
*/ 

#ifndef SHAPE_HPP
#define SHAPE_HPP


class Shape
{
private:

	static const char dead = ' ',
		alive = '*';
	static const int height = 100,
		width = 200;

	char pattern[width][height];
	char pattern2[width][height];

	// private member functions
	void swapPatterns();
	void initiate();

public:
	Shape(int, int, int);
	void makeOscillator(int, int);
	void makeGlider(int, int);
	void makeGliderGun(int, int);
	void playByTheRules(Shape);
	void printShape();
};




#endif
