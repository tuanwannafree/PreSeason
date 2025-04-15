#include <iostream>
using namespace std;

#pragma once

class toaDo
{
	private: 
		double x, y;
	public:
		void set(double, double);
		double getX();
		double getY();
		void nhap();
		void xuat();
		double getKhoangCach(toaDo);
		toaDo operator+(toaDo);

};

