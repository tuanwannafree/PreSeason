// NhanVienVanPhong.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "cNhanVienVP.h"
using namespace std;

int main()
{
    cNhanVienVP A("abc", "John Cena", "25-2-2005", 5000);
    int n;
    cout << "So nhan vien van phong la: ";
    cin >> n;
    vector<cNhanVienVP> arr;
    for (int i = 0; i < n; i++) {
        cNhanVienVP a;
        a.nhap();
        arr.push_back(a);
    }
    for (int i = 0; i < n; i++) {
        arr[i].xuat();
    }
}


