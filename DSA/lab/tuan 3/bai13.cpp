/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/
#include <bits/stdc++.h>
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

void ChenTheoThuTu(LIST &, NODE*);
//###INSERT CODE HERE -

void InsertHead(LIST &l, NODE *p)
{
    if(l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else
    {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}

void InsertAfterQ(LIST &l, NODE *p, NODE *q)
{
    if(q != NULL)
    {
        p->pNext = q->pNext;
        q->pNext = p;
        if(l.pTail == q) l.pTail = p;
    }
    else
        InsertHead(l, p);
}

void ChenTheoThuTu(LIST &l, NODE *p)
{
    if(l.pHead == NULL || p->info < l.pHead->info)
    {
        InsertHead(l, p);
        return;
    }
    NODE *q = l.pHead;
    while(q->pNext != NULL && q->pNext->info < p->info)
    {
        q = q->pNext;
    }
    InsertAfterQ(l, p, q);
}




int main()
{
    LIST L;
    CreateEmptyList(L);
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; i++){
        cin >> x;
        InsertTail(L, CreateNode(x));
    }
    cin >> x;
    ChenTheoThuTu(L, CreateNode(x));
    PrintList(L);
    return 0;
}
