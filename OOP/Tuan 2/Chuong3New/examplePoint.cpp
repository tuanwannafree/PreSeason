#include "examplePoint.h"
#include <iostream>
using namespace std;

/* Dinh nghia cac ham thanh phan */
void examplePoint::init(int ox, int oy) {
	cout << "Ham thanh phan " << endl;
	x = ox, y = oy;
	/*x, y la cac thanh phan cua doi tuong goi ham thanh phan */
}

void examplePoint::move(int dx, int dy) {
	cout << "Ham thanh phan move" << endl;
	x += dx, y += dy;
}

void examplePoint::display() {
	cout << "Ham thanh phan display" << endl;
	cout << "Toa do: " << x << y << endl;
}
