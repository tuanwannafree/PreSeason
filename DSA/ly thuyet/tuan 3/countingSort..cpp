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

void countSort(vector<int> &a, int n) {
    int k = -3000;
    for(int i = 0; i < n; i++) {
        k = max(k, a[i]);
    }

    vector<int> cnt(k + 1, 0);

    for(int i = 0; i < n; i++) {
        cnt[a[i]] ++;
    }

    for(int i = 1; i <= k; i++) {
        cnt[i] = cnt[i] + cnt[i-1];
    }

    vector<int> ans(n);
    for(int i = n - 1; i >= 0; i-- ) {
        ans[--cnt[a[i]]] = a[i];
    }

    for(int i = 0; i < n ;i++) {
        a[i] = ans[i];
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a;
    int n; cin >> n;
    for(int i =0 ; i < n; i++) {
        int tmp; cin >> tmp;
        a.push_back(tmp);
    }
    countSort(a, n);

    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }

	return 0;
}
