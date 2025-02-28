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

void selectionSort(vector<int> &a, int n) {
    int minn;
    for(int i = 0; i < n - 1; i++) {
        minn = i;
        for(int j = i + 1; j < n; j++) {
            if(a[j] < a[minn]) minn = j;
        swap(a[i], a[minn]);
        }
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> a;
    for(int i = 0; i < n ;i++) {
        int tmp; cin >> tmp;
        a.push_back(tmp);
    }
    selectionSort(a, n);
    for(int i = 0 ; i < n; i++) {
        cout << a[i] << " ";
    }

	return 0;
}
