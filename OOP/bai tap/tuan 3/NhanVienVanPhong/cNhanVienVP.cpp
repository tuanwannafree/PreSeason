#include "cNhanVienVP.h"

cNhanVienVP::cNhanVienVP() {}

cNhanVienVP::cNhanVienVP(const char msnv[25],const char fullName[50],const  char dateOfBirth[25], double salary) {
	set(msnv, fullName, dateOfBirth, salary);
}

void cNhanVienVP::set(const char msnv[25],const  char fullName[50],const char dateOfBirth[25], double salary) {
	strcpy_s(this->msnv, msnv);
	strcpy_s(this->fullName, fullName);
	strcpy_s(this->dateOfBirth, dateOfBirth);
	this -> salary = salary;
}

void cNhanVienVP::nhap() {
	cout << "Nhap ma so nhan vien: ";
	cin.get(msnv, 25);
	cin.ignore();
	cout << "Nhap ho ten nhan vien: ";
	cin.get(fullName, 50);
	cin.ignore();
	cout << "Nhap ngay thang nam sinh theo cu phap: (dd-mm-yy) ";
	cin.get(dateOfBirth, 25);

}
void cNhanVienVP::xuat() {
	std::cout << left << setw(10) << "ID"
		<< setw(20) << "Fullname"
		<< setw(15) << "Date of Birth"
		<< setw(10) << "Salary" << "\n";
	std::cout << std::string(55, '-') << "\n"; // Separator line

	// Print actual object details
	cout << left << setw(10) << msnv
		<< setw(20) << fullName
		<< setw(15) << dateOfBirth
		<< setw(10) << fixed << setprecision(2) << salary << "\n";
}
