#include <iostream>
using namespace std;

struct phanSo {
    long tuSo, mauSo;
};

void input(phanSo &a) {
    cout << "Nhap tu so : ";
    cin >> a.tuSo;
    cout << "Nhap mau so : ";
    cin >> a.mauSo;
    if( a.mauSo == 0) {
        cout << "Nhap lai mau so : ";
        cin >> a.mauSo;
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

void rutGon(phanSo &a) {
    long usc = uscln(a.tuSo, a.mauSo);
    a.tuSo = a.tuSo / usc;
    a.mauSo = a.mauSo / usc;
    if((a.tuSo > 0 && a.mauSo < 0) || (a.tuSo < 0 && a.mauSo < 0)) {
        a.tuSo = -a.tuSo;
        a.mauSo = -a.mauSo;
    }
}

void Find(phanSo a, phanSo b) {
    cout << "Phan so lon hon la : ";
    if(a.tuSo * b.mauSo > b.tuSo * a.mauSo) {
        cout << a.tuSo;
        if(!(a.mauSo == 1)) {
            cout << "/" << a.mauSo;
        }
    }
    else {
        cout << b.tuSo;
            if(!(b.mauSo == 1)) {
                cout << "/" << b.mauSo;
        }
    }
}

int main()
{
	phanSo a, b;
	cout << "Nhap phan so thu nhat " << endl;
	input(a);
	rutGon(a);
    cout << "Nhap phan so thu hai " << endl;
	input(b);
	rutGon(b);
	Find(a, b);
	return 0;
}
