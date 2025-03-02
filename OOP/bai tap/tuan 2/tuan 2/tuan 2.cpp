// tuan 2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PhanSo.h"
using namespace std;

int main()
{
    PhanSo a, b, c;
    a.Nhap();
    b.Nhap();
    c = a + b;
   // c = a - b;
    //c = a * b;
    //c = a / b;
    c.display();

}
