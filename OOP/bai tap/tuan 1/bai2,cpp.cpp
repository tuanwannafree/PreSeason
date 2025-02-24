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

int flag = false;

struct Phanso {
    int tu;
    int mau;
};

int ucln( int a, int b) {
    while(b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}



void rutgon(Phanso &a) {
    int ucl = ucln(a.tu, a.mau);
    a.tu = a.tu / ucl;
    a.mau = a.mau / ucl;
    if(a.mau != 1) {
        if((a.mau  < 0 && a.tu > 0) || (a.tu < 0 && a.mau < 0) ) {
            a.tu = - a.tu;
            a.mau = - a.mau;
        }
    }
}

void init(Phanso &a) {
    if(!flag) {
        cout << "Nhap vao tu so phan so 1: ";
        cin >> a.tu;
        cout <<"Nhap vao mau so phan so 1: ";
        cin >> a.mau;
        if(a.mau == 0) {
            cout <<"Nhap lai mau so phan so 1: ";
            cin >> a.mau;
        }
        flag = true;
    }
    else {
        cout << "Nhap vao tu so phan so 2: ";
        cin >> a.tu;
        cout <<"Nhap vao mau so phan so 2: ";
        cin >> a.mau;
        if(a.mau == 0) {
            cout <<"Nhap lai mau so phan so 2: ";
            cin >> a.mau;
        }
    }
    rutgon(a);

}

void display(Phanso a) {
    if(a.mau == 1) {
        cout << "So lon nhat la: " << a.tu;
    }
    else {
        cout << "Phan so la: " << a.tu << "/" << a.mau;
    }
}

void sosanh(Phanso a, Phanso b) {
    if(a.tu * b.mau > b.tu * a.mau) {
        display(a);
    }
    else {
        display(b);
    }
}

int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    Phanso a, b;
    init(a);
    init(b);
    sosanh(a, b);


	return 0;
}
