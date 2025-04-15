/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
using namespace std;

struct NODE {
    int info;
    NODE* pNext;
};


struct LIST {
    NODE* pHead;
    NODE* pTail;
};

void CreateEmptyList(LIST &L) {
    L.pHead = NULL;
    L.pTail = NULL;
}

NODE* CreateNode(int x) {
    NODE* p = new NODE;
    if (p == NULL)
        exit(1);
    p->info = x;
    p->pNext = NULL;
    return p;
}

void InsertTail(LIST &L, NODE* p) {
    if (L.pHead == NULL) {
        L.pTail = p;
        L.pHead = L.pTail;
    }
    else {
        L.pTail->pNext = p;
        L.pTail = p;
    }
}

void PrintList(LIST L)
{
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}

void Noi(LIST &, LIST);
//###INSERT CODE HERE -

void Noi(LIST &l1, LIST l2)
{
    NODE *p = l2.pHead;
    while(p != NULL)
    {
        InsertTail(l1, p);
        p = p->pNext;
    }
}



int main()
{
    LIST L1, L2;
    CreateEmptyList(L1);
    CreateEmptyList(L2);
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        InsertTail(L1, CreateNode(x));
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++){
        cin >> x;
        InsertTail(L2, CreateNode(x));
    }
    Noi(L1, L2);
    PrintList(L1);
    cout << "\n";
    PrintList(L2);
    return 0;
}
