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

void TronDSLK(LIST &, LIST &, LIST &);
//###INSERT CODE HERE -

void TronDSLK(LIST &l1, LIST &l2, LIST &l3)
{
    CreateEmptyList(l3);
    NODE *p = l1.pHead;
    NODE *q = l2.pHead;

    while(p != NULL && q != NULL)
    {
        NODE* newP = NULL;
        if(p->info <= q->info) {
            newP = CreateNode(p->info);
            if(newP == NULL) return;
            InsertTail(l3, newP);
            p = p->pNext;
        }
        else {
            newP = CreateNode(q->info);
            if(newP == NULL) return;
            InsertTail(l3, CreateNode(q->info));
            q = q->pNext;
        }
    }
    while(q != NULL) {
        NODE* newP = CreateNode(q->info);
        if(newP == NULL) return;
        InsertTail(l3, newP);
        q = q->pNext;
    }
    while(p != NULL) {
        NODE* newP = CreateNode(p->info);
        if(newP == NULL) return;
        InsertTail(l3, newP);
        p =p ->pNext;
    }

}


int main()
{
    int t; cin >> t;
    LIST L1;
    LIST L2;
    LIST L3;
    for (int pid = 0; pid < t; pid++){
        CreateEmptyList(L1);
        int n, m; cin >> n >> m;
        int x;
        for (int i = 0; i < n; i++){
            cin >> x;
            InsertTail(L1, CreateNode(x));
        }
        CreateEmptyList(L2);
        for (int i = 0; i < m; i++){
            cin >> x;
            InsertTail(L2, CreateNode(x));
        }
        TronDSLK(L1, L2, L3);
        PrintList(L3);
        cout << "\n";
    }
    return 0;
}
