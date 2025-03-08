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
#include <tuple>
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

struct coordinateAxis {
    double x, y, z;
};

void nhap(vector<coordinateAxis> &a, int n) {
    for(int i = 0; i < n; i++) {
        coordinateAxis tmp; cin >> tmp.x >> tmp.y >> tmp.z;
        a.push_back(tmp);
    }
}

int Search(coordinateAxis b, vector<coordinateAxis> a) {
    int cnt = 0;
    int l =0, r = a.size() - 1, m;
    while(l <= r) {
        cnt++;
        m = (l + r) / 2;
        if(b.x == a[m].x && a[m].y == b.y && a[m].z == b.z)
            return cnt;
        if(make_tuple(a[m].x, a[m].y, a[m].z) < make_tuple(b.x, b.y, b.z) )
            l  = m   +1;
        else r = m - 1;
    }
    return -1;

}


void solve(vector<coordinateAxis> a, vector<coordinateAxis> b) {
    int n = a.size();
    int m = b.size();
    for(int i = 0; i < m; i++) {
        int result = Search(b[i], a);
        if(result == -1) {
            cout << "KHONG" << endl;
        } else {
            cout << result << endl;
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

	int n; cin >> n;
	vector<coordinateAxis> arrN;
	nhap(arrN, n);
	int m; cin >> m;
	vector<coordinateAxis> arrM;
	for(int i = 0 ; i < m ; i++) {
        coordinateAxis tmp; cin >> tmp.x >> tmp.y >> tmp.z;
        arrM.push_back(tmp);
	}
	solve(arrN, arrM);

	return 0;
}
