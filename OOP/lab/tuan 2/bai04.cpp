#include <iostream>
using namespace std;

class GioPhutGiay {
private:
    int iGio;
    int iPhut;
    int iGiay;

public:
    GioPhutGiay(int gio = 0, int phut = 0, int giay = 0) {
        this->iGio = gio;
        this->iPhut = phut;
        this->iGiay = giay;
    }

    void Nhap();
    void Xuat();
    void TinhCongThemMotGiay();
};

int main() {
    GioPhutGiay thoiDiem;

    cout << "Nhap thoi diem: " << endl;
    thoiDiem.Nhap();

    cout << "Thoi diem ban dau la: ";
    thoiDiem.Xuat();
    cout << endl;

    thoiDiem.TinhCongThemMotGiay();
    cout << "Thoi diem sau khi cong them 1 giay: ";
    thoiDiem.Xuat();
    cout << endl;

    return 0;
}

void GioPhutGiay::Nhap() {
    cout << "Nhap gio: ";
    cin >> iGio;
    while (iGio < 0) {
        cout << "Gio phai la so nguyen duong." << endl;
        cout << "Nhap lai gio: ";
        cin >> iGio;
    }

    cout << "Nhap phut: ";
    cin >> iPhut;
    while (iPhut < 0 || iPhut >= 60) {
        cout << "Phut phai nam trong khoang (0;60)." << endl;
        cout << "Nhap lai phut: ";
        cin >> iPhut;
    }

    cout << "Nhap giay: ";
    cin >> iGiay;
    while (iGiay < 0 || iGiay >= 60) {
        cout << "Giay phai nam trong khoang (0;60)." << endl;
        cout << "Nhap lai giay: ";
        cin >> iGiay;
    }
}

void GioPhutGiay::Xuat() {
    cout << iGio << " gio " << iPhut << " phut " << iGiay << " giay";
}

void GioPhutGiay::TinhCongThemMotGiay() {
    iGiay++;
    if (iGiay >= 60) {
        iGiay = 0;
        iPhut++;
        if (iPhut >= 60) {
            iPhut = 0;
            iGio++;
        }
    }
}
