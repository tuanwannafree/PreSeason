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

void nhapMaSo(char *a) {
    do {
        cout << "Nhap ma so (5 ky tu): ";
        cin >> ws;
        cin.getline(a, 6);
    } while(!checkMaSo(a) || strlen(a) != 5);
}

void nhapTen(char *a) {
    do {
        cout << "Nhap ten hoc sinh : ";
        cin >> ws;
        cin.getline(a, 31);
    } while(!checkTen(a));
}

void nhapDiemToan( double &a) {
    do {
        cout << "Nhap diem toan cua hoc sinh : ";
        cin >> a;
    } while(a < 0);
}

void nhapDiemVan( double &a) {
    do {
        cout << "Nhap diem van cua hoc sinh : ";
        cin >> a;
    } while(a < 0);
}

void nhapDiemAnh( double &a) {
    do {
        cout << "Nhap diem anh cua hoc sinh : ";
        cin >> a;
    } while(a < 0);
}

void nhapDate(date &a) {
    cout <<"Nhap ngay thang nam sinh hoc sinh "<< endl;
    do {
        cout << "Nhap ngay : ";
        cin >> a.day;
        cout << "Nhap thang : ";
        cin >> a.month;
        cout << "Nhap nam : ";
        cin >> a.year;
    } while(!checkNgay(a));
}

class cCandidate {
    private:
        char maHocSinh[6];
		char hoTen[31];
        double toan;
        double van;
        double anh;
		date Date;

    public:
        cCandidate(){};
        ~cCandidate(){};
        cNhanVienVP(char* maHocSinh, char* hoTen, double toan, double van, double anh, date Date) {
            Set(maHocSinh, hoTen, toan, van, anh, Date);
        }
        void Set( char* maHocSinh, char* hoTen, double toan, double van, double anh, date Date) {
            strcpy(this->maHocSinh, maHocSinh);
            strcpy(this->hoTen, hoTen);
            this->toan = toan;
            this->van = van;
            this->anh = anh;
            this->Date = Date;
        }
        char* GetMaHocSinh() {
            return maHocSinh;
        }
        char* GetHoTen() {
            return hoTen;
        }
        double GetDiemToan() {
            return toan;
        }
        double GetDiemVan() {
            return van;
        }
        double GetDiemAnh() {
            return anh;
        }
        date GetDate() {
            return Date;
        }
        void nhap();
        void xuat();
        double getTongDiem() const { return toan + van + anh; }


};

class cListCandidate {
    private:
        vector<cCandidate> candi;
    public:
        void nhapList() {
            int n;
            cout << "Nhap so luong thi sinh: ";
            cin >> n;
            for (int i = 0; i < n; i++) {
                cout << "Nhap thong tin thi sinh thu " << i + 1 << ":\n";
                cCandidate temp;
                temp.nhap();
                candi.push_back(temp);
            }
        }
        void xuatList() {
            cout << "Danh sach thi sinh:\n";
            for (int i = 0; i < candi.size(); i++) {
                candi[i].xuat();
            }
        }
        void xuatListOver15() {
            cout << "Danh sach thi sinh co tong diem tren 15:\n";
            for (int i = 0; i < candi.size(); i++) {
                if(candi[i].GetDiemAnh() + candi[i].GetDiemToan() + candi[i].GetDiemVan() > 15) {
                    candi[i].xuat();
                }
            }
        }

        void timThiSinhTongDiemCaoNhat() const {
            if (candi.empty()) return;
            cCandidate maxCandi = candi[0];
            for(int i =1; i < candi.size(); i++) {
                if (candi[i].getTongDiem() > maxCandi.getTongDiem()) {
                    maxCandi = candi[i];
                }
            }
            cout << "Thi sinh co tong diem cao nhat:\n";
            maxCandi.xuat();
        }
        void SelectSort() {
            int n = candi.size();
            for(int i =0; i < n - 1; ++i) {
                int minn = i;
                for(int j = i + 1; j < n; ++j) {
                    if(candi[j].getTongDiem() >= candi[minn].getTongDiem()) {
                        minn = j;
                    }
                }
            swap(candi[i], candi[minn]);
            }

        }
};


void cCandidate::nhap() {
    nhapMaSo(maHocSinh);
    nhapTen(hoTen);
    nhapDiemToan(toan);
    nhapDiemVan(van);
    nhapDiemAnh(anh);
    nhapDate(Date);
}

void cCandidate::xuat() {
    cout << "Ma thi sinh : " << maHocSinh << endl;
    cout << "Ho ten thi sinh : " << hoTen << endl;
    cout << "Diem toan : " << toan << endl;
    cout << "Diem van : " << van << endl;
    cout << "Diem anh : " << anh << endl;
    cout << "Birthday: "<< Date.day <<"/"<< Date.month <<"/"<< Date.year<< endl;
}

void Menu() {
    cout << "_______________________________" << endl;
    cout << "0. Thoat" << endl;
    cout << "1. Nhap n hoc sinh" << endl;
    cout << "2. In ra danh sach thong tin thi sinh co tong diem  lon hon 15" << endl;
    cout << "3. Thong tin thi sinh co tong diem lon nhat" << endl;
    cout << "4. Sap xep danh sach thi sinh giam dan theo  tong diem" << endl;
    cout << "_______________________________" << endl;
}

void run() {
    cListCandidate a;
    int t;
    do {
        system("cls");
        Menu();
        cout << "Nhap lua chon : ";
        cin >> t;
        switch(t) {
            case 1:
                a.nhapList();
                break;

            case 2:
                a.xuatListOver15();
                break;

            case 3:
                a.timThiSinhTongDiemCaoNhat();
                break;

            case 4:
                a.SelectSort();
                a.xuatList();
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
