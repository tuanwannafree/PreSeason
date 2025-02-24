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
    //rutgon(a);

}

void display(Phanso a) {
    if(a.mau == 1) {
        cout <<a.tu << endl;
    }
    else {
        cout << a.tu << "/" << a.mau << endl;
    }
}

Phanso operator+(Phanso a, Phanso b) {
    Phanso c;
    c.tu = a.tu * b.mau + a.mau * b.tu;
    c.mau = a.mau * b.mau;
    rutgon(c);
    return c;
}

Phanso operator-(Phanso a, Phanso b) {
    Phanso c;
    c.tu = a.tu * b.mau - a.mau * b.tu;
    c.mau = a.mau * b.mau;
    rutgon(c);
    return c;
}

Phanso operator*(Phanso a, Phanso b) {
    Phanso c;
    c.tu = a.tu * b.tu;
    c.mau = a.mau * b.mau;
    rutgon(c);
    return c;
}

Phanso operator/(Phanso a, Phanso b) {
    Phanso c;
    c.tu = a.tu * b.mau ;
    c.mau = a.mau * b.tu;
    rutgon(c);
    return c;
}

int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    Phanso p1, p2, sum, sub, product, div;
    init(p1);
    init(p2);
    sum = p1 + p2;
    sub = p1 - p2;
    product = p1 * p2;
    div = p1 / p2;
    cout <<"Ket qua phep cong 2 phan so la : " <<endl;
    display(sum);
    cout <<"Ket qua phep tru 2 phan so la : " <<endl;
    display(sub);
    cout <<"Ket qua phep nhan 2 phan so la : " <<endl;
    display(product);
    if( p2.tu == 0) {
        cout << "Phep chia khong the thuc hien";
    } else {
        cout <<"Ket qua phep chia 2 phan so la : " <<endl;
        display(div);
    }



	return 0;
}
