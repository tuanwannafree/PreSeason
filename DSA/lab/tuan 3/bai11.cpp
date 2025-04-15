/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
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

void PrintList(LIST L)
{
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
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

void TimKiemVaXoa(LIST &, int);
//###INSERT CODE HERE -

void DeleteHead(LIST &l)
{
    NODE *p;
    if(l.pHead != NULL)
    {
        p = l.pHead;
        l.pHead = l.pHead->pNext;
        delete p;
        if(l.pHead == NULL) l.pTail = NULL;
    }
}

void DeleteTail(LIST &l)
{
    if(l.pHead != NULL)
    {
        if(l.pHead == l.pTail)
        {
            NODE *tmp = l.pHead;
            l.pHead = l.pTail = NULL;
            delete tmp;
        }
        else
        {
            NODE *cur = l.pHead;
            NODE *pre = NULL;
            while(cur->pNext != NULL)
            {
                pre = cur;
                cur = cur->pNext;
            }
            pre->pNext = NULL;
            l.pTail = pre;
            delete cur;
        }
    }
}

void DeleteNode(LIST &l, NODE *p)
{
    if(l.pHead == NULL || p == NULL) return;
    if(p == l.pHead)
    {
        DeleteHead(l);
        return;
    }
    if(p== l.pTail)
    {
        DeleteTail(l);
        return;
    }
    NODE *cur = l.pHead;
    NODE*pre = NULL;
    while(cur != NULL && cur != p)
    {
        pre = cur;
        cur = cur->pNext;
    }
    if(cur == NULL)
    {
        return;
    }
    pre->pNext = cur->pNext;
    delete cur;
}

void TimKiemVaXoa(LIST &l, int x)
{
    NODE *cur = l.pHead;
    NODE *pre = NULL;

    bool check = false;
    while(cur != NULL)
    {
        if(cur->info == x)
        {
            NODE *tmp = cur;
            cur = cur->pNext;
            DeleteNode(l, tmp);
            check = true;
        }
        else
        {
            pre = cur;
            cur = cur->pNext;
        }
    }
    if(check) {
        PrintList(l);
    }
    else
    {
        cout << -1;
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
    int k; cin >> k;
    TimKiemVaXoa(L, k);
    return 0;
}
