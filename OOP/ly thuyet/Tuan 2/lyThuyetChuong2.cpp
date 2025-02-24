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

//void Solve(int Arr[], int n, int rSum, int finalC[][100], int &resCnt, int current[], int &currentSize, int start) {
//    if(rSum < 0) {
//        return;
//    }
//    if(rSum == 0) {
//        for(int i = 0; i < currentSize; i++) {
//            finalC[resCnt][i] = current[i];
//        }
//        finalC[resCnt][currentSize] = -1;
//        resCnt++;
//        return;
//    }
//    for(int index = start; index < n; index++) {
//        int currentPoint = Arr[index];
//        current[currentSize++] = currentPoint;
//        Solve(Arr, n, rSum - currentPoint, finalC, resCnt, current, currentSize, index);
//        currentSize--;
//    }
//}
//
//void fSolve(int Arr[], int n, int Sum) {
//    int finalc[100][100];
//    int resCnt = 0;
//    int current[100];
//    int currentSize = 0;
//
//    Solve(Arr, n, Sum, finalc, resCnt, current, currentSize, 0);
//
//    cout << "to hop de tao ra sum " << Sum << " : " << endl;
//    for(int i = 0; i < resCnt ; i++) {
//        cout << "[";
//        for(int j = 0; finalc[i][j] != -1; j++) {
//            cout << finalc[i][j] << " ";
//        }
//        cout << "]" << endl;
//    }
//}


struct Fraction {
    int numerator, denotator;
};

//int ucln(int a, int b) {
//
//}

//void rutgon(Fraction &a) {
//    int n = ucln(a.numerator, a.denotator);
//    a.numerator = a.numerator / n;
//    a.denotator = a.denotator / n;
//}

void init(Fraction a, int &n, int &d) {
    a.numerator = n;
    a.denotator = d;

}

Fraction operator+(Fraction a, Fraction b) {
    Fraction c;
    c.numerator = a.numerator * b.denotator + b.numerator * a.denotator;
    c.denotator = a.denotator * b.denotator;
    return c;
}

int main()
{
//    int Arr[100];
//    int n; cin >> n;
//    for(int i = 0; i < n; i++) {
//        cin >> Arr[i];
//    }
//    int sum; cin >> sum;
//    fSolve(Arr, n,  sum);

    Fraction p1, p2, p3;
    int a = 2, b = 3, c= 4;
    p1.numerator = 1;
    p1.denotator = 2;
    p1.numerator = 3;
    p1.denotator = 4;

    p3 = p2 + p1;
    cout << p3.numerator << " " << p3.denotator;

    return 0;
}
