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

void print(vector<int> a) {
    int n = a.size();
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}

void bSort(vector<int> &a) {
    bool sCheck;
    for(int i = 0; i < a.size() - 1; i++) {
        sCheck = false;
        for(int j = 0; j < a.size() - i - 1; j++) {
            if(a[j] > a[j+1]) {
                swap(a[j], a[j+1]);
                print(a);
                cout << endl;
                sCheck = true;
            }
        }
        if(!sCheck) {
            break;
        }
    }
}

int main()
{
    int n; cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++) {
        int tmp; cin >> tmp;
        arr.push_back(tmp);
    }
    bSort(arr);
	return 0;
}
