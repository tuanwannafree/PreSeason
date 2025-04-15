#pragma once
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

class cNhanVienVP
{
	private:
		char msnv[25];
		char fullName[50];
		char dateOfBirth[25];
		double salary;
		static double sumSalary;
	public:
		cNhanVienVP();
		cNhanVienVP(const char msnv[25], const char fullName[50], const  char dateOfBirth[25], double salary);
		void set(const char msnv[25],const  char fullName[50],const char dateOfBirth[25], double salary);
		void nhap();
		void xuat();
};

