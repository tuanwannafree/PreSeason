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
int cnt = 0;
int binSearch(vector<int> a, int x) {

    int l = 0, r = a.size(), m;
    while( l <= r) {
        cnt++;
         m = floor((r+l) / 2);
        if(a[m] == x) {
            return m;
        }
        else if(a[m] < x) {
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    return -1;
}

int main()
{
    int n; cin >> n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int x; cin >> x;
    int res = binSearch(arr, x);
    if(res != -1) {
        cout << res << endl;
        cout << cnt;
    }
    else {
        cout << res;
    }


	return 0;
}
