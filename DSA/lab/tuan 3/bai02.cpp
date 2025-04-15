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

//###INSERT CODE HERE -



void PrintList(LIST L)
{
    NODE *p = L.pHead;
    while (p != NULL)
    {
        cout << p->info << " ";
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
        InsertHead(L, CreateNode(x));
    }
    PrintList(L);
    return 0;
}
