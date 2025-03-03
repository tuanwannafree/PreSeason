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
	c.thuc = thuc * a.thuc ;
	c.ao = ao + a.ao;
	return c;
}