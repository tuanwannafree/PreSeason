#pragma once
class examplePoint
{
	/* khai bao cac thuoc tinh */
	private:
		int x, y;
	/* Khai bao cac phuong thuc / ham thanh phan */
	public:
		void init(int ox, int oy);
		void move(int dx, int dy);
		void display();
}; // Ket thuc khai bao lop

