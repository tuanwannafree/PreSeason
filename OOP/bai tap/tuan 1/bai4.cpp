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
    while( a.day < 0 || a.day > 31) {
        cout << "Nhap lai ngay: ";
        cin >> a.day;
    }
    cout << "Nhap vao thang: ";
    cin >> a.month;
    if(a.month > 12 || a.month < 0 || (a.day > 30 && a.month == 2) || (a.day > 30 && ( a.month == 4 || a.month == 6 || a.month == 9 || a.month == 1 ))) {
        cout <<"Nhap lai thang: ";
        cin >> a.month;
    }
    cout <<"Nhap vao nam: ";
    cin >> a.year;


    while((leapYear(a.year) && a.day > 30 && a.month == 2) || (!leapYear(a.year) && a.day > 29 && a.month == 2) ) {
            init(a);

    }
}

void solve(Date &a) {
    a.day++;
    if(a.month == 2) {
        if(leapYear(a.year)) {
            if(a.day == 30) {
                a.day = 1;
                a.month = 3;
            }
        } else if( a.day == 29) {
            a.day = 1;
            a.month = 3;
        }
    } else {
        if(a.month == 4 || a.month == 6 || a.month == 9 || a.month == 11) {
            if(a.day == 32) {
                a.day = 1;
                a.month ++;
                if(a.month > 12) {
                    a.month = 1;
                    a.year++;
                }
            }
        } else {
            if(a.day == 32) {
                a.day = 1;
                a.month++;
                if(a.month > 12) {
                    a.month = 1;
                    a.year++;
                }
            }
        }
    }

}

void display(Date a) {
    cout << a.day << ' / ' << a.month << ' / ' << a.year;
}

int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    Date a;
    init(a);
    solve(a);
    display(a);


	return 0;
}
