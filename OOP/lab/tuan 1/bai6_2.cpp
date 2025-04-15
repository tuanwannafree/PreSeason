#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <iomanip>
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

struct hocSinh{
    char hoTen[31];
    double toan, van, anh;
    double diemTrungBinh;
    char loai[20];
};

bool legitName(char a[]) {
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

void nhapTen(char* a) {
    cout << "Nhap ten hoc sinh : " << endl;
    cin.ignore();
    cin.getline(a, 31);
    while(!legitName(a)) {
        cout << "Nhap lai ten hoc sinh : " << endl;
        cin.getline(a, 31);
    }
}

void nhapHocSinh(hocSinh &a) {
    nhapTen(a.hoTen);
    cout << "Nhap diem toan : ";
    cin >> a.toan;
    while(a.toan < 0 || a.toan > 10) {
        cout << "Nhap lai diem toan : ";
        cin >> a.toan;
    }
    cout << "Nhap diem van : ";
    cin >> a.van;
    while(a.van< 0 || a.van > 10) {
        cout << "Nhap lai diem van : ";
        cin >> a.van;
    }
    cout << "Nhap diem anh : ";
    cin >> a.anh;
    while(a.anh < 0 || a.anh > 10) {
        cout << "Nhap lai diem anh : ";
        cin >> a.anh;
    }
    a.diemTrungBinh = (2 * a.toan + a.van + a.anh) / 4;
    if(a.diemTrungBinh < 5) {
        strcpy(a.loai, "Yeu");
    } else if (a.diemTrungBinh < 6.5) {
        strcpy(a.loai, "Trung binh");
    } else if (a.diemTrungBinh < 8) {
        strcpy(a.loai, "Kha");
    } else if (a.diemTrungBinh < 9) {
        strcpy(a.loai, "Gioi");
    } else  {
        strcpy(a.loai, "Xuat sac");
    }



}

void nhap(vector<hocSinh> &a) {
    int n = a.size();
    for(int i = 0; i < n; i++) {
        nhapHocSinh(a[i]);
    }
}

void print(vector<hocSinh> a) {
    cout << left << setw(20) << "Ho Ten"
         << setw(10) << "Toan"
         << setw(10) << "Van"
         << setw(10) << "Anh"
         << setw(10) << "Diem TB"
         << setw(15) << "Xep Loai" << endl;
    cout << string(75, '-') << endl;
    for(int i = 0; i < a.size(); i++) {
        cout << left << setw(20) << a[i].hoTen
             << setw(10) << a[i].toan
             << setw(10) << a[i].van
             << setw(10) << a[i].anh
             << setw(10) << fixed << setprecision(2) << a[i].diemTrungBinh
             << setw(15) << a[i].loai << endl;

    }
}


void printBest(vector<hocSinh> a) {
    cout << "Hoc sinh co diem trung binh cao nhat : " << endl;
    cout << left << setw(20) << "Ho Ten"
         << setw(10) << "Toan"
         << setw(10) << "Van"
         << setw(10) << "Anh"
         << setw(10) << "Diem TB"
         << setw(15) << "Xep Loai" << endl;
    cout << string(75, '-') << endl;
    double best = -1;
    int k;
    for(int i = 0; i < a.size(); i++) {
        double tmp = best;
        best = max(best, a[i].diemTrungBinh);
        if(tmp != best) {
            k = i;
        }
    }
    cout << left << setw(20) << a[k].hoTen
         << setw(10) << a[k].toan
         << setw(10) << a[k].van
         << setw(10) << a[k].anh
         << setw(10) << fixed << setprecision(2) << a[k].diemTrungBinh
         << setw(15) << a[k].loai << endl;
}

void printByName(vector<hocSinh> a) {
    cout << "Nhap ten hoc sinh tim kiem : " << endl;
    char b[31];
    cin.ignore();
    cin.getline(b, 31);
    string subStr(b);
    cout << left << setw(20) << "Ho Ten"
         << setw(10) << "Toan"
         << setw(10) << "Van"
         << setw(10) << "Anh"
         << setw(10) << "Diem TB"
         << setw(15) << "Xep Loai" << endl;
    cout << string(75, '-') << endl;
    for(int i = 0; i < a.size(); i++) {
        string str(a[i].hoTen);
        if(str.find(subStr) != string::npos) {
            cout << left << setw(20) << a[i].hoTen
                 << setw(10) << a[i].toan
                 << setw(10) << a[i].van
                 << setw(10) << a[i].anh
                 << setw(10) << fixed << setprecision(2) << a[i].diemTrungBinh
                 << setw(15) << a[i].loai << endl;
        }
    }
}

void printMathLowest(vector<hocSinh> a) {
    cout << "Hoc sinh co diem toan thap nhat : " << endl;
    cout << left << setw(20) << "Ho Ten"
         << setw(10) << "Toan"
         << setw(10) << "Van"
         << setw(10) << "Anh"
         << setw(10) << "Diem TB"
         << setw(15) << "Xep Loai" << endl;
    cout << string(75, '-') << endl;
    double best = 11;
    int k;
    for(int i = 0; i < a.size(); i++) {
        double tmp = best;
        best = min(best, a[i].toan);
        if(tmp != best) {
            k = i;
        }
    }
    cout << left << setw(20) << a[k].hoTen
         << setw(10) << a[k].toan
         << setw(10) << a[k].van
         << setw(10) << a[k].anh
         << setw(10) << fixed << setprecision(2) << a[k].diemTrungBinh
         << setw(15) << a[k].loai << endl;
}

int main()
{
    int n;
    cout << "Nhap so luong hoc sinh : ";
    cin >> n;
	vector<hocSinh> a(n);
	nhap(a);
	print(a);
	printBest(a);
	printByName(a);
	printMathLowest(a);
	return 0;
}
