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
void MergeSplit(LIST &, LIST &, LIST &);
void Merge(LIST &, LIST &, LIST &);
void MergeSort(LIST &);
//###INSERT CODE HERE -

NODE* SeparateHead(LIST &l) {
    if(l.pHead == NULL) return NULL;
    NODE* hNode = l.pHead;
    l.pHead = l.pHead->pNext;
    if(l.pHead == NULL) l.pTail = NULL;
    hNode->pNext = NULL;
    return hNode;
}

void MergeSplit(LIST &l, LIST &l1, LIST &l2) {
    CreateEmptyList(l1);
    CreateEmptyList(l2);
    if(l.pHead == NULL) return;
    if(l.pHead->pNext == NULL) {
        l1.pHead = l.pHead;
        l1.pTail = l.pHead;
        CreateEmptyList(l);
        return;
    }
    NODE* slow = l.pHead;
    NODE* fast = l.pHead->pNext;

    while(fast != NULL) {
        fast = fast->pNext;
        if(fast != NULL) {
            slow = slow->pNext;
            fast = fast->pNext;
        }
    }

    l1.pHead = l.pHead;
    l1.pTail = slow;
    l2.pHead = slow->pNext;
    l2.pTail = l.pTail;
    slow->pNext = NULL;
    CreateEmptyList(l);
}

void Merge(LIST &l1, LIST &l2, LIST &l3) {
    CreateEmptyList(l3);
    NODE* p1 = l1.pHead;
    NODE* p2 = l2.pHead;

    if(p1 == NULL) {
        l3 = l2;
        CreateEmptyList(l2);
        CreateEmptyList(l1);
        return;
    }

    if(p2 == NULL) {
        l3 = l1;
        CreateEmptyList(l1);
        CreateEmptyList(l2);
        return;
    }

    if(p1->info <= p2->info) {
        l3.pHead = p1;
        p1 = p1->pNext;
    } else {
        l3.pHead = p2;
        p2 = p2->pNext;
    }
    l3.pTail = l3.pHead;

    while(p1 != NULL && p2 != NULL) {
        if(p1->info <= p2->info) {
            l3.pTail->pNext = p1;
            l3.pTail = p1;
            p1 = p1->pNext;
        } else {
            l3.pTail->pNext = p2;
            l3.pTail = p2;
            p2 = p2->pNext;
        }
    }

    if(p1 != NULL) {
        l3.pTail->pNext = p1;
        l3.pTail = l1.pTail;
    } else {
        l3.pTail->pNext = p2;
        if(p2 != NULL) {
            l3.pTail = l2.pTail;
        }
    }

    CreateEmptyList(l1);
    CreateEmptyList(l2);


}

void MergeSort(LIST &l) {
    if(l.pHead == NULL || l.pHead->pNext == NULL) return;
    LIST l1, l2;
    MergeSplit(l, l1, l2);
    MergeSort(l1);
    MergeSort(l2);
    Merge(l1, l2, l);
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
    MergeSort(L);
    PrintList(L);
    return 0;
}
