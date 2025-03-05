// bai 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Candidate.h"
using namespace std;

int main()
{
    int n; cin >> n;
    vector<Candidate> arr;
    cout << "Nhap thi sinh: " << endl;
    for (int i = 0; i < n; i++) {
        arr[i].nhap();
    }
}

