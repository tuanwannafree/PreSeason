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

void nhap(vector<int> &a, int n) {
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        a.push_back(tmp);
    }
}

int binarySearch(vector<int> a, int item, int low, int high) {
    if(high <= low) {
        return (item > a[low]) ? (low + 1) : low;
    }

    int mid = low + (high - low) /2;

    if(item == a[mid]) {
        return mid + 1;
    }

    if(item > a[mid]) {
        return binarySearch(a, item, mid + 1, high);
    }
    return binarySearch(a, item, low, mid - 1);
}

void sortAscending(vector<int> &a) {
    int n = a.size();
    int i, loc, j, k , selected;
    for(int i = 1; i < n; ++i) {
        j = i - 1;
        selected = a[i];

        loc = binarySearch(a, selected, 0, j);
        while( j >= loc) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = selected;
    }

}

void sortDescending(vector<int> &a) {
    int n = a.size();
    int minn;
    for(int i = 0; i < n -1; i++) {
        minn = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] > a[minn]) minn = j;
        }
        swap(a[i], a[minn]);
    }


}

bool check(int a, vector<int> arr, int cnt) {
    int tmp = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(arr[i] >= a) {
            tmp++;
        }
    }
    return tmp == cnt;
}

int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    freopen("file.inp", "r", stdin);
    freopen("file.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<int> arrayN;
    vector<int>  arrayM;
    nhap(arrayN, n);
    nhap(arrayM, m);
    sortDescending(arrayN);
    sortAscending(arrayM);
    int res = INT_MAX;
    for(int i = 0; i < n; i++) {
        int tmp = arrayN[i];
        int cnt = n - i;
        if(check(tmp, arrayM, cnt)) {
            res = min(res, tmp);
        }
    }
    cout << res;

	return 0;
}
