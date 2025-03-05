// bai 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SoPhuc.h"
using namespace std;
int main()
{
    SoPhuc a, b, c;
    cout << "Nhap so phuc a : " << endl;
    a.nhap();
    cout << "Nhap so phuc b : " << endl;
    b.nhap();
    c = a + b;
    c.display();
    c.DinhGiaTri();
    c = a - b;
    c.display();
    c.DinhGiaTri();
    c = a * b;
    c.display();
    c.DinhGiaTri();
    c = a / b;
    c.display();
    c.DinhGiaTri();
    return 0;
}

