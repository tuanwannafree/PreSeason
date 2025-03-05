#pragma once
#include <iostream>
using namespace std;
struct BirthDate
{
	int day;
	int month;
	int year;
};

class Candidate
{
	private:
		char mssv[20];
		char name[20];
		BirthDate date;
		int toan;
		int van;
		int anh;

	public:
		void nhap();
		void display();
		void nhapDate(BirthDate &a);
		void nhapDiem();

};

