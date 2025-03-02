#include "PhanSo.h"

int GCD(int a, int b) {
	int r;
	if (a == 0 || b == 0) return 1;
	while ((r = a % b) != 0) {
		a = b;
		b = r;
	}
	return b;
}

void PhanSo::rutGon(PhanSo& a) {
	int n = GCD(a.tu, a.mau);
	a.tu = a.tu / n;
	a.mau = a.mau / n;
}

PhanSo PhanSo::operator + (PhanSo a) {
	PhanSo c;
	c.tu = tu * a.mau + mau * a.tu;
	c.mau = mau * a.mau;
	rutGon(c);
	return c;
}

PhanSo PhanSo::operator - (PhanSo a) {
	PhanSo c;
	c.tu = tu * a.mau - mau * a.tu;
	c.mau = mau * a.mau;
	rutGon(c);
	return c;
}

PhanSo PhanSo::operator * (PhanSo a) {
	PhanSo c;
	c.tu = tu * a.tu;
	c.mau = mau * a.mau;
	rutGon(c);
	return c;
}

PhanSo PhanSo::operator / (PhanSo a) {
	PhanSo c;
	if (a.tu == 0) {
		cout << "Khong the thuc hien phep chia" << endl;
	}
	else {
		c.tu = tu * a.mau;
		c.mau = mau * a.tu;
		rutGon(c);
		return c;
	}
}


void PhanSo::init(int a, int b) {
	this->tu = a;
	this->mau = b;
}

void PhanSo::Nhap() {
	int a, b; cin >> a >> b;
	this->tu = a;
	this->mau = b;
}

void PhanSo::display() {
	cout << "Gia tri phep tinh la : ";
	if (tu == 0) cout << 0 << endl;
	else if (mau == 1) {
		cout << tu << endl;
	}
	else {
		cout << tu << " / " << mau << endl;
	}
	
}

void PhanSo::DinhGiaTri() {
	double b = (double)(tu) / (double)(mau);
	cout << "Dinh gia tri la : " << b << endl;
}


