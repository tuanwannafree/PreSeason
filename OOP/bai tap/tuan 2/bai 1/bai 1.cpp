// tuan 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PhanSo.h"
using namespace std;

int main()
{
    PhanSo a, b, c;
    cout << "Nhap phan so thu nhat: " << endl;
    a.Nhap();
    cout << "Nhap phan so thu hai: " << endl;
    b.Nhap();
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

}
