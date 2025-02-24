#include "Point.h"
#include <iostream>
void Point::Set(int x, int y) {
	std::cin >> x >> y;
}

Point::Point(int x, int y) {
	abscissa = x;
	ordinate = y;
}

void Point::display() {
	std::cout << abscissa << " " << ordinate;
}
