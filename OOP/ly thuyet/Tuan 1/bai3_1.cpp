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

struct PhanSo{
    long tu, mau;
};

void init(PhanSo &a) {
    cin >> a.tu >> a.mau;
    while(a.mau == 0) {
        cout << "Nhap lai mau: " << endl;
        cin >> a.mau;
    }
}

long uscln(long x, long y) {
    long r;
    x = abs(x);
    y = abs(y);
    if(x == 0 || y == 0 ) return 1;
    while((r = x % y) != 0) {
        x = y;
        y = r;
    }
    return y;
}

void UocLuoc(PhanSo &a) {
    long usc = uscln(a.tu, a.mau);
    a.tu = a.tu / usc;
    a.mau = a.mau / usc;
}

int main()
{
    PhanSo a;
    init(a);
    UocLuoc(a);
    cout << a.tu;
    if(!(a.mau == 1)) {
        cout << "/" << a.mau;
    }


	return 0;
}
