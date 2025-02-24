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

struct Point {
    float x, y;
};
int findMinSpace(float arr[], int n) {
    int k;
    float minn = 300000;
    for(int i =0 ; i < n ;i++ ) {
        if(minn > arr[i]) {
            minn = arr[i];
            k = i;
        }
    }
    return k;
}

int main()
{
	//ios_base::sync_with_stdio(false);
    //cin.tie(NULL);

    Point A[100];
    Point target;
    cout <<"Nhap toa do x cua diem B";
    cin >> target.x >> target.y;
    int n; cin >> n;
    float arr[100];
    cout <<"Nhap toa do mang: ";
    for(int i = 0; i < n; i++) {
        cin >> A[i].x >> A[i].y;
        arr[i] = sqrt(pow((A[i].x - target.x),2) + pow((A[i].y - target.y), 2));
    }
    int k = findMinSpace(arr, n);

    cout << A[k].x << " " << A[k].y;

	return 0;
}
