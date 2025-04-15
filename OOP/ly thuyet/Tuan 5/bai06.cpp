#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SinhVien {
public:
    string maSo;
    string hoTen;
    string diaChi;
    int tongSoTinChi;
    double diemTrungBinh;

    SinhVien(string m, string h, string d, int tc, double dtb) : maSo(m), hoTen(h), diaChi(d), tongSoTinChi(tc), diemTrungBinh(dtb) {}

    virtual bool xetTotNghiep() const = 0;
    virtual void xuatThongTin() const {
        cout << "Ma so: " << maSo << endl;
        cout << "Ho ten: " << hoTen << endl;
        cout << "Dia chi: " << diaChi << endl;
        cout << "Tong so tin chi: " << tongSoTinChi << endl;
        cout << "Diem trung binh: " << diemTrungBinh << endl;
    }
    double getDiemTrungBinh() const {
        return diemTrungBinh;
    }
};

class SinhVienCaoDang : public SinhVien {
public:
    double diemThiTotNghiep;

    SinhVienCaoDang(string m, string h, string d, int tc, double dtb, double dtnn)
        : SinhVien(m, h, d, tc, dtb), diemThiTotNghiep(dtnn) {}

    bool xetTotNghiep() const override {
        return tongSoTinChi >= 110 && diemTrungBinh >= 5 && diemThiTotNghiep >= 5;
    }
    void xuatThongTin() const override {
        SinhVien::xuatThongTin();
        cout << "Diem thi tot nghiep: " << diemThiTotNghiep << endl;
    }
};

class SinhVienDaiHoc : public SinhVien {
public:
    string tenLuanVan;
    double diemLuanVan;

    SinhVienDaiHoc(string m, string h, string d, int tc, double dtb, string tlv, double dlv)
        : SinhVien(m, h, d, tc, dtb), tenLuanVan(tlv), diemLuanVan(dlv) {}

    bool xetTotNghiep() const override {
        return tongSoTinChi >= 145 && diemTrungBinh >= 5 && diemLuanVan >= 5;
    }
    void xuatThongTin() const override {
        SinhVien::xuatThongTin();
        cout << "Ten luan van: " << tenLuanVan << endl;
        cout << "Diem luan van: " << diemLuanVan << endl;
    }
};

vector<SinhVienCaoDang> nhapDanhSachCaoDang() {
    vector<SinhVienCaoDang> danhSach;
    int n;
    cout << "Nhap so luong sinh vien Cao Dang: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin sinh vien Cao Dang thu " << i + 1 << ":" << endl;
        string maSo, hoTen, diaChi;
        int tongSoTinChi;
        double diemTrungBinh, diemThiTotNghiep;
        cout << "Ma so: "; cin >> maSo;
        cout << "Ho ten: "; cin >> hoTen;
        cout << "Dia chi: "; cin >> diaChi;
        cout << "Tong so tin chi: "; cin >> tongSoTinChi;
        cout << "Diem trung binh: "; cin >> diemTrungBinh;
        cout << "Diem thi tot nghiep: "; cin >> diemThiTotNghiep;
        danhSach.emplace_back(maSo, hoTen, diaChi, tongSoTinChi, diemTrungBinh, diemThiTotNghiep);
    }
    return danhSach;
}

vector<SinhVienDaiHoc> nhapDanhSachDaiHoc() {
    vector<SinhVienDaiHoc> danhSach;
    int n;
    cout << "Nhap so luong sinh vien Dai Hoc: ";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "Nhap thong tin sinh vien Dai Hoc thu " << i + 1 << ":" << endl;
        string maSo, hoTen, diaChi, tenLuanVan;
        int tongSoTinChi;
        double diemTrungBinh, diemLuanVan;
        cout << "Ma so: "; cin >> maSo;
        cout << "Ho ten: "; cin >> hoTen;
        cout << "Dia chi: "; cin >> diaChi;
        cout << "Tong so tin chi: "; cin >> tongSoTinChi;
        cout << "Diem trung binh: "; cin >> diemTrungBinh;
        cout << "Ten luan van: "; cin >> tenLuanVan;
        cout << "Diem luan van: "; cin >> diemLuanVan;
        danhSach.emplace_back(maSo, hoTen, diaChi, tongSoTinChi, diemTrungBinh, tenLuanVan, diemLuanVan);
    }
    return danhSach;
}

