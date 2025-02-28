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

void countSort(vector<int> &a, int n, int exp) {
    vector<int> output(n);
    int i;
    vector<int> cnt(10, 0);

    for( i = 0; i < n; i++) {
        cnt[(a[i] / exp) % 10]++;
    }

    for(i = 1; i < 10; i++) {
        cnt[i] += cnt[i-1];
    }

    for(i = n - 1; i >= 0; i--) {
        output[cnt[(a[i]/exp) % 10] - 1] = a[i];
        cnt[(a[i] / exp) % 10] --;
    }

    for(int i = 0 ; i< n; i++) {
        a[i] = output[i];
    }
}

void radixSort(vector<int> &a, int n) {
    int m = -30000;
    for(int i = 0; i < n; i++) {
        m = max(m, a[i]);
    }

    for(int exp = 1; m / exp > 0; exp *= 10) {
        countSort(a, n, exp);
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> a;
    for(int i = 0; i< n; i++) {
        int tmp; cin >> tmp;
        a.push_back(tmp);
    }

    radixSort(a, n);
    for(int i = 0; i < n; i++) {
        cout << a[i] <<" ";
    }

	return 0;
}
