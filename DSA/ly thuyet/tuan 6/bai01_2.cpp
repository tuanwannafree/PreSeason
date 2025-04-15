#include <algorithm>
#include <bitset>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <unordered_map>
#include <vector>
#define ll long long
#define pb push_back
#define _for(i,a,b) for(int i = a, i < b; i++)
#define _ford(i,a,b) for(int i = a, i > b; i--)
#define ln endl
using namespace std;


typedef struct tagNode
{
    long double num;
    struct tagNode *pNext;
} Node;

typedef struct tagList
{
    Node *pHead;
    Node *pTail;
}LIST;

void CreateList(LIST &l)
{
    l.pHead = NULL;
    l.pTail = NULL;
}

Node* CreateNode(long double x)
{
    Node *p;
    p = new Node;
    if(p == NULL) exit(1);
    p->num = x;
    p->pNext = NULL;
    return p;
}

int IsEmpty(LIST &s)
{
    if(s.pHead == NULL) {
        return 1;
    }
    else
        return 0;
}

void Push(LIST &s, Node *Tam)
{
    if(s.pHead == NULL)
    {
        s.pHead = Tam;
        s.pTail = Tam;
    }
    else
    {
        Tam->pNext = s.pHead;
        s.pHead = Tam;
    }
}

int Pop(LIST &s, long double trave)
{
    Node *p;
    if(IsEmpty(s) != 1)
    {
        if(s.pHead != NULL)
        {
            p = s.pHead;
            trave = p->num;
            s.pHead = s.pHead->pNext;
            if(s.pHead == NULL)
            {
                s.pTail = NULL;
            }
            return 1;
            delete p;
        }
    }
    return 0;
}

void PrintList(LIST l)
{
    Node *p;
    p = l.pHead;
    while(p != NULL) {
        cout << p->num << " ";
        p = p->pNext;
    }
}
long double calNum(string x)
{
    LIST
}
int main()
{
    LIST l1; Node *p; string x; long double num;
    CreateList(l1);
    do{
        cin >> x;
        num = calNum(x);
        if(x > 0){
            p = CreateNode(num);
            Push(l1, p);
        }
    } while(x > 0);
    PrintList(l1);
	return 0;
}
