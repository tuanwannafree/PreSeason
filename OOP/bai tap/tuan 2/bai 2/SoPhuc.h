#pragma once
#include <iostream>
using namespace std;
class SoPhuc
{
	private:
		int thuc, ao;

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

