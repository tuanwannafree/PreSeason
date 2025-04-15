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
#define MAXN 200005
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> arr(n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> ans(n);
    vector<bool> checkMex(MAXN, false);
    for(int i = 0; i < n; i++) {
        if(arr[i] < MAXN) {
            checkMex[arr[i]] = true;
        }
        while(checkMex[cnt]) {
            cnt++;
        }
        ans[i] = cnt;

    }

    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }



	return 0;
}
