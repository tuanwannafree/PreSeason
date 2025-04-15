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

void ReverseLL(LIST &);
//###INSERT CODE HERE -

void ReverseLL(LIST &l)
{
    if(l.pHead == NULL ||  l.pHead->pNext == NULL)
    {
        return;
    }
    NODE* pre = NULL;
    NODE* cur = l.pHead;
    NODE* nex = NULL;
    NODE* ori = l.pHead;

    while(cur != NULL)
    {
        nex  = cur->pNext;
        cur->pNext = pre;
        pre = cur;
        cur = nex;
    }
    l.pHead = pre;
    l.pTail = ori;
    if(l.pTail != NULL)
    {
        l.pTail->pNext = NULL;
    }
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
    ReverseLL(L);
    PrintList(L);
    return 0;
}
