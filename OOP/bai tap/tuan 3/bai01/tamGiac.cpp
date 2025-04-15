#include "tamGiac.h"

void tamGiac::nhap() {
	cout << "Nhap toa do 3 dinh cua tam giac: " << endl;
	cout << "Nhap dinh thu nhat: " << endl;
	A.nhap();
	cout << "Nhap dinh thu hai: " << endl;
	B.nhap();
	cout << "Nhap dinh thu ba: " << endl;
	C.nhap();

	if (!legitTamGiac()) {
		system("cls");
		cout << "Ba dinh tren khong the hinh thanh tam giac. Hay nhap lai toa do: " << endl;
		nhap();
	}
}

void tamGiac::xuat() {
	cout << "Toa do 3 dinh cua tam giac: " << endl;
	cout << "Dinh thu nhat: " << endl;
	A.xuat();
	cout << "Dinh thu hai: " << endl;
	B.xuat();
	cout << "Dinh thu ba: " << endl;
	C.xuat();
}

bool tamGiac::legitTamGiac() {
	double AB = A.getKhoangCach(B);
	double BC = B.getKhoangCach(C);
	double AC = A.getKhoangCach(C);

	if ((AB + BC > AC) && (BC + AC > AB) && (AB + AC > BC))
		return true;
	return false;
}

void tamGiac::checkLoaiTamGiac() {
	double AB = A.getKhoangCach(B);
	double BC = B.getKhoangCach(C);
	double AC = A.getKhoangCach(C);
	if (AB == BC && BC == AC) {
		cout << "Tam giac deu" << endl; 
	}
	else if (AB == BC || BC == AC || AB == AC) {
		if ((AB * AB + BC * BC == AC * AC) ||
			(BC * BC + AC * AC == AB * AB) ||
			(AC * AC + AB * AB == BC * BC)) {
			cout << "Tam giac vuong can" << endl;
		}
		else {
			cout << "Tam giac can" << endl; 
		}
	}
	else if ((AB * AB + BC * BC == AC * AC) ||
		(BC * BC + AC * AC == AB * AB) ||
		(AC * AC + AB * AB == BC * BC)) {
		cout << "Tam giac vuong" << endl; 
	}
	else {
		cout << "Tam giac thuong" << endl; 
	}
}

double tamGiac::chuVi() {
	double AB = A.getKhoangCach(B);
	double BC = B.getKhoangCach(C);
	double AC = A.getKhoangCach(C);
	return AB + BC + AC;
}

double tamGiac::dienTich() {
	double AB = A.getKhoangCach(B);
	double BC = B.getKhoangCach(C);
	double AC = A.getKhoangCach(C);
	double p = (AB + BC + AC) / 2;
	return sqrt((p * (p - AB) * (p - BC) * (p - AC)));
}

void tamGiac::tinhTienPoint(toaDo x) {
	A = A + x;
	B = B + x;
	C = C + x;

}

void tamGiac::tinhTien(tamGiac& a) {
	toaDo move;
	cout << "Nhap toa do vector tinh tien: ";
	move.nhap();
	a.tinhTienPoint(move);
	system("cls");
	cout << "Da tinh tien tam giac theo vector (" << move.getX() << "," << move.getY() << ")." << endl;
	a.xuat();
}
