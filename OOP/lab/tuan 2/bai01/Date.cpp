#include "Date.h"
#include <memory>
#include <iostream>
using namespace std;


void Date::Nhap() {
	cout << "  Nhap ngay: ";
	cin >> iNgay;
	cout << "  Nhap thang: ";
	cin >> iThang;
	cout << "  Nhap nam: ";
	cin >> iNam;

	if (!isValidDate()) {
		system("cls");
		cout << "Ngay thang nam khong hop le, vui long nhap lai" << endl;
		Nhap();
	}
}
