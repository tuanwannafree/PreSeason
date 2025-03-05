#pragma once
#include <iostream>
#include <math.h>
using namespace std;
class SoPhuc
{
	private:
		double thuc, ao;

	public:
		void init(int a, int b);
		void display();
		void nhap();
		void DinhGiaTri();
		SoPhuc operator + (SoPhuc a);
		SoPhuc operator - (SoPhuc a);
		SoPhuc operator * (SoPhuc a);
		SoPhuc operator / (SoPhuc a);
};

