#include <iostream>
using namespace std;

struct Student {
    char name[100];
    int diemToan;
    int diemVan;
};

int main()
{
    Student a;
	cout << "Nhap ho ten hoc sinh: " << endl;
	cin.get(a.name, 25);
	cout << "Nhap diem toan: " << endl;
	cin >> a.diemToan;
	cout << "Nhap diem van: "<< endl;
	cin >> a.diemVan;
	double diemTB = a.diemToan + a.diemVan;
	diemTB /= 2;
	 cout <<"Diem trung binh cua hoc sinh " << a.name << " la "<<diemTB<< endl;


	return 0;
}
