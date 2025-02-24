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

void Solve(int Arr[], int n, int rSum, int finalC[][100], int &resCnt, int current[], int &currentSize, int start) {
    if(rSum < 0) {
        return;
    }
    if(rSum == 0) {
        // Luu lai to hop
        for(int i = 0; i < currentSize; i++) {
            finalC[resCnt][i] = current[i];
        }
        finalC[resCnt][currentSize] = -1; // Danh dau vi tri ket thuc
        resCnt++;
        return;
    }
    for(int index = start; index < n; index++) {
        int currentPoint = Arr[index];

        // Them vao to hop hien tai
        current[currentSize++] = currentPoint;

        // Goi de quy voi gia tri moi
        Solve(Arr, n, rSum - currentPoint, finalC, resCnt, current, currentSize, index);

        // Backtrack (loai bo phan tu cuoi de thu to hop khac)
        currentSize--;
    }
}

void fSolve(int Arr[], int n, int Sum) {
    int finalc[100][100]; // Luu cac to hop hop le
    int resCnt = 0;
    int current[100]; // Mang tam luu cac to hop
    int currentSize = 0; // Luu so phan tu tam thoi

    Solve(Arr, n, Sum, finalc, resCnt, current, currentSize, 0);

    // In ra ket qua
    cout << "to hop de tao ra sum " << Sum << " : " << endl;
    for(int i = 0; i < resCnt ; i++) {
        cout << "[";
        for(int j = 0; finalc[i][j] != -1; j++) {
            cout << finalc[i][j] << " ";
        }
        cout << "]" << endl;
    }
}




int main()
{
    int Arr[] = {1, 2, 3};
    int n = sizeof(Arr) / sizeof(Arr[0]);
    int sum = 4;
    fSolve(Arr, n,  sum);
    return 0;
}
