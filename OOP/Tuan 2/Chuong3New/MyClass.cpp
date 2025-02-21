#include "MyClass.h"
#include <iostream>
using namespace std;
int MyClass::count = 0; // Phai khoi gan gia tri cho du lieu tinh

MyClass::MyClass() {
	this->count++;
}
MyClass::~MyClass() {
	this->count--;
}

void MyClass::printCount() {
	cout << "There are currently " << this->count << " instance(s) of MyClass" << endl;
}