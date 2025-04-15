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
}

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++) {
        int j = i;
        while(j > 0 && a[i] < a[j-1]) --j;
        int tmp = a[i];
        for(int k = i; k > j; k--) {
            a[k] = a[k-1];
            print(a);
            cout << endl;
        }
        a[j] = tmp;
        print(a);
        cout << endl;
    }

	return 0;
}
