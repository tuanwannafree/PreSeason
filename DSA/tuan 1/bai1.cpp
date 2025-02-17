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


void init(int a[100], int n) {
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

long solve(int &start, int &stop, int a[100], int n) {
    start = 0;
    stop = 0;
    long maxProduct = a[0];
    for(int i = 0; i < n; i++) {
        int tmp = 1;
        for(int j = i; j < n; j++) {
            tmp *= a[j];
            if(tmp > maxProduct) {
                maxProduct = tmp;
                start = i;
                stop = j;
            }
        }
    }
    return maxProduct;
}

void display(int a[], int start, int stop) {
    for(int i = start; i <= stop; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}


int main()
{
    int a[100], n;
    cin >> n;
    init(a, n);
    int start, stop, maxProduct;
    maxProduct = solve(start, stop, a, n);
    cout << "max product of sub array" << maxProduct << endl;
    cout << "sub array create max product ";
    display(a, start, stop);
    return 0;
}
