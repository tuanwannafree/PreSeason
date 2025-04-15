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

void phepCong(phanSo a, phanSo b) {
    phanSo c;
    c.tuSo = a.tuSo * b.mauSo + b.tuSo*a.mauSo;
    c.mauSo = a.mauSo * b.mauSo;
    rutGon(c);
    cout << a.tuSo <<"/" <<a.mauSo <<" + "<<b.tuSo<<"/"<<b.mauSo<<" = "<< c.tuSo;
    if(!(c.mauSo == 1)) {
        cout << "/" << c.mauSo;
    }
    cout << endl;

}


void phepTru(phanSo a, phanSo b) {
    phanSo c;
    c.tuSo = a.tuSo * b.mauSo - b.tuSo*a.mauSo;
    c.mauSo = a.mauSo * b.mauSo;
    rutGon(c);
    cout << a.tuSo <<"/" <<a.mauSo <<" - "<<b.tuSo<<"/"<<b.mauSo<<" = "<< c.tuSo;
    if(!(c.mauSo == 1)) {
        cout << "/" << c.mauSo;
    }
    cout << endl;

}

void phepNhan(phanSo a, phanSo b) {
    phanSo c;
    c.tuSo = a.tuSo * b.tuSo;
    c.mauSo = a.mauSo * b.mauSo;
    rutGon(c);
    cout << a.tuSo <<"/" <<a.mauSo <<" * "<<b.tuSo<<"/"<<b.mauSo<<" = "<< c.tuSo;
    if(!(c.mauSo == 1)) {
        cout << "/" << c.mauSo;
    }
    cout << endl;

}

void phepChia(phanSo a, phanSo b) {
    phanSo c;
    if(b.tuSo == 0) {
        cout << "Khong the thuc hien phep chia do phan so thu hai bang 0.";
    } else {
        c.tuSo = a.tuSo * b.mauSo;
        c.mauSo = a.mauSo * b.tuSo;
        rutGon(c);
        cout << a.tuSo <<"/" <<a.mauSo <<" : "<<b.tuSo<<"/"<<b.mauSo<<" = "<< c.tuSo;
        if(!(c.mauSo == 1)) {
            cout << "/" << c.mauSo;
        }
    cout << endl;
    }


}

int main()
{
	phanSo a, b;
	cout << "Nhap phan so thu nhat " << endl;
	input(a);
    cout << "Nhap phan so thu hai " << endl;
    input(b);
    cout << "Thuc hien phep cong hai phan so : " << endl;
    phepCong(a, b);
    cout << "Thuc hien phep tru hai phan so : " << endl;
    phepTru(a, b);
    cout << "Thuc hien phep nhan hai phan so : " << endl;
    phepNhan(a, b);
    cout << "Thuc hien phep chia hai phan so : " << endl;
    phepChia(a, b);


	return 0;
}
