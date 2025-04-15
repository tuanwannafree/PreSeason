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
#include <tuple>
#define ll long long
#define pb push_back
#define _for(i,a,b) for(int i = a, i < b; i++)
#define _ford(i,a,b) for(int i = a, i > b; i--)
#define ln endl
using namespace std;

struct Oxyz {
    int x, y, z;
};

bool check(Oxyz a, Oxyz b) {
    if(a.x != b.x) return a.x < b.x;
    if(a.y != b.y) return a.y  > b.y;
    return a.z < b.z;
}

void InsertSort(vector<Oxyz> &a) {
    int n = a.size();
    for(int i = 1; i < n; i++) {
        int j = i;
        while(j > 0 && check(a[i], a[j-1])) --j;
        Oxyz tmp = a[i];
        for(int k = i; k > j; k--) {
            a[k] = a[k-1];
        }
        a[j] = tmp;
    }
}

int main()
{
	int n; cin >> n;
	vector<Oxyz> a(n);
	for(int i = 0; i < n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].z;
    }
    InsertSort(a);
    for(int i = 0; i < n; i++) {
        cout << a[i].x << " " << a[i].y << " " << a[i].z << "\n";
    }

	return 0;
}
