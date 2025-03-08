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

void display(vector<int> a) {
    for(int i = 0 ; i < a.size(); i++) {
        cout << a[i] << " " ;
    }
    cout << endl;
}

void insertionSort(vector<int> &a) {
    int n = a.size();
    for(int i = 1; i < n; i++) {
        int e = a[i]; int k;
        for(k = i - 1; k > -1; k--) {
            if(a[k] < e) break;
            a[k+1]  = a[k];
            display(a);
        }
        a[k+1] = e;
        display(a);
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    vector<int> arr;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }
    insertionSort(arr);

	return 0;
}
