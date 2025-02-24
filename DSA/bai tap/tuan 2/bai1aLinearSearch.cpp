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

int solve(int A[7], int n, int x) {
    int i = 0;
    while(i < n) {
        if(A[i] == x) return i;
        i++;
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
