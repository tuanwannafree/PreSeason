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

    int mid = low + (high - low) / 2;
    if(item == a[mid]) {
        return mid + 1;
    }
    if(item > a[mid]) {
        return binarySearch(a, item, mid + 1, high);
    }
    return binarySearch(a, item, low, mid - 1);

}

void ownSort(vector<int> &a) {
    int n = a.size();
    int i, loc, j, k, selected;

    for(i = 1; i < n; ++i) {
        j = i - 1;
        selected = a[i];
        loc = binarySearch(a, selected, 0, j);
        while(j >= loc) {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = selected;
    }
}

int solve(vector<int> a) {
    int n = a.size();
    ownSort(a);
    if(n <= 1) {
        return 0;
    }

    if(n == 2) {
        return a[1] - a[0];
    }
    if(n == 3) {
        return a[2] - a[0];
    }
    if(n > 3) {
        return a[n-1] + a[n-2] - a[0] - a[1];
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("file.inp", "r", stdin);
    //freopen("file.out", "w", stdout);

    int t; cin >> t;
    for(int i = 0; i < t; i++) {
        int n; cin >> n;
        vector<int> arr;
        nhap(arr, n);
        cout << solve(arr) << endl;
    }

	return 0;
}
