// Chuong3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Rectangle.h"
using namespace std;

int main()
{	
	// Vi du trang 11
	Rectangle r1, * r2;
	r2 = &r1;
	r1.set(5, 8);
	r2->set(8, 10);
	cout << r1.area();

}

