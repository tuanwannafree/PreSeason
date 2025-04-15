#include <algorithm>
#include <tuple>
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

struct Oxyz {
    double x, y, z;
};

int timKiem(Oxyz a,vector<Oxyz> b) {
    int n = b.size();
    int l = 0, r = n -1, m;
    while(l <= r) {
        m = l + (r - l ) /2;
        if(a.x == b[m].x && a.y == b[m].y && a.z == b[m].z) {
            return 1;
        }
        if(make_tuple(b[m].x, b[m].y, b[m].z) < make_tuple(a.x, a.y, a.z)) {
            l  = m +1;
        } else {
            r = m  -1;
        }
    }
    return 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<Oxyz> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    int m; cin >> m;
    vector<Oxyz> b(m);
    for(int i = 0; i < m; i++) {
        cin >> b[i].x >> b[i].y >> b[i].z;
    }
    for(int i = 0; i < m; i++) {
        if(timKiem(b[i], a) == 1) {
            cout << "CO" <<endl;
        }
        else {
            cout << "KHONG" <<endl;
        }
    }

	return 0;
}
