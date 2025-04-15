#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct date {
    int day, month, year;
};

bool checkMaSo(const char maSo[]) {
    int length = strlen(maSo);
    if (length != 5) return false;
    for (int i = 0; i < length; i++) {
        if (!isalnum(maSo[i])) return false;
    }
    return true;
}

bool checkTen(const char name[]) {
    int length = strlen(name);
    for (int i = 0; i < length; i++) {
        if (!isalpha(name[i]) && !isspace(name[i])) return false;
    }
    return true;
}

bool leapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool checkNgay(date a) {
    if (a.year < 0 || a.month < 1 || a.month > 12 || a.day < 1 || a.day > 31) return false;
    if (a.month == 2) return a.day <= (leapYear(a.year) ? 29 : 28);
    if (a.month == 4 || a.month == 6 || a.month == 9 || a.month == 11) return a.day <= 30;
    return true;
}

class cCandidate {
private:
    char maHocSinh[6];
    char hoTen[31];
    double toan, van, anh;
    date Date;

public:
    cCandidate() {};
    void nhap();
    void xuat() const;
    double getTongDiem() const { return toan + van + anh; }
};

void cCandidate::nhap() {
    do {
        cout << "Nhap ma so (5 ky tu): ";
        cin >> ws;
        cin.getline(maHocSinh, 6);
    } while (!checkMaSo(maHocSinh));

    do {
        cout << "Nhap ten hoc sinh: ";
        cin.getline(hoTen, 31);
    } while (!checkTen(hoTen));

    do {
        cout << "Nhap diem toan: ";
        cin >> toan;
    } while (toan < 0);

    do {
        cout << "Nhap diem van: ";
        cin >> van;
    } while (van < 0);

    do {
        cout << "Nhap diem anh: ";
        cin >> anh;
    } while (anh < 0);

    do {
        cout << "Nhap ngay sinh (dd mm yyyy): ";
        cin >> Date.day >> Date.month >> Date.year;
    } while (!checkNgay(Date));
}

void cCandidate::xuat() const {
    cout << "Ma thi sinh: " << maHocSinh << "\n";
    cout << "Ho ten: " << hoTen << "\n";
    cout << "Diem toan: " << toan << "\n";
    cout << "Diem van: " << van << "\n";
    cout << "Diem anh: " << anh << "\n";
    cout << "Ngay sinh: " << Date.day << "/" << Date.month << "/" << Date.year << "\n";
}

class cListCandidate {
private:
    vector<cCandidate> candi;

public:
    void nhapList();
    void xuatList() const;
    void xuatListOver15() const;
    void timThiSinhTongDiemCaoNhat() const;
    void sapXepGiamDan();
};

void cListCandidate::nhapList() {
    int n;
    cout << "Nhap so luong thi sinh: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cCandidate temp;
        cout << "Nhap thong tin thi sinh thu " << i + 1 << ":\n";
        temp.nhap();
        candi.push_back(temp);
    }
}

void cListCandidate::xuatList() const {
    for (const auto &c : candi) {
        c.xuat();
    }
}

void cListCandidate::xuatListOver15() const {
    cout << "Danh sach thi sinh co tong diem tren 15:\n";
    for (const auto &c : candi) {
        if (c.getTongDiem() > 15) {
            c.xuat();
        }
    }
}

void cListCandidate::timThiSinhTongDiemCaoNhat() const {
    if (candi.empty()) return;
    const cCandidate *maxCandi = &candi[0];
    for (const auto &c : candi) {
        if (c.getTongDiem() > maxCandi->getTongDiem()) {
            maxCandi = &c;
        }
    }
    cout << "Thi sinh co tong diem cao nhat:\n";
    maxCandi->xuat();
}

void cListCandidate::sapXepGiamDan() {
    sort(candi.begin(), candi.end(), [](const cCandidate &a, const cCandidate &b) {
        return a.getTongDiem() > b.getTongDiem();
    });
}

void Menu() {
    cout << "_______________________________" << endl;
    cout << "0. Thoat" << endl;
    cout << "1. Nhap danh sach thi sinh" << endl;
    cout << "2. In danh sach thi sinh co tong diem tren 15" << endl;
    cout << "3. Tim thi sinh co tong diem cao nhat" << endl;
    cout << "4. Sap xep danh sach giam dan theo tong diem" << endl;
    cout << "_______________________________" << endl;
}

void run() {
    cListCandidate danhSach;
    int t;
    do {
        Menu();
        cout << "Nhap lua chon: ";
        cin >> t;
        switch (t) {
            case 1:
                danhSach.nhapList();
                break;
            case 2:
                danhSach.xuatListOver15();
                break;
            case 3:
                danhSach.timThiSinhTongDiemCaoNhat();
                break;
            case 4:
                danhSach.sapXepGiamDan();
                danhSach.xuatList();
                break;
        }
    } while (t != 0);
}

int main() {
    run();
    return 0;
}
