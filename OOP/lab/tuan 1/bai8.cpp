#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <chrono>
#include <cstdlib>
#include <iomanip>
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
#include <cctype>
#define ll long long
#define pb push_back
#define _for(i,a,b) for(int i = a, i < b; i++)
#define _ford(i,a,b) for(int i = a, i > b; i--)
#define ln endl
using namespace std;

struct date{
    int day, month, year;
};

struct soTietKiem {
    char maSo[6];
    char loaiTietKiem[31];
    char hoTenKhach[31];
    long cmnd;
    date ngayMoSo;
    long double tienGui;
    double laiSuat;
    int thoiHan;

};

bool checkMaSo(char maSo[]) {
    int length = strlen(maSo);
    if(length < 5) {
        return false;
    }
    for(int i = 0; i < length; i++) {
        if(!isalnum(maSo[i]) && !isspace(maSo[i])) {
            return false;
        }
        if(maSo[i] == ' ') {
            return false;
        }
    }
    return true;
}

bool checkTen(char name[]) {
    int length = strlen(name);
    for(int i = 0; i < length; i++) {
        if(!isalpha(name[i]) && !isspace(name[i])) {
            return false;
        }
        if(isdigit(name[i])) {
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

bool checkNgay(date ngayMoSo) {
    if(ngayMoSo.year < 0 ) {
        return false;
    }
    if(ngayMoSo.month < 1 || ngayMoSo.month > 12) {
        return false;
    }
    if(ngayMoSo.day < 1 || ngayMoSo.day > 31) {
        return false;
    }
    if(ngayMoSo.month == 2) {
        if(leapYear(ngayMoSo.year)) {
            return (ngayMoSo.day <= 29);
        }
        else {
            return ngayMoSo.day <= 28;
        }
    }

    if(ngayMoSo.month == 4 || ngayMoSo.month == 6 || ngayMoSo.month == 9 || ngayMoSo.month == 11 ) {
        return ngayMoSo.day <= 30;
    }
    return true;
}

bool checkCMND(int CMND) {
    int cnt = 0;
    while(CMND) {
        cnt++;
        CMND /= 10;
    }
    if(cnt == 9 || cnt == 11) {
        return true;
    }
    return false;
}

void nhapMaSo(char *a) {
    do {
        cout << "Nhap ma so (5 ky tu): ";
        cin >> ws;
        cin.getline(a, 6);
    } while(!checkMaSo(a) || strlen(a) != 5);
}

void nhapTen(char *a) {
    do {
        cout << "Nhap ten khach hang : ";
        cin >> ws;
        cin.getline(a, 31);
    } while(!checkTen(a));
}

void nhapCMND(long &a) {
    do {
        cout << "Nhap chung minh nhan dan hoac can cuoc cong dan : ";
        cin >> a;
    } while(!checkCMND(a));
}

void nhapDate(date a) {
    do {
        cout << "Nhap ngay : ";
        cin >> a.day;
        cout << "Nhap thang : ";
        cin >> a.month;
        cout << "Nhap nam : ";
        cin >> a.year;
    } while(!checkNgay(a));
}

void nhapTien(long double &a) {
    do {
        cout << "Nhap so tien : ";
        cin >> a;
    } while(a < 0);
}

void nhap(soTietKiem &khachHang) {
    nhapMaSo(khachHang.maSo);
    nhapTen(khachHang.hoTenKhach);
    nhapCMND(khachHang.cmnd);
    nhapDate(khachHang.ngayMoSo);
    nhapTien(khachHang.tienGui);
}

void nhapMang(vector<soTietKiem> &data) {
    for(int i = 0; i < data.size(); i++) {
        nhap(data[i]);
    }
}

int rdn(int y, int m, int d) {
    if(y < 3) {
        y--, m +=12;
    }
    return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
}

void xuat(vector<soTietKiem> data) {
    cout << "===== Thong Tin So Tiet Kiem =====" << endl;
    for(int i = 0; i < data.size(); i++) {
        cout << "Ma so          : " << data[i].maSo << endl;
        cout << "Loai tiet kiem : " << data[i].loaiTietKiem << endl;
        cout << "Ho ten KH      : " << data[i].hoTenKhach << endl;
        cout << "CMND           : " << data[i].cmnd << endl;
        cout << "Ngay mo so     : " << data[i].ngayMoSo.day<< "/"
            << data[i].ngayMoSo.month << "/"
            << data[i].ngayMoSo.year << endl;
        cout << "So tien gui    : " << fixed << setprecision(2) << data[i].tienGui << " VND" << endl;
        cout << "lai suat       : " << data[i].laiSuat << endl;
    }
    cout << "=================================" << endl;
}
void rutTien(vector<soTietKiem>& data) {
    char maSo[6];
    cout << "Nhap ma so tiet kiem can rut tien: ";
    cin.ignore();
    cin.getline(maSo, 6);

    for (auto& stk : data) {
        if (strcmp(stk.maSo, maSo) == 0) {
            cout << "Nhap so tien muon rut: ";
            long double soTienRut;
            cin >> soTienRut;

            if (soTienRut > stk.tienGui) {
                cout << "So tien vuot qua so du hien tai!" << endl;
                return;
            }

            date today;
            cout << "Nhap ngay hien tai (dd mm yyyy): ";
            cin >> today.day >> today.month >> today.year;

            int days = rdn(today.year, today.month, today.day) - rdn(stk.ngayMoSo.year, stk.ngayMoSo.month, stk.ngayMoSo.day);

            if (days < stk.thoiHan * 30) {
                cout << "Ban dang rut truoc han! Lai suat se tinh lai voi 0.5%/nam." << endl;
                stk.laiSuat = 0.005;
            }

            stk.tienGui -= soTienRut;
            cout << "Rut tien thanh cong! So du con lai: " << stk.tienGui << " VND" << endl;
            return;
        }
    }

    cout << "Khong tim thay so tiet kiem voi ma so vua nhap!" << endl;

}



int main()
{
    int n;
    cout << "Nhap so luong khach hang : ";
    cin >> n;
    vector<soTietKiem> data(n);
    nhapMang(data);
    xuat(data);



	return 0;
}
