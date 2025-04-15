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

double countNth(int n) {
    double res = 1;
    for(double i = 1; i <= n; i++) {
        res *= i;
    }
    return res;
}

int main()
{
    int n;
    cout << "Nhap n : ";
    cin >> n;
    double x;
    cout << "Nhap x : ";
    cin >> x;
    double res = 0;
    double tmp = x;
    int i = 0;
    while(fabs(tmp) >= 0.00001 ) {
        res += tmp;
        i++;
        tmp = pow(-1, i) * pow(x, 2 * i + 1) / countNth(2 * i + 1);
    }
    cout << res;

	return 0;
}
