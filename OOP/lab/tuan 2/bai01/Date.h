#pragma once
#include <memory>
#include <iostream>
using namespace std;
class Date
{
	private:
		int iNgay, iThang, iNam;
	public:
		Date() {}
		Date(int iNgay, int iThang, int iNam) {
			this->iNgay = iNgay;
			this->iThang = iThang;
			this->iNam = iNam;
		}
		bool isLeapYear();
		bool isValidDate();
		void Nhap();
		void Xuat();
		Date NGayThangNamTiepTheo();
};

