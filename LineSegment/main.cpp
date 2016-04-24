#include <iostream>
#include "lineSegment.hpp"

using namespace std;

int main()
{
	double x1,
		x2,
		y1,
		y2;

	cout << "Enter coordinates of first Point:" << endl;
	cin >> x1 >> y1;
	cout << "Enter coordinates of second Point:" << endl;
	cin >> x2 >> y2;

	Point p1(x1, y1);
	Point p2(x2, y2);
	lineSegment ls1(p1, p2);
	double length = ls1.length();
	double slope = ls1.slope();

	double dist = p1.distanceTo(p2);

	
	cout << endl << "Length: " << length << endl;
	cout << "Slope:  " << slope << endl;


	return 0;
}
