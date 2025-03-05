#include "Candidate.h"

void Candidate::nhap() {
	Candidate a;
	BirthDate date;
	cin.get(mssv, 25);
	cin.ignore();
	cin.get(name, 25);
	cin.ignore();
	nhapDate(date);



}

void Candidate::nhapDate(BirthDate& date) {
	cout << "Nhap ngay : " << endl;
	cin >> date.day;
	cout << "Nhap thang : " << endl;
	cin >> date.month;
	cout << "Nhap nam : " << endl;
	cin >> date.year;
}

void Candidate::nhapDiem() {
	cout << "Nhap diem toan : " << endl;
	cin >> toan;
	cout << "Nhap diem van : " << endl;
	cin >> van;
	cout << "Nhap diem anh " << endl;
	cin >> anh;
}

void Candidate::display() {

}