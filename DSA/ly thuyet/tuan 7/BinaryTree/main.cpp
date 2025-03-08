#include <iostream>

using namespace std;
typedef struct tagTNode
{
    int Data;
    struct tagTNode* pLeft;
    struct tagTNode* pRight;
}TNode;
typedef TNode* TREE;
TNode* CreateTNode(int x);
void NLR(TREE t);
void LNR(TREE t);
void LRN(TREE t);

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

TNode* CreateTNode(int x)
{
    TNode* p = new TNode;
    if(p == NULL)
        return NULL;
    p->Data = x;
    p->pLeft = NULL;
    p->pRight = NULL;
    return p;
}
void NLR(TREE t)
{
    if(t != NULL)
    {
        cout << t->Data << " ";
        NLR(t->pLeft);
        NLR(t->pRight);
    }
}
void LNR(TREE t)
{
    if(t != NULL)
    {
        LNR(t->pLeft);
        cout << t->Data << " ";
        LNR(t->pRight);
    }
}
//Tính tổng các node trong cây nhị phân
int Tong(TREE root)
{
    if(root == NULL)
        return 0;
    else
    {
        int a = Tong(root->pLeft);
        int b = Tong(root->pRight);
        return a + b + root->Data;
    }
}
//Tính tổng chẵn
int TongChan(TREE root)
{
    if(root == NULL)
        return 0;
    int a = TongChan(root->pLeft);
    int b = TongChan(root->pRight);
    if(root->Data % 2 == 0)
        return a + b + root->Data;
    else
        return a + b;
}
//Tìm x có trong cây nhị phân hay không?
int TimX(TREE root, int x)
{
    if(root->Data == x)
        return 1;
    if(TimX(root->pLeft, x) == 1)
        return 1;
    if(TimX(root->pRight, x) == 1)
        return 1;
    return 0;
}
//Đếm số node lá trong cây nhị phân các số nguyên
int DemLa(TREE root)
{
    if(root == NULL)
        return 0;
    int a = DemLa(root->pLeft);
    int b = DemLa(root->pRight);
    if(root->pLeft == NULL && root->pRight == NULL)
        return a + b + 1;
    else
        return a + b;
}


void LRN(TREE t)
{
    if(t != NULL)
    {
        LRN(t->pLeft);
        LRN(t->pRight);
        cout << t->Data << " ";
    }
}





