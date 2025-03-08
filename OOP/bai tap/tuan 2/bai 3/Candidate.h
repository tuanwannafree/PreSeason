#pragma once
#include <iostream>
using namespace std;
class Candidate
{
	private:
		char mssv[20];
		char name[20];
		int date;
		int month;
		int year;
		int toan;
		int van;
		int anh;

	public:
		void nhap();
		void TestCandidate();
};

