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

struct date {
    int day, month, year;
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

int rdn(int y, int m, int d) {
    if(y < 3) {
        y--, m +=12;
    }
    return 365*y + y/4 - y/100 + y/400 + (153*m - 457)/5 + d - 306;
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
        cout << "Nhap ten nhan vien : ";
        cin >> ws;
        cin.getline(a, 31);
    } while(!checkTen(a));
}

void nhapLuong( double &a) {
    do {
        cout << "Nhap luong nhan vien : ";
        cin >> a;
    } while(a < 0);
}

void nhapDate(date &a) {
    cout <<"Nhap ngay thang nam sinh nhan vien "<< endl;
    do {
        cout << "Nhap ngay : ";
        cin >> a.day;
        cout << "Nhap thang : ";
        cin >> a.month;
        cout << "Nhap nam : ";
        cin >> a.year;
    } while(!checkNgay(a));
}

class cNhanVienVP {
    private:
        char maNhanVien[6];
		char hoTen[31];
        double luong;
		date Date;

    public:
        static long long tongLuong;
        cNhanVienVP(){};
        ~cNhanVienVP(){};
        cNhanVienVP(char* maNhanVien, char* hoTen, double luong, date Date) {
            Set(maNhanVien, hoTen, luong, Date);
        }
        void Set( char* maNhanVien, char* hoTen, double luong, date Date) {
            strcpy(this->maNhanVien, maNhanVien);
            strcpy(this->hoTen, hoTen);
            this->luong = luong;
            this->Date = Date;
        }
        char* GetMaNhanVien() {
            return maNhanVien;
        }
        char* GetHoTen() {
            return hoTen;
        }
        double GetLuong() {
            return luong;
        }
        date GetDate() {
            return Date;
        }
        void GetTongLuong();
        void printTongLuong();
        void nhap();
        void xuat();


};

long long cNhanVienVP::tongLuong = 0;

void cNhanVienVP::GetTongLuong() {
    this->tongLuong += luong;
}

void cNhanVienVP::printTongLuong() {
    cout << "Tong tien ma cong ty phai tra cho nhan vien la : ";
    cout << cNhanVienVP::tongLuong<< endl;
}

void cNhanVienVP::nhap() {
    nhapMaSo(maNhanVien);
    nhapTen(hoTen);
    nhapLuong(luong);
    nhapDate(Date);
    GetTongLuong();
}

void cNhanVienVP::xuat() {
    cout << "Ma nhan vien : " << maNhanVien << endl;
    cout << "Ho ten nhan vien : " << hoTen << endl;
    cout << "Luong : " << luong << endl;
    cout << "Birthday: "<< Date.day <<"/"<< Date.month <<"/"<< Date.year<< endl;
}

void Menu() {
    cout << "_______________________________" << endl;
    cout << "0. Thoat" << endl;
    cout << "1. Nhap n nhan vien" << endl;
    cout << "2. In ra danh sach thong tin nhan vien" << endl;
    cout << "3. Thong tin nhan vien co luong thap nhat" << endl;
    cout << "4. Tinh tong tien ma cong ty phai tra cho cac nhan vien van phong" << endl;
    cout << "5. Thong tin nhan vien cao tuoi nhat" << endl;
    cout << "6. Sap xep danh sach nhan vien san xuat tang dan theo luong" << endl;
    cout << "_______________________________" << endl;
}

void SelectSortT(vector<cNhanVienVP> a) {
    int n = a.size();
    for(int i =0; i < n - 1; ++i) {
        int minn = i;
        for(int j = i + 1; j < n; ++j) {
            if(a[j].GetLuong() < a[minn].GetLuong()) {
                minn = i;
            }
        }
        swap(a[i], a[minn]);
    }
    a[n-1].xuat();
}

void SelectSortTuoi(vector<cNhanVienVP> a) {
    int n = a.size();
    for(int i =0; i < n - 1; ++i) {
        int minn = i;
        for(int j = i + 1; j < n; ++j) {
            date tmp1 = a[j].GetDate();
            date tmp2 = a[minn].GetDate();
            if(rdn(tmp1.day, tmp1.month, tmp1.year) < rdn(tmp2.day, tmp2.month, tmp2.year)) {
                minn = i;
            }
        }
        swap(a[i], a[minn]);
    }
    a[0].xuat();
}

void SelectSort(vector<cNhanVienVP> &a) {
    int n = a.size();
    for(int i =0; i < n - 1; ++i) {
        int minn = i;
        for(int j = i + 1; j < n; ++j) {
            if(a[j].GetLuong() < a[minn].GetLuong()) {
                minn = i;
            }
        }
        swap(a[i], a[minn]);
    }
}

void run() {
    vector<cNhanVienVP> nhanVien;
    int t;
    do {
        system("cls");
        Menu();
        cout << "Nhap lua chon : ";
        cin >> t;
        switch(t) {
            case 1:
                cout << "Nhap so luong nhan vien: ";
                int n; cin >> n;
                for(int i = 0; i < n; i++) {
                    cout << "Nhap nhan vien thu " << i + 1 << endl;
                    cNhanVienVP tmp; tmp.nhap();
                    nhanVien.push_back(tmp);
                }
                break;

            case 2:
                cout << "Danh sach nhan vien " << endl;
                for(auto &x : nhanVien) x.xuat();
                break;

            case 3:
                cout << "Nhan vien co luong cao nhat nhat la : " << endl;
                SelectSortT(nhanVien);
                break;

            case 4:
                cout << "Tong tien ma cong ty phai tra cho nhan vien la : " << cNhanVienVP::tongLuong << endl;
                break;

            case 5:
                cout << "Nhan vien cao tuoi nhat la : " << endl;
                SelectSortTuoi(nhanVien);
                break;

            case 6:
                cout << "Danh sach nhan vien duoc sap xep theo luong tang dan la : " << endl;
                SelectSort(nhanVien);
                for(auto &x : nhanVien) x.xuat();
                break;


        }
        system("pause");
    } while(t != 0 );
}

int main()
{
    run();
	return 0;
}
