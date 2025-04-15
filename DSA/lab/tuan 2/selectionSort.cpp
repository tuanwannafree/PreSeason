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

void print(vector<int> a) {
    int n = a.size();
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void swapt(int &a, int &b, vector<int> &ar) {
    int tmp = a;
    a = b;
    b = tmp;
    print(ar);
}

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
	int minn;
	for(int i = 0; i < n - 1; i++) {
        minn = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[minn]) minn = j;
        swapt(a[i], a[minn], a);

        }
	}

	return 0;
}
