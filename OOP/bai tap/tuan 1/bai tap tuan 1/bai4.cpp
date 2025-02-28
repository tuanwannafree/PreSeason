#include <iostream>
using namespace std;

struct Date{
    int day;
    int month;
    int year;
};

bool leapYear( int year) {
    if( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

void init(Date &a) {
    cout << "Nhap vao ngay: ";
    cin >> a.day;
    cout << "Nhap vao thang: ";
    cin >> a.month;
    cout <<"Nhap vao nam: ";
    cin >> a.year;
}

void solve(Date &a) {
    int daysAverage;
    switch (a.month) {
        case 2:
            daysAverage = leapYear(a.year) ? 29 : 28;
            break;
        case 4 : case 6 : case 9 : case 11 :
            daysAverage = 30;
            break;
        default:
            daysAverage = 31;
    }

    a.day++;
    if( a.day > daysAverage) {
        a.day = 1;
        a.month++;
        if(a.month > 12) {
            a.month = 1;
            a.year++;
        }
    }


}

void display(Date a) {
    cout << "Ngay thang nam ke tiep la: " << endl;
    cout << a.day << " / " << a.month << " / "  << a.year;
}

int main()
{
    Date a;
    init(a);
    solve(a);
    display(a);


	return 0;
}
