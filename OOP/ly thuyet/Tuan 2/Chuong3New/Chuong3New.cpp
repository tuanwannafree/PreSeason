// Chuong3New.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Point.h"
#include "examplePoint.h"
#include "MyClass.h"
using namespace std;
int main()
{   // class point
    //Point a(3, 2);
    //a.display();

    // class example point
    /*examplePoint p;
    p.init(2, 4);
    p.display();
    p.move(1, 2);
    p.display(); */

    // class vi du static
    MyClass* x = new MyClass;
    x->printCount();
    MyClass* y = new MyClass;
    x->printCount();
    y->printCount();
    delete x;
    y->printCount();

}

