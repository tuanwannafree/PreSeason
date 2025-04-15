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

NODE* SeparateHead(LIST &);
void Join(LIST &, LIST &, NODE* , LIST &);
void Partition(LIST &, LIST &, NODE *&, LIST &);
void QuickSort(LIST &);
//###INSERT CODE HERE -

NODE* SeparateHead(LIST &l) {
    if(l.pHead == NULL) return NULL;
    NODE* hNode = l.pHead;
    l.pHead = l.pHead->pNext;
    if(l.pHead == NULL) l.pTail = NULL;
    hNode->pNext = NULL;
    return hNode;
}

void Join(LIST &l1, LIST &l2, NODE* pivot, LIST &l3) {
    CreateEmptyList(l3);
    if(l1.pHead != NULL) {
        l3.pHead = l1.pHead;
        l3.pTail = l1.pTail;

        l3.pTail->pNext = pivot;
        l3.pTail = pivot;
    } else {
        l3.pHead = pivot;
        l3.pTail = pivot;
    }
    pivot->pNext = NULL;

    if(l2.pHead != NULL) {
        l3.pTail->pNext = l2.pHead;
        l3.pTail = l2.pTail;
    }
    CreateEmptyList(l1);
    CreateEmptyList(l2);

}

void Partition(LIST &l, LIST &l1, NODE* &pivot, LIST &l2)
{
    CreateEmptyList(l1);
    CreateEmptyList(l2);

    pivot = SeparateHead(l);
    if(pivot == NULL || l.pHead == NULL) return;
    NODE* p = NULL;
    while(l.pHead != NULL) {
        p = SeparateHead(l);
        if(p->info <= pivot->info) {
            InsertTail(l1, p);
        } else {
            InsertTail(l2, p);
        }
    }
    l.pTail = NULL;
}

void QuickSort(LIST &l) {
    if(l.pHead == NULL || l.pHead->pNext == NULL) return;
    LIST l1, l2;
    NODE* pivot;
    Partition(l, l1, pivot, l2);

    QuickSort(l1);
    QuickSort(l2);
    Join(l1, l2, pivot, l);
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
    QuickSort(L);
    PrintList(L);
    return 0;
}
