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
#define MAXN 200005
#define min(x,y) (x>y) ? y : x
using namespace std;

void mergeSort(vector<int> &data, int left, int right, vector<int> &temp) {
    if( left >= right) {
        return;
    }

    int mid = (left + right) / 2;

    mergeSort(data, left, mid, temp);
    mergeSort(data, mid + 1, right, temp);

    int i = left, j = mid + 1;
    int cur = 0;

    while(i <= mid || j <= right) {
        if(i > mid) {
            temp[cur++] = data[j++];
        }
        else if(j > right) {
            temp[cur++] = data[i++];
        }
        else if(data[i] < data[j]) {
            temp[cur++] = data[i++];
        }
        else {
            temp[cur++] = data[j++];
        }
    }

    for(int k = 0; k < cur; k++) {
        data[left + k] = temp[k];
    }


}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    vector<int> data(n);
    vector<int> temp(n);
    for(int i = 0; i < n; i++) {
        cin >> data[i];
    }

    mergeSort(data, 0, n - 1, temp);

    for(int i = 0 ; i < n; i++) {
        cout << data[i] << " ";
    }

	return 0;
}
