#include "PhanSo.h"

int ucln(int a, int b) {
	int r;
	if (a == 0 || b == 0) return 1;
	while ((r = a % b) != 0) {
		a = b;
		b = r;
	}
	return b;
}

void PhanSo::nhap() {
	cout << "Nhap tu so: ";
	cin >> tuSo;
	cout << "Nhap mau so: ";
	cin >> mauSo;
	if (mauSo == 0) {
		cout << "nhap lai mau so: ";
		cin >> mauSo;
	}
}

void PhanSo::xuat() {
	if (mauSo == 1) {
		cout << "So duoc rut gon tu phan so la : " << tuSo;
	}
	else {
		cout << "Phan so  sau rut gon la : " << tuSo << " / " << mauSo;
	}
}

void PhanSo::rutGon() {
	int uc = ucln(tuSo, mauSo);
	tuSo = tuSo / uc;
	mauSo = mauSo / uc;
}

void PhanSo::xuLy() {
	if ((tuSo > 0 && mauSo < 0) || (tuSo < 0 && mauSo < 0) ) {
		tuSo = -tuSo;
		mauSo = -mauSo;
	}
}