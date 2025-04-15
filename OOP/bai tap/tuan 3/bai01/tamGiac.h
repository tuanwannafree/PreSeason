#include "toaDo.h"
#pragma once
class tamGiac
{
	private:
		toaDo A, B, C;
	public:
		void nhap();
		void xuat();
		bool legitTamGiac();
		void checkLoaiTamGiac();
		double chuVi();
		double dienTich();
		void tinhTien(tamGiac &a );
		void tinhTienPoint(toaDo);
		void quay();
		void phongTo();
		void thuNho();
		void veTamGiac();
};

