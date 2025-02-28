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

void insertionSort(vector<int> &a, int n) {
    for(int i = 1; i < n; i++) {
        int e = a[i]; int k;
        for( k = i -1; k > -1; k--) {
            if(a[k] >= e) break;
            a[k+1] = a[k];
        }
        a[k+1] = e;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> a;
    int sum =0;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        sum += tmp;
        a.push_back(tmp);
    }
    insertionSort(a, n);
//    for(int i = 0 ; i < n; i++) {
//        cout << a[i] << " ";
//    }
    int cnt = 0;
    int resum = 0;
    while(resum <= sum && cnt < n) {
        resum += a[cnt];
        sum -=a[cnt];
        cnt++;
    }

    cout << cnt;
	return 0;
}

//src: https://codeforces.com/problemset/problem/160/A
