#pragma once
class TamGiac
{
	private:
		float a, b, c; // Do dai ba canh
		int Loaitg(); //Cho biet loai tam giac: 1-d, 2-vc, 3-c, 4-v, 5-t
		float DienTich(); // Tinh dien tich cua tam giac

	public:
		void Nhap(); // Nhap vao do dai 3 canh
		void Display();
};

