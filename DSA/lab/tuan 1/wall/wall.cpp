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

void solve(vector<int> a, int l, int r, int x , vector<int> b, int low, int high) {
    vector<int> tmp;
    tmp.push_back(x);
    for(int i = l; i < r; i++) {
        if( a[i] < x) {
            tmp.push_back(a[i]);
        }
    }
    cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    int wall = INT_MIN;

    int n; cin >> n;
    vector<int> arrN(n);
    for(int i = 0 ; i < n; i++) {
        cin >> arrN[i];
    }

    int m; cin >> m;
    vector<int> arrM(m);
    for(int i = 0 ; i < m; i++) {
        cin >> arrM[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            int tmp = wall;
            wall = max(wall, arrN[i] + arrM[j]);
            if(tmp < wall) {
                cout << wall << " ";
                solve(arrN, i + 1, arrN.size(), wall, arrM, j + 1, arrM.size());
            }
        }
    }



	return 0;
}
