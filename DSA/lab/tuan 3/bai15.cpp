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

void SelectionSort(LIST &);
//###INSERT CODE HERE -
void SelectionSort(LIST &l)
{

    if (l.pHead == NULL || l.pHead == l.pTail) {
        return;
    }

    NODE *p, *q, *minn;
    p = l.pHead;

    while (p != l.pTail) {
        minn = p;
        q = p->pNext;
        while (q != NULL) {
            if (q->info < minn->info) {
                minn = q;
            }
            q = q->pNext;
        }


        if (minn != p) {
           swap(minn->info, p->info);
        }


        p = p->pNext;

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
    SelectionSort(L);
    PrintList(L);
    return 0;
}
