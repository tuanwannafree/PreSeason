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

void print(vector<int> a) {
    int n = a.size();
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

int binarySearch(vector<int> a, int target, int low, int high) {
    if(high <= low) {
        return (target > a[low]) ? (low + 1) : low;
    }
    int mid = low + (high - low) / 2;
    if(target == a[mid]) {
        return mid + 1;
    }
    if(target > a[mid]) {
        return binarySearch(a, target, mid + 1, high);
    }
    return binarySearch(a, target, low, mid - 1);
}

void insertionSortUsingBinarySearch(vector<int> &a) {
    int n = a.size();
    int i, loc, j, k, chose;
    for( i = 1; i < n; ++i) {
        j = i - 1;
        chose = a[i];

        loc = binarySearch(a, chose, 0, j);
        while(j >= loc) {
            a[j+1] = a[j];
            print(a);
            cout << endl;
            j--;
        }
        a[j+1] = chose;
        print(a);
        cout << endl;
    }
}

int main()
{

	int n; cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
        cin >> a[i];
	}
	insertionSortUsingBinarySearch(a);
	return 0;
}
