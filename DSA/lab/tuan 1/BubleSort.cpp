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

void bubleSort(vector<int> &arr) {
    int n = arr.size();
    bool t;
    for(int i = 0; i < n -1; i++) {
        t = false;
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                t = true;
                display(arr);
            }
        }
        if(!t)
            break;
    }
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr;
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }
    bubleSort(arr);

	return 0;
}
