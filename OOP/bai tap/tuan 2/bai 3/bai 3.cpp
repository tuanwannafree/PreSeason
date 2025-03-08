// bai 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Candidate.h"
using namespace std;

int main()
{

    //freopen("test.inp", "r", stdin);
    //freopen("test.out", "w", stdout);
    cout << "Nhap so sinh vien: " << endl;
    int n; cin >> n;
    cin.ignore();
    vector<Candidate> arr(n);
    for (int i = 0; i < n; i++) {
        arr[i].nhap();
    }
    cout << "In ra so sinh vien co tong diem 3 mon tren 15 diem " << endl;
    for (int i = 0; i < n; i++) {
        arr[i].TestCandidate();
    }
}

