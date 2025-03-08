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

//int mex(vector<int> a) {
//    static bool used[200006] = {0};
//
//    for(int x : a) {
//        if(x <= 200005) {
//            used[x] = true;
//        }
//    }
//
//    int result = 0;
//
//    while(used[result]) {
//        ++result;
//    }
//    for(int x : a) {
//        if(x <= 200005) {
//            used[x] = false;
//        }
//    }
//    return result;
//}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> arr(n);
    vector<int> res(n);
    vector<bool> test(200005, false);
    int mex = 0;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];

        if(arr[i] < 200005) {
            test[arr[i]] = true;
        }
        while( test[mex]) {
            mex++;
        }

        res[i] = mex;
    }

    for(int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }







	return 0;
}
