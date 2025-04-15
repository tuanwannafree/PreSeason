#include <algorithm>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

int minDeSwap(vector<int> a, int n) {
    vector<pair<int, int>> vec(n);
    for(int i =0 ; i< n;i ++) {
        vec[i] = {a[i], i};
    }
    sort(vec.begin(), vec.end());

    vector<bool> check(n, false);
    int swaps = 0;
    for(int i = 0; i < n; i++) {
        if(vec[i].second == i|| check[i]) continue;
        int cycleSize = 0;
        int j = i;
        while(!check[j]) {
            check[j] = true;
            j = vec[j].second;
            cycleSize++;
        }
        if(cycleSize > 1) {
            swaps+=(cycleSize- 1);
        }
    }
    return swaps;
}

int minAsSwap(vector<int> a, int n) {
    vector<pair<int, int>> vec(n);
    for(int i =0 ; i< n;i ++) {
        vec[i] = {a[i], i};
    }
    sort(vec.begin(), vec.end(), greater<pair<int, int>>());

    vector<bool> check(n, false);
    int swaps = 0;
    for(int i = 0; i < n; i++) {
        if(vec[i].second == i|| check[i]) continue;
        int cycleSize = 0;
        int j = i;
        while(!check[j]) {
            check[j] = true;
            j = vec[j].second;
            cycleSize++;
        }
        if(cycleSize > 1) {
            swaps+=(cycleSize- 1);
        }
    }
    return swaps;
}

int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int res = min(minDeSwap(a,n), minAsSwap(a,n));
    cout << res;

	return 0;
}
