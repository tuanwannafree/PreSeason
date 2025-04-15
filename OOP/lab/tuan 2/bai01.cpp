#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>
#define ll long long
#define pb push_back
#define _for(i,a,b) for(int i = a, i < b; i++)
#define _ford(i,a,b) for(int i = a, i > b; i--)
#define ln endl
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

void Date::Xuat() {
	cout << iNgay<< "/" << iThang << "/" << iNam << endl;
}

bool Date::isLeapYear(){
	if ((iNam % 4 == 0 && iNam % 100 != 0) || (iNam % 400 == 0))
		return true;
	return false;
}

bool Date::isValidDate() {
	if (iNam< 1 || iNgay < 1)
		return false;
	if (iThang < 1 || iThang > 12)
		return false;
	if ((iThang == 1 || iThang == 3 || iThang == 5 || iThang == 7 || iThang == 8 || iThang == 10 || iThang == 12) && (iNgay > 31))
		return false;
	if ((iThang == 4 || iThang == 6 || iThang == 9 || iThang == 11) && (iNgay > 30))
		return false;
	if ((isLeapYear() && iThang == 2 && iNgay > 29) || (!isLeapYear() && iThang == 2 && iNgay > 28))
		return false;
	return true;
}

Date Date::NGayThangNamTiepTheo() {
	Date tmp(++this->iNgay, this->iThang, this->iNam);

	if (tmp.iNgay> 31) {
		tmp.iNgay = 1;
		tmp.iThang++;
		if (tmp.iThang > 12) {
			tmp.iThang = 1;
			tmp.iNam++;
		}
	}
	else if (tmp.iNgay > 30) {
		if ((tmp.iThang == 4 || tmp.iThang == 6 || tmp.iThang == 9 || tmp.iThang == 11))
		{
			tmp.iNgay = 1;
			tmp.iThang++;
		}
	}
	else if (tmp.iThang == 2) {
		if (isLeapYear()) {
			if (tmp.iNgay > 29)
			{
				tmp.iNgay = 1;
				tmp.iThang++;
			}
		}
		else {
			if (tmp.iNgay > 28)
			{
				tmp.iNgay = 1;
				tmp.iThang++;
			}
		}
	}

	return tmp;
}

int main()
{
    Date date;
	cout << "Nhap ngay thang nam: " << endl;
	date.Nhap();

	cout << "Ngay tiep theo la ";
	date.NGayThangNamTiepTheo().Xuat();

	system("pause");
    return 0;
}
