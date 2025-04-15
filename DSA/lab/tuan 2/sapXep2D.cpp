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

struct Oxy {
    int x, y;
};


bool check(Oxy a, Oxy b) {
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y  > b.y;
}

void heapify(vector<Oxy> &a, int k , int n) {
    int j = 2 * k + 1;
    while(j < n) {
        if(j + 1 < n) {
            if(check(a[j], a[j+1])) j = j + 1;
        }
        if(!check(a[k], a[j])) return;
        swap(a[k], a[j]);
        k = j; j = 2 * k + 1;
    }
}

void buildHeap(vector<Oxy> &a, int n) {
    int i;
    i = (n - 1) / 2;
    while(i >= 0) {
        heapify(a, i, n);
        i--;
    }
}

void HeapSort(vector<Oxy> &a, int n) {
    buildHeap(a, n);
    while(n > 0) {
        n = n - 1;
        swap(a[0], a[n]);
        heapify(a, 0, n);
    }
}

int main()
{
    int n; cin >> n;
	vector<Oxy> a(n);
	for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    HeapSort(a, n);
    for(int i = 0; i < n; i++) {
        cout << a[i].x << " " << a[i].y <<"\n";
    }


	return 0;
}
