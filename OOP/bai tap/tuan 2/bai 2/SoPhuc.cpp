#include "SoPhuc.h"

void SoPhuc::nhap() {
	int a, b; cin >> a >> b;
	this -> thuc = a;
	this->ao = b;
}

SoPhuc SoPhuc::operator + (SoPhuc a) {
	SoPhuc c;
	c.thuc = thuc + a.thuc;
	c.ao = ao + a.ao;
	return c;
}

SoPhuc SoPhuc::operator - (SoPhuc a) {
	SoPhuc c;
	c.thuc = thuc - a.thuc;
	c.ao = ao - a.ao;
	return c;
}

SoPhuc SoPhuc::operator * (SoPhuc a) {
	SoPhuc c;
	c.thuc = thuc * a.thuc - ao * a.ao;
	c.ao = thuc * a.ao + ao * a.thuc;
	return c;
}

SoPhuc SoPhuc::operator / (SoPhuc a) {
	SoPhuc c;
	c.thuc = (thuc * a.thuc + ao * a.ao) / ( (a.thuc * a.thuc) + (a.ao * a.ao)) ;
	c.ao = (a.thuc * ao - thuc * a.ao) / ((a.thuc * a.thuc) + (a.ao * a.ao));
	return c;
}

void SoPhuc::display() {
	cout << "So phuc la : ";
	cout << thuc;
	if (ao > 0) {
		cout << " +";
	}
	cout << " " <<ao << "i" << endl;
}

void SoPhuc::init(int a, int b) {
	thuc = a;
	ao = b;
}

void SoPhuc::DinhGiaTri() {
	float c = sqrt(thuc * thuc + ao * ao);
	cout << "Dinh gia tri so phuc : " << c << endl;
}