void xuatDanhSachSinhVien(const vector<SinhVienCaoDang>& cd, const vector<SinhVienDaiHoc>& dh) {
    cout << "\n--- Danh sach sinh vien Cao Dang ---" << endl;
    for (const auto& sv : cd) {
        sv.xuatThongTin();
        cout << "Du dieu kien tot nghiep: " << (sv.xetTotNghiep() ? "Co" : "Khong") << endl;
        cout << "---" << endl;
    }
    cout << "\n--- Danh sach sinh vien Dai Hoc ---" << endl;
    for (const auto& sv : dh) {
        sv.xuatThongTin();
        cout << "Du dieu kien tot nghiep: " << (sv.xetTotNghiep() ? "Co" : "Khong") << endl;
        cout << "---" << endl;
    }
}

void xuatDanhSachTotNghiep(const vector<SinhVienCaoDang>& cd, const vector<SinhVienDaiHoc>& dh) {
    cout << "\n--- Danh sach sinh vien Cao Dang du dieu kien tot nghiep ---" << endl;
    for (const auto& sv : cd) {
        if (sv.xetTotNghiep()) {
            sv.xuatThongTin();
            cout << "---" << endl;
        }
    }
    cout << "\n--- Danh sach sinh vien Dai Hoc du dieu kien tot nghiep ---" << endl;
    for (const auto& sv : dh) {
        if (sv.xetTotNghiep()) {
            sv.xuatThongTin();
            cout << "---" << endl;
        }
    }
}

void xuatDanhSachKhongTotNghiep(const vector<SinhVienCaoDang>& cd, const vector<SinhVienDaiHoc>& dh) {
    cout << "\n--- Danh sach sinh vien Cao Dang khong du dieu kien tot nghiep ---" << endl;
    for (const auto& sv : cd) {
        if (!sv.xetTotNghiep()) {
            sv.xuatThongTin();
            cout << "---" << endl;
        }
    }
    cout << "\n--- Danh sach sinh vien Dai Hoc khong du dieu kien tot nghiep ---" << endl;
    for (const auto& sv : dh) {
        if (!sv.xetTotNghiep()) {
            sv.xuatThongTin();
            cout << "---" << endl;
        }
    }
}

void timSinhVienDaiHocDiemCaoNhat(const vector<SinhVienDaiHoc>& dh) {
    double maxDiem = -1;
    SinhVienDaiHoc sinhVienDiemCaoNhat("", "", "", 0, 0, "", 0);
    bool found = false;
    for (int i = 0; i < dh.size(); ++i) {
        if (dh[i].getDiemTrungBinh() > maxDiem) {
            maxDiem = dh[i].getDiemTrungBinh();
            sinhVienDiemCaoNhat = dh[i];
            found = true;
        }
    }
    if (found) {
        cout << "\n--- Sinh vien Dai Hoc co diem trung binh cao nhat ---" << endl;
        sinhVienDiemCaoNhat.xuatThongTin();
    } else {
        cout << "\nKhong co sinh vien Dai Hoc trong danh sach." << endl;
    }
}

int main() {
    vector<SinhVienDaiHoc> danhSachDaiHoc = nhapDanhSachDaiHoc();
    vector<SinhVienCaoDang> danhSachCaoDang = nhapDanhSachCaoDang();

    xuatDanhSachSinhVien(danhSachCaoDang, danhSachDaiHoc);
    xuatDanhSachTotNghiep(danhSachCaoDang, danhSachDaiHoc);
    xuatDanhSachKhongTotNghiep(danhSachCaoDang, danhSachDaiHoc);
    timSinhVienDaiHocDiemCaoNhat(danhSachDaiHoc);

    return 0;
}
