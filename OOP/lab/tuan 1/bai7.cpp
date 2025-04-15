#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <regex>
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

struct date {
    int day, month, year;
};
struct Time {
    int hour, minute;
};

struct fly {
    char maChuyenBay[6];
    date Date;
    Time dayTime;
    char noiDi[21];
    char noiDen[21];
};

int rdn(int y, int m, int d) {
    if(y < 3) {
        y--, m +=12;
    }
    return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}

bool legitMaChuyenBay(char a[]) {
    int length = strlen(a);
    for (int i = 0; i < length; i++) {
        if (!isalnum(static_cast<unsigned char>(a[i]))) {  // If not a letter or number
            return false;
        }
    }
    return true;
}

bool leapYear(int year) {
    return (((year % 4 == 0) &&
         (year % 100 != 0)) ||
         (year % 400 == 0));
}

bool checkNgay(date a) {
    if(a.year < 0 ) {
        return false;
    }
    if(a.month < 1 || a.month > 12) {
        return false;
    }
    if(a.day < 1 || a.day > 31) {
        return false;
    }
    if(a.month == 2) {
        if(leapYear(a.year)) {
            return (a.day <= 29);
        }
        else {
            return a.day <= 28;
        }
    }

    if(a.month == 4 || a.month == 6 || a.month == 9 || a.month == 11 ) {
        return a.day <= 30;
    }
    return true;
}

bool legitDiaDanh(char a[]) {
    int length = strlen(a);
    for(int i = 0; i < length; i++) {
        if(!isalpha(a[i]) && !isspace(a[i])) {
            return false;
        }
        if(isdigit(a[i])) {
            return false;
        }
    }
    return true;
}

bool check(fly a, fly b) {
    if(rdn(a.Date.year, a.Date.month, a.Date.day ) - rdn(b.Date.year, b.Date.month, b.Date.day ) < 0) {
        return true;
    } else if(rdn(a.Date.year, a.Date.month, a.Date.day ) == rdn(b.Date.year, b.Date.month, b.Date.day)) {
        if(a.dayTime.hour * 60 + a.dayTime.minute < b.dayTime.hour * 60 + b.dayTime.minute) {
            return true;
        } else {
            return false;
        }
    }
    return false;
}


void nhapNgay(date &a) {
    cout << "Nhap ngay : ";
    cin >> a.day;
    cout << "Nhap thang : ";
    cin >> a.month;
    cout << "Nhap nam : ";
    cin >> a.year;
    while(checkNgay(a) == 0) {
        cout << "Nhap lai ngay " << endl;
        cout << "Nhap ngay ";
        cin >> a.day;
        cout << "Nhap thang ";
        cin >> a.month;
        cout << "Nhap nam ";
        cin >> a.year;
    }
}

void nhapTime(Time &a) {
    cout << "Nhap thoi gian cat canh " << endl;
    cout << "Nhap gio : ";
    cin >> a.hour;
    cout << "Nhap phut : ";
    cin >> a.minute;
    while(a.hour < 0 || a.hour > 24 || a.minute < 0 || a.minute >= 60) {
        cout << "Nhap lai thoi gian cat canh " << endl;
        cout << "Nhap gio : ";
        cin >> a.hour;
        cout << "Nhap phut : ";
        cin >> a.minute;
    }

}

void nhapMaChuyenBay(char *a) {
    do {
        cout << "Nhap ma chuyen bay (5 ky tu): ";
        cin >> ws;
        cin.getline(a, 6);
    } while (!legitMaChuyenBay(a) || strlen(a) != 5);
}

void nhapNoiDi(char * a) {
    do {
        cout << "Nhap noi di: ";
        cin >> ws;
        cin.getline(a, 21);
    } while (!legitDiaDanh(a));
}

void nhapNoiDen(char * a) {
    do {
        cout << "Nhap noi den: ";
        cin >> ws;
        cin.getline(a, 21);
    } while (!legitDiaDanh(a));
}

void nhapChuyenBay(fly &a) {
    nhapMaChuyenBay(a.maChuyenBay);
    nhapNgay(a.Date);
    nhapTime(a.dayTime);
    nhapNoiDi(a.noiDi);;
    nhapNoiDen(a.noiDen);
}

void nhap(vector<fly> &a) {
    for(int i = 0; i < a.size(); i++) {
        nhapChuyenBay(a[i]);
    }
}

void timKiemChuyenBay(vector<fly> a) {
    cout << "Nhap ma chuyen bay hoac noi di hoac noi den de tim kiem : ";

    char b[31];
    cin.getline(b, 31);
    string subStr(b);

    for(int i = 0; i < a.size(); i++) {
        string stra(a[i].maChuyenBay), strb(a[i].noiDi), strc(a[i].noiDen);
        if(stra.find(subStr) != string::npos || strb.find(subStr) != string::npos || strc.find(subStr) != string::npos )
        cout << "Ma chuyen bay: " << a[i].maChuyenBay << " | "
             << "Ngay bay: " << a[i].Date.day <<"/"<<a[i].Date.month <<"/"<<a[i].Date.year << " | "
             << "Gio bay: " << a[i].dayTime.hour << "/"<<a[i].dayTime.minute << " | "
             << "Noi di: " << a[i].noiDi << " | "
             << "Noi den: " << a[i].noiDen << endl;
   }
}

void sapXepChuyenBay(vector<fly> &a) {
    int minn;
    for(int i = 0; i < a.size()-1; i++) {
        minn = i;
        for(int j = i + 1; j < a.size();j++) {
            if(check(a[j], a[minn])) minn = j;
        swap(a[i], a[minn]);
        }
    }
    cout << "Sap xep chuyen bay : " << endl;
    for(int i = 0; i < a.size(); i++) {
        cout << "Ma chuyen bay: " << a[i].maChuyenBay << " | "
             << "Ngay bay: " << a[i].Date.day <<"/"<<a[i].Date.month <<"/"<<a[i].Date.year << " | "
             << "Gio bay: " << a[i].dayTime.hour << "/"<<a[i].dayTime.minute << " | "
             << "Noi di: " << a[i].noiDi << " | "
             << "Noi den: " << a[i].noiDen << endl;
    }
}

void demChuyenBay(vector<fly> a) {
    cout << "Nhap noi di va noi den de dem chuyen bai "<< endl;
    fly tmp;
    nhapNoiDi(tmp.noiDi);
    nhapNoiDen(tmp.noiDen);
    int cnt = 0;
    for(int i = 0; i < a.size(); i++) {
        if(strcmp(tmp.noiDi, a[i].noiDi) == 0 && strcmp(tmp.noiDen, a[i].noiDen) == 0) {
            cnt++;
        }
    }
    cout << "So luong chuyen bay di tu " << tmp.noiDi << " den " << tmp.noiDen <<" la " <<cnt;
}

int main()
{
    cout << "Nhap so luong chuyen bay : ";
    int n; cin >> n;
    vector<fly> Flies(n);
    nhap(Flies);
    timKiemChuyenBay(Flies);
    sapXepChuyenBay(Flies);
    demChuyenBay(Flies);

	return 0;
}
