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

void xuat(vector<int> a) {
    for(int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void heapifyMin(vector<int> &a, int k, int n) {
    int j = 2 * k + 1;
    while( j < n) {
        if(j + 1 < n) {
            if(a[j] >= a[j+1]) {
                    j = j + 1;
            }
        }
        if(a[k] < a[j]) return;
        xuat(a);
        swap(a[k], a[j]);
        xuat(a);
        k = j; j = 2 * k + 1;
    }
}

void buildHeapMin(vector<int> &a) {
    int i;
    int n = a.size();
    i = (n - 1)  / 2;
    while(i >= 0) {
        heapifyMin(a, i, n);
        i--;
    }
}

void heapSortMin(vector<int> &a) {
    int n = a.size();
    buildHeapMin(a);
//    while(n > 0) {
//        n = n - 1;
//        xuat(a);
//        swap(a[0], a[n]);
//        xuat(a);
//        heapifyMin(a, 0, n);
//    }
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr = {8,2,1,9,4,5,7,6,3};

    heapSortMin(arr);

    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
	}

	return 0;
}
