#include <iostream>
#include <cmath>

using namespace std;

class SoPhuc {
private:
	double iThuc, iAo;

public:
	void Nhap();
	void Xuat();
	SoPhuc Tong(SoPhuc sp);
	SoPhuc Hieu(SoPhuc sp);
	SoPhuc Tich(SoPhuc sp);
	SoPhuc Thuong(SoPhuc sp);
};

void SoPhuc::Nhap() {
	cout << " Phan thuc: ";
	cin >> iThuc;
	cout << " Phan ao: ";
	cin >> iAo;
}

void SoPhuc::Xuat() {
	if (iAo > 0)
		cout << iThuc << " + " << iAo << "i";
	else if (iAo == 0)
		cout << iThuc;
	else cout << iThuc << " - " << -iAo << "i";
}

SoPhuc SoPhuc::Tong(SoPhuc sp) {
	SoPhuc result;
	result.iThuc = iThuc + sp.iThuc;
	result.iAo = iAo + sp.iAo;
	return result;
}

SoPhuc SoPhuc::Hieu(SoPhuc sp) {
	SoPhuc result;
	result.iThuc = iThuc - sp.iThuc;
	result.iAo = iAo - sp.iAo;
	return result;
}

SoPhuc SoPhuc::Tich(SoPhuc sp) {
	SoPhuc result;
	result.iThuc = iThuc * sp.iThuc - iAo * sp.iAo;
	result.iAo = iThuc * sp.iAo + iAo * sp.iThuc;
	return result;
}

SoPhuc SoPhuc::Thuong(SoPhuc sp) {
	SoPhuc result;
	double denominator = sp.iThuc * sp.iThuc + sp.iAo * sp.iAo;
	if (denominator == 0) {
		cout << "Khong the chia cho so phuc 0" << endl;
		result.iThuc = 0;
		result.iAo = 0;
	} else {
		result.iThuc = (iThuc * sp.iThuc + iAo * sp.iAo) / denominator;
		result.iAo = (iAo * sp.iThuc - iThuc * sp.iAo) / denominator;
	}
	return result;
}

int main() {
	SoPhuc a, b, c;
	cout << "So phuc thu nhat: " << endl;
	a.Nhap();
	cout << "So phuc thu hai: " << endl;
	b.Nhap();
	system("cls");

	cout << "a = ";
	a.Xuat();
	cout << endl;
	cout << "b = ";
	b.Xuat();
	cout << endl;
	cout << endl;

	c = a.Tong(b);
	cout << "a + b = ";
	c.Xuat();
	cout << endl;
	c = a.Hieu(b);
	cout << "a - b = ";
	c.Xuat();
	cout << endl;
	c = a.Tich(b);
	cout << "a * b = ";
	c.Xuat();
	cout << endl;
	c = a.Thuong(b);
	cout << "a : b = ";
	c.Xuat();
	cout << endl;
	cout << endl;

	system("pause");
	return 0;
}
