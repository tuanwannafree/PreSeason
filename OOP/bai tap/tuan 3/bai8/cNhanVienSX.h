#pragma once
class cNhanVienSX
{
	private:
		struct date {
			int day, month, year;
		};
		char maNhanVien[6];
		char hoTen[31];
		int soSanPham;
		long double giaMotSanPham;
		date a;
		static long long tongLuong;
	public:
		cNhanVienSX(char maNhanVien[],char hoTen[], int soSanPham, long double giaMotSanPham, date a) {
			set( maNhanVien, hoTen, soSanPham, giaMotSanPham, a);
		}
		void set(char maNhanVien[], char hoTen[], int soSanPham, long doulbe giaMotSanPham, date a) {

		}

};

