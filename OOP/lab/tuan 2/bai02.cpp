#include <iostream>     // Thư viện nhập xuất
#include <cstdlib>      // Dùng cho system("cls")
#include <cmath>        // Dùng cho hàm abs trong rut gon
using namespace std;

// Định nghĩa lớp Phân Số
class PhanSo {
private:
    int iTu, iMau;  // Tử số và mẫu số
public:
    int getTuSo();                         // Trả về tử số
    void set(int, int);                   // Thiết lập phân số

    void Nhap();                          // Nhập phân số từ người dùng
    void Xuat();                          // Xuất phân số ra màn hình

    void RutGon();                        // Rút gọn phân số

    // Toán tử nạp chồng cho các phép tính
    PhanSo operator+(PhanSo);
    PhanSo operator-(PhanSo);
    PhanSo operator*(PhanSo);
    PhanSo operator/(PhanSo);
};

// Các hàm thực hiện phép toán giữa hai phân số
void Tong(PhanSo, PhanSo);
void Hieu(PhanSo, PhanSo);
void Tich(PhanSo, PhanSo);
void Thuong(PhanSo, PhanSo);
void SoSanh(PhanSo, PhanSo);  // Thêm hàm so sánh

int main() {
    PhanSo a, b;
    cout << "Nhap phan so thu nhat" << endl;
    a.Nhap();

    cout << "Nhap phan so thu hai" << endl;
    b.Nhap();

    Tong(a, b);
    Hieu(a, b);
    Tich(a, b);
    Thuong(a, b);
    SoSanh(a, b);

    cout << endl;
    system("pause");
    return 0;
}

// Hàm nhập phân số
void PhanSo::Nhap() {
    cout << " Tu so la: ";
    cin >> iTu;
    cout << " Mau so la: ";
    cin >> iMau;

    // Kiểm tra mẫu số khác 0
    while (iMau == 0) {
        cout << "Mau so phai khac 0. \n Mau so moi la: ";
        cin >> iMau;
    }

    system("cls");  // Xóa màn hình sau khi nhập
}

// Hàm xuất phân số
void PhanSo::Xuat() {
    if (iTu % iMau == 0)
        cout << iTu / iMau;
    else
        cout << iTu << "/" << iMau << " ";
}

// Lấy tử số
int PhanSo::getTuSo() {
    return iTu;
}

// Gán giá trị tử và mẫu số
void PhanSo::set(int iTu, int iMau) {
    this->iTu = iTu;
    this->iMau = iMau;
}

// Hàm tìm ước số chung lớn nhất
long uscln(long x, long y) {
    long r;
    x = abs(x);
    y = abs(y);
    if (x == 0 || y == 0) return 1;
    while ((r = x % y) != 0) {
        x = y;
        y = r;
    }
    return y;
}

// Hàm rút gọn phân số
void PhanSo::RutGon() {
    long usc = uscln(iTu, iMau);
    iTu /= usc;
    iMau /= usc;

    // Đưa dấu âm lên tử số
    if ((iTu > 0 && iMau < 0) || (iTu < 0 && iMau < 0)) {
        iTu = -iTu;
        iMau = -iMau;
    }
}

// Nạp chồng toán tử +
PhanSo PhanSo::operator+(PhanSo x) {
    PhanSo tmp;
    tmp.iTu = iTu * x.iMau + x.iTu * iMau;
    tmp.iMau = iMau * x.iMau;
    tmp.RutGon();
    return tmp;
}

// Nạp chồng toán tử -
PhanSo PhanSo::operator-(PhanSo x) {
    PhanSo tmp;
    tmp.iTu = iTu * x.iMau - x.iTu * iMau;
    tmp.iMau = iMau * x.iMau;
    tmp.RutGon();
    return tmp;
}

// Nạp chồng toán tử *
PhanSo PhanSo::operator*(PhanSo x) {
    PhanSo tmp;
tmp.iTu = iTu * x.iTu;
    tmp.iMau = iMau * x.iMau;
    tmp.RutGon();
    return tmp;
}

// Nạp chồng toán tử /
PhanSo PhanSo::operator/(PhanSo x) {
    PhanSo tmp;
    tmp.iTu = iTu * x.iMau;
    tmp.iMau = iMau * x.iTu;
    tmp.RutGon();
    return tmp;
}

// Hàm tính tổng
void Tong(PhanSo x, PhanSo y) {
    cout << "Tong cua hai phan so la ";
    PhanSo tong = x + y;
    tong.Xuat();
}

// Hàm tính hiệu
void Hieu(PhanSo x, PhanSo y) {
    cout << "\nHieu cua hai phan so la ";
    PhanSo hieu = x - y;
    hieu.Xuat();
}

// Hàm tính tích
void Tich(PhanSo x, PhanSo y) {
    cout << "\nTich cua hai phan so la ";
    PhanSo tich = x * y;
    tich.Xuat();
}

// Hàm tính thương
void Thuong(PhanSo x, PhanSo y) {
    cout << "\nThuong cua hai phan so la ";
    if (y.getTuSo() == 0)
        cout << "khong ton tai" << endl;
    else {
        PhanSo thuong = x / y;
        thuong.Xuat();
    }
}

// Hàm so sánh hai phân số
void SoSanh(PhanSo x, PhanSo y) {
    int trai = x.getTuSo() * y.operator*(PhanSo{1, 1}).iMau;
    int phai = y.getTuSo() * x.operator*(PhanSo{1, 1}).iMau;

    cout << "\nSo sanh hai phan so: ";
    if ((x - y).getTuSo() == 0)
        cout << "Hai phan so bang nhau.";
    else if ((x - y).getTuSo() > 0)
        cout << "Phan so thu nhat lon hon phan so thu hai.";
    else
        cout << "Phan so thu nhat nho hon phan so thu hai.";
}
