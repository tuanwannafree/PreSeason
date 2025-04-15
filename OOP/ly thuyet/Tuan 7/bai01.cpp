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

class soPhuc{
private:
    double iThuc, iAo;
public:
    soPhuc() {};
    soPhuc(double iThuc, double iAo) {
        this->iThuc = iThuc;
        this->iAo = iAo;
    }
    soPhuc operator+(soPhuc);
    soPhuc operator-(soPhuc);
    soPhuc operator*(soPhuc);
    soPhuc operator/(soPhuc);
    bool operator==(const soPhuc& other) const {
        return(iThuc== other.iThuc && iAo == other.iAo);
    }
    bool operator!=(const soPhuc& other) const {
        return !(*this == other);
    }

    friend istream& operator>>(istream& in, soPhuc& c) {
        cout << "Nhap phan thuc:  ";
        in >> c.iThuc;
        cout << "Nhap phan ao: ";
        in >> c.iAo;
        return in;
    }
    friend ostream& operator<<(ostream& out, const soPhuc& c) {
        out << c.iThuc;
        if (c.iAo >= 0) {
            out << " + " << c.iAo << "i";
        } else {
            out << " - " << -c.iAo<< "i";
        }
        return out;
    }
};

soPhuc soPhuc::operator+(soPhuc x) {
    soPhuc c;
    c.iThuc = iThuc + x.iThuc;
    c.iAo = iAo + x.iAo;
    return c;
}

soPhuc soPhuc::operator-(soPhuc x) {
    soPhuc c;
    c.iThuc = iThuc - x.iThuc;
    c.iAo = iAo - x.iAo;
    return c;
}

soPhuc soPhuc::operator*(soPhuc x) {
    soPhuc c;
    c.iThuc = iThuc * x.iThuc - iAo * x.iAo;
    c.iAo = iThuc * x.iAo + iAo * x.iThuc;
    return c;
}

soPhuc soPhuc::operator/(soPhuc x) {
    soPhuc c;
    double denominator = x.iThuc * x.iThuc + x.iAo * x.iAo;
    if(denominator == 0)
    {
        cout << "Khong the chia cho so phuc 0" << endl;
		c.iThuc = 0;
		c.iAo = 0;
    }
    else
    {
        c.iThuc = (iThuc * x.iThuc + iAo * x.iAo) / denominator;
        c.iAo = (iAo * x.iThuc - iThuc * x.iAo) / denominator;
    }
    return c;
}

int main()
{
    soPhuc a,b ,c;
    cout << "Nhap so phuc thu nhat" << endl;
    cin >>  a;
    cout << "Nhap so phuc thu hai" << endl;
    cin >> b;
    c = a + b;
    cout <<  c << endl;
    c = a - b;
    cout <<  c << endl;
    c = a * b;
    cout <<  c << endl;
    c = a / b;
    cout <<  c << endl;
    cout << "a va b la hai so phuc ";
    if(a == b) {
        cout <<"bang nhau";
    }
    else {
        cout << "khong bang nhau";
    }
	return 0;
}
