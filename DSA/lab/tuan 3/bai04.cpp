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
            NODE  *pre = NULL;
            while(cur->pNext !=NULL)
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
        InsertTail(L, CreateNode(x));
    }
    int k; cin >> k;
    for (int i = 0; i < k; i++)
        DeleteTail(L);
    PrintList(L);
    return 0;
}
