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

void heapify(vector<int> &a, int k , int n) {
    int j = 2 * k + 1;
    while(j < n) {
        if(j + 1 < n) {
            if(a[j] < a[j+1]) j = j + 1;
        }
        if(a[k] >= a[j]) return;
        swap(a[k], a[j]);
        k = j; j = 2 * k + 1;
    }
}

void buildHeap(vector<int> &a, int n) {
    int i;
    i = (n - 1) / 2;
    while(i >= 0) {
        heapify(a, i, n);
        i--;
    }
}

void heapSort(vector<int> &a, int n) {
    buildHeap(a, n);
    while(n > 0) {
        n = n - 1;
        swap(a[0], a[n]);
        heapify(a, 0, n);
    }
}
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }

    heapSort(arr, n);

	for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
	}


	return 0;
}
