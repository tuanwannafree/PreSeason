#include "Candidate.h"

void Candidate::nhap() {
	cout << "Nhap ma so sinh vien ";
	cin.ignore();
	cin.getline(mssv, 20);
	cout << "Nhap ten sinh vien ";
	cin.getline(name, 20);
	cout << "Nhap ngay thang nam sinh" << endl;
	cout << "Nhap ngay sinh: ";
	cin >> date;
	cout << "Nhap thang sinh: ";
	cin >> month;
	cout << "Nhap nam sinh: ";
	cin >> year;
	cout << "Nhap diem sinh vien" << endl;
	cout << "Nhap diem toan: ";
	cin >> toan;
	cout << "Nhap diem van: ";
	cin >> van;
	cout << "Nhap diem anh: ";
	cin >> anh;

}

void Candidate::TestCandidate() {
	if (toan + van + anh > 15) {
		cout << "Sinh vien: " << name << " ma so: " << mssv << endl;
	}
}
