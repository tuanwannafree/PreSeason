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

void PrintList(LIST L)
{
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
        p = p->pNext;
    }
}

NODE* TimKiem(LIST l, int x)
{
    NODE *p;
    p = l.pHead;
    while((p != NULL) && (p->info != x))
    {
        p = p->pNext;
    }
    return p;
}

void InsertTail(LIST &l, NODE *p)
{
    if(l.pHead == NULL)
    {
        l.pHead = p;
        l.pTail = l.pHead;
    }
    else
    {
        l.pTail ->pNext = p;
        l.pTail = p;
    }
}

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
    {
        InsertHead(l, p);
    }
}

void TimKiemVaThem(LIST &l, int x)
{
    NODE *q = TimKiem(l, x);
    if(q == NULL)
    {
        InsertTail(l, CreateNode(1999));
    }
    else
    {
        InsertAfterQ(l, CreateNode(1999), q);
    }
    PrintList(l);
}

//###INSERT CODE HERE -






NODE* TimKiem(LIST, int);
void InsertNode(LIST &, NODE*);
void TimKiemVaThem(LIST &, int);

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
    TimKiemVaThem(L, k);
    return 0;
}
