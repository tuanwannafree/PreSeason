#include <iostream>
#include <cstring>
using namespace std;

struct student {
    char MSSV[9];
    char TEN[31];
    double DTB;
};

typedef struct tagNode {
    student uni;
    struct tagNode *pNext;
} Node;

typedef struct tagList
{
    Node *pHead;
    Node *pTail;
} LIST;

void CreateList(LIST &l) {
    l.pHead = NULL;
    l.pTail = NULL;
}

Node* CreateNode(student x)
{
    Node *p;
    p = new Node; // cap phat vung nho cho phan tu
    if(p == NULL) exit(1);
    p ->uni = x;
    p->pNext = NULL;
    return p;
}

void PrintList(LIST l)
{
    Node *p;
    p = l.pHead;
    while(p != NULL) {
        cout << p->uni.TEN << " " << p->uni.MSSV << " " << p->uni.DTB << endl;
        p = p ->pNext;
    }
}

void PrintListBigger5(LIST l) {
    Node *p;
    p = l.pHead;
    while(p != NULL && p->uni.DTB >= 5) {
        cout << p->uni.TEN << " " << p->uni.MSSV << " " << p->uni.DTB << endl;
        p = p ->pNext;
    }
}

string XepLoai(double dtb) {
    if(dtb < 3.6) {
        return "loai kem";
    }
    else if(dtb < 5) {
        return "loai yeu";
    }
    else if(dtb < 6.5) {
        return "loai trung binh";
    }
    else if(dtb < 7) {
        return "loai trung binh kha";
    }
    else if(dtb < 8) {
        return "loai kha";
    }
    else if(dtb < 9) {
        return "loai gioi";
    }
    else {
        return "loai xuat sac";
    }
}

void PrintListAndXepHang(LIST l) {
    Node *p;
    p = l.pHead;
    while(p != NULL) {
        cout << p->uni.TEN << " " << p->uni.MSSV << " " << p->uni.DTB ;
        cout << " xep loai : " << XepLoai(p->uni.DTB) << endl;
        p = p ->pNext;
    }
}

Node *Search(LIST l, student a) {
    Node *p;
    p = l.pHead;
    while((p != NULL) && ( (strcmp(p ->uni.MSSV, a.MSSV) == 0) && (strcmp(p ->uni.TEN, a.TEN) == 0) && (p->uni.DTB == a.DTB))) {
         p = p->pNext;
    }
    return p;
}

void AddHead(LIST &l, Node* p) {
    if(l.pHead == NULL) {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void AddTail(LIST &l, Node *p) {
    if(l.pHead == NULL) {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

void InsertAfterQ(LIST &l, Node *p, Node *q) {
    if(q != NULL) {
        p->pNext = q->pNext;
        q->pNext = p;
        if(l.pTail == q) {
            l.pTail = p;
        }
    }
    else {
        AddHead(l,p);
    }
}

int RemoveHead(LIST &l, student &a) {
    Node *p;
    if(l.pHead != NULL) {
        p = l.pHead;
        a = p->uni;
        l.pHead = l.pHead ->pNext;
        delete p;
        if(l.pHead == NULL) l.pTail = NULL;
        return 1;
    }
    return 0;
}

int RemoveAfterQ(LIST &l, Node *q, student &a) {
    Node *p;
    if(q != NULL)
    {
        p = q->pNext;
        if(p != NULL)
        {
            if(p == l.pTail) {
                l.pTail = q;
            }
            q->pNext = p->pNext;
            a = p->uni;
            delete p;
        }
        return 1;
    }
    else return 0;
}

int DeleteX(LIST &l, student a) {
    Node *p, *q = NULL; p = l.pHead;
    while((p != NULL) && ( (strcmp(p ->uni.MSSV, a.MSSV) != 0) && (strcmp(p ->uni.TEN, a.TEN) != 0) && (p->uni.DTB != a.DTB))) {
        q = p;
        p = p->pNext;
    }
    if( p == NULL) {
        return 0;
    }
    if(q != NULL) {
        RemoveAfterQ(l, q, a);
    }
    else RemoveHead(l, a);
    return 1;
}

void SelectionSort(LIST &l) {
    Node *p, *q, *minDTB;
    p = l.pHead;
    while(p != l.pTail) {
        minDTB = p;
        q = p ->pNext;
        while(q != NULL) {
            if(q ->uni.DTB < p ->uni.DTB)
                minDTB = q;
            q = q->pNext;
        }
        swap(minDTB->uni, p->uni);
        p = p ->pNext;

    }
}

void insertSorted(LIST &l, Node *p) {
    if(l.pHead == NULL || p->uni.DTB < l.pHead->uni.DTB) {
        AddHead(l, p);
        return;
    }

    Node *q = l.pHead;
    while(q->pNext != NULL && q->pNext->uni.DTB < p->uni.DTB) {
        q = q->pNext;
    }
    InsertAfterQ(l, p, q);
}

bool check(const char a[]) {
    for(int i = 0; a[i] != '\0'; i++) {
        if(!isspace(a[i])) {
            return false;
        }
    }
    return true;
}

void input(student &a) {
    cout << "Nhap MSSV : ";
    cin.getline(a.MSSV, 9);

    cout << "Nhap Ten sinh vien : ";
    cin.getline(a.TEN, 31);

    cout << "Nhap DTB : ";
    cin >> a.DTB;
    cin.ignore();
}

int main()
{
    LIST l1; Node *p;
    CreateList(l1);
    student x;
    while(!check(x.TEN)) {
        input(x);

        if(!check(x.TEN)) {
            p = CreateNode(x);
            AddHead(l1, p);
        }
    }
    cout << "Danh sach sinh vien moi tao la : " << endl;
    PrintList(l1);
    cout << "Nhap thong tin sinh vien can tim : " << endl;
    student a;
    input(a);
    p = Search(l1, a);
    if(p == NULL) cout << "Khong tim thay sinh vien tren" << endl;
    else {
        cout << "Tim thay sinh vien" << endl;
    }
    DeleteX(l1,a);
    cout << "Danh sach sinh vien sau khi xoa : " << endl;
    PrintList(l1);
    cout << "Thong tin sinh vien co diem trung binh lon hon hay bang 5 : " << endl;
    PrintListBigger5(l1);
    cout << "Thong tin sinh vien va xep hang dua tren diem trung binh : " << endl;
    PrintListAndXepHang(l1);
    cout << "Sap xep danh sach sinh vien theo tang theo diem trung binh : " << endl;
    SelectionSort(l1);
    PrintList(l1);
    student b;
    input(b);
    p = CreateNode(b);
    insertSorted(l1, p);

    cout << "Danh sach sinh vien sau khi them vao danh sach la : " << endl;
    PrintList(l1);



	return 0;
}
