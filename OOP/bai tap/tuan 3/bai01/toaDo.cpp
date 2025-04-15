#include "toaDo.h"

void toaDo::set(double x, double y) {
	this->x = x;
	this->y = y;
}

double toaDo::getX() {
	return x;
}

double toaDo::getY() {
	return y;
}

void toaDo::nhap() {
	cout << "Hoanh do: " << endl;
	cin >> x;
	cout << "Tung do: " << endl;
	cin >> y;
}

toaDo toaDo::operator+(toaDo a) {
	toaDo tmp;
	tmp.x = x + a.x;
	tmp.y = y + a.y;
	return tmp;
}

void toaDo::xuat() {
	cout << "(" << x << "," << y << ")" << endl;
}

double toaDo::getKhoangCach(toaDo point) {
	return sqrt((x - point.getX()) * (x - point.getX()) + (y - point.getY()) * (y - point.getY()));
}