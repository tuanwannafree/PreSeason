#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

bool isValidName(const string& name) {
    return !name.empty();
}

bool isValidDate(const string& date) {
    if (date.length() != 10) {
        return false;
    }
    if (date[4] != '-' || date[7] != '-') {
        return false;
    }
    int year, month, day;
    try {
        year = stoi(date.substr(0, 4));
        month = stoi(date.substr(5, 2));
        day = stoi(date.substr(8, 2));
    } catch (const std::invalid_argument& e) {
        return false;
    } catch (const std::out_of_range& e) {
        return false;
    }

    if (year < 1900 || year > 2099 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }
    if (month == 2) {
        bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (day > 29 || (day == 29 && !isLeap)) {
            return false;
        }
    }
    return true;
}

class NhanVien {
private:
    string hoTen;
    string ngaySinh;
    double luongCoBan;

public:
    NhanVien(string hoTen, string ngaySinh, double luongCoBan) : hoTen(hoTen), ngaySinh(ngaySinh), luongCoBan(luongCoBan) {}

    virtual double tinhLuong() const {
        return luongCoBan;
    }

    virtual void xuatThongTin() const {
        cout << "Ho ten: " << hoTen << endl;
        cout << "Ngay sinh: " << ngaySinh << endl;
        cout << "Luong: " << tinhLuong() << " VND" << endl;
    }
};

class NhanVienSanXuat : public NhanVien {
private:
    int soSanPham;

public:
    NhanVienSanXuat(string hoTen, string ngaySinh, double luongCoBan, int soSanPham)
        : NhanVien(hoTen, ngaySinh, luongCoBan), soSanPham(soSanPham) {}

    double tinhLuong() const override {
        return NhanVien::tinhLuong() + soSanPham * 5000;
    }

    void xuatThongTin() const override {
        NhanVien::xuatThongTin();
        cout << "So san pham: " << soSanPham << endl;
    }
};

class NhanVienVanPhong : public NhanVien {
private:
    int soNgayLamViec;

public:
    NhanVienVanPhong(string hoTen, string ngaySinh, int soNgayLamViec)
        : NhanVien(hoTen, ngaySinh, 0), soNgayLamViec(soNgayLamViec) {}

    double tinhLuong() const override {
        return soNgayLamViec * 100000;
    }

    void xuatThongTin() const override {
        NhanVien::xuatThongTin();
        cout << "So ngay lam viec: " << soNgayLamViec << endl;
    }
};

int main() {
    vector<NhanVienSanXuat> danhSachSanXuat;
    vector<NhanVienVanPhong> danhSachVanPhong;

    cout << "--- Nhap thong tin nhan vien san xuat ---" << endl;
    while (true) {
        string hoTen;
        cout << "Nhap ho ten (hoac 'q' de ket thuc): ";
        getline(cin >> ws, hoTen);
        if (hoTen == "q") {
            break;
        }
        if (!isValidName(hoTen)) {
            cout << "Ten khong hop le. Vui long nhap lai." << endl;
            continue;
        }
        string ngaySinh;
        cout << "Nhap ngay sinh (YYYY-MM-DD): ";
        cin >> ngaySinh;
        if (!isValidDate(ngaySinh)) {
            cout << "Ngay sinh khong hop le. Vui long nhap lai theo dinh dang YYYY-MM-DD." << endl;
            continue;
        }
        double luongCoBan;
        cout << "Nhap luong can ban: ";
        cin >> luongCoBan;
        int soSanPham;
        cout << "Nhap so san pham: ";
        cin >> soSanPham;
        danhSachSanXuat.emplace_back(hoTen, ngaySinh, luongCoBan, soSanPham);
        cin.ignore();
    }

    cout << "\n--- Nhap thong tin nhan vien van phong ---" << endl;
    while (true) {
        string hoTen;
        cout << "Nhap ho ten (hoac 'q' de ket thuc): ";
        getline(cin >> ws, hoTen);
        if (hoTen == "q") {
            break;
        }
        if (!isValidName(hoTen)) {
            cout << "Ten khong hop le. Vui long nhap lai." << endl;
            continue;
        }
        string ngaySinh;
        cout << "Nhap ngay sinh (YYYY-MM-DD): ";
        cin >> ngaySinh;
        if (!isValidDate(ngaySinh)) {
            cout << "Ngay sinh khong hop le. Vui long nhap lai theo dinh dang YYYY-MM-DD." << endl;
            continue;
        }
        int soNgayLamViec;
        cout << "Nhap so ngay lam viec: ";
        cin >> soNgayLamViec;
        danhSachVanPhong.emplace_back(hoTen, ngaySinh, soNgayLamViec);
        cin.ignore();
    }

    double tongLuongCongTy = 0;
    cout << "\n--- Thong tin va luong cua tung nhan vien ---" << endl;
    cout << "\n--- Nhan vien san xuat ---" << endl;
    for (const auto& nv : danhSachSanXuat) {
        nv.xuatThongTin();
        tongLuongCongTy += nv.tinhLuong();
        cout << "---" << endl;
    }

    cout << "\n--- Nhan vien van phong ---" << endl;
    for (const auto& nv : danhSachVanPhong) {
        nv.xuatThongTin();
        tongLuongCongTy += nv.tinhLuong();
        cout << "---" << endl;
    }

    cout << "\n--- Tong luong cong ty phai tra ---" << endl;
    cout << "Tong luong: " << tongLuongCongTy << " VND" << endl;

    return 0;
}
