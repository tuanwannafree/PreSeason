/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
std
###End banned keyword*/

#include <iostream>
using namespace std;

typedef struct tagNode
{
    int info;
    struct tagNode *pNext;
}NODE;

typedef struct tagList
{
    NODE *pHead;
    NODE *pTail;
}LIST;

void CreateEmptyList(LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

NODE* CreateNode(int x)
{
    NODE *p;
    p = new NODE;
    if(p == NULL) exit(1);
    p->info = x;
    p->pNext = NULL;
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
        l.pTail->pNext = p;
        l.pTail = p;
    }
}

int DemSoLuongPhanTuTrongL(LIST l) {
    int res = 0;
    if(l.pHead == l.pTail) {
        if(l.pHead == NULL) {
            return 0;
        }
        else {
            return 1;
        }
    }
    NODE *p = l.pHead;
    while(p != NULL) {
        res++;
        p = p->pNext;
    }
    return res;
}

//###INSERT CODE HERE -



void InsertTail(LIST &, NODE *);
int DemSoLuongPhanTuTrongL(LIST);

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
    int k = DemSoLuongPhanTuTrongL(L);
    cout << k;
    return 0;
}
