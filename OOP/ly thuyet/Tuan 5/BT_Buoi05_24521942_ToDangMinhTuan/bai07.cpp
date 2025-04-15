#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>

using namespace std;

class GiaSuc {
public:
    virtual void keuDoi() const = 0;
    virtual GiaSuc* sinhCon() const = 0;
    virtual int choSua() const = 0;
    virtual string loai() const = 0;
    virtual ~GiaSuc() {}
};

class Bo : public GiaSuc {
public:
    void keuDoi() const override {
        cout << "Umbo!" << endl;
    }
    GiaSuc* sinhCon() const override {
        return new Bo();
    }
    int choSua() const override {
        return rand() % 21;
    }
    string loai() const override {
        return "Bo";
    }
};

class Cuu : public GiaSuc {
public:
    void keuKhiDoi() const override {
        cout << "Bee!" << endl;
    }
    GiaSuc* sinhCon() const override {
        if (rand() % 3 != 0) {
            return new Cuu();
        } else {
            return nullptr;
        }
    }
    int choSua() const override {
        return rand() % 6;
    }
    string loai() const override {
        return "Cuu";
    }
};

class De : public GiaSuc {
public:
    void keuKhiDoi() const override {
        cout << "Meh!" << endl;
    }
    GiaSuc* sinhCon() const override {
        if (rand() % 2 != 0) {
            return new De();
        } else {
            return nullptr;
        }
    }
    int choSua() const override {
        return rand() % 11;
    }
    string loai() const override {
        return "De";
    }
};

int main() {
    srand(time(0));

    int soBoBanDau, soCuuBanDau, soDeBanDau;

    cout << "Nhap so luong bo ban dau: ";
    cin >> soBoBanDau;
    cout << "Nhap so luong cuu ban dau: ";
    cin >> soCuuBanDau;
    cout << "Nhap so luong de ban dau: ";
    cin >> soDeBanDau;

    vector<Bo> trangTraiBo;
    for (int i = 0; i < soBoBanDau; ++i) {
        trangTraiBo.push_back(Bo());
    }

    vector<Cuu> trangTraiCuu;
    for (int i = 0; i < soCuuBanDau; ++i) {
        trangTraiCuu.push_back(Cuu());
    }

    vector<De> trangTraiDe;
    for (int i = 0; i < soDeBanDau; ++i) {
        trangTraiDe.push_back(De());
    }

    cout << "\n--- Tieng keu khi doi ---" << endl;
    for (int i = 0; i < trangTraiBo.size(); ++i) {
        trangTraiBo[i].keuKhiDoi();
    }
    for (int i = 0; i < trangTraiCuu.size(); ++i) {
        trangTraiCuu[i].keuKhiDoi();
    }
    for (int i = 0; i < trangTraiDe.size(); ++i) {
        trangTraiDe[i].keuKhiDoi();
    }

    cout << "\n--- Thong ke sau mot lua sinh va mot luot cho sua ---" << endl;

    vector<Bo> boMoi = trangTraiBo;
    for (int i = 0; i < trangTraiBo.size(); ++i) {
        int soCon = trangTraiBo[i].sinhCon();
        for (int j = 0; j < soCon; ++j) {
            boMoi.push_back(Bo());
        }
    }
    trangTraiBo = boMoi;

    vector<Cuu> cuuMoi = trangTraiCuu;
    for (int i = 0; i < trangTraiCuu.size(); ++i) {
        int soCon = trangTraiCuu[i].sinhCon();
        for (int j = 0; j < soCon; ++j) {
            cuuMoi.push_back(Cuu());
        }
    }
    trangTraiCuu = cuuMoi;

    vector<De> deMoi = trangTraiDe;
    for (int i = 0; i < trangTraiDe.size(); ++i) {
        int soCon = trangTraiDe[i].sinhCon();
        for (int j = 0; j < soCon; ++j) {
            deMoi.push_back(De());
        }
    }
    trangTraiDe = deMoi;

    int tongSoBo = trangTraiBo.size();
    int tongSoCuu = trangTraiCuu.size();
    int tongSoDe = trangTraiDe.size();

    cout << "So luong bo: " << tongSoBo << endl;
    cout << "So luong cuu: " << tongSoCuu << endl;
    cout << "So luong de: " << tongSoDe << endl;

    int tongSoSua = 0;
    for (int i = 0; i < trangTraiBo.size(); ++i) {
        tongSoSua += trangTraiBo[i].choSua();
    }
    for (int i = 0; i < trangTraiCuu.size(); ++i) {
        tongSoSua += trangTraiCuu[i].choSua();
    }
    for (int i = 0; i < trangTraiDe.size(); ++i) {
        tongSoSua += trangTraiDe[i].choSua();
    }

    cout << "Tong so lit sua: " << tongSoSua << " lit" << endl;

    return 0;
}
