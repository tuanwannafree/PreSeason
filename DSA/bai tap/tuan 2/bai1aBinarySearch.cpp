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

int solve(int A[], int n, int x) {
    int l = 0, r = n -1, m;
    while( l <= r) {
        m = l + (r - l) /2;
        if(A[m] == x) {
            return m;
        } else if( A[m] < x) {
            l = m + 1;
        } else {
            r = m  - 1;
        }
    }
    return -1;
}

int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    int A[] = {1,2,3,4,5,6,100000};
	int n = 7;
	int x; cin >> x;
	cout << solve(A, 7,x);

	return 0;
}
