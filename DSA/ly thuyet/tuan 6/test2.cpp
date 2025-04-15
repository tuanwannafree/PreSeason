#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct NGAY {
    int Ngay, Thang, Nam;
};
struct SINHVIEN {
    string MASV;
    string HoTen;
    NGAY NgaySinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
struct NODE{
    SINHVIEN key;
    NODE* pNext;
};
struct LIST{
    NODE*pHead, *pTail;
};

void NhapNgay(NGAY &a);
void XuatNgay(NGAY a);
void NhapSinhVien(SINHVIEN &a);
void XuatSinhVien(SINHVIEN a);
NODE* CreateNode(SINHVIEN x);
void CreateEmptyList(LIST &L);
void AddTail(LIST& l, NODE* p);
void XuatDS(LIST L);
void NhapDS(LIST &L, int n);
void ChenGiam(LIST &, SINHVIEN);

int main() {
    LIST L;
    int n;
    SINHVIEN sv;

    NhapSinhVien(sv);

    cin >> n ;
    NhapDS(L, n);

    ChenGiam(L, sv);

    XuatDS(L);

    return 0;
}
void NhapNgay(NGAY &a){
    cin >> a.Ngay >> a.Thang >> a.Nam;
}
void XuatNgay(NGAY a){
    cout << a.Ngay << "/" << a.Thang << "/" << a.Nam;
}
void NhapSinhVien(SINHVIEN &a){
    cin >> ws;
    getline(cin, a.MASV);
    getline(cin, a.HoTen);
    NhapNgay(a.NgaySinh);
    cin >> a.GioiTinh;
    cin >> a.DiemToan >> a.DiemLy >> a.DiemHoa;
    a.DTB = (a.DiemToan + a.DiemLy + a.DiemHoa) / 3.0;
}
void XuatSinhVien(SINHVIEN a){
    cout << a.MASV;           cout << "\t";
    cout << a.HoTen;          cout << "\t";
    XuatNgay(a.NgaySinh);     cout << "\t";
    cout << a.GioiTinh;       cout << "\t";
    cout << fixed << setprecision(2) << a.DiemToan; cout << "\t";
    cout << fixed << setprecision(2) << a.DiemLy;   cout << "\t";
    cout << fixed << setprecision(2) << a.DiemHoa;  cout << "\t";
    cout << fixed << setprecision(2) << a.DTB;
}

//###INSERT CODE HERE -
NODE* CreateNode(SINHVIEN x){
    NODE* p = new NODE;
    if (p == NULL) {
        cout << "Khong du bo nho!";
        exit(1);
    }
    p->key = x;
    p->pNext = NULL;
    return p;
}

void CreateEmptyList(LIST &L){
    L.pHead = NULL;
    L.pTail = NULL;
}

void AddTail(LIST& l, NODE* p){
    if(l.pHead == NULL){
        l.pHead = l.pTail = p;
    }
    else{
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void XuatDS(LIST L){
    NODE* p = L.pHead;
    while(p != NULL){
        XuatSinhVien(p->key);
        cout << endl;
        p = p->pNext;
    }
}

void NhapDS(LIST &L, int n){
    CreateEmptyList(L);
    SINHVIEN sv;
    for(int i = 0; i < n; i++){
        NhapSinhVien(sv);
        NODE* p = CreateNode(sv);
        AddTail(L, p);
    }
}

void ChenGiam(LIST &L, SINHVIEN sv){
    NODE* newNode = CreateNode(sv);

    if(L.pHead == NULL || newNode->key.MASV >= L.pHead->key.MASV){
        newNode->pNext = L.pHead;
        L.pHead = newNode;
        if(L.pTail == NULL){
            L.pTail = newNode;
        }
        return;
    }

    NODE *p = L.pHead;
    while(p->pNext != NULL && p->pNext->key.MASV > newNode->key.MASV){
        p = p->pNext;
    }

    newNode->pNext = p->pNext;
    p->pNext = newNode;

    if(newNode->pNext == NULL){
        L.pTail = newNode;
    }
}
//###END INSERT CODE -
