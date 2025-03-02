#pragma once
#include <iostream>
using namespace std;
class PhanSo
{
	private:
		int tu, mau;
	public:
		void init(int a, int b);
		void display();
		void Nhap();
		void DinhGiaTri(PhanSo a);
		void rutGon(PhanSo &a);

		PhanSo operator + (PhanSo a);
		PhanSo operator - (PhanSo a);
		//PhanSo operator * (PhanSo a);
		//PhanSo operator / (PhanSo a);
};

