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
#include <tuple>
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

struct Oxyz {
    double x, y, z;
};

void nhap(vector<Oxyz> &a, int n) {
    for(int i = 0 ; i < n; i++) {
        Oxyz tmp; cin >> tmp.x >> tmp.y >> tmp.z;
        a.push_back(tmp);
    }
}

int findPoint(Oxyz a, vector<Oxyz> arr) {
    int l = 0, r = arr.size() - 1, m;
    while( l <= r) {
        m = l + (r - l) / 2;
        if(a.x == arr[m].x && arr[m].y == a.y && arr[m].z == a.z) {
            return 1;
        }
        if(make_tuple(arr[m].x, arr[m].y, arr[m].z) < make_tuple(a.x, a.y, a.z)) {
            l = m  + 1;
        }
        else {
            r =  m - 1;
        }
    }
    return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    vector<Oxyz> arrN;
    vector<Oxyz> arrM;

    int n; cin >> n;
    nhap(arrN, n);
    int m; cin >> m;
    nhap(arrM, m);

    for(int i = 0; i < m; i++) {
        if(findPoint(arrM[i], arrN)) {
           cout << "CO" << endl;
        }
        else {
            cout <<"KHONG" << endl;
        }
    }

	return 0;
}
