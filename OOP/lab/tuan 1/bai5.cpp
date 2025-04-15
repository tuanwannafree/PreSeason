#include<iostream>
using namespace std;

struct date {
    int day, month, year;
};

void nhap(date &a) {
    cout << "Nhap ngay : ";
    cin >> a.day;
    cout << "Nhap thang : ";
    cin >> a.month;
    cout << "Nhap nam : ";
    cin >> a.year;

}

bool isLeapYear(int a) {
    if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
		return true;
	return false;
}

bool legitDate(date a) {
    if (a.year < 1 || a.day < 1)
		return false;
	if (a.month < 1 || a.month > 12)
		return false;
	if ((a.month == 1 || a.month == 3 || a.month == 5 || a.month == 7 || a.month == 8 || a.month == 10 || a.month == 12) && (a.day > 31))
		return false;
	if ((a.month == 4 || a.month == 6 || a.month == 9 || a.month == 11) && (a.day > 30))
		return false;
	if ((isLeapYear(a.year) && a.month == 2 && a.day > 29) || (!isLeapYear(a.year) && a.month == 2 && a.day > 28))
		return false;
	return true;
}


void findNextDate(date &a) {
    a.day++;

    if (a.day > 31) {
		a.day = 1;
		a.month++;
		if (a.month > 12) {
			a.month = 1;
			a.year++;
		}
	}
	else if (a.day > 30) {
		if ((a.month == 4 || a.month == 6 || a.month == 9 || a.month == 11))
		{
			a.day = 1;
			a.month++;
		}
	}
	else if (a.month == 2) {
		if (isLeapYear(a.year)) {
			if (a.day > 29)
			{
				a.day = 1;
				a.month++;
			}
		}
		else {
			if (a.day > 28)
			{
				a.day = 1;
				a.month++;
			}
		}
	}


}

void print(date a) {
    cout << "Ngay tiep theo la : " ;
    cout << a.day << "/" << a.month << "/" << a.year << endl;
}

int main()
{
    date Date;
    cout << "Nhap ngay thang nam " << endl;
    nhap(Date);
    while(!legitDate(Date)) {
        cout << "Ngay thang nam khong hop le, yeu cau nhap lai " << endl;
        nhap(Date);
    }
    findNextDate(Date);
    print(Date);

	return 0;
}
