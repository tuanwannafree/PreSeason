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

//###INSERT CODE HERE -

void SwapPointers(LIST &l, NODE* n1, NODE* n2) {
    if(n1 == n2 || l.pHead == NULL) return;
    NODE* prev1 = NULL;
    NODE* prev2 = NULL;
    NODE* cur = l.pHead;


    while(cur != NULL) {
        if(cur->pNext == n1) {
            prev1 = cur;
        }
        if(cur->pNext == n2) {
            prev2 = cur;
        }
        cur = cur->pNext;
    }

    if(l.pHead == n1) {
        prev1 = NULL;
    }
    if(l.pHead == n2) {
        prev2 = NULL;
    }

    if(prev1 != NULL) {
        prev1->pNext = n2;
    } else {
        l.pHead = n2;
    }
    if(prev2 != NULL) {
        prev2->pNext = n1;
    } else {
        l.pHead = n1;
    }

    NODE* tmpNext = n1->pNext;
    n1->pNext = n2->pNext;
    n2->pNext = tmpNext;

    if(l.pTail == n1) {
        l.pTail = n2;
    }
    else if(l.pTail == n2) {
        l.pTail = n1;
    }
}



void SelectionSort(LIST &L){
    NODE* tmp;
    NODE* p = L.pHead;
    NODE* q;
    NODE* node_min;
    while (p != NULL){
        node_min = p;
        for (q = p->pNext; q != NULL; q = q->pNext){
            if (q->info < node_min->info)
                node_min = q;
        }
        SwapPointers(L, p, node_min);
        p = node_min->pNext;
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
